#include <iostream>
using namespace std;
int  main();

void upperhalf(int arrayA[][100],int nc, int nr){


	for (int ri=0;ri<nr;ri++) {
		for (int j=1;j<=ri;j++){
			cout<<" ";
		}
		for(int ci=0;ci<nc-1;ci++) {
cout<<arrayA[ri][ci];
		}

		cout<<endl;
		}







}


int main () {
	int arrayA[100][100];
		int nc,nr;
	cout<<"Enter Number of coloumns : ";
	cin>>nc;
	cout<<"Enter Number of rows : ";
	cin>>nr;

	for (int r=0;r<nr;r++){
		cout<<"Enter data For Row "<<r+1<<" : "<<endl;

		for (int c=0;c<nc;c++) {
			cin>>arrayA[r][nc];
		}

	}

	upperhalf(arrayA,nc,nr);





	system("pause");
	return 0;

}