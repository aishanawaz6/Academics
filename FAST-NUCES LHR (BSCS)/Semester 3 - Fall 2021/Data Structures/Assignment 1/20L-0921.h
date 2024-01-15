// 20L-0921 Aisha Muhammad Nawaz section 3E1 BSCS Assignment 1 DATA STRUCTURES FALL 2021
#include <iostream>
using namespace std;

template <typename T>
struct Node 
{
	T data;
	Node*next;
};

template <typename T>
class SortedSet
{
	Node<T>*head;
Node<T>*		tail;
int totalelements;
public:
	SortedSet()
	{
	this->head=NULL;
	this->tail=NULL;
	totalelements=0;
	}
	void insert (T const data)
	{
	// 3 cases , a) No elements b) one element c) more than one element already in list

		// Case a) No element
		if (this->head==NULL)
		{
			Node<T> *newNode=new Node<T>();
		    newNode->data=data;
	        newNode->next=NULL;
	        this->head=this->tail=newNode;
			totalelements++;
		}

		//Case b) Only one element
		else
			if (this->head==this->tail)
{                             // This further has 3 cases, head data greater, less than or equal to new data

			if (data>this->head->data) // case 1 new data greater than head data
			{
		    Node<T>* newNode=new Node <T>;
		    newNode->data=data;
		    newNode->next=NULL;
		    this->head->next=newNode;
			this->tail=newNode;
		    totalelements++;
			}
			else
				if (data<this->head->data) // case 2 new data less than head data
			{
		    Node<T>* newNode=new Node <T>;
		    newNode->data=data;
			newNode->next=this->head;
			this->head=newNode;
			this->tail=newNode->next;
			totalelements++;
			}	
			else                      // case 3 new data equal to head data
			    cout<<"Duplicate data not allowed!"<<endl;
}
			// Case c) more than one element present
			else
{
	//Checking before head
	int check=0; // To know if node already added
 if (this->head->data > data )
 {
 Node<T>* newNode=new Node <T>;
newNode->data=data;
newNode->next=this->head;
this->head=newNode;
totalelements++;
check=1;
 }
 else
 if (this->head->data == data)
 { cout<<"Duplicate Data not allowed!"<<endl;
   check=1;
 }
 //Checking after head
 if (check==0){
Node<T> *round=new Node <T>();
 round=this->head;

		while (round->next!=NULL) //Will check till tail
		{ // 3 cases , New Data less than, greater to or equal to node under consideration

		if (data<(round->next->data)) // if data less than node under check insert new node in between
		{
	    Node<T> *newOne=new Node <T>();
		newOne->data=data;
		newOne->next=round->next;
		round->next=newOne;
		totalelements++;	
		break;
		}
		else
		if (data>(round->next->data)) // if data greater than node under check , keep moving forward
		{
				if (round->next==tail) //if tail near
				{
				Node<T> *newOne=new Node <T>();
				newOne->data=data;
				newOne->next=NULL;
				round->next->next=newOne;
				tail=newOne;
			    totalelements++;
		
				break;
				}
		      else
					round=round->next;			
		}
		else  // // if data equal to node under check 
		{
		cout<<"Duplicate Data not allowed!"<<endl;
		break;	
		}

		} }
	}
	}
	void print () const 
	{
		if (this->head!=NULL){
	Node<T>*temp=new Node<T>();
	temp=this->head;
	while (temp!=NULL)
	{
	cout<<temp->data<<" ";
	temp=temp->next;
	}
	cout<<endl;
	cout<<"Total Elements : "<<this->totalelements<<endl<<endl;}
		else
			cout<<"List Empty!"<<endl;
	}

	void deletee (int const index) // Deletes element at the given index
	{
		if (index<totalelements){
	// Four cases to handle : a) No prior elements b) One element c) more than one element present d) at tail
		//a) No prior elements 
	   if (this->head==NULL)
		   cout<<"No element present in the list!"<<endl;
	   else// b) One element at head
		   if (this->head==this->tail)
		   {
		if (index==0)
		{
		delete head;
		this->head=NULL;
		this->tail=NULL;
		totalelements--;
		}
		   }
		   else// c) more than one element
			   if (index==0)
			   {
				   Node<T>*stemp=new Node <T>();
		stemp=this->head;
		this->head=this->head->next;
		delete stemp;
			  totalelements--;
			   }

			   else
		  if (index!=totalelements-1) 
		  {
		   Node <T>* temp=new Node <T>();
		   temp=this->head;
		   int i=0;
		   while(i<(index-1))
		   {
		   temp=temp->next;
		   i++;
		   }
		   Node <T>*temp2=new Node <T>();
		   temp2=temp->next;
		   temp->next=temp->next->next;
		   delete temp2;
		
			   
		   totalelements--;
		  }
		  else // if delete at tail
			  if (index==totalelements-1)
			  {  
				  Node <T>* round=new Node<T>();
				  round=this->head;
				  int i=0;
				  while (round->next!=tail)
					  round=round->next;
				   tail=round;
				  Node<T>*tem=new Node <T>();
				  tem=round->next;
				  round->next=NULL;
				  delete tem;
				 
				  totalelements--;

			  }
	
		}
		else
	cout<<"Index number not in range of list! Size of list is smaller"<<endl;
	}
	
	void unionn(SortedSet<T>  const&otherSet)
	{
	
 Node <T>* newRound=otherSet.head; 
 while (newRound!=NULL) // will go through the elements of second set, if they are different, it will add them to first set using the old insert function above
 {
 insert(newRound->data);
 newRound=newRound->next;
 }

	}
	
	void intersect(SortedSet<T> const&otherSet)
{

Node <T>* fRound=this->head; // for first set
Node <T>* sRound;  // for second set

int check=0,i=0; // for checks and to find index at which to delete the element which is not in both sets

while (fRound) // This loop will one by one check the if the elements of first set are in second set or not and will delete those not found in both
{
check=0;// will again be set to zero to check the next element in the first list against the whole second list elements
for(sRound=otherSet.head;sRound;sRound=sRound->next)
{
	if (sRound->data==(fRound->data))
		{ 
		   check=1; // will let us know if same element present in second set (used as a flag)
			break; // will immediately break the loop as there is no further need to check
	     }
}
if (check==0)// will tell us if the element has not been found
{
fRound=fRound->next; // we will move it to next node before deleting current one
	deletee(i);  // will delete the uncommon node
		
}
else
{	i++; 
fRound=fRound->next;
}




}
	}
	~SortedSet() // Destructor
	{
	Node <T>* temp=head;
		while (head)
	{
		temp=temp->next;
		delete head;
		head=temp;
	}

	totalelements=0;
	
	}

};