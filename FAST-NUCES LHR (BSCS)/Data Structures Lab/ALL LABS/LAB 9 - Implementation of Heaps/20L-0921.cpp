#include <iostream>
#include "assert.h"
#include <algorithm>
using namespace std;

template<typename k, typename v>
struct HeapItem
{
	k key;
	v value;
};
template<typename k, typename v>
class MinHeap
{
	HeapItem<k,v>*arr;
	int capacity;
	int totalItems;
public:
	MinHeap()
	{
	arr=nullptr;
	capacity=0;
	totalItems=0;
	}
	MinHeap(int _capacity)
	{
	arr=new HeapItem<k,v>[_capacity];
	capacity=_capacity;
	totalItems=0;
	}
	void doublecapacity()
	{int ncapacity;
		if(capacity==0)
			ncapacity=2;
		else
	 ncapacity=capacity*2;
	HeapItem<k,v>*narr=new HeapItem<k,v>[ncapacity];
	for(int i=0;i<capacity;i++)
	narr[i]=arr[i];
	delete []arr;
	arr=narr;
	capacity=ncapacity;
	}
	void insert(k key, v value)
	{
	if(totalItems==capacity)
		doublecapacity();
	arr[totalItems].key=key;
	arr[totalItems].value=value;
	totalItems++;
	if(totalItems==1)
		{
			return;
	}

	scrollup(totalItems-1);
	}
	void scrollup(int index)
	{
		int parent=(index-1)/2;

		if(arr[parent].key>arr[index].key)
		swap(arr[parent],arr[index]);		
		else
			return;
		if(parent>0)
scrollup(parent);
	}
	void getMin(v &_value)
	{
		assert(totalItems>0);
		_value=arr[0];
	}
	void deleteMin()
	{
		assert(totalItems>0);
		swap(arr[totalItems-1],arr[0]);
		totalItems--;
		scrolldown(0);
	}

	void scrolldown(int index)
	{
	int lchild=i*2+1;
	int rchild=i*2+2;
	int min=i;

	if(lchild<totalItems && arr[lchild].key<arr[min].key)
	min=lchild;


	if(rchild<totalItems && arr[rchild].key<arr[min].key)
min=rchild;

if(min==i)
	return;
swap(arr[index],arr[min]);
scrolldown(min);

	}
	void Heapify(HeapItem<k,v>* narr,int size)
	{
	for(int i=0;i<size;i++)
	insert(narr[i].key,narr[i].value);
	
	capacity=size;
	totalItems=size;
	}
	bool isEmpty() const
	{
		return (totalItems==0);
	
	}
	void shrinkHeap()
	{
		int tbd=capacity-totalItems;
		int nc=capacity-tbd;
		
		if((nc/capacity)*100==25)
			nc=capacity/2;

		HeapItem<k,v>*narr=new HeapItem<k,v>[nc];
		for(int i=0;i<totalItems;i++)
			narr[i]=arr[i];
	delete []arr;
	arr=narr;
	capacity=nc;
	}
	~MinHeap()
	{
		delete[]this->arr;
		totalItems=0;
	}
	void print()
	{cout<<"Min Heap.."<<endl;
		for(int i=0;i<totalItems;i++)
		{	cout<<i+1<<" key: "<<arr[i].key<<" value: "<<arr[i].value<<endl;}
	}
};
template<typename k, typename v>
class MaxHeap
{
	HeapItem<k,v>*arr;
	int capacity;
	int totalItems;
	public:
	MaxHeap()
	{
	arr=nullptr;
	capacity=0;
	totalItems=0;
	}
	MaxHeap(int _capacity)
	{
		arr=new HeapItem<k,v>[_capacity];
	capacity=_capacity;
	totalItems=0;
	}
	void insert(k key, v value)
	{
	if(totalItems==capacity)
		doublecapacity();
	arr[totalItems].key=key;
	arr[totalItems].value=value;

	totalItems++;
	if(totalItems==1)
		{
			return;
	}

	scrollup(totalItems-1);
	}
	void doublecapacity()
	{int ncapacity;
		if(capacity==0)
			ncapacity=2;
		else
	 ncapacity=capacity*2;
	
	HeapItem<k,v>*narr=new HeapItem<k,v>[ncapacity];
	for(int i=0;i<capacity;i++)
	narr[i]=arr[i];
	delete []arr;
	arr=narr;
	capacity=ncapacity;
	}
	void scrollup(int index)
	{
		int parent=(index-1)/2;

		if(arr[parent].key<arr[index].key)
		swap(arr[parent],arr[index]);		
		else
			return;
		if(parent>0)
scrollup(parent);
	}
	void getMax(v &_value)
	{
		assert(totalItems>0);
		_value=arr[0];
	}
	void deleteMax()
	{
		assert(totalItems>0);
		swap(arr[totalItems-1],arr[0]);
		totalItems--;
		scrolldown(0);
	}

	void scrolldown(int index)
	{
	int lchild=i*2+1;
	int rchild=i*2+2;
	int max=i;

	if(lchild<totalItems && arr[lchild].key>arr[max].key)
	max=lchild;


	if(rchild<totalItems && arr[rchild].key>arr[max].key)
max=rchild;

if(max==i)
	return;
swap(arr[index],arr[max]);
scrolldown(max);

	}
	void Heapify(HeapItem<k,v>* narr,int size)
	{
	for(int i=0;i<size;i++)
	insert(narr[i].key,narr[i].value);
	
	capacity=size;
	totalItems=size;
	}
	bool isEmpty() const
	{
		return (totalItems==0);
	
	}
	~MaxHeap()
	{
		delete[]this->arr;
		totalItems=0;
	}
	void shrinkHeap()
	{
		int tbd=capacity-totalItems;
		int nc=capacity-tbd;
		
		if((nc/capacity)*100==25)
			nc=capacity/2;

		HeapItem<k,v>*narr=new HeapItem<k,v>[nc];
		for(int i=0;i<totalItems;i++)
			narr[i]=arr[i];
	delete []arr;
	arr=narr;
	capacity=nc;
	}
	void print()
	{cout<<"Max Values.."<<endl;
		for(int i=0;i<totalItems;i++)
	cout<<i+1<<" key: "<<arr[i].key<<" value: "<<arr[i].value<<endl;
	}
};




int main ()
{
	MinHeap<int,float>min;
	min.insert(9, 2.53);
	min.insert(254, 2.98);
	min.insert(111, 3.20);
	min.insert(6, 3.3);
	min.insert(5, 3.1);
	min.insert(4, 3.2);
	min.insert (176, 3.5);
	min.insert (101, 3.2);
	min.insert(153, 2.34);
	min.insert(10,2.64);
	min.insert(16, 2.5);
	min.insert(300, 2.38);
	min.insert (43, 2.9);
	min.insert(15, 3.5);
	min.print();
		MaxHeap<int,float>max;
		max.insert(9, 2.53);
	max.insert(254, 2.98);
max.insert(111, 3.20);
	max.insert(6, 3.3);
	max.insert(5, 3.1);
	max.insert(4, 3.2);
	max.insert (176, 3.5);
	max.insert (101, 3.2);
	max.insert(153, 2.34);
	max.insert(10,2.64);
	max.insert(16, 2.5);
	max.insert(300, 2.38);
	max.insert (43, 2.9);
	max.insert(15, 3.5);
	max.print();

system("pause");
return 0;
}