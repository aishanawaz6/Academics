//Aisha Muhammad Nawaz 20L-0921 Section 3E1 BSCS DATA STRUCTURES ASSIGNMENT # 5
#include <iostream>
#include<fstream>
#include <queue> //Using STL of queue to store and display huffman code
#include "assert.h"
#include <unordered_map> //to use STL hash map
using namespace std;

//min heap code taken from my lab
struct HNode;
template<typename k, typename v>
struct HeapItem
{
	k key;
	v value;
	HNode*ptr;
	HeapItem()
	{
		ptr=nullptr;
	};
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
	int gettotalItems()
	{
		return totalItems;
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
	HeapItem<k,v>* getMinN()
	{
	return &arr[0];
	}
	
	void insert(k key, v value, HNode*p=nullptr)
	{
	if(totalItems==capacity)
		doublecapacity();
	arr[totalItems].key=key;
	arr[totalItems].value=value;
	if(p!=nullptr)
		arr[totalItems].ptr=p;
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
		_value=arr[0].value;
	}
	k getMinKey()
	{
	assert(totalItems>0);
		return arr[0].key;
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

	if(lchild<totalItems && arr[lchild].key<arr[min].key)
	min=lchild;


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
	{
		cout<<"Min Heap.."<<endl;
		for(int i=0;i<totalItems;i++)
		{	
			cout<<i+1<<" key: "<<arr[i].key<<" value: "<<arr[i].value<<endl;}
	    }
};



//implementing huffman
struct HNode
{
int freq;
char character;
HNode *left,*right;
HNode(int f, char c) // Parameterized Constructor
{
	freq=f;
	character=c;
	left=right=nullptr;
}
};

class Huffman
{
	HNode *root;
public:
	Huffman() //Default Constructor
	{
	root=nullptr;
	}
	void insert (int freq,char ch,HNode*ptr1, int freq2,char ch2,HNode*ptr2)
	{
	
		root=new HNode(freq+freq2,'\0'); //root has sum of frequencies of left & right child

		if(ptr1==nullptr) // checks if it is a subtree and not just a node
			 root->left=new HNode(freq,ch); //first min value stored in left child
		else
			root->left=ptr1; // if subtree

		if(ptr2==nullptr) // checks if it is a subtree and not just a node
	    root->right=new HNode(freq2,ch2); //Second min value stored in right child
		else
			root->right=ptr2; // if subtree

	}
	void createHuffman(char*fileName)
	{
	ifstream file;
	file.open(fileName);
	if(file.is_open())
	{
	
	cout<<"File opened successfully"<<endl;
	char r;
	unordered_map<char,int>m;

	while (!file.eof()) // Reading and storing values in hashmap
	{
	file>>r;
	m[r]++;
	}
	m[r]--;//due to repetition of last char in loop (while reading)

	MinHeap<int,char> minh; // Storing Values from HashMap to MinHeap
	for(auto x: m)
	minh.insert(x.second,x.first);

	while(minh.gettotalItems()!=1) //creating huffman binary tree
	{
		//getting  min Node
	HeapItem<int,char>*min1=minh.getMinN();
	int k=min1->key;
	char v=min1->value;
	HNode*minS=nullptr;
	if(min1->ptr)
		minS=min1->ptr;
       
	minh.deleteMin(); //deleting it from min heap

	//getting second min Node
	HeapItem<int,char>*min2=minh.getMinN();
	int k2=min2->key;
	char v2=min2->value;

	HNode*minS2=nullptr;
	if(min2->ptr)
		minS2=min2->ptr;

	minh.deleteMin(); //deleting it from min heap

	
	insert(k,v,minS,k2,v2,minS2); //inserting them both in huffman binary tree's root
    minh.insert(root->freq,root->character,root); //inserting the new node made back into min heap

	}

	}
	else
		cout<<"File not found!"<<endl;
	}

	void getcode(char c) const
	{
	queue<int> q; //using queue to store code due to FIFO method of queue
	getcode(root,c,q);

	cout<<" Huffman Code: ";
	while(!q.empty()) //printing the code
{
	cout<<q.front();
	q.pop();
}
cout<<" ";

	}

	void printHuffman() const //prints the Huffman code of every character along with the character and its frequency.
	{
	cout<<"Printing Huffman binary tree using inorder printing.."<<endl;
	int i=1;
	printHuffman(root,i);
	}

	~Huffman() //Destructor
	{
	deleteAll(root);
	}
private:
	void getcode(HNode*ptr,char c,queue<int>&q) const // Finds the huffman code of character and displays it
	{
		if(ptr)
		{
			if(ptr->left) //if left child exists
		if(ptr->left->character==c)
			{
				q.push(0); // 0 for left edge
				return;
		    }
		else
		    {   q.push(1); // 1 for right edge
		      	getcode(ptr->right,c,q);
		    }
		}

	}
	void deleteAll(HNode*&ptr)
	{
		if(ptr)
		{
			deleteAll(ptr->left);
			deleteAll(ptr->right);
			delete ptr;
		}
	
	}
	void printHuffman(HNode*ptr,int &i) const
	{
		if(ptr)
		{
			
		printHuffman(ptr->left,i);
		if(ptr->character!='\0') // Because we are supposed to print only unique characters
		{
		cout<<i<<")  |";
		getcode(ptr->character);
		cout<<" Character: "<<ptr->character<<"  Frequency: "<<ptr->freq<<" |"<<endl<<endl;
		i++;
		}
		printHuffman(ptr->right,i);
	}

	}

};

int main() //main function
{

Huffman h; //creating a Huffman object

h.createHuffman("data.txt"); //calling the createHuffman function and passing the name of a text file to it.

h.printHuffman(); //calling the printHuffman function to print Huffman code of all unique characters.


system("pause");
return 0;
}