// Aisha Muhammad Nawaz 20L-0921 BSCS Section 3E1 Final Exam Q2
#include<iostream>
#include <string>
#include <fstream>
using namespace std;
//Using data structure circularlinklist 

struct Node{
int amount;
int distancetonext;
Node*next;
};
class CircularLinkList
{
	Node*head;
	Node*tail;
	int size;
public:
	CircularLinkList()
	{
	head=nullptr;
	size=0;
	}
	void incirc(int n)
	{
	size=n;
	}
	void insertattail(int a,int d)
	{
	if(head==nullptr)//No prior element
	{
		head=new Node;
		head->amount=a;
		head->distancetonext=d;
		head->next=head;
		tail=head;
	}
	else // prior elements
	{

	Node*newNode=new Node;
	tail->next=newNode;
	newNode->amount=a;
	newNode->distancetonext=d;
	newNode->next=head;
	tail=newNode;
	tail->next=head;
	}
	
	}
	int checknode(Node*temp,int a)
	{
	int s=0;
	for(int i=0;i<size;i++)
	{
		if (a<=temp->distancetonext)
		{
		s++;
		temp=temp->next;
		a=a+temp->amount;
		}
		else
			break;
	}
	return s;
	}
	int CompleteTour()
	{ 
		Node*temp=head;
		int s=-1;
		bool f=false;
		int i=0,j=0;
		int a=0;
		while (j<size)
		{
			a=temp->amount;
			s=checknode(temp,a);
			if(s==size)
			{
				f=true;
				break;
			}
			temp=temp->next;
			i++;
			j++;
		}
		if(!f)
		cout<<"Start = "<<1<<endl;
		else
			cout<<"No such point exists"<<endl;

		return i;
	}

	void insertfromfile(string filename)
	{
		ifstream file;
		file.open(filename);
		if (file.is_open())
		{
		int fsize;
		file>>fsize;
		incirc(fsize); //Size inserted

		//Now getting data
		int a1,d1;
		while(!file.eof())
		{
		file>>a1;
		file>>d1;
		insertattail(a1,d1);
		}
		
		}
		else
			cout<<"File not openend!"<<endl;
	}
	
	void printnodes()
	{Node*temp=head;
	for (int i=0;i<size;i++)
	{
		cout<<"p"<<i+1<<" Amount: "<<temp->amount<<" Distance to next: "<<temp->distancetonext<<endl;
		temp=temp->next;
	}
	}

};


int main ()
{
	string filename;

	cout<<"Enter filename to insert data from (eg. Q2.txt): ";
	cin>>filename;
	CircularLinkList p;
	p.insertfromfile(filename);
	p.printnodes();
	p.CompleteTour();

system("pause");
return 0;
}