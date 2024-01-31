#include <iostream>
#include "BST 20L-0921.h"
using namespace std;


template <typename k, typename v>
class AVL : public BST<k,v> 
{
	int height;
private:
	void rightRotate(TNode<k,v>*&ptr)
	{
	TNode<k,v>*x=ptr;
	TNode<k,v>*y=x->leftChild;
	TNode<k,v>*T1=y->rightChild;
ptr=y;
y->rightChild=x;
x->leftChild=T1;
UpdateHeight(x);
UpdateHeight(y);

	}
	void leftRotate(TNode<k,v>*&ptr)
	{
		TNode<k,v>*y=ptr;
		TNode<k,v>*x=y->rightChild;
		TNode<k,v>*T1=x->leftChild;

		ptr=x;
		x->leftChild=y;
		y->rightChild=T1;
		UpdateHeight(y);
		UpdateHeight(x);
	
	}
void insertRec(k const key, v const value,TNode<k,v>*&ptr){
	if (ptr==nullptr)
		 BST::insertRec(key,value);
	else
		if (key<ptr->key || key>ptr->key)
		{
			if (key<ptr->key)
				insertRec(key, value,ptr->leftChild);
			else
				insertRec(key,value,ptr->rightChild);
	int BF=getBalanceFactor(ptr);
	// left left case
	if (BF>1 && key<ptr->leftChild->key)
	{
	rightRotate(ptr);
	}
	else // right right case
		if(BF<-1 && key > ptr->rightChild->key)
		{
		leftRotate(ptr);
		}
		else
			//left right case
			if(BF>1 && key> ptr->leftChild->key)
			{
			leftRotate(ptr->leftChild);
			rightRotate (ptr);
			}
			else // right left case
				if (BF<-1 && key< ptr->rightChild->key)
				{
				rightRotate(ptr->rightChild);
				leftRotate(ptr);
				}
				else
					UpdateHeight(ptr);
		}
	}
v*searchh(k key, TNode<k,v>*ptr)
{
	if(ptr==nullptr)
		return nullptr;
	if (key<ptr->key)
	{
	searchh(key,ptr->leftChild);
	}
	else
		if (key>ptr->key)
		{
		searchh(key,ptr->rightChild);
		}
		else
			if (key==ptr->key)
			{
			return &ptr->value;
			}
			else 
				return nullptr;
}
void deleteNode(k const key, TNode<k,v>*&ptr){
	 if (ptr==nullptr)
		 return;
 if (key==ptr->key)
 {
	 BST::deleteNode(key);
	 return;
 }
 if(key<ptr->key||key>ptr->key)
 {
 if(key<ptr->key)
	 deleteNode(key,ptr->leftChild);
 else
	 deleteNode(key,ptr->rightChild);
 int BF=getBalanceFactor(ptr);

 // left left case
 if (BF>1 && getBalanceFactor(ptr->leftChild)>=0)
 {
	 rightRotate(ptr);
 }
 else
	 // right right case
	 if(BF<-1 && getBalanceFactor(ptr->rightChild)<=0)
	 {
		 leftRotate(ptr);
	 }
	 else
		 // left right case
		 if (BF>1 && getBalanceFactor(ptr->leftChild)<0)
		 {
			 leftRotate(ptr->leftChild);
			 rightRotate(ptr);
		 }
		 else // right left case
			 if (BF<-1 && getBalanceFactor(ptr->rightChild)>0)
			 {
				 rightRotate(ptr->rightChild);
				 leftRotate(ptr);
			 }
			 else
				 UpdateHeight(ptr);
 }

 }
public:
  int getHeight(TNode<k,v>*&ptr)
	{	
	if (ptr==nullptr)
		return -1;
	else
		return ptr->height;
	}
	void UpdateHeight(TNode<k,v>*&ptr)
	{
	ptr->height=1+max(getHeight(ptr->leftChild),getHeight(ptr->rightChild));
	
	}
	 int getBalanceFactor(TNode<k,v>*ptr)
 {
 return getHeight(ptr->leftChild)-getHeight(ptr->rightChild);
 }
 AVL() 
 {
 cout<<"Called"<<endl;
 height=0;
 }
 
 void insertRec(k const key, v const value)
 {
insertRec(key,value,BST::getroot());
 }
 void inorderPrintKeys()
 {
 BST::inorderPrintKeys();
 }
 int height_() 
 {
	 return getHeight(BST::getroot());
 }
 void deleteNode(k const key)
 {
 deleteNode(key,BST::getroot());
 }
v* searchh(k b)
{
	return searchh(b,BST::getroot());
}
};

int main()
{
	/*AVL<int, int> tree;
for (int i = 1; i <= 100; i++)
tree.insertRec(i, i);
for (int i = -1; i >= -100; i--)
tree.insertRec(i, i);
for (int i = 150; i > 100; i--)
tree.insertRec(i, i);
for (int i = -150; i < -100; i++)
tree.insertRec(i, i);
for (int i = 150; i > 100; i--)
tree.deleteNode(i);

tree.inorderPrintKeys();
cout << endl << endl;
cout <<"Tree Height: "<< tree.height_() << endl;
int *val = tree.searchh(-100);
if (val != nullptr)
{
cout <<"Key= -100 found "<< endl;
}
val = tree.searchh(-151);
if (val == nullptr)
{
cout <<"Key= -151 not found"<<endl;
}*/

	BST<int,int>t;
	t.insertRec(4,5);
	t.insertRec(1,6);
	t.insertRec(8,7);
	t.insertRec(11,2);
	t.insertRec(9,8);
	t.insertRec(14,1);

	

	t.preOrderPrintKeys();
	t.printCommonAncestors(8,9);
	int c=t.getTreeWidth();
	cout<<c<<endl;
int k=t.kthMaxKey(2);
cout<<"k: "<<k<<endl;
cout<<t.isComplete()<<endl;
system("pause");
return 0;
}