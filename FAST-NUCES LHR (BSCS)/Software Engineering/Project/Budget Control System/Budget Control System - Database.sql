create database bcs
use bcs


create table Customer (
	fname varchar(20) NOT NULL,
	lname varchar(20) NOT NULL,
	contact_no varchar(11) NOT NULL,
	cust_username varchar (20) NOT NULL unique, 
	customer_email varchar (50) NOT NULL unique,	
	customer_password varchar (15) NOT NULL,

primary key (cust_username)
);


INSERT INTO Customer(fname, lname, contact_no, cust_username, customer_email , customer_password )
VALUES
('Daniyal','Ali','03158955748','danali1','danali@gmail.com','a0pl'),
('Muhammad','Jawad','03178950749','mjawad','mjawad@gmail.com','mjaw220'),
('Maria','Safdar','03148953445','marsafdar','marsafdar@gmail.com','maw40r'),
('Fatima','Kamran','03135755743','fatiymahh','fatimakamran@gmail.com','678joi'),
('Armaan','Junaid','03154455740','armanjunaid','armanjun@gmail.com','ar078'),
('Rao','Hussain','03158005742','raohussain','raohussain@gmail.com','xyz678op'),
('Saleh','Ahmed','03198955998','salehahmed','saledahmed@gmail.com','sale90ahm'),
('Raza','Malik','03148955901','razamalik','razamalik@gmail.com','orange90'),
('Osama','Aziz','03159874427','osamaAziz','osamaz@gmail.com','osama123'),
('Faryal','Makhdoom','03110984433','faryalmakhdoom','faryalmakdoom@gmail.com','fari')

--INSERT INTO Customer values( 'Amy', 'Ford','03156895541','aford','ford.amy@gmail.com','asdfgh12')
--INSERT INTO Customer values( 'Mike',' Ross','25879962','mikey', 'mike.ross@yahoo.com', '1234567')
--INSERT INTO Customer values( 'Rachel',' Green', '02145587','rachelgreen','rachelgreen12@gmail.com', 'greens90')
--INSERT INTO Customer values( 'Bran',' Stark','12547789', 'brandon','bran.stark@outlook.com', 'thenorth1')
--INSERT INTO Customer values('Louisa ','Durrel','254788962' ,'louisa','durrell.louisa23@yahoo.com', 'spiero2')
--INSERT INTO Customer values( 'Georgia',' Miller','56875589','georgiamiller', 'georgia.97@gmail.com', 'peachstate')
--INSERT INTO Customer values( 'Haley',' Dunphy','25445582', 'hdunphy','haley.dunphy@nerp.com', 'password123')
--INSERT INTO Customer values( 'Devi',' Vishwukumar', '25644895','deviw','devi.v@outlook.com', 'lkjhgfdsa985')

create Table Business (
	business_id varchar (20) NOT NULL unique,
	business_name varchar (50) NOT NULL unique,
--	product_list varchar (5000) NOT NULL					-- Redundant as each product will have business_id so can be traced through that

	primary key (business_id)
);


insert into Business values('921','Samsung')
insert into Business values('922','TCL')
insert into Business values('923','AMF MOTORS')
insert into Business values('925','Shell')
insert into Business values('926','PSO')
insert into Business values('928','Limelight')
insert into Business values('929','Nestle')
insert into Business values('930','Dawn')
insert into Business values('931','Adams')
insert into Business values('932','Anhaar')




create Table Product (
	product_id varchar (20) NOT NULL unique, 
	product_name varchar(50) not null, 
	product_price float not null,
	product_category varchar(50) not null,				-- Grocery, Fuel, Cosmetics
	business_id varchar(20) not null,
--	stores varchar(500) not null,						-- Redundant because of Product-Store Relationship Table

	primary key (product_id),
	foreign key (business_id) references Business (business_id)
);

insert into Product values ('1','Plain Youghurt', 100,'Grocery', '929')
insert into Product values ('2','Plain Youghurt', 70,'Grocery', '931')
insert into Product values ('3','Flavoured Youghurt - Mango',120,'Grocery', '929')

insert into Product values ('4','Milk',230, 'Grocery', '929')
insert into Product values ('5','Chocolate Milk',100, 'Grocery', '931')
insert into Product values ('6','Almond Milk',300, 'Grocery', '932')
insert into Product values ('7','Milk',140,'Grocery','931')

insert into Product values ('8','Cheddar Cheese', 600, 'Grocery', '931')
insert into Product values ('9','Mozzarella Cheese',650, 'Grocery', '931')
insert into Product values ('10','Mozzarella Cheese',710, 'Grocery', '929')

insert into Product values ('11','Eggs',240, 'Grocery', '932')

