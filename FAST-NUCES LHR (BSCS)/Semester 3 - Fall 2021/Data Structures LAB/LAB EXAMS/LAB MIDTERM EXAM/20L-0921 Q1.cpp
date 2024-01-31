#include <iostream>
#include <string>
using namespace std;


struct Node {
int invoicenum;
string date;
int totalbill;

Node*next;
Node*prev;
};

class dlinklist 
{
Node*head;
int totalE;
public:
	dlinklist()
	{
	head=nullptr;
	totalE=0;
	}
	bool isEmpty()
	{
	return (head==nullptr);
	}
	void insert(int iv,string d,int tb)
	{
	if (isEmpty())
	{
	head=new Node;
	head->invoicenum=iv;
	head->date=d;
	head->totalbill=tb;
	head->next=head->prev=nullptr;
	}
	else
	{
	Node*nw=new Node;
	nw->invoicenum=iv;
	nw->date=d;
	nw->totalbill=tb;
	nw->next=head;
	nw->prev=nullptr;
	nw->next->prev=nw;
	head=nw;
	}
	
	}
void showData()
{
	if (isEmpty())
		cout<<"List Empty nothing to show!"<<endl;
	else{
Node*temp=head;
cout<<"Now Showing All Record: "<<endl;
while(temp)
{
	cout<<"Invoice Number: "<<temp->invoicenum<<" Date: "<<temp->date<<" Total Bill:  "<<temp->totalbill<<endl;
	temp=temp->next;

}

	}
}
void showRecentData()
{

	Node*temp=head;
	int i=0;
cout<<"Now Showing Recent Record (last 3 entries): "<<endl;
while(i<3)
{
	cout<<"Invoice Number: "<<temp->invoicenum<<" Date: "<<temp->date<<" Total Bill:  "<<temp->totalbill<<endl;
	temp=temp->next;
	i++;
}



}
void update(int iv,string d,int tb)
{int f=0;
	if (isEmpty())
		cout<<"List Empty nothing to update!"<<endl;
	else
	{
	Node*temp=head;
	while(temp)
	{
		if(temp->invoicenum==iv)
		{
			deleteR(iv);
			insert(iv,d,tb);
			f=1;
	       cout<<"Invoice Number "<<iv<<" Updated!"<<endl;
			break;
		}
		else
			temp=temp->next;
	
	}
	
	if(f==0)
		cout<<"Invoice Number does not exist"<<endl;
	
	
	
	}
}
void deleteR(int iv)
{int f=0;
	if (isEmpty())
		cout<<"List Empty nothing to delete!"<<endl;
	else
	{
		if(head->invoicenum==iv)
		{
		Node*tempp=head;
head->next->prev=nullptr;
				head=head->next;
				delete tempp;
		}
		else
		{
	Node*temp=head;
	
	while(temp)
	{
		if(temp->invoicenum==iv)
		{
			Node*temp2=temp;
			if(temp->next!=nullptr)
			{
				temp->prev->next=temp->next;
				temp->next->prev=temp->prev;
			delete temp2;
			f=1;
			}
			else
			{
			temp->prev->next=nullptr;
	delete temp2;
			f=1;
			}

			break;
		}
		else
			temp=temp->next;
	
	}

	if(f==0)
		cout<<"Invoice Number does not exist"<<endl;
	
	
	
		}
	}
}
void deleteRecord()
{
	if(isEmpty())
	{
	cout<<"List Empty! Nothing to Delete!"<<endl;
	
	}else
	{
		Node*temp;
		while(head)
		{
		temp=head->next;
		delete head;
		head=temp;
		}

		cout<<"All records deleted!"<<endl;}
}
void insertAfter(int ivA,int iv,string d,int tb)
{
if (isEmpty())
	{
	cout<<"List Empty cannot find any invoice number!"<<endl;
	}
	else
	{
		int f=0;
		Node*temp=head;
		while (temp)
	{
		if(temp->invoicenum==ivA)
		{
		Node*nw=new Node;
	nw->invoicenum=iv;
	nw->date=d;
	nw->totalbill=tb;
	nw->next=temp->next;
	nw->prev=temp;
	temp->next->prev=nw;
	temp->next=nw;
	f=1;
	break;
		}
		else
			temp=temp->next;
	}
		if(f==0)
		{
		cout<<"Invoice number not found!"<<endl;
		}
}
}
};


int main ()
{

	dlinklist l;
l.insert (2,"10-11-2021", 18000);
l.insert (3, "10-11-2021", 1600);
l.insert (4, "11-11-2021", 19560);
l.insert (6, "14-11-2021", 23780);
l.insert (7, "15-11-2021", 54980);
l.insert (8, "15-11-2021", 42970);

l.showData();
l.insert(1,"09-11-2021", 7560);
l.showData();
l.showRecentData();
l.insertAfter(4, 5, "12-11-2021", 14650);

l.showData();

l.update(9,"13-11-2021", 54980);
l.update(4, "18-11-2021", 67500);
l.showData();
l.deleteR(6);
l.showData();
l.showRecentData();
l.deleteRecord();
l.showData();
system("pause");
return 0;
}