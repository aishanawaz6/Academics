#include <iostream>
#include "Player.h"
#include <string>
#include <fstream>
using namespace std;



Player :: Player () 
{
    TeamName= "TEAM NAME";
    PlayerName= "PLAYER NAME";
    numberofinnings=0;
    numberofnotouts=-1;
    numberofscores=0;
    scoreList=0;
}

void Player :: setTeamName(char *tname)
{
	TeamName=tname;
}
void Player :: setPlayerName(char *pname)
{
	PlayerName=pname;
}
void Player :: setnumberofinnings(int noi)
{
    numberofinnings=noi;
}
void Player:: setnumberofnotouts(int nono)
{
    numberofnotouts=nono;
}
void Player :: setscorelist (int*sl,int n)
{
scoreList=sl;
numberofscores=n;
}
void Player :: setnumberofscores(int nos) 
{
	numberofscores=nos;
}
char * Player:: getTeamName()
	{
		return TeamName;
	}
char * Player:: getPlayerName()
{
	return PlayerName;
}
int  Player::  getnumberofinnings()
{
	return numberofinnings;
}
int Player :: getnumberofnotouts()
{
	return numberofnotouts;
}
int Player :: getnumberofscores()
{
	return numberofscores;
}
int  * Player :: getscoreList()
{
	return scoreList;
}

double Player :: average ()
{
	double average;
	double totalscore =0.0;
	for (int i=0;i<numberofscores;i++)
		totalscore=totalscore+scoreList[i];
	average = totalscore/(numberofinnings-numberofnotouts);

	return average;

}
void Player :: print () 
{
cout<<"Team Name: "<<TeamName<<endl;
cout<<"Name: "<<PlayerName<<endl;
cout<<"Score list : ";
for (int i=0;i<numberofscores;i++)
{
	cout<<scoreList[i]<<" ";
}
cout<<endl;
cout<<"Number of Innings: "<<numberofinnings<<endl;
cout<<"Number of outs: "<<numberofnotouts<<endl;
cout<<"AverageScore: "<<average()<<endl;
}
void Player:: Compare(Player object)
{
   if ( object.average() > average() )
		{
			cout<<"player average = "<<object.average()<<" and not so good player average : "<<average()<<endl;
			cout<<object.PlayerName<<" is a good player"<<endl;
			object.print();

   }
   else
   {
	cout<<"player average = "<<average()<<" and not so good player average : "<<object.average()<<endl;
			cout<<PlayerName<<" is a good player"<<endl;
			print();
   }
}

