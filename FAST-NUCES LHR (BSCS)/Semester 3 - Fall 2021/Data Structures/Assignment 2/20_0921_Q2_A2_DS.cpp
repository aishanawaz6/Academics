// Aisha Muhammad Nawaz 20L-0921 BSCS SECTION 3E1 DATA STRUCTURES ASSIGNEMENT 2 FALL 2021 Question 2

#include <iostream>
#include <string> // For the purposes of using string data type
#include <queue>// For the purposes of using queue
#include <cstdlib> // For the purposes of using rand function
#include <ctime> // For the purposes of using rand function
#include<conio.h> // To use getch
using namespace std;

int main ()
{
	srand(static_cast<int>(time(0))); // For the purposes of using rand function
	cout<<"~~~~~~~~~~~~~~~~~ Welcome! This Game is a simple version of snakes and ladder ~~~~~~~~~~~~~~~~~"<<endl<<endl; // For decoration purposes
	//Code to get number of players
	int n;
	do { // Loop to ensure user enters a positive number
	cout<<"How many players will play the game? ";
	cin>>n;
	if (n<=1)
		cout<<"Please enter a number greater than one!"<<endl;
	}
	while (n<=1);

	cout<<"When entering names avoid Spaces use '-' instead"<<endl;
	// Code to get names of players and store in queue
	string name;
	queue <string> qn;
	for (int i=0;i<n;i++)
	{
	cout<<"Enter name of player "<<i+1<<" : ";
	cin>>name;
	qn.push(name);
	}


		
	int s,ts; // s is to store face value of dice, ts is to store sum of prev score and face value of dice of player

	string tn; // to store popped name temporarily(for the purposes of iteration as in queue can't access a certain element below front without popping all others before it)
	queue <int>qs; // qs queue stores scores of players
	for (int i=0;i<n;i++) // Initializing to zero all the scores of players
		{
			qs.push(0);
		}

	queue <string> wn; // wn queue stores name of winners as they win

	int it=0; // to store number of players who reached score 100 (increments as winners increase)

	while(it!=n-1)
	{
	//useful messages for players
	cout<<"It is "<<qn.front()<<"'s turn, please enter any key to continue."<<endl;
	_getch();

		// To roll dice
	s=rand()%6+1;
	 // To calculate sum of previous and current score of player
	ts=qs.front()+s;
	
	// to check if score is greater than 100
	if (ts>100)
		{
			cout<<"Score above 100! Retry in next iteration";
			//For the purposes of showing next player's name in order everytime the loop works
	tn=qn.front();
	qn.pop();
	qn.push(tn);
	ts=ts-s;
	//For the purposes of showing next player's score in order everytime the loop works
	qs.pop();
	qs.push(ts);

	cout<<endl;
			continue;
	    }

	cout<<qn.front()<<" got "<<s<<". The total score of "<<qn.front()<<" is now "<<ts<<".";

	// for checking snake and ladder conditions
		if (ts==20)
 {
	 ts=40;
	 cout<<"There is a ladder at 20, so total score is now 40.";
 }
	if (ts==60)
{
	ts=75;
	cout<<"There is a ladder at 60, so total score is now 75.";
}
	if (ts==50)
    {
	ts=40;
	cout<<"There is a snake at 50, so total score is now 40.";
	}
	if (ts==90)
    {
	ts=79;
cout<<"There is a snake at 90, so total score is now 79.";
	}


	if (ts==100) // if condition to check winners
	{
		cout<<endl<<qn.front()<<" WON!";
		if (it==0)
			cout<<" 1st Position"<<endl;
			else
				if (it==1)
					cout<<" 2nd Position"<<endl;
				else
					if (it==2)
						cout<<" 3rd Position"<<endl;
					else
					{
					cout<<" "<<it+1<<"th Position"<<endl;
					}

	it++;
	wn.push(qn.front());
	qn.pop();
	qs.pop();
	
	continue;
	}

	//For the purposes of showing next player's name in order everytime the loop works
	tn=qn.front();
	qn.pop();
	qn.push(tn);
	
	//For the purposes of showing next player's score in order everytime the loop works
	qs.pop();
	qs.push(ts);

	cout<<endl;
	}
	cout<<endl<<"                      GAMEOVER!                       "<<endl;
	cout<<endl<<"-----Position of all players that participated in the game---"<<endl<<endl;
	//game ends and the position of all players that participated in the game is displayed in ascending order.



	for (int i=0;i<it;i++)// Winners displayed
		{
			cout<<"Player "<<wn.front()<<" got";
			if (i==0)
			cout<<" 1st Position"<<endl;
			else
				if (i==1)
					cout<<" 2nd Position"<<endl;
				else
					if (i==2)
						cout<<" 3rd Position"<<endl;
					else
					{
					cout<<" "<<i+1<<"th Position"<<endl;
					}
					wn.pop();

	}
	
	cout<<"Player "<<qn.front()<<" With score: "<<qs.front()<<" came last.";
	it;
	if (it==0)
			cout<<" 1st Position"<<endl;
			else
				if (it==1)
					cout<<" 2nd Position"<<endl;
				else
					if (it==2)
						cout<<" 3rd Position"<<endl;
					else
					{
					cout<<" "<<it+1<<"th Position"<<endl;
					}
cout<<endl;
system("pause");
return 0;
}