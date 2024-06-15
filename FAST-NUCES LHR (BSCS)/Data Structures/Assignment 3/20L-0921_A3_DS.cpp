// Aisha Muhammad Nawaz 20L-0921 BSCS SECTION 3E1 FALL 2021 DATA STRUCTURES ASSIGNMENT 3
#include <fstream>
#include <iostream>
#include <string>
using namespace std;
#include <chrono>
using namespace std::chrono;
template <typename T>
struct Node
{
	T data;
	Node<T>* next;
};

template <typename T>
class LinkList
{
private:
	Node<T>* head;
	Node<T>* tail;

	int totalElements;
public:
	LinkList()
	{
		this->head = nullptr;
		this->tail = nullptr;
		this->totalElements = 0;
	}

	bool isEmpty() const
	{
		return !this->head;
	}

	void insertAtHead(T data)
	{
		if (isEmpty())
		{
			this->head = this->tail = new Node<T>();
			this->head->data = data;
			this->head->next = nullptr;
			totalElements++;
		}

		else
		{
			Node<T>* newNode = new Node<T>;
			newNode->data = data;
			newNode->next = this->head;
			this->head = newNode;
			totalElements++;
		}
	}

	void insertAtTail(T data)
	{
		if (this->isEmpty()) //if list is empty.
		{
			Node<T>* newNode = new Node<T>;
			newNode->data = data;
			newNode->next = nullptr;
			this->head = this->tail= newNode;
			totalElements++;
		}
		else
		{
			this->tail->next = new Node<T>;
			this->tail->next->data = data;
			this->tail->next->next = nullptr;
			this->tail = this->tail->next;
			totalElements++;
		}
	}

	void delete_(T data)
	{
		//if the list is empty
		if (this->head == nullptr)
			return;

		//if the element is found at head node.
		while (this->head->data == data)
		{
			Node<T>* deleteNode = this->head;
			this->head = this->head->next;
			delete deleteNode;
			this->totalElements--;

			if (this->head == nullptr)
			{
				this->tail = nullptr;
				return;
			}
		}

		Node<T>* curr = this->head;

		while (curr->next != nullptr)
		{
			if (curr->next->data == data)
			{
				Node<T>* deleteNode = curr->next;
				curr->next = curr->next->next;
				delete deleteNode;
				this->totalElements--;
				if (curr->next == nullptr)
				{
					this->tail = curr;
				}

			}
			else curr = curr->next;
		}
	}

	void deleteFromTail()
	{
		if (this->isEmpty())
			return;

		if (this->head == this->tail) //if there is only one element in the list.
		{
			delete this->head;
			this->head = this->tail = nullptr;
			this->totalElements--;
		}

		else
		{
			Node<T>* curr = this->head;
			while (curr->next != this->tail)
			{
				curr = curr->next;
			}

			delete this->tail;
			this->tail = curr;
			this->tail->next = nullptr;
			this->totalElements--;
		}
	}

	void print()
	{
		Node<T>* tmp = this->head;
		int i=1;
		while (tmp)
		{
			cout<<i<<".";
			cout << tmp->data << endl;
			tmp = tmp->next;
			i++;
		}
		
	}
	bool alreadyPresent(T findit)
	{
	Node<T>*temp=head;
	while(temp)
	{
   if(temp->data==findit)
	   return true;
	temp=temp->next;
	}
	return false;
	}

	~LinkList()
	{
		Node<T>* ptr;
		while (this->head)
		{
			ptr = this->head->next;
			delete this->head;
			this->head = ptr;
		}
	
	}
	int getsize()
	{
		return totalElements;
	}
};
class BSTNode
{
public:
string keyword; //key of the tree node
LinkList<string> URLs;
BSTNode *lChild;
BSTNode *rChild;
BSTNode()
{
lChild=nullptr;
rChild=nullptr;
}
bool isleafnode()
	{
	return (lChild==nullptr&&rChild==nullptr);
	}

};

class BST
{
	BSTNode *root;
	int noOfElements;
public:
	BST()
	{
	root=nullptr;
	noOfElements=0;
	}
	bool isEmpty()
	{
	return (root==nullptr);
	}
	void insert (string keyword,string url)
	{
		if(isEmpty())
		{
		    root=new BSTNode;
			root->URLs.insertAtTail(url);
			root->keyword=keyword;
			noOfElements++;
		}
		else
		{
			BSTNode*temp=root;
			int flag=1;
			while(flag)
			{
				
				if (keyword<temp->keyword)
				{
			if(temp->lChild==nullptr)
		{
		temp->lChild=new BSTNode;
		temp->lChild->URLs.insertAtTail(url);
		temp->lChild->keyword=keyword;
		noOfElements++;
		flag=0;
		}
			else
				temp=temp->lChild;
			  }
			else 
				if (keyword>temp->keyword)
				{
				if (temp->rChild==nullptr)
				{
		temp->rChild=new BSTNode;
		temp->rChild->URLs.insertAtTail(url);
		temp->rChild->keyword=keyword;
		noOfElements++;
		flag=0;
				}
				else
					temp=temp->rChild;
			   }
				else //same keyword
				{
					if(temp->URLs.alreadyPresent(url)==true)
					{
						//cout<<"URL Already Present!"<<endl; //was only added to check answers while coding
					}
					else
					{
						temp->URLs.insertAtTail(url);
					}
				flag=0;
				}


			}
	
	
	}
	}

