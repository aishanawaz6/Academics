create database L200921_Lab03;

use L200921_Lab03;
--TASK 1

create Table Users 
(
UserID int primary key,
Name nvarchar(100) NOT NULL,
EmailAddress nvarchar(100),
SignupDate date NOT NULL,
);

create Table Category
(
categoryID int primary key,
categoryName nvarchar(100) NOT NULL,
);

create Table Movies
(
MovieID int primary key,
MovieTitle nvarchar(100) NOT NULL,
MovieCategoryID int foreign key references Category(categoryID),
RentalRatePerDay float NOT NULL,
);

create Table Rentals 
(
rentalID int primary key,
UserID int foreign key references Users(UserID),
MovieID int foreign key references Movies(MovieID),
RentalStarDate date NOT NULL,
RentalEndDate date NOT NULL,
);

use L200921_Lab03;
insert into Users values
(1,'bob','bob@gmail.com','1-1-2016'),
(2,'Tom','tom@yahoo.com','1-2-2017'),
(3,'Alice','alice@gmail.com','1-6-2014'),
(4,'Jim','Jim@ymail.com','1-6-2017')
insert into Category values
(1,'Horror'),(2,'Comedy')
,(3,'Animated')
,(4,'Action')
Insert into Movies
values
(1,'MI-I',4,3.3),
(2,'MI-II',4,4.3),
(3,'MI-III',4,5),
(4,'horton hears a who',3,5.0),
(5,'sherk-2',3,5.0)
Insert into Movies values (6,'xyz',null,10)
Insert into rentals values (1,1,1,'1-6-2019','1-10-2019')
Insert into rentals values (2,1,1,'2-7-2018','2-10-2018')
Insert into rentals values (3,1,2,'3-8-2018','2-13-2019')
Insert into rentals values (4,2,3,'4-9-2019','4-15-2019')
Insert into rentals values (5,3,1,'1-7-2018','1-30-2018')
Insert into rentals values (6,3,5,'2-8-2018','2-21-2018')
Insert into rentals values (7,3,6,'2-8-2019','2-21-2019')

--TASK 2
--Q1 1)Display the user ID and name of users from table Users. The names of users should be in uppercase.
use L200921_Lab03;
SELECT UserID, upper(Name)
From Users 

--Q2 2) Show the movie titles and their Rental Rate Per Week.
use L200921_Lab03;
SELECT MovieTitle,(RentalRatePerDay*7) AS RentalRatePerWeek
From Movies

--Q3 3) Display the movie Ids that user Id 3 has rented.
SELECT MovieID
From Rentals
where UserID=3

--Q4 4) Display all the users who have rented any movie but no user Id should be repeated in the result. (Hint: ‘Distinct’ keyword).
SELECT DISTINCT UserID
From Rentals

--Q5 5) Display the users who have signed up in the year 2017.
SELECT UserID,Name
From Users
where SignupDate BETWEEN '2017-01-01' AND '2017-12-31'

--Q6 6) Display the names and the rental rate of the movies whose rental rate is less than 5.
SELECT MovieTitle,RentalRatePerDay
From Movies
where RentalRatePerDay<5

--Q7 7) Show the users who have never rented any movie. (Hint: Set Operations).
SELECT UserID
From Users
EXCEPT 
SELECT UserID
From rentals

--Q8 8) Display the user Ids of those who have rented movies with id 1 and 5.
SELECT Distinct UserID
From Rentals
where MovieID='1' OR MovieID='5'

--Q9 9) Display the category IDs with no movie listings.
SELECT categoryID
From Category
EXCEPT 
SELECT MovieCategoryID
From Movies

--Q10 10) Find the Category IDs that have character ‘c’ in category name. Display the index number of character ‘c’ in the name.
SELECT categoryID,CHARINDEX ('c', categoryName) AS IndexNumber
From Category
where categoryName LIKE '%c%'


--Q11 11) Display the users who have account on gmail.
SELECT UserID, Name
From Users
where EmailAddress LIKE '%gmail%'

--Q12 12) Display All the category IDs from Movies’ record and their titles. In case a category Id is null, show zero instead.
SELECT isNull(MovieCategoryID,0) AS CategoryID, MovieTitle
From Movies

--Q13 13) Find the number of days UserId 1 rented movie Id 2.
SELECT DATEDIFF ( DAY , RentalStarDate , RentalEndDate ) AS NumberOfDays
from Rentals
where UserID=1 AND MovieID=2

