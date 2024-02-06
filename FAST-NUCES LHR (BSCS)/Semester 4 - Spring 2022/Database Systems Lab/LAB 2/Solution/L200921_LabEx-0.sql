use master
go
 
Create database Neo1
go 
use Neo1

go
create table Students
(RollNo varchar(7) primary key
,Name varchar(30)
,WarningCount int
,Department varchar(15)
)
GO
INSERT [dbo].[Students] ([RollNo], [Name], [WarningCount], [Department]) VALUES ('1', 'Ali', 0, 'CS')
INSERT [dbo].[Students] ([RollNo], [Name], [WarningCount], [Department]) VALUES ('2', 'Bilal', 0, 'CS')
INSERT [dbo].[Students] ([RollNo], [Name], [WarningCount], [Department]) VALUES ('3', 'Ayesha', 0, 'CS')
INSERT [dbo].[Students] ([RollNo], [Name], [WarningCount], [Department]) VALUES ('4', 'Ahmed', 0, 'CS')
INSERT [dbo].[Students] ([RollNo], [Name], [WarningCount], [Department]) VALUES ('5', 'Sara', 0, 'EE')
INSERT [dbo].[Students] ([RollNo], [Name], [WarningCount], [Department]) VALUES ('6', 'Salma', 1, 'EE')
INSERT [dbo].[Students] ([RollNo], [Name], [WarningCount], [Department]) VALUES ('7', 'Zainab', 2, 'CS')
INSERT [dbo].[Students] ([RollNo], [Name], [WarningCount], [Department]) VALUES ('8', 'Danial', 1, 'CS')
INSERT [dbo].[Students] ([RollNo], [Name], [WarningCount], [Department]) VALUES ('8', 'Arsala', 1, 'CS')
go
create table Courses
(
CourseID int primary key,
CourseName varchar(40),
PrerequiteCourseID int,
CreditHours int
) 
GO
INSERT [dbo].[Courses] ([CourseID], [CourseName], [PrerequiteCourseID],CreditHours) VALUES (10, 'Database Systems', 20, 3)
INSERT [dbo].[Courses] ([CourseID], [CourseName], [PrerequiteCourseID],CreditHours) VALUES (NULL, 'Database Systems', 20, 3)
INSERT [dbo].[Courses] ([CourseID], [CourseName], [PrerequiteCourseID],CreditHours) VALUES (20, 'Data Structures', 30,3)
INSERT [dbo].[Courses] ([CourseID], [CourseName], [PrerequiteCourseID],CreditHours) VALUES (30, 'Programing', NULL,3)
INSERT [dbo].[Courses] ([CourseID], [CourseName], [PrerequiteCourseID],CreditHours) VALUES (40, 'Basic Electronics', NULL,3)
go

go
Create table Instructors 
(
InstructorID int Primary key,
Name varchar(30),
Department varchar(7) ,
)
GO
INSERT [dbo].[Instructors] ([InstructorID], [Name], [Department]) VALUES (100, 'Ishaq Raza', 'CS')
INSERT [dbo].[Instructors] ([InstructorID], [Name], [Department]) VALUES (200, 'Zareen Alamgir', 'CS')
INSERT [dbo].[Instructors] ([InstructorID], [Name], [Department]) VALUES (300, 'Saima Zafar', 'EE')
go
Create table Semester
(
Semester varchar(15) Primary key,
[Status] varchar(10),
)
GO
INSERT [dbo].[Semester] ([Semester], [Status]) VALUES ('Fall2016', 'Complete')
INSERT [dbo].[Semester] ([Semester], [Status]) VALUES ('Spring2016', 'Complete')
INSERT [dbo].[Semester] ([Semester], [Status]) VALUES ('Spring2017', 'InProgress')
INSERT [dbo].[Semester] ([Semester], [Status]) VALUES ('Summer2016', 'Cancelled')
go

go
Create table Courses_Semester
(
InstructorID int Foreign key References Instructors(InstructorID),
CourseID int Foreign key References Courses(CourseID),
Semester varchar(15) Foreign key References Semester(Semester), 
Section varchar(1) ,
AvailableSeats int,
Department varchar(2)
)
GO

