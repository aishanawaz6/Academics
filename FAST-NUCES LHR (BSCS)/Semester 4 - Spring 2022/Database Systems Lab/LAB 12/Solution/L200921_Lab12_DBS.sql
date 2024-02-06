--Aisha Muhammad Nawaz L200921 BSCS Section 4A LAB 12 DBS
--Q1
/*
Question:
Create a procedure for student registration in some course the procedure must check 
that the CGPA of the student if the CGPA is less than 2.5 the transaction must 
rollback and the record must not be stored and a message must be displayed that 
he can only enroll in subjects that he can improve however if the student’s CGPA
is greater than 2.5 he can enroll in any subject he wants in this case the 
transaction should be committed.  Assume that the enrollment can only be done 
through stored procedure.
*/
--use Lab12_L200921
create procedure Lab12Q1
(
@sem varchar(15),
@Rn varchar(7),
@ci int,
@s varchar(15),
@gpa float
)
as begin
begin transaction
save transaction savepoint;
begin try
INSERT [dbo].[Registration] ([Semester], [RollNumber], [CourseID], [Section],GPA) VALUES (@sem,@Rn,@ci,@s,@gpa)
end try
begin catch
if(@gpa<2.5)
begin
rollback transaction savepoint;
print 'Can only enroll in subjects that you can improve'
end
end catch
commit transaction
end

execute Lab12Q1 @sem ='Spring2022',@Rn='8',@ci='20',@s='A',@gpa='2.4'

