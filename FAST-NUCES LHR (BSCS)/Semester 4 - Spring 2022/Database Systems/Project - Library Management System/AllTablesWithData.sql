create database Project
use Project
--drop database Project
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
INSERT INTO Users VALUES(1,'Humaira','Batool',20,'111 111 111','humaira@gmail.com','Female')
INSERT INTO Users VALUES(2,'Hufsa','Hafeez',20,'111 222 111','hfsa@gmail.com','Female')
INSERT INTO Users VALUES(3,'Hamid','Hameed',20,'111 111 222','Hamid@gmail.com','Male')
INSERT INTO Users VALUES(4,'Zahid','Zaki',20,'111 222 333','Zahid@gmail.com','Male')
INSERT INTO Users VALUES(5,'Hamza','Ata',20,'111 222 444','Hamza@gmail.com','Male')

create Table Books
(
BookID INT primary key ,
BookName nvarchar(200) NOT NULL,
Author nvarchar(200) NOT NULL,
Genre nvarchar (100) NOT NULL,
NumberOfCopiesAvailable int ,
Locations nvarchar(150),
Ratings int,
RackNumber int,
unique (BookName, Author),
)
INSERT INTO Books VALUES(1,'Adventures of Sherlock Holmes','Sir Arthur Conan Doyle','Crime Fiction',1,'Lahore',4,2)
INSERT INTO Books VALUES(2,'Ain-i-Akbari','Abul Fazal','Biography Biographies',1,'Karachi',4,2)
INSERT INTO Books VALUES(3,'The Alchemist','Paulo Coelho','Adventure Fiction',1,'Lahore',4,2)
INSERT INTO Books VALUES(4,'Alice in the Wonderland','Lewis Carroll','Absurdist Fiction',1,'Islamabad',4,2)
INSERT INTO Books VALUES(5,'Arabian Nights','Sir Richard Burton','Adventure Fiction',1,'Lahore',4,2)

create Table Tracking 
(
BookID INT foreign key references Books(BookID) on delete cascade,
IssuedTo nvarchar(100) foreign key references Users(UserID) on delete cascade,
IssuedDate date,
DueDate date
)
INSERT INTO Tracking VALUES(1,1,'2022-01-05','2022-01-15')
INSERT INTO Tracking VALUES(2,2,'2022-02-05','2022-02-15')
INSERT INTO Tracking VALUES(3,3,'2022-03-05','2022-03-15')
INSERT INTO Tracking VALUES(4,4,'2022-04-05','2022-04-15')
INSERT INTO Tracking VALUES(5,5,'2022-05-05','2022-05-15')

create Table DiscussionRooms
(
RoomID nvarchar(100) primary key,
Availabile nvarchar(50),
BookedBy nvarchar(100) foreign key references Users(UserID) on delete cascade,
BookedDate date
)
INSERT INTO DiscussionRooms VALUES(1,'YES',NULL,NULL)
INSERT INTO DiscussionRooms VALUES(2,'NO',2,'2022-05-06')
INSERT INTO DiscussionRooms VALUES(3,'YES',NULL,NULL)
INSERT INTO DiscussionRooms VALUES(4,'NO',4,'2022-05-08')
INSERT INTO DiscussionRooms VALUES(5,'YES',NULL,NULL)

create Table Membership 
(
UserID nvarchar(100) foreign key references Users(UserID) on delete cascade,
MemebershipID nvarchar(100) primary key,
MemberShipType nvarchar (100),
NumberOfBooksIssued int,
Payments int,
Subscription nvarchar(100)
)
INSERT INTO Membership VALUES(1,1,'Full Individual Membership',5,10000,'A')
INSERT INTO Membership VALUES(2,2,'Full Life Membership',10,20000,'B')
INSERT INTO Membership VALUES(3,3,'Supported Membershi',15,30000,'C')
INSERT INTO Membership VALUES(4,4,'Associate Membership',20,40000,'D')
INSERT INTO Membership VALUES(5,5,'Remote Membership',25,50000,'E')



create Table Catalogue 
(
BookID INT foreign key references Books (BookID) on delete CASCADE,
BookType nvarchar(200) NOT NULL,
Genres nvarchar(100) NOT NULL,
Authors nvarchar(100) NOT NULL,
NumberOfCopies int 
)
INSERT INTO Catalogue VALUES(1,'Fiction','Crime Fiction','Sir Arthur Conan Doyle',1)
INSERT INTO Catalogue VALUES(2,'Biography','Biography Biographies','Abul Fazal',1)
INSERT INTO Catalogue VALUES(3,'Adventure','Adventure Fiction','Paulo Coelho',1)
INSERT INTO Catalogue VALUES(4,'Fiction','Absurdist Fiction','Lewis Carroll',1)
INSERT INTO Catalogue VALUES(5,'Adventure','Adventure Fiction','Sir Richard Burton',1)

