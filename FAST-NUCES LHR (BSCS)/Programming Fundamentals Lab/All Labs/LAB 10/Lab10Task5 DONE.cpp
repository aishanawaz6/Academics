#include <iostream>
#include<fstream>
using namespace std;
int main () {
	int a[4][4],b[4][4],r[4][4],t[4][4];
	cout<<"Enter data for matrix A"<<endl;
	for (int i=0;i<4;i++) {
		for (int j=0;j<4;j++){
		cout<<"Enter data for row "<<i+1<<" coloumn "<<j+1<<" : ";
		cin>>a[i][j]; 

	} 
	}
		cout<<"Enter data for matrix B"<<endl;
	for (int i=0;i<4;i++) {
		for (int j=0;j<4;j++){
		cout<<"Enter data for row "<<i+1<<" coloumn "<<j+1<<" : ";
		cin>>b[i][j]; 

	} 
	}
	
	for(int q=0;q<4;q++) {
		for(int l=0;l<4;l++){
		r[q][l]=a[q][l]+b[q][l];

		}

	}


	for(int y=0;y<4;y++){
		for (int p=0;p<4;p++){
			t[y][p]=r[p][y];
	}
	}
	cout<<"Resultant matrix after addition & transpose: "<<endl;
	for (int k=0;k<4;k++)
	{
		for (int f=0;f<4;f++) {
			cout<<t[k][f]<<" ";
		
		}
		cout<<endl;


	}
	ofstream file;
	file.open("result.txt");
	for(int u=0;u<4;u++) {
		for(int s=0;s<4;s++) {
	file<<t[u][s]<<" ";
		}
		file<<endl;
		}
	file.close();




	system("pause");
	return 0;
}