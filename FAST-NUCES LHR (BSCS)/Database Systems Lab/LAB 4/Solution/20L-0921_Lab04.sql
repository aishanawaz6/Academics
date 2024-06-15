use twitter

--Q1
select max(Age) as MaxAge,min(Age) as MinAge,avg(Age) as AvgAge, STDEV(Age) as StdevAvg
from users

--Q2
select FollowedUserName, count(*) as numberOfFollowers
from Following
Group by FollowedUserName
having count(*) IN
(
Select Top 1 count(*)
from Following
Group by FollowedUserName
Order by count(*) desc
)

--Q3
Select FollowedUserName, count(*) as numberOfFollowers
from Following
Group by FollowedUserName
having count(*) IN
(
select min(y.c) 
from (
Select distinct Top 2 count(*) as c
from Following
Group by FollowedUserName
Order by count(*) desc) y
)

--Q4
Select UserName-- u.UserName
from Users 
Except 
Select UserName
from tweets 

--Q5*
select h.HashtagID,count(*)
from tweets as t join Hashtags as h on like h.Hashtag


--Q6
select UserName
from tweets 
Except
select Username
from tweets 
where Text like '%#Census%'

--Q7
Select UserName
from users
Except
Select FollowedUserName
from following

--Q8
Select UserName
from Users 
where not Exists(
Select FollowedUserName
from Following as f
where f.FollowedUserName=Users.UserName
)

--Q9
--Largest Number of users Interest 
Select i.InterestID,Count(*) as noOfInterests
from Interests as i join UserInterests as u on i.InterestID=u.InterestID
Group By i.InterestID
having count(*) IN (
Select Top 1 count(*) 
from Interests as i join UserInterests as u on i.InterestID=u.InterestID
Group By i.InterestID
Order by count(*) desc
)
--Smallest number of users interest
Select i.InterestID,Count(*) as noOfInterests
from Interests as i join UserInterests as u on i.InterestID=u.InterestID
Group By i.InterestID
having count(*) IN (
Select Top 1 count(*) 
from Interests as i join UserInterests as u on i.InterestID=u.InterestID
Group By i.InterestID
Order by count(*) 
)


--Q10
Select Country,count(*) as totalNoOfTweets
from users as u join tweets as t on u.UserName=t.UserName
Group by Country
order by Country


--Q11
Select u.UserName, count(*) as noOfTweets
from users as u join tweets as t on u.UserName=t.UserName
Group by u.UserName
having count(*) > (select  avg(y.c) from (

Select User_ID, count(*) as c
from users as u join tweets as t on u.UserName=t.UserName
Group by User_ID

)y)

-- Q12
Select distinct f.FollowedUserName
from users as u join following as f on f.FollowerUserName=u.UserName
where Country ='Pakistan'

--Q13
Select i.InterestID,i.Description,Count(*) as CountInterest
from userinterests as u join Interests as i on u.InterestID=i.InterestID
group by i.Description,i.InterestID
having count(*) IN (
Select Top 1 count(*) 
from Interests as i join UserInterests as u on i.InterestID=u.InterestID
Group By i.InterestID
Order by count(*) desc
)

