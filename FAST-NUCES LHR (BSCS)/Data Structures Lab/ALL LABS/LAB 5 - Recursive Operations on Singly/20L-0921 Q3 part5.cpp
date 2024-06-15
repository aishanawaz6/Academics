#include <iostream>
using namespace std;

template <typename T>
struct Node
{
	T SalesRecord;
	T expenses;
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
	void insertAthead(T sr,T exp)
	{
	if(head==nullptr)
	{
	Node<T>* newNode=new Node<T>;
	head=newNode;
	newNode->SalesRecord=sr;
	newNode->expenses=exp;
	    newNode->next=nullptr;
	}
	else
		{ Node<T>* newNode=new Node<T>;
		newNode->SalesRecord=sr;
	newNode->expenses=exp;
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
		cout<<"SalesRecord: "<<temp->SalesRecord<<" expenses: "<<temp->expenses<<endl;
	temp=temp->next;
	}

	}
	
	else
		cout<<"List Empty!"<<endl;
	}
	void recursivePrint() const
	{
	this->recursivePrint(head);
	cout<<endl;
	}

	void deleteAll() //recursively deletes all nodes of linked list.
	{
	this->deleteAll(head);
	}
	int calcProfit()
	{
		int pf=0;
		pf=calcProfit(head,pf);
		return pf;
	}

private:
	int calcProfit(Node<T>*t,int pf)
	{
		if(t->next!=nullptr)
		pf=pf+calcProfit(t->next,(t->SalesRecord-t->expenses));
		else
		{ pf=pf+(t->SalesRecord-t->expenses); 
				return pf;
		}
	}
	void recursivePrint(Node<T>*Node) const
	{
		if(Node!=nullptr)
		{
	recursivePrint(Node->next);
	cout<<"SalesRecord: "<<Node->SalesRecord<<" expenses: "<<Node->expenses<<endl;
		}
	
	}
};

int main()
{

	SinglyLinkList<int> s1;
	s1.insertAthead(6000,5000);
	s1.insertAthead(4000,2000);
	s1.insertAthead(8000,6000);
	s1.insertAthead(9000,2000);
	s1.recursivePrint();
	cout<<"TOTAL PROFIT : "<<s1.calcProfit()<<endl;

system("pause");
return 0;

}