#include <iostream>
#include <fstream>
using namespace std;

int ReadQuizData (ifstream &file,double Array[],int s) {
		int c=0;
	file.open("marks.txt");
	if(file.is_open()) {
		while (	file>>Array[c]) 
		c++;
		
	}
		file.close();
	return c;
}

void ShowArray (double Array[],int N) {
	cout<<"Showing marks stored in the Array: "<<endl;
for (int j=0;j<N;j++){
	cout<<Array[j]<<" ";
}
cout<<endl;
}

int main () {
	double Array[250];
	ifstream file("marks.txt");
	ReadQuizData(file,Array,250);
	ShowArray(Array,ReadQuizData(file,Array,250));

	

	system("pause");
	return 0;

}