INSERT [dbo].[Courses_Semester] ([InstructorID], [CourseID], [Semester], [Section], [AvailableSeats], [Department]) VALUES (200, 10, 'Spring2017', 'D', 45, 'CS')
INSERT [dbo].[Courses_Semester] ([InstructorID], [CourseID], [Semester], [Section], [AvailableSeats], [Department]) VALUES (400, 10, 'Spring2017', 'D', 45, 'CS')
INSERT [dbo].[Courses_Semester] ([InstructorID], [CourseID], [Semester], [Section], [AvailableSeats], [Department]) VALUES (200, 10, 'Spring2017', 'C', 0, 'CS')
INSERT [dbo].[Courses_Semester] ([InstructorID], [CourseID], [Semester], [Section], [AvailableSeats], [Department]) VALUES (100, 10, 'Spring2017', 'A', 6, 'CS')
INSERT [dbo].[Courses_Semester] ([InstructorID], [CourseID], [Semester], [Section], [AvailableSeats], [Department]) VALUES (300, 40, 'Spring2017', 'A', 6, 'CS')
INSERT [dbo].[Courses_Semester] ([InstructorID], [CourseID], [Semester], [Section], [AvailableSeats], [Department]) VALUES (300, 11, 'Spring2017', 'A', 6, 'CS')
INSERT [dbo].[Courses_Semester] ([InstructorID], [CourseID], [Semester], [Section], [AvailableSeats], [Department]) VALUES (300, 40, 'Spring2016', 'A', 6, 'CS')
INSERT [dbo].[Courses_Semester] ([InstructorID], [CourseID], [Semester], [Section], [AvailableSeats], [Department]) VALUES (200, 10, 'Spring2016', 'A', 0, 'CS')

go
Delete from dbo.Semester
where Semester='Spring2017' 
go


create table Registration
(
Semester varchar(15) Foreign key References Semester(Semester),
RollNumber  varchar(7) Foreign key References Students(RollNo),
CourseID int Foreign key References Courses(CourseID), 
Section varchar(1),
GPA float
)
INSERT [dbo].[Registration] ([Semester], [RollNumber], [CourseID], [Section],GPA) VALUES ('Fall2016', '1', 20, 'A', 3.3)
INSERT [dbo].[Registration] ([Semester], [RollNumber], [CourseID], [Section],GPA) VALUES ('Fall2016', '2', 20, 'B', 4)
INSERT [dbo].[Registration] ([Semester], [RollNumber], [CourseID], [Section],GPA) VALUES ('Spring2016', '1', 30, 'A', 1.0)
INSERT [dbo].[Registration] ([Semester], [RollNumber], [CourseID], [Section],GPA) VALUES ('Fall2016', '6', 40, 'D',0.0)
INSERT [dbo].[Registration] ([Semester], [RollNumber], [CourseID], [Section],GPA) VALUES ('Spring2017', '6', 40, 'D',1)


go

Create table ChallanForm
(Semester varchar(15) Foreign key References Semester(Semester),
RollNumber  varchar(7) Foreign key References Students(RollNo),
TotalDues int,
[Status] varchar(10)
)
GO
INSERT [dbo].[ChallanForm] ([Semester], [RollNumber], [TotalDues], [Status]) VALUES ('Fall2016', '1', 100000, 'Paid')
INSERT [dbo].[ChallanForm] ([Semester], [RollNumber], [TotalDues], [Status]) VALUES ('Fall2016', '2', 13333, 'Paid')
INSERT [dbo].[ChallanForm] ([Semester], [RollNumber], [TotalDues], [Status]) VALUES ('Fall2016', '3', 5000, 'Paid')
INSERT [dbo].[ChallanForm] ([Semester], [RollNumber], [TotalDues], [Status]) VALUES ('Fall2016', '4', 20000, 'Pending')

Update Students
set Students.RollNo=5
where RollNo=4

select * from Students
select * from Courses
select * from Instructors
select * from Registration
select * from Semester
select * from Courses_Semester
select * from ChallanForm


----ERRORS
/*
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

*/