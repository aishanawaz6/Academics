-- DBS PROJECT DELIVERABLE 03 STORED PROCEDURES, VIEWS & TRIGGERS 20L1116,20L1186,20L0921
use project

---------------------------------------------STORED PROCEDURES----------------------------------------------------------------------------------
-- Procedure 1: To retrieve data from user inorder to login.
create procedure getLoginDetails @Usern nvarchar(100),@passw nvarchar(50)
as
begin
declare  @checkUsern nvarchar(100)
set @checkUsern=(
select UserID
from UserLogin
where UserID=@Usern AND Passwords=@passw
)
if(@checkUsern=@Usern)
print 'Login Successfull!'
else
print'Login Failed!'
end
--Testing Procedure 1
insert into Users values ('an','a','n','20','190','an@gmail.com','Female')
insert into Books values ('123','THE GOLDEN GLOBE','Arzo','Comedy','15','Karachi','5','8')
insert into UserLogin values ('an','a3','3650','5-11-2022','Current','None','0','123','2','5-11-22','6-11-22')
execute getLoginDetails @Usern='an', @passw='a3' 


-- Procedure 2: To retrieve data inorder to Sign Up
create procedure signUp @UI nvarchar(100),@fn nvarchar(100), @ln nvarchar(100), @ag int , @ph nvarchar(20), @em nvarchar(50), @G nvarchar(10),  @pass nvarchar(50) ,@cnic nvarchar(60)
as 
begin
insert into Users values (@UI,@fn,@ln,@ag,@ph,@em,@G)
insert into UserLogin (UserID,Passwords,CNIC,JoinDate,MembershipType) values(@UI,@pass,@cnic,GETDATE(),'Current')
print 'Sign Up Successfull!'
end
--Testing Procedure 2
execute signUp @UI='abc',@fn='Aaa',@ln='Zzz',@ag='12',@ph='0305',@em='aaa@gmail.com',@G='Male',@pass='123v',@cnic='0304'


--Procedure 3 : To Search all details of a specific author
create procedure AllDetailsOfAuthor @AuthorName nvarchar(200)
as 
begin 
select *
from Authors 
where AuthorName=@AuthorName
end
-- Testing Procedure 3
insert into Authors values ('Arzo','123','THE GOLDEN GLOBE','4','THE GOLDEN GLOBE','5')
insert into Books values ('456','THE PERSIAN WOLF','Arzo','Comedy','15','Karachi','4','8')
insert into Authors values ('Arzo','456','THE PERSIAN WOLF','5','THE GOLDEN GLOBE','4')
insert into Books values ('789','THE DEAD','Arui','Horror','4','Lahore','3','1')
insert into Authors values ('Arui','789','THE DEAD','3','THE DEAD','3')
execute AllDetailsOfAuthor @AuthorName='Arzo'


-- Procedure 4: To Search A Book by its name
create procedure SearchABook @BookName nvarchar(200)
as 
begin
select *
from Books
where BookName=@BookName
end
-- Testing Procedure 4
execute SearchABook @BookName='THE PERSIAN WOLF'


--- Procedure 5 : To Search Books by Genre
create procedure SearchByGenre @gen nvarchar(100)
as
begin
select*
from Books
where Genre=@gen
end
-- Testing Procedure 5
execute SearchByGenre @gen ='Comedy'
execute SearchByGenre @gen ='Horror'


--- Procedure 6 : To Search bestselling of a specifc author
create procedure searchAuthorBestSelling @authorName nvarchar(200) 
as 
begin
select distinct BestSelling,AuthorName
from Authors
where AuthorName=@authorName
end
-- Testing Procedure 6
execute searchAuthorBestSelling @authorName ='Arzo'


--- Procedure 7 : To Show fines histroy of a specifc user
create procedure ShowFinesHistory @uID nvarchar(100)
as
begin
select FineHistory
from UserLogin
where UserID=@uID
end
-- Testing Procedure 7
execute ShowFinesHistory @uID='abc'


