#include <iostream>
using namespace std;
int main();

int i,arr[50],j,t,k,l;
void sort(int l, int arr[]){

		for (j=0;j<l-1;j++)
	{
		for (k=0;k<(l-j-1);k++) {
		if (arr[k]>arr[k+1])
				{t=arr[k];
			arr[k]=arr[k+1];
			arr[k+1]=t; 
		}
		}
	}



}


int main () {
	
	cout<<"Enter how many numbers you will enter: "<<endl;
	cin>>l;
	cout<<"Enter numbers now: "<<endl;
	for (i=0;i<l;i++)
	{cout<<"Enter number "<<i+1<<" = ";
		cin>>arr[i];
}

	sort(l,arr);

		cout<<"Maximum = "<<arr[l-1]<<endl;
		cout<<"Minimum = "<<arr[0]<<endl;







	system("pause");
	return 0;

}