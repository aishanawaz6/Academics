use twitter

Select * from [Following]
Select * from Hashtags
Select * from Interests
Select * from Tweets
Select * from UserInterests
Select * from Users

Select * from Users
--1.	What is maximum, minimum, average and standard deviation of ages of the users? (Search Standard Dev function)

select max(age) MaxAge, min(age) MinAge, STDEV(age) StdevAge
from Users

Select * from [Following]
Select * from Users
--2,3.	Give name of the user who has the highest number of followers. 

Select Users.UserName,  Count(Following.FollowedUserName) as NoOfFollowers 
from Users join Following 
on Users.UserName = Following.FollowedUserName 
group by Users.UserName 
having count(Following.FollowedUserName) =  (
	Select Max(y.NoOfFollowers) as NoOfFollowers
	from (Select Users.UserName,  Count(*) as NoOfFollowers 
	from Users join Following 
	on Users.UserName = Following.FollowedUserName 
	group by Users.UserName) y)

Select * from [Following]
Select * from Users
--4.	Give name of the user who has second highest followers.

Select Users.UserName,  Count(*) as NoOfFollowers 
from Users join Following 
on Users.UserName = Following.FollowedUserName 
group by Users.UserName 
having count(*) = (
	Select MIN(y.NoOfFollowers) 
	from (
		Select Distinct TOP 2 Count(*) as NoOfFollowers 
		from Users join Following 
		on Users.UserName = Following.FollowedUserName 
		group by Users.UserName
		order by NoOfFollowers DESC)
	y)

Select * from Tweets
Select * from Users
--5.	List names of all the users who have never tweeted.

Select Users.UserName 
from Users 
except 
(Select Users.UserName 
from Users join Tweets 
on Users.UserName = Tweets.UserName)

Select * from Hashtags
Select * from Tweets
--6.	List all the hashtags and usernames and number of times that user used that hashtag.

select hashtag, username, count(*) noOfTimes
from hashtags join tweets
on CHARINDEX(hashtag, tweets.Text)!=0
group by Hashtag, UserName

Select * from Tweets
--7.	Find the users who have never used the hashtag #Census.

select distinct username
from tweets
where tweets.Text not like '%#census%'
except
select distinct username
from tweets
where tweets.Text like '%#census%'

--8.	List all the usernames that have never been followed. Using Set operation 
select UserName
from users
except
select followedusername
from following

--9.	List all the usernames that have never been followed. Using Exist Clause.

select UserName
from users u
where not exists
	(
	select followedusername
	from following f
	where u.UserName=f.FollowedUserName
	)

Select * from Interests
Select * from UserInterests
--10.	Find the most common interest of users. (The interest with largest number of users). Also find the least common interest.

select ui.InterestID, COUNT(ui.InterestID) as CountInterest
from UserInterests ui join Interests i
on ui.InterestID = i.InterestID
group by ui.InterestID
having count(ui.InterestID) = 
	(
		select MAX(z.CountInterest) 
		from 
			(
				select ui.InterestID, COUNT(ui.InterestID) as CountInterest
				from UserInterests ui join Interests i
				on ui.InterestID = i.InterestID
				group by ui.InterestID
			) z
	) 

select ui.InterestID, COUNT(ui.InterestID) as CountInterest
from UserInterests ui join Interests i
on ui.InterestID = i.InterestID
group by ui.InterestID
having count(ui.InterestID) = 
	(
		select MIN(z.CountInterest) 
		from 
			(
				select ui.InterestID, COUNT(ui.InterestID) as CountInterest
				from UserInterests ui join Interests i
				on ui.InterestID = i.InterestID
				group by ui.InterestID
			) z
	) 

--11.	Show total tweets per country. The result should be in order of country name.

select country, count(*) as totalNoOfTweets
from users join tweets
on users.username = tweets.UserName
group by Country
order by Country

Select * from Tweets
--12.	List names of all the users whose number of tweets is more than average number of tweets per user. 

select username,count(UserName) as NumberOfTweets
from Tweets
group by UserName
having count(UserName) > 
	(
		select avg(y.SumOfTweets/y.TotalUsers) as AvgTweetPerUser
		from
		(
			select Sum(x.TweetsPerUser) as SumOfTweets , count(x.TweetsPerUser) as TotalUsers
			from
			(
				select count(username) as TweetsPerUser
				from Tweets
				group by UserName
			) x
		) y
	)

Select * from Following
--13.	Give the name of the users who have at least one follower from Pakistan.

select distinct f.FollowedUserName
from users u join [Following] f
on u.UserName = f.FollowerUserName
where u.Country= 'Pakistan'


--14.	Show the interest ID and description of interest with the most number of users.

select y.InterestID, Interests.Description, y.CountInterest from Interests join 
(
	select ui.InterestID, COUNT(ui.InterestID) as CountInterest
	from UserInterests ui join Interests i
	on ui.InterestID = i.InterestID
	group by ui.InterestID
	having count(ui.InterestID) = 
		(
			select MAX(z.CountInterest) 
			from 
				(
					select ui.InterestID, COUNT(ui.InterestID) as CountInterest
					from UserInterests ui join Interests i
					on ui.InterestID = i.InterestID
					group by ui.InterestID
				) z
		)  
) y 
on interests.InterestID = y.InterestID


