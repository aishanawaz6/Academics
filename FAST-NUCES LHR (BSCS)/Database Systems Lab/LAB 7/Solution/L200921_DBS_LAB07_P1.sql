--20L0921 AISHA MUHAMMAD NAWAZ BSCS 4A1 DATABASE LAB 07 VIEWS

-- Q1
use Lab5
create view orderNoAndPrice
as
select od.orderNo,sum(od.Quantity*i.price) as TotalPrice
from [OrderDetails] as od join Items as i on i.ItemNo=od.ItemNo
group by od.orderNo


-- Q2
create view itemsWellinSale
as
select*
from items
where itemNo IN(
select  itemNo
from OrderDetails
group by ItemNo
having sum(Quantity)>20
)

--Q3
use  Lab5
create view StarCustomers
as
select*
from Customers
where CustomerNo IN(
select o.CustomerNo
from [Order] as o join orderDetails as od on od.orderNo=o.orderNo join Items as i on i.ItemNo=od.ItemNo
group by CustomerNo
having sum(od.Quantity*i.Price)>2000
)

--Q4
create view notNullPhoneNo
as
select *
from Customers
where Phone is not Null

--with check
create view notNullPhoneNo2
as
select *
from Customers
where Phone is not Null
with check option


--Inserting
insert into notNullPhoneNo
values ('C7','Aisha','KHI','00300')

insert into notNullPhoneNo2
values ('C7','Aisha','KHI','00300')


insert into notNullPhoneNo
values ('C8','Aliya','LHR',NULL)

insert into notNullPhoneNo2 -- Won't execute
values ('C9','Aiza','SWL',NULL)

--Deleting

delete from notNullPhoneNo
where CustomerNo='C5'

delete from notNullPhoneNo2
where CustomerNo='C6'

--Update
update notNullPhoneNo
set Phone=NULL
where CustomerNo='C7'

update notNullPhoneNo2 -- Won't execute
set Phone=NULL
where CustomerNo='C3'


