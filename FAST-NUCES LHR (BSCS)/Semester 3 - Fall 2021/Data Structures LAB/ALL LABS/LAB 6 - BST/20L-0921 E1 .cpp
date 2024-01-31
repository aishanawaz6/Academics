#include <iostream>
using namespace std;

template <typename k, typename v>
struct TNode
{
k key;
v value;
TNode <k, v> *leftChild;
TNode<k, v> *rightChild;
TNode(k k,v v)
{
key=k;
value=v;
leftChild=nullptr;
rightChild=nullptr;
}
bool isLeaf ()
{
	return (leftChild==nullptr && rightChild==nullptr);
}

};
template <typename k, typename v>
class  BST
{
TNode<k,v> *root;
int totalNodes;
private:
	void insertRec(k const key, v const value, TNode<k,v>*&ptr)
	{
		if (ptr==nullptr)
		{
			ptr=new TNode<k,v>(key,value);
			totalNodes++;

		}
		else
			if(key<ptr->key)
		{   
		
			insertRec(key,value,ptr->leftChild);
		}

		else
			if (key>ptr->key)
		{
		
				insertRec(key,value,ptr->rightChild);
				totalNodes++;
			
		}
		if (key==ptr->key)
		{
		ptr->value=value;
		}
	
	}
	void inorderPrintKeys(TNode<k,v>*ptr)  const
	{
		if(ptr)
		{
		inorderPrintKeys(ptr->leftChild);
		cout<<"Key: "<<ptr->key<<" value: "<<ptr->value<<endl;
		inorderPrintKeys(ptr->rightChild);
		}
	}
	void preOrderPrintKeys(TNode<k,v>*ptr)  const
	{
		if (ptr)		
		{
	    cout<<"Key: "<<ptr->key<<" value: "<<ptr->value<<endl;
		preOrderPrintKeys(ptr->leftChild);
		preOrderPrintKeys(ptr->rightChild);
		}

	}
	void postOrderPrintKeys(TNode<k,v>*ptr)  const
	{
		if (ptr)		
		{
        postOrderPrintKeys(ptr->leftChild);
		postOrderPrintKeys(ptr->rightChild);
	    cout<<"Key: "<<ptr->key<<" value: "<<ptr->value<<endl;
		}

	}
	v* searchh(k key,TNode<k,v>*ptr)
	{
		if(ptr==nullptr)
	     return nullptr;

	if(ptr->key==key)
		return &ptr->value;
	if(key<ptr->key)
		searchh(key,ptr->leftChild);
	else
	  if(key>ptr->key)
		searchh(key,ptr->rightChild);
	  
		  
	}
	int lengthh(TNode<k,v>*ptr,int& l) const
	{
		if(ptr)
		{
		l++;
		lengthh(ptr->leftChild,l);
		lengthh(ptr->rightChild,l);
		}
	return l;
	}
	void deleteNode(k const key, TNode<k,v>*&ptr) 
	{
	if(ptr==nullptr)
		return;
	else
		if(key<ptr->key)
			deleteNode(key,ptr->leftChild);
		else
			if(key>ptr->key)
			{
				deleteNode(key,ptr->rightChild);
			}
			else
				if(key==ptr->key)
				{
					if(ptr->leftChild==nullptr && ptr->rightChild==nullptr)
					{
					delete ptr;
					ptr=nullptr;
					}
					else
						if(ptr->leftChild!=nullptr && ptr->rightChild==nullptr)
						{
						TNode<k,v> *p=ptr->leftChild;
						delete ptr;
						ptr=p;
						}
						else
							if (ptr->leftChild==nullptr && ptr->rightChild!=nullptr)
							{
							TNode<k,v> *p=ptr;
							ptr=ptr->rightChild;
						delete p;
							}
							else
							{
								TNode<k,v>*suc=ptr->leftChild;
								while(suc->rightChild)
							{
								suc=suc->rightChild;
							}
								ptr->key=suc->key;
								ptr->value=suc->value;

								deleteNode(suc->key,ptr->leftChild);
							
							}
				}
	}
	v inorderPredecessor(k key,TNode<k,v>*ptr)
	{
	if(ptr==nullptr)
		return 0;
	else
		if(key<ptr->key)
			inorderPredecessor(key,ptr->leftChild);
		else
			if(key>ptr->key)
			{
				inorderPredecessor(key,ptr->rightChild);
			}
			else
				if(key==ptr->key)
				{
					if(ptr->leftChild==nullptr && ptr->rightChild==nullptr)
					{
				return ptr->value;
					}
					else
						if(ptr->leftChild!=nullptr && ptr->rightChild==nullptr)
						{
							ptr->key=ptr->leftChild->key;
							ptr->value=ptr->leftChild->value;
							delete ptr->leftChild;
							ptr->leftChild=nullptr;
							return ptr->value;
						}
						else
							if (ptr->leftChild==nullptr && ptr->rightChild!=nullptr)
							{
						ptr->key=ptr->rightChild->key;
							ptr->value=ptr->rightChild->value;
							delete ptr->rightChild;
							ptr->rightChild=nullptr;
							return ptr->value;
							}
							else
							{
								TNode<k,v>*suc=ptr->leftChild;
								while(suc->rightChild)
							{
								suc=suc->rightChild;
							}
								
								ptr->key=suc->key;
								ptr->value=suc->value;

								inorderPredecessor(suc->key,ptr->leftChild);
							return ptr->value;
							}
				}
	}
	void deleteAll(TNode<k,v>*ptr)
	{
		if  (ptr)
	{
		deleteAll(ptr->leftChild);
		deleteAll(ptr->rightChild);
		delete ptr;
		}
	}
	
