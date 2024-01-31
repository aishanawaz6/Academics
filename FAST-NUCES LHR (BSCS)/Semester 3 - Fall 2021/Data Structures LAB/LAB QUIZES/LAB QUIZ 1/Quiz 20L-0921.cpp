#include <iostream>
#include <string>
using namespace std;

struct Node{
int emp_id;
string emp_name;
int salary;
Node*next;
};

class SinglyLinkList
{
	Node*head;
	Node*tail;
	int totalE;
public:
	SinglyLinkList()
	{
	head=nullptr;
	tail=nullptr;
	}
	void insertAtHead(int id, string nam,int s)
	{
	if (head==nullptr)
	{
	head=new Node;
	head->emp_id=id;
	head->emp_name=nam;
	head->salary=s;
	head->next=nullptr;
	tail=head;
	}
	else
	{
		Node*newNode=new Node;
	newNode->emp_id=id;
	newNode->emp_name=nam;
	newNode->salary=s;
	newNode->next=head;
	head=newNode;
	}
	
	}
	void insert(int id, string nam,int s)
	{
	if (head==nullptr)
	{
	head=tail=new Node;
	head->emp_id=id;
	head->emp_name=nam;
	head->salary=s;
	head->next=nullptr;
	}
	else
		if(head==tail) // one element
	{
		if (head->salary<s)
		{
		Node*newNode=new Node;
	newNode->emp_id=id;
	newNode->emp_name=nam;
	newNode->salary=s;
	newNode->next=head;
	tail=head;
	head=newNode;
	}
		else
		{
			Node*newNode=new Node;
	newNode->emp_id=id;
	newNode->emp_name=nam;
	newNode->salary=s;
	head->next=newNode;
	tail=newNode;
	newNode->next=nullptr;
		}
	}
		else// More than one element
		{
		if (head->salary<s) // at head
		{
		Node*newNode=new Node;
	   newNode->emp_id=id;
	   newNode->emp_name=nam;
	    newNode->salary=s;
	    newNode->next=head;
	    head=newNode;
	}
		else
		{
			Node*newNode=new Node;
	newNode->emp_id=id;
	newNode->emp_name=nam;
	newNode->salary=s;
	newNode->next=head->next;
	head->next=newNode;
		}

		// after head
		Node*temp=head;
		while(temp->next)
		{
			if(temp->next->salary<s)
			{
			Node*newNode=new Node;
	newNode->emp_id=id;
	newNode->emp_name=nam;
	newNode->salary=s;
	newNode->next=temp->next;
	temp->next=newNode;
	break;
			}
			else
			{
				if (temp->next!=nullptr)
				temp=temp->next;
				else
					break;
			}
		
		}

				{	Node*newNode=new Node;
	newNode->emp_id=id;
	newNode->emp_name=nam;
	newNode->salary=s;
	newNode->next=nullptr;
	temp->next=newNode;
	tail=newNode;
				}
					
	
				
		}

	}
	void print()
	{
		if (head!=nullptr)
		{
	Node *temp=head;
	while(temp)
	{
	cout<<temp->emp_name<<endl;
		cout<<temp->emp_id<<endl;
		cout<<temp->salary<<endl;
	temp=temp->next;
	}
		}
		else
			cout<<"List empty!"<<endl;
	
	}


	void showData()
	{
		
		if(head!=nullptr)
		{
			cout<<"Highest Salaried employee:"<<endl;
			cout<<head->emp_name<<endl;
		cout<<head->emp_id<<endl;
		cout<<head->salary<<endl;

		cout<<"	Least Salaried employee:"<<endl;
			cout<<tail->emp_name<<endl;
		cout<<tail->emp_id<<endl;
		cout<<tail->salary<<endl;

		Node*temp=head;
		cout<<"employees data:"<<endl;
	while(temp)
	{
		cout<<temp->emp_name<<endl;
		cout<<temp->emp_id<<endl;
		cout<<temp->salary<<endl;
		temp=temp->next;
	
	}
		}
		else
			cout<<"List Empty!"<<endl;
	}



};


int main()
{

	SinglyLinkList l1;
	l1.insert(921,"Aisha",56000);
	l1.insert(931,"isha",50000);
	l1.insert(951,"sha",40000);
	l1.print();

	l1.showData();



system("pause");
return 0;
}