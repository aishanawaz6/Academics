#include <iostream>
#include<cstring>
#include <string>
#include<fstream>
using namespace std;
void goToLine (int n) {
	ifstream file;
	string line;
	int r=0;
	file.open ("userdetails.txt");
	while (r!=n){
		getline(file,line);
		r++;
		
	}
		cout<<line<<endl;
	file.close();

}
struct userdata{
char name[50];
char add[500];
char num[25];


}user[500];

int main () {
	int c=0, f=0;
	int offset;
	string line;
string sr;
string ch;
	int i=0;
	userdata user[500];
	for(int i=0;ch!="no";i++) {
		ofstream file;
		file.open ("userdetails.txt",ios:: app);

	cout<<"Please enter the user's name: ";
cin.getline(user[i].name,50);
file<<user[i].name<<endl;
	cout<<"Please enter the user's Address: ";
	cin.getline(user[i].add,500);
	file<<user[i].add<<endl;
	cout<<"Please enter the user's Phone Number: ";
	cin.getline(user[i].num,25);
	if (user[i].num[11]==0){ 
		file<<user[i].num<<endl;
	cout<<"Do you want to add more data of users (yes or no): "<<endl;
cin>>ch;
cin.ignore();
	}
	else
		cout<<"invalid phone number. Try all over again! "<<endl;
	file.close();
	} 
	ifstream file;
	file.open("userdetails.txt");
	cout<<"Enter a phone number you wish to search: "<<endl;
	cin>>sr;
	cout<<"Reading from file.."<<endl;
	if (file.is_open()) {
while (!file.eof())
{
	getline(file,line);
	
if ((offset=line.find(sr,0))!=string::npos ){
	f=1;
	cout<<"Phone number matched!"<<endl;
	cout<<"Name of user: ";
	goToLine(c-1);
cout<<"Address of user: ";
	goToLine(c);
	cout<<"Phone number of user: ";
	cout<<line<<endl;
}
else
c++;
}
file.close();
if (f==0)
		cout<<"Sorry the user phone number doesn't exist!"<<endl;
	}
	

	

	system("pause");
	return 0;
}

