#include <iostream>
using namespace std;

template <typename t>
bool RSort(t *Arr,int l, int r,int& q,int x) // l for left, r for right
{
	if(Arr[l]==2)
			return false;
	if (l<r) // will only be false if one element left in array when left will no longer be smaller than right but equal.
	{
	int m=(l+r)/2;
RSort(Arr,l,m,q,x);
RSort(Arr,m+1,r,q,x);
	}
		else
		{q=q+1;
			
			if(Arr[l]==x)
			{
			cout<<"The Position is:  "<<q<<endl;
			return true;
			}

			return false;
    	}
};


int main ()
{
	int arri[]={4,5,2,8};
	int x=-1;
	int &q=x;
	RSort(arri,0,3,q,5);

system("pause");
return 0;
}