--Procedure 8 : To search all location details of a book by Book name
create procedure SearchLocationDetailsofBook @BookN nvarchar(200)
as
begin
select *
from Locations
where BookName=@BookN
end
-- Testing Procedure 8
insert into Locations values('123','THE GOLDEN GLOBE','78','Karachi','15')
execute SearchLocationDetailsofBook @BookN='THE GOLDEN GLOBE'
insert into Locations values('456','THE PERSIAN WOLF','79','Karachi','15')
execute SearchLocationDetailsofBook @BookN='THE PERSIAN WOLF'


--Procedure 9 : To search membership details of a specific user by using userID
create procedure SearchMembershipDetails @uID nvarchar(100)
as
begin
select *
from Membership
where UserID=@uID
end
-- Testing Procedure 9
insert into Membership values('abc','1001','Current','0','0','FREE')
insert into Membership values('an','1000','Current','2','5000','Premium')
execute SearchMembershipDetails @uID='abc'


--Procedure 10 : To display all details of user to themselves (Like view profile)
create procedure showMyDetails @uID nvarchar(100)
as
begin 
select *
from Users as u join UserLogin as ul on ul.UserID=u.UserID join Membership as m on m.UserID=u.UserID
where u.UserID=@uID
end
-- Testing Procedure 10
execute showMyDetails @uID ='abc'


---Procedure 11 : To show all recommended books for a specific user
create procedure showRecommendations @uID nvarchar(100)
as
begin
select *
from Recommendations
where UserID=@uID
end
-- Testing Procedure 11
insert into Recommendations values ('abc','THE GOLDEN GLOBE','Comedy')
execute showRecommendations @uID='abc'


--Procedure 12: to show all Books of a sepcific type
create procedure SearchBooksByType @bt nvarchar(200)
as
begin
select *
from books
where BookID IN (
select BookID
from Catalogue
where BookType=@bt
)
end
---Testing procedure 12
insert into Catalogue values('123','Magazine','Comedy','Arzo','15')
execute SearchBooksByType @bt = 'Magazine'


--Procedure 13: to search all books available at a specific location
create procedure searchByLoaction @ln nvarchar(200)
as
begin
select *
from books
where Locations=@ln
end
-- Testing procedure 13
execute searchByLoaction @ln ='Karachi'
execute searchByLoaction @ln ='Lahore'


--Procedure 14: to serach to whom a specifc book has been issued to using book ID
create procedure FindIssuedTo @BI nvarchar(100)
as
begin
select *
from Tracking
where BookID=@BI
end
---Testing procedure 14
insert into Tracking values('123','an','2022-05-11','2022-06-11')
execute FindIssuedTo @BI='123'


---Procedure 15: To search books by a specific rating
create procedure searchBookByRatings @rat int
as
begin
select *
from books
where Ratings=@rat
end
---Testing procedure 15
execute searchBookByRatings @rat=3


---Procedure 16: To search all details of a specific staff member
create procedure searchAStaffMember @sID nvarchar(100)
as
begin
select *
from staff
where StaffID=@sID
end
---Testing proecdure 16:
insert into staff values('190','Sped','jame','28','Library Supervisor','190Sped@Library.com','178-900-345','25000','0')
execute searchAStaffMember @sID='190'


---Procedure 17: To search all suggestions (by bookname) given of a specific book  by users
 create procedure searchSuggestionofBook @bn nvarchar(200)
 as
 begin
 select *
 from Suggestions
 where BookName=@bn
 end
 -- Testing procedure 17
insert into Suggestions values ('abc','Books','THE ANCIENT RIDDLE','05-05-22','Good ratings')
execute searchSuggestionofBook @bn='THE ANCIENT RIDDLE'


--Procedure 18 : To check if a specific Discussion Room is available
create procedure searchDiscussionRoom @ri nvarchar(100)
as
begin
select*
from DiscussionRooms
where RoomID=@ri
end
---Testing procedure 18
insert into DiscussionRooms values('809','YES',NULL,NULL)
execute searchDiscussionRoom @ri = '809'


------------------------------------------------------VIEWS-------------------------------------------------------------------------------------


--1.                          ALL AVAILABLE BOOKS
CREATE VIEW AVAILABLE_BOOKS
AS
SELECT * FROM Books
WHERE Books.NumberOfCopiesAvailable>0

SELECT* FROM AVAILABLE_BOOKS