insert into Product values ('12','Plain Bread',190, 'Grocery', '930')
insert into Product values ('13','Bran Bread',240, 'Grocery', '930')


insert into Product values ('14','Wireless Headset', 25000,' Electronics','921')
insert into Product values ('15','UHD TV', 107900, 'Electronics', '922')
insert into Product values ('16','LED TV', 190000, 'Electronics', '921')

insert into Product values ('17','Geolandar H/T G056 Truck Tires', 7000, 'Spare Parts', '923')
insert into Product values ('18','Ladies Printed Kurti - RED',5000, 'Clothes', '928')
insert into Product values ('19','Gents kurta - BLUE',6000, 'Clothes', '928')

insert into Product values ('20','Petrol',280, 'Fuel', '926')
insert into Product values ('21','Diesel',290, 'Fuel', '926')
insert into Product values ('22','Light Diesel',170, 'Fuel', '925')




create Table Store (
	store_id varchar (20) NOT NULL unique,
	store_name varchar (50) NOT NULL unique,
	store_address varchar (100) not null,

--	product_list varchar (5000) NOT NULL,					-- Mapped via Product-Store relationship table
--	businesses_list varchar (5000) NOT NULL					-- Mapped via Business-Store relationship table

	primary key (store_id)
);

insert into Store Values('89','SAMSUNG RETAIL STORE','JOHAR TOWN, LAHORE')
insert into Store Values('90','TCL RETAIL STORE','GULBERG, LAHORE')
insert into Store Values('91','AMF MOTORS STORE','JOHAR TOWN, LAHORE')
insert into Store Values('92','LIMELIGHT RETAIL STORE','JOHAR TOWN, LAHORE')
insert into Store Values('93','Alfatah Store','Johar TOWN, LAHORE')
insert into Store Values('94','Metro Supermarket','Thokar Niaz Baig, LAHORE')
insert into Store Values('95','PSO Petrol Pump','DHA -Phase 5, LAHORE')
insert into Store Values('96','SHELL Petrol Pump','Gulberg, LAHORE')





create Table Product_Store_Relationship (
	product_id varchar (20) NOT NULL, 
	store_id varchar (20) NOT NULL,

	foreign key (product_id) references Product (product_id),
	foreign key (store_id) references Store (store_id),
	primary key(product_id, store_id)	
);


insert into Product_Store_Relationship values ('1','93')
insert into Product_Store_Relationship values ('2','94')
insert into Product_Store_Relationship values ('3','93')
insert into Product_Store_Relationship values ('4','93')
insert into Product_Store_Relationship values ('5','94')
insert into Product_Store_Relationship values ('6','93')
insert into Product_Store_Relationship values ('6','94')
insert into Product_Store_Relationship values ('7','94')
insert into Product_Store_Relationship values ('8','93')
insert into Product_Store_Relationship values ('9','94')
insert into Product_Store_Relationship values ('10','94')
insert into Product_Store_Relationship values ('11','93')
insert into Product_Store_Relationship values ('12','94')
insert into Product_Store_Relationship values ('13','93')
insert into Product_Store_Relationship values ('14','89')
insert into Product_Store_Relationship values ('15','90')
insert into Product_Store_Relationship values ('16','89')
insert into Product_Store_Relationship values ('17','91')
insert into Product_Store_Relationship values ('18','92')
insert into Product_Store_Relationship values ('19','92')
insert into Product_Store_Relationship values ('20','95')
insert into Product_Store_Relationship values ('21','95')
insert into Product_Store_Relationship values ('22','96')



create Table Business_Store_Relationship (
	business_id varchar (20) NOT NULL,
	store_id varchar (20) NOT NULL,

	primary key(business_id, store_id),
	foreign key (business_id) references Business (business_id),
	foreign key (store_id) references Store (store_id)
);

insert into Business_Store_Relationship values ('921','89')
insert into Business_Store_Relationship values ('922','90')
insert into Business_Store_Relationship values ('923','91')
insert into Business_Store_Relationship values ('925','96')
insert into Business_Store_Relationship values ('926','95')
insert into Business_Store_Relationship values ('928','92')
insert into Business_Store_Relationship values ('929','93')
insert into Business_Store_Relationship values ('929','94')
insert into Business_Store_Relationship values ('930','93')
insert into Business_Store_Relationship values ('930','94')
insert into Business_Store_Relationship values ('931','93')
insert into Business_Store_Relationship values ('931','94')
insert into Business_Store_Relationship values ('932','93')
insert into Business_Store_Relationship values ('932','94')


create Table Budget (
	cust_username varchar(50) not null,
	budget_id varchar(20) not null unique,
--	budget_values  varchar(50) not null						-- Mapped via a separate table BudgetItem (Inheritance ?)

	primary key (budget_id)
);


