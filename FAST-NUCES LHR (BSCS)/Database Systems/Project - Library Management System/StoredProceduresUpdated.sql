use project



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
select* from UserLogin where UserID=@Usern AND Passwords=@passw
else
select* from UserLogin where UserID=@Usern AND Passwords=@passw
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
select * from Users where UserID=@UI
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

create procedure IssueABook @BookId nvarchar(200), @uID nvarchar(100),@issue_date date,@Found int output
as
begin
declare @checkBookId nvarchar(200)
set @checkBookId=(
select BookId
from Books
where BookId=@BookId
)
if (@checkBookId=@BookId)
begin
insert into Tracking values (@BookId,@uID,@issue_date,DATEADD(DAY,14,@issue_date))
select * from Tracking 
end
if @@ROWCOUNT>0 --item found
begin
set @Found=1
end
else 
set @Found=0
end

create procedure ShowFinesHistory @uID nvarchar(100),@Found int output
as
begin
select FineHistory
from UserLogin
where UserID=@uID
if @@ROWCOUNT >0
begin
set @Found=1
end
else
set @Found=0
end


-- Testing Procedure 7
--execute ShowFinesHistory @uID='abc'


--Procedure 8 : To search all location details of a book by Book name
create procedure SearchLocationDetailsofBook @BookN nvarchar(200),@Found int output
as
begin
select *
from Locations
where BookName=@BookN

if @@ROWCOUNT >0
begin
set @Found=1
end
else
set @Found=0
end

-- Testing Procedure 8
--insert into Locations values('123','THE GOLDEN GLOBE','78','Karachi','15')
--execute SearchLocationDetailsofBook @BookN='THE GOLDEN GLOBE'
--insert into Locations values('456','THE PERSIAN WOLF','79','Karachi','15')
--execute SearchLocationDetailsofBook @BookN='THE PERSIAN WOLF'


--Procedure 9 : To search membership details of a specific user by using userID
create procedure SearchMembershipDetails @uID nvarchar(100),@Found int output
as
begin
select *
from Membership
where UserID=@uID
if @@ROWCOUNT >0
begin
set @Found=1
end
else
set @Found=0
end
-- Testing Procedure 9
--insert into Membership values('abc','1001','Current','0','0','FREE')
--insert into Membership values('an','1000','Current','2','5000','Premium')
--execute SearchMembershipDetails @uID='abc'

--Procedure 10 : To display all details of user to themselves (Like view profile)
create procedure showMyDetails @uID nvarchar(100),@Found int output
as
begin 
select *
from Users as u join UserLogin as ul on ul.UserID=u.UserID join Membership as m on m.UserID=u.UserID
where u.UserID=@uID
if @@ROWCOUNT >0
begin
set @Found=1
end
else
set @Found=0
end

-- Testing Procedure 10
--execute showMyDetails @uID ='abc'


---Procedure 11 : To show all recommended books for a specific user
create procedure showRecommendations @uID nvarchar(100),@Found int output
as
begin
select *
from Recommendations
where UserID=@uID
if @@ROWCOUNT >0
begin
set @Found=1
end
else
set @Found=0
end
drop procedure showRecommendations
-- Testing Procedure 11
--insert into Recommendations values ('abc','THE GOLDEN GLOBE','Comedy')
--execute showRecommendations @uID='abc'


--Procedure 12: to show all Books of a sepcific type
create procedure SearchBooksByType @bt nvarchar(200),@Found int output
as
begin
select *
from books
where BookID IN (
select BookID
from Catalogue
where BookType=@bt
)

if @@ROWCOUNT >0
begin
set @Found=1
end
else
set @Found=0
end
---Testing procedure 12
--insert into Catalogue values('123','Magazine','Comedy','Arzo','15')
--execute SearchBooksByType @bt = 'Magazine'



CREATE PROCEDURE DiscussionRoom_Booking @ui nvarchar(100),@ri nvarchar(100),@Found int output
AS
BEGIN
UPDATE  DiscussionRooms 
SET BookedBy=@ui,BookedDate=GETDATE()
WHERE RoomID=@ri
select*
from DiscussionRooms
if @@ROWCOUNT>0 --item found
begin
set @Found=1
end
else 
set @Found=0
end
END

--Procedure 13: to search all books available at a specific location
create procedure searchByLoaction @ln nvarchar(200),@Found int output
as
begin
select *
from books
where Locations=@ln

if @@ROWCOUNT>0 --item found
begin
set @Found=1
end
else 
set @Found=0
end
drop procedure searchByLoaction
-- Testing procedure 13
--execute searchByLoaction @ln ='Karachi'
--execute searchByLoaction @ln ='Lahore'


--Procedure 14: to serach to whom a specifc book has been issued to using book ID
create procedure FindIssuedTo @BI nvarchar(100),@Found int output
as
begin
select *
from Tracking
where BookID=@BI

if @@ROWCOUNT>0 --item found
begin
set @Found=1
end
else 
set @Found=0
end

drop procedure FindIssuedTo

---Procedure 15: To search books by a specific rating
create procedure searchBookByRatings @rat int,@Found int output
as
begin
select *
from books
where Ratings=@rat

if @@ROWCOUNT>0 --item found
begin
set @Found=1
end
else 
set @Found=0
end

drop procedure searchBookByRatings

---Procedure 17: To search all suggestions (by bookname) given of a specific book  by users
 create procedure searchSuggestionofBook @bn nvarchar(200),@Found int output
 as
 begin
 select *
 from Suggestions
 where BookName=@bn

 if @@ROWCOUNT>0 --item found
begin
set @Found=1
end
else 
set @Found=0
 end

--Procedure 18 : To check if a specific Discussion Room is available
create procedure searchDiscussionRoom @ri nvarchar(100),@Found int output
as
begin
select*
from DiscussionRooms
where RoomID=@ri

 if @@ROWCOUNT>0 --item found
begin
set @Found=1
end
else 
set @Found=0
end



