--- Aisha Muhammad Nawaz 20L-0921 BSCS LAB06 SECTION 4A1
use ATM;
---Q1
select cardNum
from Card
except
select cardNum
from [Transaction]

--OR (with IN)

select cardNum
from Card
where cardNum NOT IN (
select cardNum
from [Transaction]
)

--Q2
select u.Name
from Card as c join UserCard as uc on c.cardNum = uc.cardNum join [User] as u on u.userId=uc.userID 
where c.balance = (
select max(Balance)
from card )

--Q3 
select U.name,UT.name as UserTypeName
from [User] as u join [UserType] as ut on u.userType=ut.userTypeId


-- Q4
select userID
from UserCard
where cardNum IN(
select cardNum 
from [Transaction]
where transType IN(
select transTypeID
from [TransactionType]
where typeName='failed')
)

--Q5
select userID
from [Transaction] as t join UserCard as uc on t.cardNum =uc.cardNum
group by userID
having count(*) IN
(
select max (y.c)
from (
select count(*) as c
from [Transaction] as t join UserCard as uc on t.cardNum =uc.cardNum
group by userID) y
)

 --Q6*
 select userType,name
 from [User]
 where userId IN(
 select uc.userID
 from Card as c join UserCard as uc on c.cardNum=uc.cardNum join [User] as u on u.userId=uc.userId
 group by uc.userID
 having uc.userID IN(
 select uc.userID
 from CardType as ct join Card as c on c.cardTypeID=ct.cardTypeID join UserCard as uc on uc.cardNum = c.cardNum 
 where name='Credit'
 )

 )


 -- Q7

 select ct.cardTypeID, count(*) as Numberofusers
 from CardType as ct join Card as c on c.cardTypeID=ct.cardTypeID join UserCard as uc on uc.cardNum=c.cardNum
 group by ct.cardTypeID
 order by count(*)desc

 --Q8 
select u.Name
from Card as c join UserCard as uc on c.cardNum = uc.cardNum join [User] as u on u.userId=uc.userID 
where balance IN (
select TOP 2 (balance)
from [Card]
group by balance 
except 
select max(balance)
from [Card]
)
order by balance desc

-- Q9 
select * 
from [UserType]
where UserTypeId in(
select  userType
from [User]
where userId IN(
select userId
from UserCard
where cardNum IN(
select cardNum
from Card
where cardNum NOT IN (
select cardNum
from [Transaction] as tr join TransactionType as tt on tt.transTypeID=tr.transType
where tt.typeName='Withdraw'))))