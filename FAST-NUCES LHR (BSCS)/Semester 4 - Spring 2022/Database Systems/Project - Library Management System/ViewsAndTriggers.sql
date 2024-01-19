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