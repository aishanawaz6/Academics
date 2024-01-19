create database Project
use Project

create Table Users
(
UserID nvarchar(100) primary key,
FirstName nvarchar(100) NOT NULL,
LastName nvarchar(100) ,
Age int NOT NULL,
Phone nvarchar(20) NOT NULL,
Email nvarchar(50),
Gender nvarchar(10) NOT NULL
)

create Table Staff
(
StaffID nvarchar(100) primary key ,
FirstName nvarchar(100) NOT NULL,
LastName nvarchar(100),
Age int NOT NULL,
Designation nvarchar(150) NOT NULL,
Email nvarchar(50),
Phone nvarchar(20) NOT NULL,
Salary nvarchar(15),
Loans nvarchar(50),
)

create Table Books
(
BookID nvarchar(100) primary key,
BookName nvarchar(200) NOT NULL,
Author nvarchar(200) NOT NULL,
Genre nvarchar (100) NOT NULL,
NumberOfCopiesAvailable int ,
Locations nvarchar(150),
Ratings int,
RackNumber int,
unique (BookName, Author)
)

create Table UserLogin
(
UserID nvarchar(100) foreign key references Users (UserID) on delete NO ACTION,
Passwords nvarchar (50) NOT NULL,
CNIC nvarchar (60) NOT NULL unique ,
JoinDate date NOT NULL,
MembershipType nvarchar (100),
FineHistory nvarchar(200),
Fine int,
BookID nvarchar(100) foreign key references Books (BookID) on delete NO ACTION,
NumberOfBooksIssued int,
IssuedDate date,
DueDate date,
unique (UserID,Passwords)
)
create Table Catalogue 
(
BookID nvarchar(100) foreign key references Books (BookID) on delete CASCADE,
BookType nvarchar(200) NOT NULL,
Genres nvarchar(100) NOT NULL,
Authors nvarchar(100) NOT NULL,
NumberOfCopies int 
)
create Table Authors
(
AuthorName nvarchar(200) NOT NULL,
BookID nvarchar(100) foreign key references Books (BookID) on delete CASCADE,
BookName nvarchar(200) NOT NULL,
NumberOfBooksPublishes int NOT NULL,
BestSelling nvarchar(200) NOT NULL,
Ratings int,
primary key (AuthorName,BookName),
unique (BookID,BookName)
)
create Table Tracking 
(
BookID nvarchar(100) foreign key references Books(BookID) on delete cascade,
IssuedTo nvarchar(100) foreign key references Users(UserID) on delete cascade,
IssuedDate date,
DueDate date
)
create Table Membership 
(
UserID nvarchar(100) foreign key references Users(UserID) on delete cascade,
MemebershipID nvarchar(100) primary key,
MemberShipType nvarchar (100),
NumberOfBooksIssued int,
Payments int,
Subscription nvarchar(100)
)
create Table Recommendations
(
UserID nvarchar(100) foreign key references Users(UserID) on delete cascade,
SuggestedBook nvarchar(200),
SuggestedGenre nvarchar(200),
)
create Table DiscussionRooms
(
RoomID nvarchar(100) primary key,
Availabile nvarchar(50),
BookedBy nvarchar(100) foreign key references Users(UserID) on delete cascade,
BookedDate date
)

create Table Locations
(
BookID nvarchar(100) foreign key references Books(BookID) on delete cascade,
BookName nvarchar(200) ,
LocationID nvarchar(100) primary key,
LocationName nvarchar (200),
CopiesAvailable int
)
create Table Suggestions
(
UserID nvarchar(100) foreign key references Users(UserID) on delete cascade,
AreaOfSuggestion nvarchar(200),
BookName nvarchar(200),
DateOfRelease date,
ReasonToSuggest nvarchar(200),
)