create Table Authors
(
AuthorName nvarchar(200) NOT NULL,
BookID INT foreign key references Books (BookID) on delete CASCADE,
BookName nvarchar(200) NOT NULL,
NumberOfBooksPublishes int NOT NULL,
BestSelling nvarchar(200) NOT NULL,
Ratings int,
primary key (AuthorName,BookName),
unique (BookID,BookName)
)
INSERT INTO Authors VALUES('Sir Arthur Conan Doyle',1,'Adventures of Sherlock Holmes',5,'The Memoirs of Sherlock Holmes.',4)
INSERT INTO Authors VALUES('Abul Fazal',2,'Ain-i-Akbari',10,'Ain-i-Akbari',4)
INSERT INTO Authors VALUES('Paulo Coelho',3,'The Alchemist',15,'The Alchemis',5)
INSERT INTO Authors VALUES('Lewis Carroll',4,'Alice in the Wonderland',20,'Alice’s Adventures in Wonderland',4)
INSERT INTO Authors VALUES('Sir Richard Burton',5,'Arabian Nights',30,'Arabian Nights',4)

create Table Locations
(
BookID INT foreign key references Books(BookID) on delete cascade,
BookName nvarchar(200) ,
LocationID nvarchar(100),
LocationName nvarchar (200),
CopiesAvailable int
PRIMARY KEY(BookID,LocationID)
)
insert into Locations VALUES(1,'Adventures of Sherlock Holmes',1,'Lahore',2)
insert into Locations VALUES(2,'Ain-i-Akbari',2,'Karachi',2)
insert into Locations VALUES(3,'The Alchemist',1,'Lahore',2)
insert into Locations VALUES(4,'Alice in the Wonderland',3,'Islamabad',2)
insert into Locations VALUES(5,'Arabian Nights',1,'Lahore',2)

create Table UserLogin
(
UserID nvarchar(100) foreign key references Users (UserID) on delete NO ACTION,
Passwords nvarchar (50) NOT NULL,
CNIC nvarchar (60) NOT NULL unique ,
JoinDate date NOT NULL,
MembershipType nvarchar (100),
FineHistory nvarchar(200),
Fine int,
BookID INT foreign key references Books (BookID) on delete NO ACTION,
NumberOfBooksIssued int,
IssuedDate date,
DueDate date,
unique (UserID,Passwords)
)
INSERT INTO UserLogin VALUES(1,'123','23345','2-05-2020','Full Individual Membership',0,0,1,1,'2022-01-05','2022-01-15')
INSERT INTO UserLogin VALUES(2,'321','12367','9-05-2020','Full Life Membership',0,0,2,1,'2022-02-05','2022-02-15')
INSERT INTO UserLogin VALUES(3,'456','56732','2-05-2020','Supported Membership',0,0,3,1,'2022-03-05','2022-03-15')
INSERT INTO UserLogin VALUES(4,'907','32167','9-08-2020','Associate Membership',0,0,4,1,'2022-04-05','2022-04-15')
INSERT INTO UserLogin VALUES(5,'563','23876','2-01-2020','Remote Membership',0,0,5,1,'2022-05-05','2022-05-15')

create Table Recommendations
(
UserID nvarchar(100) foreign key references Users(UserID) on delete cascade,
SuggestedBook nvarchar(200),
SuggestedGenre nvarchar(200),
)
INSERT INTO Recommendations VALUES(1,'Anand Math','Historical Fiction')
INSERT INTO Recommendations VALUES(2,'Androcles and the Lion','epic pastiche')
INSERT INTO Recommendations VALUES(3,'Ape and Essence','Science Fiction')
INSERT INTO Recommendations VALUES(4,'Arthashastra','Treatise')
INSERT INTO Recommendations VALUES(5,'Area of Darkness','Travel Literature')
create Table Suggestions
(
UserID nvarchar(100) foreign key references Users(UserID) on delete cascade,
AreaOfSuggestion nvarchar(200),
BookName nvarchar(200),
DateOfRelease date,
ReasonToSuggest nvarchar(200),
)
insert into Suggestions values(1,'A','Anand Math','2021-01-05','AA')
insert into Suggestions values(2,'B','Androcles and the Lion','2012-02-06','BB')
insert into Suggestions values(3,'C','Ape and Essence','2002-02-07','CC')
insert into Suggestions values(4,'D','Arthashastra','2012-04-03','DD')
insert into Suggestions values(5,'E','Area of Darkness','2015-01-05','EE')

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

insert into Staff values ('001','Arbaz','Malik','20','Junior Library Assistant','001Arbaz@gmail.com','123-456-789','5000','0');
insert into Staff values ('002','Sahinaz','Choudhry','28','Security Guard','002Sahinaz@gmail.com','113-456-788','7000','9000');
insert into Staff values ('003','Faiq','Subhani','35','Library Technician','003Faiq@gmail.com','183-456-089','4000','0');
insert into Staff values ('004','Haiqa','Abdul','32','Clerk','004Haiqa@gmail.com','143-496-789','8000','1000');
insert into Staff values ('005','Laiba','Zahid','22','Receptionist','005Laiba@gmail.com','103-776-789','9000','0');
insert into Staff values ('006','Aleesha','Butt','30','Clerk','006Aleesha@gmail.com','173-456-789','3000','10000');

