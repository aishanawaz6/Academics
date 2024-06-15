#include <iostream>
#include <fstream>
#include <string>
using namespace std;
void count (int arr[],ifstream&file);
void printnow(int arr[]);
void openFile (string name,int arr[]) {
ifstream file;
file.open(name);
if (file.is_open()==true){
	cout<<"The File Contains: "<<endl;
	count(arr,file);
	printnow(arr);
}
else
cout<<"File not found.. program terminate!!"<<endl;


	}

void count ( int  arr[],ifstream&file) {
	char pick;
	int factor =0;
	while (file>>pick){
			factor =int (pick);
		if (factor>=65&& factor<=90)
			arr[factor-65]++;
		else
			if (factor>=97 && factor <=122)
				arr[factor-71]++;
	}

}

void printnow(int arr[]) {

	for (int i=0;i<52;i++) 
		arr[i]=(arr[i]*100)/52;
	cout<<"Upper case letters: "<<endl;
	for (int j=0;j<26;j++) 
		cout<<(char)(j+65)<<" "<<arr[j]<<"%"<<endl;
	cout<<endl<<"Lower case letters: "<<endl;
	for (int j=26;j<52;j++) 
		cout<<(char)(j+71)<<" "<<arr[j]<<"%"<<endl;

}


int main () {
	int arr[52]={0};
	string name;
	cout<<"Please enter name of file (e.g abc.txt): ";
	cin>>name;
	openFile(name,arr);
	system("pause");
	return 0;
}