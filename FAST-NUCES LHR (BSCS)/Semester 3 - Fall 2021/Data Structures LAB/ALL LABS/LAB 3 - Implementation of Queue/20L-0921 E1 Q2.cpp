#include <iostream>
using namespace std;



class fixedsizearray
{
 int capacity;
 int noofElements;
 int rear,front,prear;
 int *ar;

public:
	fixedsizearray()
	{
	ar=nullptr;
	noofElements=0;
	capacity=0;
	rear=front=0;
	}
	fixedsizearray(int s)
	{
	ar=new int [s];
	noofElements=0;
	capacity=s;
	rear=front=0;
	}
	bool isEmpty()
{

return noofElements==0;

}
bool isFull ()
	{
	
		return (noofElements==capacity);
	}
	void enqueue (int it)
	{
	if (isFull()==true)
		cout<<"No Space Left!"<<endl;

	else
	{
		if (it>=0){
	ar[rear]=it;
	prear=rear;
	rear=(rear+1)%capacity;
	noofElements++;
		}
		else
			cout<<"Negative Values Not Allowed"<<endl;
	}
	
	}
	int dequeue ()
	{
	if (isEmpty()==true)
		cout<<"No Elements to dequeue"<<endl;
	else
	{
		int vr=ar[front];
		front=(front+1)%capacity;
		noofElements--;
		return vr;
	
	
	}
	}
	int getLength ()
	{
		return noofElements;
	}

	int getSize ()
	{
		return capacity;
	}
	void reSize(int rs)
	{
	int *ar2=new int [rs];
	for (int i=0;i<noofElements;i++)
	{
	ar2[i]=ar[i];
	
	}
	capacity=rs;
	
	}
	int getRear ()
	{
		return ar[prear];

	}
	int getMin ()
	{
	int l=0;
	for (int i=front,j=0;j<noofElements;i=(i+1)%capacity,j++)
	{
	if (ar[i]<ar[l])
		l=i;
	}
	return l;
	
	}
	int getMax ()
	{
	int m=0;
	for (int i=front,j=0;j<noofElements;i=(i+1)%capacity,j++)
	{
	if (ar[i]>ar[m])
		m=i;
	}
	return m;
	}

	int getCountofSimilar()
	{
	int count =0;
	 for (int i=front,i2=0;i2<noofElements;i=(i+1)%capacity,i2++)
	{
		for (int j=front,j2=0;j2<noofElements;j=(j+1)%capacity,j2++)
			if (ar[i]==ar[j])
				count++;


	}
	return count-noofElements;
	}
	void show ()
	{
		for (int i=front,j=0;j<noofElements;i=(i+1)%capacity,j++)
		{
		cout<<ar[i]<<" ";
		}
	
	}
	int totaltime ()
	{int sum=0;

		for (int i=front,j=0;j<noofElements;i=(i+1)%capacity,j++)
		{
		sum=sum+ar[i];
		
		}
	return sum;
	
	}
	~fixedsizearray()
	{

		delete []ar;
		noofElements=0;
		cout<<"~fixedsizearray() called"<<endl;
	}
};








int main ()
{

	fixedsizearray a1;
	a1.enqueue(5);
	fixedsizearray a2(5);
	a2.enqueue(1);
		a2.enqueue(4);
			a2.enqueue(10);
				a2.enqueue(-2);
				a2.enqueue(2);
				
	a2.show();
	a2.dequeue();
	cout<<endl;
	cout<<"After dequeue();"<<endl;
	a2.show();
	cout<<endl<<"isEmpty(): "<<a2.isEmpty()<<endl;
cout<<endl<<"isFull(): "<<a2.isFull()<<endl;
cout<<endl<<"getLength(): "<<a2.getLength()<<endl;
cout<<endl<<"getSize(): "<<a2.getSize()<<endl;
cout<<endl<<"getRear(): "<<a2.getRear()<<endl;
cout<<endl<<"getMin(): "<<a2.getMin()<<endl;
cout<<endl<<"getMax(): "<<a2.getMax()<<endl;
cout<<endl<<"getCountofSimilar(): "<<a2.getCountofSimilar()<<endl;
cout<<"Total Time: "<<a2.totaltime()<<endl;
cout<<"AFTER  reSize(6): ";
a2.reSize(6);
cout<<endl<<"getSize(): "<<a2.getSize()<<endl;
cout<<"Caliing Destructor.."<<endl;
fixedsizearray*a3=new fixedsizearray;
delete a3;
system ("pause");
return 0;

}