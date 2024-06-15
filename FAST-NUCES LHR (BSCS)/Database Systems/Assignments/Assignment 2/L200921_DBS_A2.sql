create database dbA2;
use dbA2;

create table Student(
StudID int primary key,
StudName nvarchar(100),
DeptID int foreign key references Department(DeptID),
Age int,
GPA float
);

create table Course 
(
CourseID int primary key,
CourseName nvarchar(100),
InstructorID int foreign key references Instructor(InstructorID),
);

create table Department 
(
DeptID int primary key,
DeptName nvarchar(100),
Location nvarchar(100)
);

create table Instructor 
(
InstructorID int primary key,
InstructorName nvarchar(100),
DeptID int foreign key references Department(DeptID),
);

create table Section (
SectionID int primary key,
SectionName nvarchar(100),
Time time,
RoomID int foreign key references Room(RoomID),
CourseID int foreign key references Course(CourseID),
InstructorID int foreign key references Instructor(InstructorID),
);

create table Room (
RoomID int primary key,
RoomName nvarchar(100),
Location nvarchar(100)
);

create table Enrolled (
StudID int  foreign key references Student(StudID),
SectionID int  foreign key references Section(SectionID),
primary key clustered (StudID,SectionID)

);

/* Assignment 2 Questions part starts here*/

--1) 
use dbA2;
Select StudName
from Student AS s join Enrolled AS E on s.StudID=E.StudID
where SectionID = (
Select SectionID
from Section se join Instructor As I on se.InstructorID=I.InstructorID  
where InstructorName='Ishaq') AND GPA>3

--2) 
Select InstructorName 
from Instructor AS I join Department AS d on I.DeptID=d.DeptID
where DeptName='Computer Science'

--3) 
Select avg(GPA) As AverageGPA
from Student AS s join Enrolled As e on s.StudID=e.StudID
where SectionID=12345678

--4) 
Select max(Age) As OldestAge
from Student
where DeptID=(
Select DeptID
from Department
where DeptName='Management Sciences'
)
--5) 
Select max(Age) As OldestAge
from Student As s join department As d on s.DeptID=d.DeptID join Enrolled as E on s.StudID=E.StudID join section As Se on se.SectionID=E.SectionID join Instructor AS I on I.InstructorID=se.InstructorID
where DeptName='Computer Science' AND InstructorName='Ishaq'

--6) 
Select distinct SectionName 
from Section AS s join Enrolled AS E on S.SectionID=E.SectionID join Room AS R on r.RoomID=S.RoomID
where RoomName='CS-3' 
Union
Select distinct S.SectionName --,count(*) AS counts--count(*)-- SectionName
from  Enrolled AS E join Section AS S on E.SectionID=S.SectionID
Group by S.SectionName
having count(*)>=50


--7)* Later corrected
Select distinct s.StudName
from Student as s join Enrolled as e on s.StudID=e.StudID join section as sec on sec.SectionID=e.SectionID 
join Student as s2 join Enrolled as e2 on s2.StudID=e2.StudID join section as sec2 on sec2.SectionID=e2.SectionID 
on sec.Time=sec2.Time
where sec.SectionID<>sec2.sectionID

--8)* Later corrected
use dbA2;
Select InstructorName
from Instructor
where InstructorID IN(
select InstructorID
from
Section as S join Room as r on r.RoomID=s.RoomID
Group by InstructorID
having count(*)=(SELECT COUNT(distinct RoomID)
          FROM section)
)
--9)
Select instructorname
from instructor as i join Section as se on i.InstructorID=se.InstructorID
where se.SectionID IN 
(
Select e.SectionID
from course as c join Instructor as I on c.CourseID=I.InstructorID join Section as s on s.CourseID=c.CourseID join Enrolled as e on e.SectionID=s.SectionID
Group by e.SectionID
having count(*)<100
) 

--10)
Select GPA,avg(age) 
from Student
Group by GPA


--11)
Select GPA,avg(age) 
from Student
Group by GPA
having GPA!=2.0

--12)
Select i.InstructorName, count(*) as TotalSectionsTaught
from Instructor as i join section as s on i.InstructorID=s.InstructorID
where i.InstructorID IN(
Select distinct I.InstructorID
from Instructor as I join Section as S on I.InstructorID=S.InstructorID join Room as R on R.RoomID=S.RoomID
where RoomName='CS-3'
Except 
Select distinct I.InstructorID
from Instructor as I join Section as S on I.InstructorID=S.InstructorID join Room as R on R.RoomID=S.RoomID
where RoomName!='CS-3')
Group by InstructorName

--13)
Select StudName
from Student 
where StudID IN(
Select StudID
from Enrolled 
where StudID IN (Select s.StudID
from Student as s join Enrolled as E on s.StudID=e.StudID
)
Group by StudID
having count(*) =
(
select count(*)
from Section
))  -- Assuming max number of sections that can be enrolled into is equal to total number of sections

--14)
Select StudName
from Student 
where StudID IN(
Select distinct StudID  
from Student 
Except
Select distinct StudID
from Enrolled
)
--15)
use dbA2
select n1.Age, max(n1.GPA) as gpa
from
(
select v.age, max(v.gpa_count) as gpa_count FROM
(
select s3.age, s3.gpa, count(*) as gpa_count
from students s3
where s3.age in (
select s.age
from students s
group by s.age
)
group by s3.age, s3.gpa
) v
group by v.age
) n JOIN
(
select s3.age, s3.gpa, count(*) as gpa_count
from students s3
where s3.age in (
select s.age
from students s
group by s.age
)
group by s3.age, s3.gpa
) n1 on n.gpa_count=n1.gpa_count and n.age=n1.age
GROUP by n1.age
order by n1.age