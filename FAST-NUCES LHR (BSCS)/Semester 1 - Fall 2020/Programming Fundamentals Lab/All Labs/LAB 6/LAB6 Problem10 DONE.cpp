#include <iostream>
using namespace std;


	void menu () 
	{ cout<<"Welcome to the fitness center"<<endl;
		cout<<"If you are a senior citizen (age>50years) you will get discount of 20%"<<endl;
	cout<<"If the membership is bought and paid for 12 or more months, the discount is 10%"<<endl;
	cout<<"If more than five personal training sessions are bought and paid for, the discount on each session is 15%"<<endl;
	}



		
	bool duration (int memmonths)
	{ if (memmonths>=12)
return true;
		return false;
	}
	bool personalsession ( int psessions)
	{if (psessions>5)
	return true;
	return false;
	}



	
	int main () {
		double cost,ocost,opcost,pcost,fcost;
		char age;
		int membershipduration,psessions;

		cout<<"Are you a senior citizen(age>50) (Enter Y for yes and N for no) : ";
		cin>>age;
		cout<<" Please enter months of membership: ";
		cin>>membershipduration;
		cout<<"Please enter number of personal training sessions: ";
		cin>>psessions;
		cout<<"Please enter original cost of membership: ";
		cin>>ocost;
		cout<<"Please enter original cost of each personal training session: ";
		cin>>opcost;

		
		if ( duration (membershipduration) )
			cost=ocost*membershipduration*0.9;
		else
			cost = ocost*membershipduration;
		if (personalsession(psessions))
			pcost=opcost*0.15*psessions;
		else 
			pcost =opcost*psessions;


		fcost=pcost+cost;
		if (age=='Y' || age=='y')
		{
			fcost=cost*0.8+opcost*psessions;
		}
		else fcost=fcost;
		cout<<"Cost = "<<fcost<<endl;
		
	system ("pause");
	return 0;
}









	
