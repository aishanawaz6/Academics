#include <iostream>
using namespace std;

int main () {
	int p1,p2;
	cout <<"First Player = ";
	cin>>p1;
	cout<<"Second Player = ";
	cin>>p2;

	if (p1==p2)
		cout <<"Draw"<<endl;
	else
		if (p1==1 && p2==3 || p1==3 && p2==2 || p1==2 && p2==1 )
			cout<<"Player 1 has won!"<<endl;
		else
			if (p1==1 && p2==2 || p1==2 && p2==3 || p1==3 && p2==1)
				cout<<"Player 2 has won!"<<endl;



	system("pause");
	return 0;
}