	bool isPerfect(TNode<k,v>*ptr,int d, int l=0)
	{
		if(ptr==nullptr)
			return true;

		if (ptr->leftChild==nullptr && ptr->rightChild==nullptr)
			return (d==l+1);

		if (ptr->leftChild==nullptr ||ptr->rightChild==nullptr)
			return false;
		

		return isPerfect(ptr->leftChild,d,l+1)&&isPerfect(ptr->rightChild,d,l+1);
	
	}
public:
	BST()
	{
	root=nullptr;
	totalNodes=0;
	}
	int findAdepthNode(TNode<k,v>*ptr)
	{
		int d=0;
		while (ptr)
		{
			d++;
			ptr=ptr->leftChild;
		}
		return d;
	
	
	}
	v* searchh(k key)
	{
	if(root)
	return searchh(key,this->root);
	else
		return nullptr;
	}
	void insertRec(k const key, v const value)
	{

		insertRec(key,value, this->root);
	}
	void inorderPrintKeys()const
	{
	inorderPrintKeys(this->root);
	}
	void preOrderPrintKeys()const
	{
	preOrderPrintKeys(this->root);
	}
	void postOrderPrintKeys()const
	{
	postOrderPrintKeys(this->root);
	}

	int lengthh() const
	{
		int l=0;
	 lengthh(root,l);
return l;
	}
	void deleteNode(k const key) 
	{
       deleteNode(key, root);
	}
	v inorderPredecessor(k key)
	{
		return inorderPredecessor(key,root);
	}
	~ BST ()
	{
	deleteAll(root);
	}
	bool isPerfect()
	{
		int d=findAdepthNode(root);
return isPerfect(root,d);
	}
};
int main()
{

/*BST <int, int>t;  // My own tests
	t.insertRec(2,4);
	t.insertRec(4,6);
	t.insertRec(1,8);

	t.preOrderPrintKeys();
	int *v=t.searchh(4);
	cout<<"v= "<<*v<<endl;
	cout<<"Lenght: "<<t.lengthh()<<endl;
	t.deleteNode(1);
    t.postOrderPrintKeys();
	t.preOrderPrintKeys();
	t.inorderPrintKeys();
	cout<<t.isPerfect();*/

BST<int, int> tree; //the key and value both are of type int
tree.insertRec(500, 500);
tree.insertRec(1000, 1000);
tree.insertRec(1, 1);
tree.insertRec(600, 600);
tree.insertRec(700, 700);
tree.insertRec(10, 10);
tree.insertRec(30, 30);
tree.insertRec(9000, 9000);
tree.insertRec(50000, 50000);
tree.insertRec(20, 20);
cout <<"Printing keys using inorder traversal: ";
tree.inorderPrintKeys();

cout << endl << endl << "Printing keys using recursive inorder traversal: ";
tree.inorderPrintKeys();
cout << endl << endl<<"Tree Length: "<<tree.lengthh() << endl << endl;
int *val = tree.searchh(123);
if (val != nullptr)
{
cout << "123 found"<<endl;
}
val = tree.searchh(123);
if (val == nullptr){
cout <<"123 not found"<<endl;}
cout <<endl<< "Printing the keys using preOrder traversal: ";
tree.preOrderPrintKeys();
cout <<endl<< "Printing the keys of ancestor nodes of 20 ";
tree.inorderPredecessor(20);
tree.deleteNode(1);
cout <<"Post order traversal: "; 
tree.postOrderPrintKeys();
cout<<tree.isPerfect();


system("pause");
return 0;
}