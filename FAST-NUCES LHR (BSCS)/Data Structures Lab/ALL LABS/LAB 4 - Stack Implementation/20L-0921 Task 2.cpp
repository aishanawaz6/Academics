#include <iostream>
#include <string>
using namespace std;
template<typename T>
struct Node
{
	T dataa;
	Node<T>*next;

};
template<typename T>
class stack
{
	Node<T>* head;
	int totalE;

public:
	stack()
	{	
	head=nullptr;
	totalE=0;
	}
	int size()
	{
	return totalE;
	}
	bool isEmpty()
	{
	return(totalE==0);
	}
	bool Top(T&data)
	{
		if (isEmpty())
			return false;
		else
		{
	data=head->dataa;
	return true;
		}
	}
	bool pop()
	{
	
		if (isEmpty())
			return false;
		else
		{
head=head->next;
totalE--;
	return true;
		}
	
	}
void push(T const&e)
{

	Node<T>*temp=head;
	head=new Node<T>;
	head->dataa=e;
	head->next=temp;
	totalE++;

}
void print()
{
	Node<T>*temp=head;
	if(temp==nullptr)
	cout<<"Empty!"<<endl;
	else
	{
while(temp)
{	cout<<temp->dataa<<" ";
temp=temp->next;
}
}
} 



};
void ReverseString (string &s)
{char data;
stack<char> st;
int l;
for (l=0;s[l]!='\0';l++);
for (int i=0;s[i]!='\0';i++)
{	
	st.push(s[i]);
}
for (int i=0;i<l;i++)
{	
st.Top(data);
	s[i]=data;
	st.pop();
}


}

int main ()
{

	stack <int> s;
	cout<<"s.isEmpty(); : "<<s.isEmpty()<<endl;
	s.push(5);
		s.push(2);
	int data;
	s.Top(data);
	cout<<"data: "<<data<< endl;
	cout<<"s.size(); : "<<s.size()<<endl;
	s.print();
	cout<<"s.isEmpty(); : "<<s.isEmpty()<<endl;
	s.pop();
	s.print();
	cout<<endl;
	string st="Aisha";
	cout<<"BEFORE ReverseString(st);"<<endl;
		cout<<st<<endl;
	ReverseString(st);
	cout<<"AFTER ReverseString(st);"<<endl;
	cout<<st<<endl;
system("pause");
return 0;
}