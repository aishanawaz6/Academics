--20L0921 BSCS SECTION 4A1 DATABASE LAB07 STORED PROCEDURES

--Q1
use ATM

create Procedure p1
as
begin
select *
from [User] 
end

execute p1

--Q2
declare @uname varchar(20)
create Procedure p2 @uname varchar(20)
as
begin
select *
from [User] 
where name=@uname
end

execute p2 @uname='Ali'


--Q3
declare @cardnum varchar(20)
create Procedure p3 @cardnum varchar(20)
as
begin
select u.name,u.phoneNum,u.city
from [User] as u join UserCard as uc on uc.userID=u.userId
where uc.cardnum=@cardnum
end

execute p3 @cardnum='2324325423336'

--Q4
declare @minbal float 
create Procedure p4 @minbal float output
as
begin
set @minbal=(
select min(balance)
from card)
end

declare @mb float 
execute p4 @minbal=@mb output
select @mb as MinimumBalance


--Q5
declare @un varchar(20), @id int , @noofcards int

create Procedure p5  @un varchar(20), @id int , @noofcards int OUTPUT
as
begin
set @noofcards =(
select count(*)
from [User] as u join UserCard as uc on uc.userID=u.userId
where u.name=@un and u.userId=@id
group by uc.userID)
end

declare @nc int
execute p5 @un='Ali',@id=1, @noofcards=@nc output
select @nc as NumberOfCards

--Q6
declare @cn varchar(20), @pin varchar(4), @status int 
create procedure login @cn varchar(20), @pin varchar(4), @status int output
as 
begin
if exists (
select *
from card 
where cardNum=@cn and PIN=@pin
)
set @status=1
else
set @status=0
end

declare @st int
execute login @cn='2324325423336',@pin='0234', @status=@st output
select @st as Status


--Q7
declare @cn varchar(20), @opin varchar(4), @npin varchar(4), @outp varchar(20) 
create procedure p7  @cn varchar(20), @opin varchar(4), @npin varchar(4), @outp varchar(20) OUTPUT
as 
begin
if exists (
select *
from card 
where cardNum=@cn and PIN=@opin and len(@npin)=len(@opin)
)
begin
update card 
set pin=@npin
where pin=@opin
set @outp='Updated PIN'
end
else
begin
set @outp='Error'
end
end

declare @op varchar(20)
execute p7 @cn='2324325436566',@opin='4326',@npin='43265', @outp=@op output
select @op as OutputIs

-- Q8
create procedure WithDraw @cn2 varchar(20),@pin2 varchar(4),@Tran int
as
begin 
declare @st int 
execute login @cn=@cn2,@pin=@pin2, @status=@st output
if (@st=1)
begin
insert into [Transaction]
values (6,'08-04-2022',@cn2,@Tran,1)
end
end

execute WithDraw @cn2='2324325436566',@pin2='4326',@Tran=35000
