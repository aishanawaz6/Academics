//Aisha Muhammad Nawaz 20L-0921 DATA STRUCTURES BSCS FALL 2021 SECTION 3E1 LAB 12 Question 2
#include <iostream>
#include<string>
#include <fstream>
using namespace std;

//Question 2 Design a class that will store an unweighted directed graph using adjacency List with following functions.
//1- Count the out-degree of all nodes.  
//2- Count the in-degree of all nodes.
//3- Print all neighboring vertices of a particular vertex.
//4- Check if two vertices are directly connected if their indices are provided.


//LINKLIST CODE
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


	void deleteFromHead()
	{
		if (this->isEmpty())
			return;

		//if there was only one element in the list
		if (this->head == this->tail)
		{
			delete this->head;
			this->head=this->tail = nullptr;
			this->totalElements--;
			return;
		}

		Node<T>* delNode = this->head;
		this->head = this->head->next;
		delete delNode;
		this->totalElements--;


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
		while (tmp)
		{
			cout << tmp->data << endl;
			tmp = tmp->next;
		}
	}
bool elementpresent(T d)
{
	Node<T>* tmp = this->head;
		while (tmp)
		{
			if(tmp->data==d)
				return true;
			tmp = tmp->next;
		}
		return false;
}
int getsize()
{
	return totalElements;
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
};

// Question 2 code starts here
class unweightedDirectedGraph
{
LinkList<int> *arr;
int size;
public:
	unweightedDirectedGraph()
	{
	arr=nullptr;
	size=0;
	}
	unweightedDirectedGraph(int s)
	{
		size=s;
		arr=new LinkList<int>[s];
	}
 void insert(int n1,int n2)
 {
 n1--; // Becuase index starts with zero
 arr[n1].insertAtTail(n2);
 }
	int outdegree()
	{
		int *count=new int(size);
		for(int i=0;i<size;i++) //Initializing count to zero of all nodes
			count[i]=0;

		for (int i=0;i<size;i++) // counting individually outdegree of each node
		{
			count[i]=arr[i].getsize();
		cout<<"Out-degree of "<<i+1<<" is: "<<count[i]<<endl;
		}

		int totalsum=0;
		for (int i=0;i<size;i++) //Counting total out degree of all nodes
		totalsum=totalsum+count[i];
		
		cout<<"TOTAL OUT-DEGREE= "<<totalsum<<endl;

		return totalsum;
	}
	int indegree()
	{
		int *count=new int[size];
		for(int i=0;i<size;i++) //Initializing count to zero of all nodes
			count[i]=0;

		for (int i=0;i<size;i++) // counting individually outdegree of each node
		{
	for(int j=0;j<size;j++)
	{
	if(arr[j].elementpresent(i+1))
		count[i]++;
	}
		cout<<"In-degree of "<<i+1<<" is: "<<count[i]<<endl;
		}

		int totalsum=0;
		for (int i=0;i<size;i++) //Counting total out degree of all nodes
		totalsum=totalsum+count[i];
		
		cout<<"TOTAL IN-DEGREE= "<<totalsum<<endl;

		return totalsum;
	}
	void neighboringVertices(int v)
	{
		
		cout<<"Neighbouring Vertices of "<<v<<" are: "<<endl;
		v--; //Because index starts with 0
		arr[v].print();
		for(int i=0;i<size;i++)
		{
			if (arr[i].elementpresent(v+1))
			{if(!arr[v].elementpresent(i+1)) // To avoid duplicate vertices being printed!
				cout<<i+1<<" ";
			}
		}
		cout<<endl;
}

	
	bool directlyConnected(int i1,int i2)
	{bool flag=false;

	i1--; //Becuase indexes start with 0
	i2--; 
	if (arr[i1].elementpresent(i2+1))
		flag = true;
	if (arr[i2].elementpresent(i1+1))
		flag = true;
		
	return flag;
		}


		
void print()
{
for (int i=0;i<size;i++)
{
arr[i].print();
cout<<endl;
}

}

};

int main ()
{

	ifstream file;
	string name;
	cout<<"Enter name of file to read data from (eg. abc.txt): "<<endl;
	cin>>name;


	file.open(name);

	if (file.is_open())
{	// Reading data from file
	int c;
	file>>c; // Tells number of nodes in graph.	
	unweightedDirectedGraph obj(c);
	int n1,n2;

	while(!file.eof())
	{
	file>>n1;
	file>>n2;
	obj.insert(n1,n2);
	}
	//Till here all data read from file and inserted in obj object

	//Checking function : Count the out-degree of all nodes.
	obj.outdegree();

	//Checking function : Count the in-degree of all nodes.
	obj.indegree();

	//Checking function : Print all neighboring vertices of a particular vertex.
	obj.neighboringVertices(1);
	obj.neighboringVertices(2);
	obj.neighboringVertices(3);
	obj.neighboringVertices(4);
	obj.neighboringVertices(5);


	//Checking function : Check if two vertices are directly connected if their indices are provided 
	cout<<"Are 2 and 4 directly connected?"<<endl;
	if(obj.directlyConnected(2,4))
		cout<<"True!"<<endl;
	else
		cout<<"False!"<<endl;

	cout<<"Are 1 and 3 directly connected?"<<endl;
	if(obj.directlyConnected(1,3))
		cout<<"True!"<<endl;
	else
		cout<<"False!"<<endl;

	cout<<"Are 1 and 5 directly connected?"<<endl;
	if(obj.directlyConnected(1,5))
		cout<<"True!"<<endl;
	else
		cout<<"False!"<<endl;

	cout<<"Are 1 and 4 directly connected?"<<endl;
	if(obj.directlyConnected(1,4))
		cout<<"True!"<<endl;
	else
		cout<<"False!"<<endl;

	cout<<"Are 2 and 3 directly connected?"<<endl;
	if(obj.directlyConnected(2,3))
		cout<<"True!"<<endl;
	else
		cout<<"False!"<<endl;

	}
	else
		cout<<"Unable to open file!"<<endl;




	system("pause");
	return 0;
}