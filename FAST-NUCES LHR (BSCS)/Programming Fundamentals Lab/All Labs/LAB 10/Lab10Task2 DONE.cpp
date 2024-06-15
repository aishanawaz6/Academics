#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int main () {
	char data[200];
	string ch;
	cout<<"Reading from file: "<<endl;
	cout<<"Which detail do you want to see?"<<endl;
	cin>>ch;
	ifstream  file;
		file.open("user info.txt");
	if (ch=="Name"){
	file.getline(data,200);
	cout<<data<<endl;
	}
	else 
		
			if (ch=="Address"){
				file.getline(data,200);
file.getline(data,200);
					cout<<data<<endl;}
			else
		if (ch=="DOB"){
		file.getline(data,200);
		file.getline(data,200);
	file.getline(data,200);
		cout<<data<<endl;
		
		}
			else
				if (ch=="Status"){
				file.getline(data,200);
		file.getline(data,200);
		file.getline(data,200);
		file.getline(data,200);
cout<<data<<endl;
				}
				file.close();



	system("pause");
	return 0;


}