create Table BudgetItem (
	budget_id varchar(20) not null,
	expense_category varchar(50) not null,
	expense_amount float,

	primary key (budget_id, expense_category),
	foreign key (budget_id) references Budget(budget_id)
);




create table Transactions (
	transaction_date date NOT NULL,
	transaction_id varchar (20) NOT NULL unique,
	product_id varchar (20) NOT NULL,
	cust_username varchar (20) NOT NULL, 

	primary key (transaction_id),
	foreign key (product_id) references Product (product_id),
	foreign key (cust_username) references Customer (cust_username)
);




insert into Transactions(transaction_date, transaction_id, product_id, cust_username)
VALUES
('2023-04-01', 1, '3', 'danali1'),
('2023-04-02', 2, '1', 'faryalmakhdoom'),
('2023-04-02', 3, '3', 'faryalmakhdoom'),
('2023-04-02', 4, '10', 'armanjunaid'),
('2023-04-05', 5, '7', 'fatiymahh'),
('2023-04-06', 6, '2', 'salehahmed'),
('2023-04-06', 7, '6', 'armanjunaid'),
('2023-04-03', 8, '9', 'raohussain'),
('2023-04-10', 9, '2', 'danali1'),
('2023-04-19', 10, '2', 'osamaAziz'),
('2023-04-19', 11, '4', 'raohussain'),
('2023-04-20', 12, '5', 'marsafdar'),
('2023-04-21', 13, '1', 'armanjunaid'),
('2023-04-22', 14, '8', 'fatiymahh'),
('2023-04-23', 15, '9', 'faryalmakhdoom'),
('2023-04-29', 16, '7', 'mjawad'),
('2023-04-30', 17, '1', 'razamalik')




create Table Report (
	report_id varchar(20) not null unique,
	cust_username varchar(50) not null,
--	transaction_arr varchar(500) not null,			-- Array of all trans. of the month: Make an intermediary table to connect Trasactions and Report
	report_month date not null,
	suggestions_array varchar(1000),

	primary key (report_id)
);


INSERT INTO Report (report_id, cust_username, report_month, suggestions_array)
VALUES
(1, 'danali1', '2023-04-30', ''),
(2, 'mjawad', '2023-04-30', ''),
(3, 'marsafdar', '2023-04-30', ''),
(4, 'fatiymahh', '2023-04-30', ''),
(5, 'armanjunaid', '2023-04-30', ''),
(6, 'raohussain', '2023-04-30', ''),
(7, 'salehahmed', '2023-04-30', ''),
(8, 'razamalik', '2023-04-30', ''),
(9, 'osamaAziz', '2023-04-30', ''),
(10, 'faryalmakhdoom', '2023-04-30', '')






create table Suggestion (
	suggestion_id varchar (20) not null,
	suggestion_text varchar (500),
	report_id varchar(20),

	primary key(report_id),
	foreign key (report_id) references Report (report_id)
);




create Table Rating (
	product_id varchar(20) not null unique,
	rating_value int,
	review varchar(500)

	primary key (product_id),
	foreign key (product_id) references Product (product_id)
);


create Table RewardPoints (
	cust_username varchar(50) not null,
	points int,

	primary key(cust_username),
	foreign key (cust_username) references Customer(cust_username)
);

select* from Customer
select* from Business
select* from Product
select* from Store
select* from Transactions


select* from Transactions
where cust_username = 'danali1'


----------------------------------------------Procedures------------------------------------------------

--------------------------------------------------1. History--------------------------------------------

create procedure HistoryProcedure(
	@cuname varchar(20)
)
as begin

if exists (select cust_username from Transactions t where t.cust_username = @cuname)
	begin
		select* from Transactions t2
		where t2.cust_username = @cuname
	end
else
	begin
		print 'No transaction exists for the entered user'
	end

end

exec HistoryProcedure @cuname = 'danali1'



----------------------------------------------Experimental Content------------------------------------------------

--------------------------------------------------2. Products--------------------------------------------





select* from Product p join Business b join 

SELECT *
FROM Product p
JOIN Business b ON p.business_id = b.business_id
JOIN Store s ON s.business_id = s.business_id



create procedure ShowProductProcedure(
	@pcat varchar(50)
)
as begin

if exists (select product_category from Product p where p.product_category = @pcat)
	begin
		select* from Product p2
		where p2.product_category = @pcat
	end
else
	begin
		print 'No product exists for the entered category'
	end

end

exec HistoryProcedure @cuname = 'Electronics'

drop procedure ProductProcedure


1. HistoryProcedure to retrieve history
2. ClearHistoryProcedure

3. Display product by category		(show all product details, along with Store and Business)
4. AddTransaction