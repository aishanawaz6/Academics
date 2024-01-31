// Aisha Muhammad Nawaz 20L-0921 BSCS Section 3E1 Final Exam Q1
#include <iostream>
using namespace std;


struct Node
{
	int data;
};
class MinHeap
{
	 Node*arr;
	 int capi;
	 int noOfelements;
public:
	MinHeap()
	{
	arr=new Node[1];
	capi=1;
	noOfelements=0;
	}
	void resizeit()
	{
		
	int ns=capi*2;
	Node*narr=new Node[ns];
	for (int i=0;i<capi;i++)
		narr[i]=arr[i];

	delete []arr;
	arr=narr;
	capi=ns;
	}
void insertinHeap(int d)
{
	if(capi==noOfelements)
		resizeit();

	arr[noOfelements].data=d;
	noOfelements++;

	if (noOfelements==1)
		return;
	else
		pullup(noOfelements-1);


}
void pullup(int i)
{
	int parent=(i-1)/2;
	if (arr[parent].data>arr[i].data)
	{
			swap(arr[parent],arr[i]);
	}

	if (parent==0)
	return;
	pullup(parent);

}

void bstToMinHeap (int *arr,int size)
{
	for (int i=0;i<size;i++)
	insertinHeap(arr[i]);

}
void print()
{
	cout<<"Printing MinHeap: "<<endl;
	for (int i=0;i<noOfelements;i++)
	{
	cout<<arr[i].data<<" ";
	}
	cout<<endl;
}
};
int main ()
{
	MinHeap h;
	int arr[7]={5,3,8,2,4,6,10};

	h.bstToMinHeap(arr,7);
	h.print();



system ("pause");
return 0;
}