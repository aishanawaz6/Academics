#include <iostream>
#include <fstream>
using namespace std;
int main();

bool UpperTriangularMatrix(int Arr[][4],int totalRows){
	int c=0;
		for (int j=0;j<4;j++) {
		for(int k=0;k<j;k++) {
			if (Arr[j][k]==0)
				c=c+1;
		}
	}
	if (c==6)
		return true;
	else 
		return false;

}

int main () {
	int totalRows=4;
	ofstream file;
	file.open("matrix.txt");
	int a[4][4]={{1,2,3,4},{0,5,8,9},{0,0,9,10},{0,0,0,6}};
	for(int j=0;j<4;j++){
		for(int r=0;r<4;r++){
			file<<a[j][r];
		}
	}
		file.close();
	ifstream fike;
	fike.open("matrix.txt");
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
	fike>>a[i][j];
		}
		}
	if(	UpperTriangularMatrix(a,4) == 1)
		cout<<"matrix is upper triangular matrix"<<endl;
	else
		cout<<"matrix is not upper triangular matrix"<<endl;
	file.close();
	system("pause");
	return 0;
}