--20L0921 BSCS SECTION 4A1 Lab 08 DBS

---Q1
create view q1
as
select  o.OwnerID,o.OwnerName,o.Phone,o.city,o.Country,b.BoatName,b.BoatType,b.Price
from OWNER as o join BOAT as b on o.OwnerID=b.OwnerID
select *from q1

---Q2
create view q2
as
select r.ReserveID,r.SailorID,r.BoatName,r.Date,r.Day,s.SailorName,s.Phone,s.city,b.BoatType,b.price,b.OwnerID
from Reservation as r join sailor as s  on s.SailorID=r.SailorID join BOAT as b on b.BoatName=r.BoatName

select *from q2

---Q3
create procedure q3
as 
begin 
select OwnerName, count(*)as numberOfBoats
from q1
group by OwnerName
end

execute q3

---Q4
create view q4
as
select * 
from Owner

insert into q4 values ('6','Aisha','123-123-123','Karachi','Pakistan')
select * from q4

---Q5
create trigger q5
on  database
for drop_procedure,create_procedure
as
begin
print 'Alert! Someone tried to drop or create a procedure on date and time:'
print getdate();
end

--Testing
create procedure test
as 
begin
select *
from OWNER
end

--Q6
create trigger q6
on q4
instead of insert
as
begin
execute q3
end

--Testing
insert into q4 values('7','A','123-123-123','KHI','Pakistan')