#include <iostream>
using namespace std;

template <typename T>
struct Node
{
	T data;
	Node<T>*next;

};
template <typename T>
class SinglyLinkList
{
Node<T>*head;
public:
	SinglyLinkList()
	{
	head=nullptr;	
	}
	void insertAthead(T dataa)
	{
	if(head==nullptr)
	{
	Node<T>* newNode=new Node<T>;
	head=newNode;
		newNode->data=dataa;
	    newNode->next=nullptr;
	}
	else
		{ Node<T>* newNode=new Node<T>;
		newNode->data=dataa;
	    newNode->next=head;
	    head=newNode;
	}
	}

	void print()
	{
		if (head!=nullptr)
		{
	Node<T>*temp=head;
	while(temp)
	{
		cout<<temp->data<<" ";
	temp=temp->next;
	}
	cout<<endl;
	}
	
	else
		cout<<"List Empty!"<<endl;
	}
	void recursivePrint() const
	{
	this->recursivePrint(head);
	cout<<endl;
	}
	int length() const //recursively finds the length of the linked list.
	{
		int l=0;
		this->length(head,l);
	return l;
	
	}
	void deleteAll() //recursively deletes all nodes of linked list.
	{
	this->deleteAll(head);
	}
	bool isSorted() const
	{
	
	return isSorted(head);
	
	
	}
private:
	bool isSorted(Node<T>*nod) const
	{
	if(nod->next!=nullptr)
	{
		if(nod->data<nod->next->data)
			isSorted(nod->next);
		else
			return false;
	}
	else
		return true;
	
	
	}
	void deleteAll(Node<T>*Nodee)
	{    
		
		if (Nodee!=nullptr)
		{
		Node<T>*temp=Nodee->next;
		delete Nodee;
		Nodee=temp;
		deleteAll(Nodee);
		}
		head=nullptr;
				
	}
	int length(Node<T>*Node,int& l) const
	{
	
if (Node!=nullptr)
		{	l++;
length(Node->next,l);
		}
return l;
	}
	void recursivePrint(Node<T>*Node) const
	{
		if(Node!=nullptr)
		{
	recursivePrint(Node->next);
	cout<<Node->data<<" ";
		}
	
	}
};

int main()
{
	// Testing functions
	/*SinglyLinkList<int> l1; 
	l1.insertAthead(5);
	l1.insertAthead(6);
		l1.insertAthead(7);
	l1.insertAthead(8);
		l1.insertAthead(9);
	l1.insertAthead(10);
		l1.insertAthead(11);
	l1.insertAthead(12);
	cout<<"Now printing in correct order: "<<endl;
	l1.print();
	cout<<"Now printing in reverse order: "<<endl;
	l1.recursivePrint();
	cout<<l1.length()<<endl;
		SinglyLinkList<int> l2;
	l2.insertAthead(6);
	l2.insertAthead(5);
		l2.insertAthead(4);
	l2.print();
	cout<<l2.isSorted()<<endl;
	l1.deleteAll();
	l1.print();*/

	SinglyLinkList<int>l;
	l.insertAthead(10);
	l.insertAthead(9);
	l.insertAthead(7);
	l.insertAthead(5);
	l.recursivePrint();
	cout<<"Printing the output of isSorted : "<<l.isSorted()<<endl;
	cout<<"length of linked list: "<<l.length()<<endl;
	l.deleteAll();
	cout<<"After Calling deleteAll function. "<<endl;
	cout<<"length of linked list: "<<l.length()<<endl;


system("pause");
return 0;

}