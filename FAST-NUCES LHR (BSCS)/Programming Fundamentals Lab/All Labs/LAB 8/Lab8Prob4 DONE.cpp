#include<iostream>
using namespace std;
int main();

void inputarray (int arr[][300]) {
	int m,n;
		cout<<"Enter number of rows of matrix: ";
cin>>m;
cout<<"Enter number of coloumns of matrix: ";
cin>>n;
	for(int i=0;i<m;i++) {
	cout<<"Enter data for row "<<i+1<<" : ";
	for (int j =0;j<n;j++) {
cin>>arr[i][j];
	}
	}
	
}

void display(int arr[300][300]){

	for(int k=0;k<2;k++){
		for (int ki=0;ki<3;ki++)
			cout<<arr[k][ki]<<" ";
		cout<<endl;
	}



}

void sum(int arr[][300]) {
	int sum=0;
	for(int r=0;r<2;r++) {
		for (int c=0;c<3;c++) {
			sum=arr[r][c]+sum;


		}

	}
			cout<<"Sum of all elements is: "<<sum<<endl;

}
void rsum(int arr[][300]) {
	int sum=0;
	for (int r=0;r<2;r++){
		sum=0;
		for (int c=0;c<3;c++) {
			sum=sum+arr[r][c];

		}
		cout<<"Sum of row "<<r+1<<" is: "<<sum<<endl;


	}
}
void csum(int arr[][300]) {
	int sum=0;
	for (int c=0;c<3;c++){
		sum=0;
		for (int r=0;r<2;r++) {
			sum=sum+arr[r][c];

		}
		cout<<"Sum of coloumn "<<c+1<<" is: "<<sum<<endl;

	}
}

void tran(){
	int arr[3][2]={{2,4},{5,6},{8,9}};
	for(int k=0;k<3;k++){
		for (int ki=0;ki<2;ki++)
			cout<<arr[k][ki]<<" ";
		cout<<endl;
	}



}
int main () {
	int e=0,arr[300][300]={{2,4,5},{6,8,9}};
while (e!=-1){
	cout<<"To input elements into matrix of size m x n enter 1"<<endl;
 cout<<"To display elements of matrix of size m x n enter 2"<<endl;
 cout<<"Sum of all elements of matrix of size m x n enter 3"<<endl;
 cout<<"To display row-wise sum of matrix of size m x n enter 4"<<endl;
 cout<<"To display column-wise sum of matrix of size m x n enter 5"<<endl;
 cout<<"To create transpose of matrix B of size n x m enter 6"<<endl;
  cout<<"To exit enter -1"<<endl;
 cin>>e;
 if (e==1)
inputarray(arr);
 else
	 if (e==2)
		 display(arr);
	 else
		 if (e==3)
		 sum(arr);
		 else
			 if (e==4)
			 rsum(arr);
			 else
				 if (e ==5)
				 csum(arr);
 if (e==6)
	 tran();
	 if (e ==-1)
	 break;

}
	system("pause");
	return 0;


}