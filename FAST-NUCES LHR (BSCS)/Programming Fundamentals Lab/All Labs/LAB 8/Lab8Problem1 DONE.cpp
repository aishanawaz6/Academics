#include <iostream>
using namespace std;
int main();
void averagengrade();
void readnstore(char arrname[][30],int arrmarks[][6]) {
	for (int i =0;i<10;i++){
	cout<<"Please enter the name of student: ";
	cin.getline(arrname[i],30);
	}
	for(int k=0;k<10;k++){
			cout<<arrname[k]<<" 5 test scores: ";
	for(int j=0;j<5;j++){
	cin>>arrmarks[k][j];
	}
	}
}
double averagengrade(char arrname[][30],int arrmarks[][6]){
	double at;
	for (int u=0;u<10;u++){
	at=((arrmarks[u][0]+arrmarks[u][1]+arrmarks[u][2]+arrmarks[u][3]+arrmarks[u][4])/500.0)*100;
	return at;
	}
	

	}

void result(double at,char arrname[][30]) {
	char calc;
	if (at>=80.0)
		calc='A';
	else
		if (at>=70.0)
			calc='B';
		else
			if 
				(at>=60.0)
				calc='c';
			else
			if (at>=50.0)
				calc='D';
			else
				calc='F';
	for (int u=0;u<10;u++){

		cout<<"Grade of "<<arrname[u]<<" is "<<calc<<endl;
	}
}

int main() {
	char arrname[10][30];
	int arrmarks[10][6];
char arrgrades[3];

readnstore(arrname,arrmarks);
averagengrade(arrname,arrmarks);
result(averagengrade(arrname,arrmarks),arrname);

	system("pause");
	return 0;
}