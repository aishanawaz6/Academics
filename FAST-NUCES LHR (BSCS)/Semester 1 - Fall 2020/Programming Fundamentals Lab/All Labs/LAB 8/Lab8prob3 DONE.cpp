#include <iostream>
using namespace std;
int main();

void midrowncol (int r, int c, int arr[][300]) {
	int m;
	for(int i=0;i<r;i++) {
	cout<<"Enter data for row "<<i+1<<" : ";
	for (int j =0;j<c;j++) {
cin>>arr[i][j];
	}
}
m=((r+1)/2)-1;

cout<<"Elements of middle row: ";
for(int ci=0;ci<c;ci++){
	cout<<arr[m][ci]<<" ";
}
cout<<endl;
cout<<"Elements of middle column: "<<endl;
for(int ri=0;ri<c;ri++){
	cout<<arr[ri][m]<<endl;
}



}

int main () {

int arr[300][300],r,c;
cout<<"Enter number of rows of matrix: ";
cin>>r;
cout<<"Enter number of coloumns of matrix: ";
cin>>c;
midrowncol(r,c,arr);
	system ("pause");
	return 0;
}