--2.                          ALL UNAVAILABLE BOOKS
CREATE VIEW UNAVAILABLE_BOOKS
AS
SELECT * FROM Books
WHERE Books.NumberOfCopiesAvailable=0

SELECT* FROM UNAVAILABLE_BOOKS

--3.                          ALL MEMBERSHIPS DETAILS
CREATE VIEW MEMBERSHIPS_DETAILS
AS
SELECT* FROM Membership

SELECT* FROM MEMBERSHIPS_DETAILS

--4.                          ALL SUGGESTED BOOKS
CREATE VIEW SUGGESTED_BOOKS
AS
SELECT S.BookName,S.AreaOfSuggestion,S.UserID FROM  Suggestions S

SELECT*FROM SUGGESTED_BOOKS

--5.                            ALL STAFF
CREATE VIEW ALL_STAFF
AS 
SELECT* FROM Staff

SELECT* FROM ALL_STAFF

--6.                           RECOMMENDED_BOOKS
CREATE VIEW RECOMMENDED_BOOKS
AS 
SELECT*  FROM Recommendations 

SELECT * FROM RECOMMENDED_BOOKS

--7.                            AVAILABLE_DISCUSSION_ROOMS
CREATE VIEW AVAILABLE_DISCUSSION_ROOMS
AS 
SELECT * FROM DiscussionRooms D
WHERE D.Availabile != NULL

SELECT * FROM AVAILABLE_DISCUSSION_ROOMS

--8.                            UNAVAILABLE_DISCUSSION_ROOMS
CREATE VIEW UNAVAILABLE_DISCUSSION_ROOMS
AS 
SELECT * FROM DiscussionRooms D
WHERE D.Availabile = NULL

SELECT * FROM UNAVAILABLE_DISCUSSION_ROOMS


--9.                             BOOKS_GROUPBY_GENRE
CREATE VIEW BOOKS_GROUPBY_GENRE1
AS 
SELECT B.BookID,B.BookName,B.Genre FROM Books B
GROUP BY B.Genre, B.BookID,B.BookName

SELECT* FROM BOOKS_GROUPBY_GENRE1

--OR
CREATE VIEW BOOKS_GROUPBY_GENRE2
AS 
SELECT* FROM Books B
WHERE B.GenrE IN(
SELECT Genre FROM Books 
GROUP BY Genre
)

SELECT* FROM BOOKS_GROUPBY_GENRE2

--10.                               USERS HAVING FINES
CREATE VIEW USERS_HAVING_FINES
AS 
SELECT U.UserID,U.Fine FROM UserLogin U
WHERE U.Fine>0

SELECT* FROM USERS_HAVING_FINES

--11.                                ALL USERS_HAVE_NOT_MEMBERSHIP
CREATE VIEW USERS_HAVE_NOT_MEMBERSHIP
AS
SELECT * FROM Users U
WHERE U.UserID !=(
SELECT M.UserID FROM Membership M
)

SELECT * FROM USERS_HAVE_NOT_MEMBERSHIP

INSERT INTO Users VALUES(1,'H','B',20,1111,'HUMAIRA@GMAIL.COM','F');
INSERT INTO Users VALUES(2,'F','K',25,2222,'FAIZI@GMAIL.COM','M');
INSERT INTO Membership VALUES(1,1,'TEMPORARY',5,5000,NULL);

--12.                                ALL USERS_HAVE_MEMBERSHIP
CREATE VIEW USERS_HAVE_MEMBERSHIP
AS
SELECT * FROM Users U
WHERE U.UserID =(
SELECT M.UserID FROM Membership M
) 
SELECT * FROM USERS_HAVE_MEMBERSHIP

--13.                                AUTHORS_BEST_SELLING_BOOKS
CREATE VIEW AUTHORS_BEST_SELLING_BOOKS
AS 
SELECT A.AuthorName,A.BestSelling  FROM Authors A

SELECT* FROM AUTHORS_BEST_SELLING_BOOKS

--14.                    BOOKS_AT_SPECIFIC_LOCATIONS
CREATE VIEW BOOKS_AT_SPECIFIC_LOCATIONS
AS 
SELECT L.LocationName, L.BookID,L.BookName  FROM Locations L
GROUP BY L.LocationID,L.BookID,L.BookName,L.LocationName

