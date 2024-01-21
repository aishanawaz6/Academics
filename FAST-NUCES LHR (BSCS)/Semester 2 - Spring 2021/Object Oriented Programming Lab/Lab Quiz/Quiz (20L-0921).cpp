#include <iostream>
using namespace std;

int main () 
  {
	  int *arr,N;
	  cout<<"Enter the size of array: ";
	  cin>>N;
	  arr=new int [N];
	  cout<<"Print array: ";
	  for(int i=0;i<N;i++)
	{	  arr[i]=0;
	  cout<<arr[i]<<" ";
	 }
	  cout<<endl;
	  int Q;
	 cout<<"Enter number of quires:"<<endl;
	  cin>>Q;
	 if (Q>=3){
	  int *arrL=new int [Q];
	  int *arrR=new int [Q];
	  for (int j=0;j<Q;j++)
	  {
	  cout<<"Enter value of left for query "<<j+1<<": ";
	  cin>>arrL[j];
	  cout<<"Enter value of right for query "<<j+1<<": ";
	  cin>>arrR[j];
	  }
	 
	  int k=0;
	  for(int i=arrL[k];i<=arrR[k]&&k<Q;i++)
{	  
	arr[i]++;
	  if (i==arrR[k])
	  {
	  k++;
	  i=arrL[k]-1;
	  }



}
	  for (int i=0;i<N;i++)
		  cout<<arr[i]<<" ";
	  cout<<endl;
	 }
	 else
		 cout<<"Quires should be more than or equal to 3! "<<endl;
system ("pause");
return 0;
}