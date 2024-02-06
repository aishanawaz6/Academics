--TASK 4
--Q1
use ATM;
SELECT name,cardNum FROM [User] JOIN UserCard on [User].userId=UserCard.userID
--Q2
use ATM;
SELECT cardNum,balance,name FROM [Card] JOIN CardType on [Card].cardTypeID=CardType.cardTypeID
--Q3
use ATM;
SELECT* FROM [Card] LEFT JOIN [Transaction] on [Card].cardNum=[Transaction].cardNum
--Q4
use ATM;
SELECT* FROM [User] 
LEFT JOIN [UserCard] on [User].userId=[UserCard].userID 
LEFT JOIN [Transaction] on [UserCard].cardNum=[Transaction].cardNum
--Q5
Select name
from [User]
where userId=(
SELECT [User].userId
from [User]
EXCEPT
Select [UserCard].userID
from [UserCard])

--Q6
Select name from [User] 
left join [UserCard] on [User].userid=[UserCard].userID 
left join [Card] on [UserCard].[cardNum]=[Card].cardNum
where balance>=20000 AND balance<=40000

--Q7
Select  [User].userId, [User].name,[User].phoneNum, [User].city ,[Card].cardNum, [CardType].name from [User] 
left join [UserCard] on [User].userid=[UserCard].userID 
left join [Card] on [UserCard].[cardNum]=[Card].cardNum
left join [CardType] on [Card].cardTypeID=[CardType].cardTypeID
where (Month(expireDate)<06 ) OR ( Month(expireDate)=06 AND Day(expireDate)<=11 )
