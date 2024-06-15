#include <iostream>
using namespace std;




template <typename T>
struct Node
{
	T processid;
	int extime;
	Node<T>* next;

};
template <typename T>
class queue
{    
	Node <T>* head;
	Node<T>* tail;
	int totalElements;

public:
	queue ()
	{
	head=tail=nullptr;
	totalElements=0;
	}
	void enqueue(T pi, int t) // Basically insert at tail
	{
		if (pi>0 && t>0){
			int f=0;
			Node<T>*curr=head;
			while (curr){
				if (curr->processid==pi)
					f=1;
				curr=curr->next;
			}
			if (f==0){
		if (totalElements==0)
		{
         Node<T>* newNode=new Node<T>();
         newNode->processid=pi;
         newNode->extime=t;
         totalElements++;
         head=tail=newNode;
         newNode->next=nullptr;
    	}
		else
		{
		Node<T>* newNode=new Node<T>();
        newNode->processid=pi;
        newNode->extime=t;
        totalElements++;
        tail->next=newNode;
		tail=newNode;
        newNode->next=nullptr;	
		}
			}
			else
				cout<<"ID Already Exists!"<<endl;
		}
		else
			cout<<"Negative Values Not Allowed!"<<endl;

	}
		void dequeue () // Basically delete at tail
		{
if (totalElements==0)		
		cout<<"Nothing to delete"<<endl;
else
if (totalElements==1)
{
delete head;
head=tail=nullptr;
totalElements--;
}
else
{
Node<T>* del=head;
head=head->next;
delete del;
totalElements--;
}
		}
int getLength()
{
	return totalElements;
}
Node<T>* getRear ()
{
	return tail;

}
bool isEmpty()
{
return (totalElements==0);
}
T getMin ()
{
int least=head->extime;
int leastid=head->processid;
Node<T>*curr=head;
while (curr)
{
if (curr->extime<least)
	{
		least=curr->extime;
		leastid=curr->processid;
}
curr=curr->next;

}
return leastid;
}
T getMax()
{

	int most=head->extime;
int mostid=head->processid;
Node<T>*curr=head;
while (curr)
{
if (curr->extime>most)
	{
		most=curr->extime;
		mostid=curr->processid;
    }
curr=curr->next;
}
return mostid;


}

int getCountofSimilar()
{
	Node<T>* curr1=head;
	Node<T>* curr2;
	int count=0;
for (int i=0;i<totalElements;i++)
{
	
for (int j=0;j<totalElements;j++)
{
	curr2=head;
if (curr1->extime==curr2->extime)
	count++;

curr2=curr2->next;
}
curr1=curr1->next;
}

count=count-totalElements;
return count;
		}
void print (Node<T>* t)
{
	cout<<"Process ID: "<<t->processid<<endl;
		cout<<" Execution time: "<<t->extime<<endl;
}
void show ()
{
Node<T>*temp=head;
if (head!=nullptr)
{
while (temp)
{	cout<<"Process ID: "<<temp->processid<<" Execution time: "<<temp->extime<<endl;
	temp=temp->next;
}
}
else
	cout<<"Queue Empty!"<<endl;

}
		
};




int main (){

	
queue<int> q1;
char i=0;
while (i!='q' || i!='Q')
{

	cout<<endl;
	cout<<"enter A for enqueue"<<endl;
	cout<<"enter B for dequeue()"<<endl;
	cout<<"enter C for show()"<<endl;
	cout<<"enter D for getLength()"<<endl;
	cout<<"enter E for getCountofSimilar()"<<endl;
	cout<<"enter F for getMax "<<endl;
	cout<<"enter G for getMin"<<endl;
	cout<<"enter H for getRear"<<endl;
	cout<<"enter I for isEmpty"<<endl;
	
	int fg=0;
	do {cin>>i;
	if (i=='q'||i=='Q')
	{ fg=1;
		break;
	}
	if (i<'A' || i>'I')
		cout<<"INVALID INPUT! ENTER AGAIN"<<endl;
	}
	while ((i<'A'&& i!='q'&&i=='Q') || (i>'I'&& i!='q'&&i=='Q'));
	if (fg==1)
		break;
	if (i=='A'){
		int in,tin;
		cout<<"Enter process id: ";
		cin>>in;
			cout<<"Enter time: ";
		cin>>tin;
	q1.enqueue(in,tin);
}
	else
		if (i=='B'){
			q1.dequeue();}
		else
			if (i=='C'){
				cout<<"now printing ..."<<endl;
	q1.show();
			}
			else
				if (i=='D')
				{
					cout<<"Length()=  "<<q1.getLength()<<endl;
				}
				else
					if (i=='E'){

						cout<<"CountofSimilar= "<<q1.getCountofSimilar()<<endl;
					}
					else
						if (i=='F'){
							cout<<"Max is:  "<<q1.getMax()<<endl;
						}
						else
							if (i=='G'){
								cout<<"Min is : "<<q1.getMin()<<endl;}
							else
								if (i=='H')
								{
									q1.print(q1.getRear());
								}
								else
									if (i=='I')
									{	cout<<"isEmpty =  "<<q1.isEmpty()<<endl;
	}
	
}


system("pause");
return 0;
}
