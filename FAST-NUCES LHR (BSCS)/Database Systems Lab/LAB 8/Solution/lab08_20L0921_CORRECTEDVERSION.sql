--20L-0921 AISHA MUHAMAMD NAWAZ BSCS LAB08 DATABASE SYSTEMS SECTION 4A1

use dblab08

--Q1
create trigger trigger1 on Students
instead of delete 
as begin
print 'You don’t have the permission to delete the student'
end

delete from Students
where RollNo=4


--Q2
create trigger trigger2 on Courses
instead of insert
as begin 
print 'You don’t have the permission to Insert a new Course'
end

insert into Courses
values ('50','DBSLAB','10','3');

--Q3
create trigger trigger3 on Registration
after insert
as begin
declare @dRollNo varchar(7)
select @dRollNo=RollNumber from inserted
if EXISTS(
select*
from Students as s join ChallanForm as cf on s.RollNo =cf.RollNumber
where s.RollNo=@dRollNo AND cf.Status <> 'Pending'
)
begin
if EXISTS(
select*
from Students as s join ChallanForm as cf on s.RollNo=cf.RollNumber
where s.RollNo=@dRollNo AND cf.TotalDues<=200000
)
print 'pass'
end
else
begin
delete from Registration
where RollNumber=@dRollNo
print 'Cannot insert.'
end
end

insert into Registration values ('Fall2016','4','40','D','2.5');

--Q4
create trigger trigger4 on Courses_Semester
instead of delete 
as begin
declare @ins int, @courid int, @sem varchar(15),@sec varchar(1)
select @ins=InstructorID from deleted 
select @courid=CourseID from deleted
select @sem=Semester from deleted 
select @sec=Section from deleted
if EXISTS (
select*
from Courses_Semester
where InstructorID=@ins AND CourseID=@courid AND AvailableSeats>=10 AND @sem=Semester AND @sec=Section
)
begin
print 'Successfully deleted'
delete from Courses_Semester
where InstructorID=@ins AND CourseID=@courid AND @sem=Semester AND @sec=Section
end
else
if (@ins != NULL AND @courid!=NULL AND @sem !=NULL AND @sec !=NULL)
begin
print 'Does not exist'
end
else
print 'not possible'
end

delete from Courses_Semester 
where InstructorID='200'  AND CourseID='10' AND Semester ='Spring2017' AND Section ='D'


--Q5
create trigger trigger5 
on database
FOR 
drop_table,alter_table
as begin
print 'you are not allowed to modify or drop tabels.'
Rollback
end

drop table ChallanForm
