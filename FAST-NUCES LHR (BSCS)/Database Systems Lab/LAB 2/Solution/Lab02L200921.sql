-- Task I
Answer:
1) Msg 2627, Level 14, State 1, Line 24
Violation of PRIMARY KEY constraint &#39;PK__Students__7886D5A003C232AA&#39;. Cannot insert duplicate
key in object &#39;dbo.Students&#39;. The duplicate key value is (8).

On Line 24 there is violation of primary key. Duplicate key is being violated by adding 8 when 8 is already present.
2) Msg 515, Level 16, State 2, Line 35
Cannot insert the value NULL into column &#39;CourseID&#39;, table &#39;Neo1.dbo.Courses&#39;; column does not
allow nulls. INSERT fails.

Cannot set a primary key as null. Course ID is primary key so attempting to insert null in the column gives error.
3) Msg 547, Level 16, State 0, Line 78
The INSERT statement conflicted with the FOREIGN KEY constraint
&quot;FK__Courses_S__Instr__173876EA&quot;. The conflict occurred in database &quot;Neo1&quot;, table
&quot;dbo.Instructors&quot;, column &#39;InstructorID&#39;.

Instructor Id 400 doesn’t exist in referenced table it is foreign key hence cannot be inserted if it is not available.
4) Msg 547, Level 16, State 0, Line 82
The INSERT statement conflicted with the FOREIGN KEY constraint
&quot;FK__Courses_S__Cours__182C9B23&quot;. The conflict occurred in database &quot;Neo1&quot;, table
&quot;dbo.Courses&quot;, column &#39;CourseID&#39;.

Course Id 11 doesn’t exist in referenced table it is foreign key hence cannot be inserted if it is not available.
5)
Msg 547, Level 16, State 0, Line 87
The DELETE statement conflicted with the REFERENCE constraint
&quot;FK__Courses_S__Semes__1920BF5C&quot;. The conflict occurred in database &quot;Neo1&quot;, table
&quot;dbo.Courses_Semester&quot;, column &#39;Semester&#39;.


We are trying to delete parent when its child exists. Which gives error.
6) Msg 2627, Level 14, State 1, Line 121
Violation of PRIMARY KEY constraint &#39;PK__Students__7886D5A003C232AA&#39;. Cannot insert duplicate
key in object &#39;dbo.Students&#39;. The duplicate key value is (5).

The roll number 5 already exist in referenced table. The foreign key is primary key in referenced table and hence can
be duplicated.


-- Task II 
create database Lab02L200921;
use Lab02L200921;

create table Student (
RollNum nvarchar(100),
Name nvarchar(100),
Gender nvarchar(100),
Phone nvarchar(100)
);
create table Attendance  
(
RollNum nvarchar(100),
Date date,
Status char,
ClassVenue int
);

create table ClassVenue
(
ID int,
Building nvarchar(100),
RoomNum int,
TeacherId int
);

create table Teacher 
(
Id int,
Name nvarchar(100),
Designation nvarchar(100),
Department nvarchar(100),
);


--Task III 
--Q1
insert into Student values
('L164123','Ali Ahmad','Male','0333-3333333'),
('L164124','Rafia Ahmed','Female','0333-3456789'),
('L164125','Basit Junaid','Male','0345-3243567')

insert into Attendance values
('L164123','02-22-16','P',2),
('L164124','02-23-16','A',1),
('L164125','03-4-16','P',2)


insert into ClassVenue values 
(1,'CS',2,1),
(2,'Civil',7,2)

insert into Teacher values 
(1,'Sarim Baig','Assistant Prof.','Computer Science'),
(2,'Bismillah Jan','Lecturer','Civil Eng.'),
(3,'Kashif zafar','Professor','Electrical Eng.')

--Q2
Alter Table Student alter column RollNum nvarchar(100) NOT NULL
Alter Table Student add constraint PK_STUDENT primary key (RollNum)

Alter Table Attendance alter column RollNum nvarchar(100) NOT NULL
Alter Table Attendance add constraint PK_Attendance primary key (RollNum)

Alter Table ClassVenue alter column ID int NOT NULL
Alter Table ClassVenue add constraint PK_ClassVenue primary key (ID)

Alter Table Teacher alter column Id int NOT NULL
Alter Table Teacher add constraint PK_Teachcer primary key (Id)

--Q3
--(a) & (b) 
alter table Attendance add constraint FK_ATTENDANCE foreign key (RollNum) references Student
(RollNum) on delete No Action on update Cascade
alter table Attendance add constraint FK_ATTENDANCE2 foreign key (ClassVenue) references ClassVenue
(ID) on delete No Action on update Cascade
alter table ClassVenue add constraint FK_ClassVenue foreign key (TeacherId) references Teacher
(Id) on delete No Action on update Cascade

--Q4
alter table Student add warningcount int

--Q5
/*
(a).

insert into Student ([RollNum],[Name],[Gender],[warningcount])
values  ('L162334', 'Fozan Shahid','Male', 3.2 )*/
/*
Invalid because warning count is int not float and phone number is missing

Valid way:
<L162334, Fozan Shahid, Male,0333-1234567, 3 >

*/
/*

(b)
invalid 
tecaher id can not be a name. Int cannot be nvarchar(100)
insert into ClassVenue values (3,'CS',5,'Ali')
valid way :
insert into ClassVenue values (3,'CS',5,1)



(c). Valid
(d). valid
(e). Invalid becuase cannot delete a value whoose children exist
(f) Valid

*/

Update Teacher
set Name='Dr. Kashif Zafar'
where Name='Kashif zafar'

Delete from Student 
where RollNum='L162334'

Delete from Student 
where RollNum='L164123'


Delete from Attendance
where RollNum='L164124' AND Status='A'


--Q6 
--(a)
alter table Student add CNIC nvarchar(100)
--(b)
alter table Student drop column Phone
--(c)
Alter Table Teacher add constraint UNIQUE_CONSTRAINT_TEACHER_NAME Unique (Name)
--(d)
alter table Student add Constraint STUDENT_CHECK_Gender check (Gender='Female' OR Gender= 'MALE')
--(e)
alter table Attendance add Constraint ATTENDANCE_CHECK_STATUS check (Status='A' OR Status= 'P')