#include <iostream>
using namespace std;
template <typename k,typename T>
struct Node
{
	k key;
	T data;
	Node<k,T>* next;
	Node()
	{
	next=nullptr;
	}
};

template <typename k,typename T>
class LinkList
{
private:
	Node<k,T>* head;
	Node<k,T>* tail;

	int totalElements;
public:
	LinkList()
	{
		this->head = nullptr;
		this->tail = nullptr;
		this->totalElements = 0;
	}
	void delete_(k key)
	{
		//if the list is empty
		if (this->head == nullptr)
			return;

		//if the element is found at head node.
		while (this->head->key == key)
		{
			Node<k,T>* deleteNode = this->head;
			this->head = this->head->next;
			delete deleteNode;
			this->totalElements--;

			if (this->head == nullptr)
			{
				this->tail = nullptr;
				return;
			}
		}

		Node<k,T>* curr = this->head;

		while (curr->next != nullptr)
		{
			if (curr->next->key == key)
			{
				Node<k,T>* deleteNode = curr->next;
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
	bool isEmpty() const
	{
		return !this->head;
	}

	void insertAtHead(k key,T data)
	{
		if (isEmpty())
		{
			this->head = this->tail = new Node<k,T>();
			this->head->data = data;
			this->head->key=key;
			this->head->next = nullptr;
			totalElements++;
		}

		else
		{
			Node<k,T>* newNode = new Node<k,T>;
			newNode->data = data;
			newNode->key=key;
			newNode->next = this->head;
			this->head = newNode;
			totalElements++;
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

		Node<k,T>* delNode = this->head;
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
			Node<k,T>* curr = this->head;
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
		Node<k,T>* tmp = this->head;
		while (tmp)
		{
			cout <<"Data: " tmp->data << endl;
			cout <<"Key:  "<<tmp->key<< endl;
			tmp = tmp->next;
		}
	}
	
T* returnData(k key)
	{
		Node<k,T>* tmp = this->head;
		while (tmp)
		{
			if(tmp->key==key)
				return &tmp->data;
			tmp = tmp->next;
		}
		return nullptr;
	}

	~LinkList()
	{
		Node<k,T>* ptr;
		while (this->head)
		{
			ptr = this->head->next;
			delete this->head;
			this->head = ptr;
		}
	
	}
};
template<typename k,typename v>
class HashItem
{public:
LinkList<k,v> items;
};

template<typename k, typename v>
class HashMap
{
HashItem<k, v>* arr;
int capacity;
int totalElements;
//add any required private function
public:
	HashMap()
	{
	arr=new HashItem<k,v>[10];
	capacity=10;
	totalElements=0;
	}
	void doublecapacity()
	{
	HashItem<k,v>*arr2=new HashItem<k,v>[capacity*2];
	int oc=capacity;
	capacity=capacity*2;
	int i=0;

	while(i<oc)
	{
		arr2[i].items=arr[i].items;

	i++;	
	}
	delete []arr;
	arr=arr2;
	}
	int compressionfunction(int hashCode)
	{
	return hashCode%capacity;
	}
void insert(k key, v value) //add the remaining required public functions
{

int hashCode = key.hashCode();
//now apply a compression function and then insert the key, value pair.
int index=compressionfunction(hashCode);

     arr[index].items.insertAtHead(key,value);
     totalElements++;
     float loadFactor=float(totalElements/capacity);

     if(loadFactor>=0.75)
	 doublecapacity();
}
void remove(k key, v value)
{
	for(int i=0;i<capacity;i++)
	arr[i].items.delete_(key);
}
v* getvalue(k key)
{
	for(int i=0;i<capacity;i++)
	{
		v* val=arr[i].items.returnData(key);
	if(val)
		return val;
	}
}
v* operator [] (k key)
{for(int i=0;i<capacity;i++)
	{
		v* val=arr[i].items.returnData(key);
	if(val)
		return val;
	}

}
bool hashKey(k key)
{
	for(int i=0;i<capacity;i++)
	{
		v* val=arr[i].items.getData(key);
	if(!val)
		return false;
	}
	return true;
}
~HashMap()
{
delete []arr;
arr=nullptr;
totalElements=capacity=0;
}
};

struct Integer
{
int integerNum;
int key;
Integer()
{}
bool operator ==(Integer obj)
{
	return key==obj.key;

}
Integer(int k){key=k;}
int hashCode()
{
int hashCode = key << 1 | key>> 5; //it’s the bitwise OR between the key shifted 1 time left and the same key shifted 5 times right.
if(hashCode<0)
	hashCode=hashCode*-1;
return hashCode;
}
};
int main ()
{

	HashMap<Integer, string>hashObj;
	Integer obj(5);
	hashObj.insert(obj,"Ash");
	string *s=hashObj.getvalue(obj);
	for(int i=0;i<3;i++)
	cout<<s[0][i];
	
	system ("pause");
	return 0;
}