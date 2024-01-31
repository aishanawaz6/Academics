template <typename k, typename v>
struct TNode
{
k key;
v value;
int height;
TNode <k, v> *leftChild;
TNode<k, v> *rightChild;

TNode(k k,v v)
{
key=k;
value=v;
leftChild=nullptr;
rightChild=nullptr;
height=0;
}
bool isLeaf ()
{
	return (leftChild==nullptr && rightChild==nullptr);
}

};
template <typename k, typename v>
class  BST
{

int totalNodes;
TNode<k,v> *root;
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
	
	void printCommonAncestors (k k1, k k2,TNode<k,v>*ptr) const
	{
		if (ptr==nullptr)
		{
		cout<<"k1 not found!"<<endl;
		return;
		}
	if (k1<ptr->key)
		{
				cout<<ptr->value<<endl;
			printCommonAncestors(k1,k2,ptr->leftChild);
		
	}
	else
		if (k1>ptr->key)
			{
				cout<<ptr->value<<endl;
				printCommonAncestors(k1,k2,ptr->rightChild);
				
		}
		else
			if(k1==ptr->key)
			return;
	
	}
int getTreeWidth(int &c,TNode<k,v>*ptr)const
	{
		if(ptr==nullptr)
			return c;
		TNode<k,v>* a=ptr->leftChild;
		TNode<k,v>*  b=ptr->rightChild;
		int c1=0;

		if(a)
		{
			if(a->leftChild)
	     c1++;
		if(a->rightChild)
			c1++;
		}

		if(b)
		{
		if(b->leftChild)
	     c1++;
		if(b->rightChild)
			c1++;
		}

		if (c1>c)
			c=c1;
		getTreeWidth(c,ptr->leftChild);
		getTreeWidth(c,ptr->rightChild);
		return c;
	}
	k kthMaxKey(int const ky,TNode<k,v>*ptr,int &c) const
	{
		if(ptr)
		{ 
			if(c==ky)
					return ptr->key;
			c++;
			
			kthMaxKey(ky,ptr->rightChild,c);
		}
		else{
			try{
                   throw exception("Exception here!");		
		       }
			catch(exception e)
			{
			cout<<e.what()<<endl;
			}
		
		}
	}
public:
bool isComplete ( )
   {      
		  int totalnodes = countNodes(root);
          return  isComplete(root, 0, totalnodes);
   }
int countNodes(TNode<k,v>* ptr)
{
    if (ptr==NULL)
        return 0;
    return (1 + countNodes(ptr->leftChild) + countNodes(ptr->rightChild));
}
	bool isComplete ( TNode<k,v>* ptr, int i,int totalNodes)
{
    if (ptr==NULL)
        return true;
 
    if (i >= totalNodes)
        return false;

    return (isComplete(ptr->leftChild, 2*i + 1, totalNodes) && isComplete(ptr->rightChild, 2*i + 2, totalNodes));
}
	BST()
	{
	 cout<<"Called2"<<endl;
	root=nullptr;
	totalNodes=0;

	}
	TNode<k,v>*&getroot()
	{
	return root;
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
virtual	void insertRec(k const key, v const value)
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
virtual	void deleteNode(k const key) 
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

	void printCommonAncestors (k k1, k k2) const
	{
		printCommonAncestors(k1,k2,root);
	}
int getTreeWidth()const
	{
	int count=0;
	getTreeWidth(count,root);
	return count;
	}

k kthMaxKey(int const key)const
{int c=1;

	return kthMaxKey(key,root,c);
	
}


};