SELECT* FROM BOOKS_AT_SPECIFIC_LOCATIONS

INSERT INTO Locations VALUES(455,'NOT',1,'LAHORE',5)
INSERT INTO Locations VALUES(788,'NOTHING',2,'KARACHI',5)

--15.                  TRACKING OF ALL BOOKS
CREATE VIEW TRACKING_OF_ALL_BOOKS
AS 
SELECT* FROM Tracking

SELECT* FROM TRACKING_OF_ALL_BOOKS


--16.                   DETAILS OF ALL AUTHORS
CREATE VIEW DETAILS_OF_AUTHORS
AS
SELECT* FROM Authors

SELECT* FROM DETAILS_OF_AUTHORS


-------------------------------------------------------TRIGGERS---------------------------------------------------------------------------------


--trigger for new signup
--1)
use Projectv2
create trigger signup
on UserLogin
after insert
as begin
print 'You have signed up successfully. Congratulation on joining our Reading Club'
end

--trigger for a new author
--2)
create trigger author
on Authors
after insert
as begin
print 'A new author has been added to library'
end

--Trigger for addition of books
--3)
create trigger book
on Books
after insert
as begin
print ' A new Book has been added to our Collection'
end

--Trigger for deleting book
--4)
create trigger deltrig
on Users
after delete
as begin
print 'User deleted Succesfully'
end

--Trigger for Location
--5)
create trigger loctrigger
on Locations
after delete
as begin
print ' This Book is no longer available on this location'
end

--Trigger for new addition in Catalogue
--6)
create trigger Cataloguetrigger
on Catalogue
after insert 
as begin
print 'A new addition has been made to Library'
end

--Trigger for updating a book
--7)
create trigger UpdateBook
on Books
after update
as begin
print 'Book has been Updated'
end

--TESTING
update Books
set NumberOfCopiesAvailable=15
where BookID='125'

select* from Books
--Updating Available Copies of Books after a Book has been issued
--8)
create trigger updatecopies
on Tracking 
after insert 
as begin
update Books 
set NumberOfCopiesAvailable=NumberOfCopiesAvailable-1
from books b join inserted i on b.BookID=i.BookID
end


--testing
insert into Tracking values ('125','ashiinz','2022-04-01','2022-05-01')
select * from books

--Trigger for deleting Book
--9)
create trigger delBook
on Books
after delete
as begin
print' This Book has been deleted permanently from this Library'
end

--Updating the Availabilty of Room after it has been Booked
--10)
create trigger roomUpdate
on DiscussionRooms
after insert ,update 
as begin
Update DiscussionRooms
set Availabile='No'
where BookedDate is not null 
end


--testing 
insert into DiscussionRooms values('809','YES',NULL,NULL)
insert into DiscussionRooms values('810','YES','ashiinz','2022-04-01')


update DiscussionRooms
set BookedBy='faiqa_Adnan' , BookedDate='2022-04-01'
where Availabile='yes'

--11)
create trigger checkcopies
on Tracking
after insert
as begin
declare @copies int
select @copies=NumberOfCopiesAvailable
from Books b join inserted i on b.BookID=i.BookID
if (@copies<0)
begin
ROLLBACK TRANSACTION
print 'This Book is Not Available'
end

end

--TESTING
insert into Tracking values('125','faiqa_Adnan','2022-05-01','2022-05-14')
insert into Tracking values('124','ashiinz','2022-04-14','2022-05-01')

select *from Books
select * from Users
select* from Tracking
delete from Tracking

--12)
create trigger checkroom
on DiscussionRooms
after update 
as begin
declare @avail nvarchar(50)

select @avail=dr.Availabile
from DiscussionRooms dr join inserted i on i.RoomID=dr.RoomID

if(@avail='no')
begin
Rollback transaction
print'This Room is Not Available'
end
end
--TESTING
select *From DiscussionRooms
update DiscussionRooms
set BookedBy='ashiinz',BookedDate='2022-04-01'
where RoomID='809'

--13)
create trigger stafftrig
on staff
after update 
as begin
print 'Staff has been Updated'
end


--14)
create trigger staff2
on staff
after insert 
as begin 
print ' New Staff has been Added'
end