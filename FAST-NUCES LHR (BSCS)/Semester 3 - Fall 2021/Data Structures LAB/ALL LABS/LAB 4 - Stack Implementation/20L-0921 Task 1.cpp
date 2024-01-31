#include <iostream>
using namespace std;

template<typename T>
class stack{

int capacity;
int totalElements;
int top;
T*arr;

public:
	stack()
	{
	arr=nullptr;
	capacity=0;
	top=-1;
	totalElements=0;
	}
	stack(int size)
	{
		top=-1;
	arr=new T[size-1];
	capacity=size;
	totalElements=0;
	}
int getCout()
{
	return totalElements;

}
bool isEmpty()
{
	return (totalElements==0);

}

bool isFull()
{
	return (capacity==totalElements);
}
bool Top(T&Data)
{
	if (isEmpty())
		return false;
	else
	{

		Data=arr[top];

	return true;

	}
}
bool pop()
{
	if (isEmpty())
		return false;
	else
	{
	top--;
	totalElements--;
	return true;
	}

}
int reSize(int size)
{
	T*temp=arr;
	arr=new T[size];
for (int i=0;i<totalElements;i++)
{
arr[i]=temp[i];
}

		capacity=size;
		if (totalElements<0.25*capacity)
		{
size=size/2;
		T*temp2=arr;
		arr=new T[size];
		for (int i=0;i<totalElements;i++)
{
arr[i]=temp2[i];
} 
		capacity=size;
		}
	return size;
}
bool push (T const&e)
{
	if (isFull())
	{
			cout<<"Have to resize!"<<endl;
	reSize(capacity*2);
	}
			top++;
arr[top]=e;
totalElements++;
return true;
	
	

}
void print()
	{
	for (int i=top;i>=0;i--)
	{

	cout<<arr[i]<<" ";
	}
	
	}
};



int main ()
{
	int data;

		stack <int>s(5);
		cout<<"s.isFull(): "<<s.isFull()<<endl;
	cout<<"s.isEmpty(): "<<s.isEmpty()<<endl;
			cout<<s.Top(data)<<endl;
		s.push(3);
			s.push(4);
				s.push(5);
				s.push(6);
				s.push(7);
				s.print();
					cout<<endl;
				s.push(8);
		s.print();
		
			
	cout<<"pop: "<<s.pop()<<endl;
			s.print();
			cout<<s.Top(data)<<endl;
			cout<<data<<endl;
			cout<<"s.getCout() : "<< s.getCout()  <<endl;

	cout<<"s.isFull(): "<<s.isFull()<<endl;
	cout<<"s.isEmpty(): "<<s.isEmpty()<<endl;

system("pause");
return 0;
}