	void print()
	{
		if (!isEmpty())
		{
	print(this->root);
		}
		else
			cout<<"Nothig to print!"<<endl;
	}
	
	LinkList<string>* search(string keyword)	{	BSTNode*temp=root;		while (temp)	{		    if (keyword<temp->keyword)		    {			temp=temp->lChild;		    }		else		    if(keyword>temp->keyword)			{				temp=temp->rChild;			}		else			if(temp->keyword==keyword)		    {			return &temp->URLs;		    }		}		return nullptr;	}
	~ BST ()
	{
		if(!isEmpty())
		{
			BSTNode*temp=root->lChild;
		while(temp)
		{
			BSTNode*temp2=temp->lChild;
			delete temp;
			temp=temp2;
		}
	    BSTNode*temp3=root->rChild;
		while(temp3)
		{
			BSTNode*temp4=temp3->rChild;
			delete temp3;
			temp3=temp4;
		}
		delete root;
		root=nullptr;
		}

		noOfElements=0;
	}
	void deleteit(string key)
	{
		deleteit(key, this->root);
	}
private:
	void print(BSTNode*temp)
	{
		if (temp)
	   {
		cout<<"URLs-> "<<endl;
		temp->URLs.print();
		cout<<"Keyword: "<<endl;
		cout<<temp->keyword<<endl;
	print(temp->lChild);
	print(temp->rChild);
		}
	}
void deleteit(string k, BSTNode* &ptr)
	{	
		if (ptr == nullptr)
		return;
		else 
		if (k < ptr->keyword)
			deleteit(k, ptr->lChild);
		else 
		if (k > ptr->keyword)
			deleteit(k, ptr->rChild);
		else
		{
			if (ptr->isleafnode())
			{
				delete ptr;
				ptr=nullptr;
			}
			else 
			if (ptr->lChild && !ptr->rChild)
			{
				BSTNode*t = ptr;
				ptr = ptr->lChild;
				delete t;
			}
			else if (!ptr->lChild && ptr->rChild)
			{
				BSTNode* t = ptr;
				ptr = ptr->rChild;
				delete t;
			}
			else
			{
				BSTNode* s = ptr->lChild;
				//Finding successor from left subtree
				while (s->rChild)
				s = s->rChild;
				ptr->keyword = s->keyword;
				ptr->URLs=s->URLs;
				deleteit(s->keyword, ptr->lChild);
			}
		}
	}
};

int main ()
{
	string fn;
	cout<<"Please enter a filename(eg. abc.txt): ";
	cin>>fn;

auto start=high_resolution_clock::now();

ifstream file;
file.open(fn);

if(file.is_open()) // Checks if file is found and opened. Only moves forward if file is open
{
	
	BST c; // BST to store data of file
    int count=0; // Basically counts the number of urls being read and stored
	string st,st2; // These two are used for the purposes of storing url and keywords. st2 reads url and st reads keyword
	int c1=0,c2=1; // These two are used to aid reading of data.( for e.g c1 inidcates that when 0 read next data that will be read is going to be url. c2 indicates when 1 read next url started and so on..)
	
	file>>st; // reads first index
	while(!file.eof()) // loop works till end of file
	{
       if(st==to_string(c1)) // ID read 
{
	count++; // number of urls stored increases by one
	file>>st2; // here url is read 
  while (st!=to_string(c2) && !file.eof()) // works till next ID read
{

	file>>st; // is now basically reading all the keywords
    if(st!=to_string(c2)) // Checks if next ID reached. Does not let next ID get stored as keyword
    c.insert(st,st2); // is storing the keywords under that specfic url that was read in st2
}

}
c2++; // to move forward with the next urls
c1++;

}
	
//c.print(); //uncomment to check storage of data (for verification purposes while coding)

 // Calculation and display of time taken to read and store data
cout<<"File loaded into the BST successfully."<<" "<<count<<" URLs loaded from the file in ";
auto stop=high_resolution_clock::now();
auto duration=duration_cast<microseconds>(stop-start);
cout<<duration.count()/1000000<<" seconds and "<<duration.count()%1000000<<" microseconds"<<endl;

// Now to search keywords
string inp;
while(inp!="-")
{

cout<<"Please enter a word to search, or enter - to exit: ";
auto start=high_resolution_clock::now();
cin>>inp; // Input taken for keyword to search 

LinkList<string> *in;
in=c.search(inp);

auto stop=high_resolution_clock::now();
auto duration=duration_cast<microseconds>(stop-start);

if (in) // printing match
{
	cout<<in->getsize()<<" result(s) found in "<<duration.count()/1000000<<" seconds and "<<duration.count()%1000000<<" microseconds"<<endl;
	in->print();
}
else
	if (inp!="-")
cout<<"No match found."<<endl;

}

}
else
	cout<<"file not found!"<<endl;
system("pause");
return 0;
}