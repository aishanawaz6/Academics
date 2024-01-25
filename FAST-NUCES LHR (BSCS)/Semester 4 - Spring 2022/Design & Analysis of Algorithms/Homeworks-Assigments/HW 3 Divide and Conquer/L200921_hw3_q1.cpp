//20L-0921 Aisha Muhammad Nawaz BSCS-4A1 HOMEWORK # 3 (ASSUMPTION: 10^6 Array was used because of exceptions when using 10^8 array.)

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include<time.h>
using  namespace std;
#include <chrono>
//#include <unistd.h>

//Now implement Merge Sort, Heap Sort, and Quick Sort in C++ and perform the following experiment:..
int i=0;
int g_lessthan()
{
i++;
return i;
};
// Implementng Heap Sort (Min Heap)
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

		g_lessthan();
		if(arr[parent].key>arr[index].key)
		swap(arr[parent],arr[index]);		
		else
			return;
		if(parent>0)
scrollup(parent);
	}
v getMin()
	{
		assert(totalItems>0);
		v v =arr[0].value;
		return v;
	}
	void deleteMin()
	{
		assert(totalItems>0);
		swap(arr[totalItems-1],arr[0]);
		totalItems--;
		scrolldown(0);
	}

	void scrolldown(int i)
	{
	int lchild=i*2+1;
	int rchild=i*2+2;
	int min=i;

	g_lessthan();
	if(lchild<totalItems && arr[lchild].key<arr[min].key)
	min=lchild;

	g_lessthan();
	if(rchild<totalItems && arr[rchild].key<arr[min].key)
min=rchild;

if(min==i)
	return;
swap(arr[i],arr[min]);
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

// Implementing Merge Sort using divide and conquer approach
template <typename t>
void MergeSort(t *Arr,int l, int r) // l for left, r for right
{
	if (l<r) // will only be false if one element left in array when left will no longer be smaller than right but equal.
	{
	int m=(l+r)/2;

	MergeSort(Arr,l,m);
	MergeSort(Arr,m+1,r);
 MergeSortCombine(Arr,l,r,m);
	}
};

template <typename t>
void MergeSortCombine (t*A,int l,int r,int m)
{
	t *nA=new t[1000000]; // Assuming max possible size is 1000000
	int i=l,j=m+1,k=l;

while (i<=m && j<=r) // To make sure neither array's boundary is crossed
{
	g_lessthan();
	if(A[i]<A[j])
	{
	nA[k]=A[i];
	i++;
    k++;
	}
	else
	{
	nA[k]=A[j];
	j++;
	k++;
	}
}

    while (i <= m) // Incase the above loop ended without copying all values of left array
    {
        nA[k] = A[i];
        k++;
        i++;
    }
    while (j <= r) // Incase the above loop ended without copying all values of right array
	{
        nA[k] =A[j];
        k++;
        j++;
    }
    for (i = l; i < k; i++)  // Copying All values of new Array to Original Array
	{
        A[i] = nA[i];
    }
};
/*
//Implementing Quick Sort using divide and conquer Approach
template <typename t>
void QuickSort(t Arr[],int l, int r)
{
if (l<r)
{
	int q;
	q=Partition(Arr,l,r);
  
	QuickSort(Arr,l,r-1);
	QuickSort(Arr,l+1,r);
}
};
template <typename t>
int Partition(t A[],int l,int r)
{

t p=A[r];
int i=l-1;
for(int j=l;j<=r-1;j++)
{
	g_lessthan();
if(A[j]<p)
	{i++;
	swap(A[j],A[i]);		
    }

}
swap(A[r],A[i+1]);
return i+1;
}*/

void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}
int partition(int array[], int low, int high) 
{
    
  int pivot = array[high];
  int i = (low - 1);

  for (int j = low; j < high; j++) {
    if (array[j] <= pivot) {
        g_lessthan();

      i++;
      swap(&array[i], &array[j]);
    }
  }
  
  swap(&array[i + 1], &array[high]);

  return (i + 1);
}

void quickSort(int array[], int low, int high) 
{
  if (low < high) {
      
    int pi = partition(array, low, high);
    quickSort(array, low, pi - 1);
    quickSort(array, pi + 1, high);
  }
}
void merge(int array[], int const left, int const mid, int const right)
{
    auto const subArrayOne = mid - left + 1;
    auto const subArrayTwo = right - mid;
  
    auto *leftArray = new int[subArrayOne],
         *rightArray = new int[subArrayTwo];
  
    for (auto i = 0; i < subArrayOne; i++)
        leftArray[i] = array[left + i];
    for (auto j = 0; j < subArrayTwo; j++)
        rightArray[j] = array[mid + 1 + j];
  
    auto indexOfSubArrayOne = 0, 
        indexOfSubArrayTwo = 0;
    int indexOfMergedArray = left; 
   
    while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo) {
		g_lessthan();
        if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo]) {	
            array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }
        else {
            array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }
    
    while (indexOfSubArrayOne < subArrayOne) {
        array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }
    
    while (indexOfSubArrayTwo < subArrayTwo) {
        array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
}
  
void mergeSort(int array[], int const begin, int const end)
{
    if (begin >= end)
        return; 
  
    auto mid = begin + (end - begin) / 2;
    mergeSort(array, begin, mid);
    mergeSort(array, mid + 1, end);
    merge(array, begin, mid, end);
}

int main ()
{ srand(time(0));
 const int s=1000000; //Size of Arrays
int *A=new int[s];
int *B=new int[s];
int *C=new int[s];
    for(int i = 0; i<s; i++) //Generating random numbers array A and making its copies B and C
        { 
		A[i]=rand();
	    B[i]=A[i];
		C[i]=A[i];
	    }
   
	auto start = chrono::steady_clock::now();
mergeSort(A,0,s-1);
	auto end = chrono::steady_clock::now();
	cout << "Elapsed time in milliseconds: "<< chrono::duration_cast<chrono::milliseconds>(end - start).count()<< " milliseconds";
    cout<<endl<<"Total # of comparisions: "<<::i<<endl;
	::i=0;

    MinHeap<int,int> obj(s);
	auto start2 = chrono::steady_clock::now();
	for (int i=0;i<s;i++)
			obj.insert(B[i],B[i]);   
       for (int i=0;i<s;i++)
	   {	
	obj.getMin();
	obj.deleteMin();
	   }
 auto end2 = chrono::steady_clock::now();
 cout << "Elapsed time in milliseconds: "<< chrono::duration_cast<chrono::milliseconds>(end2 - start2).count()<< " milliseconds";
cout<<endl<<"Total # of comparisions: "<<::i<<endl;
	::i=0;
	


     auto start3 = chrono::steady_clock::now();
     quickSort(C,0,s-1);
     auto end3 = chrono::steady_clock::now();
     cout << "Elapsed time in milliseconds: "<< chrono::duration_cast<chrono::milliseconds>(end3 - start3).count() << " milliseconds";
	 cout<<endl<<"Total # of comparisions: "<<::i<<endl;
 

system ("pause");
return 0;
}


