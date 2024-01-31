#include <iostream>
#include <string>
using namespace std;
#include <iostream>
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

bool isBalanced(string exp)
{
	stack <char> s;
	int l;
	char data;
	for (l=0;exp[l]!='\0';l++);
	for (int i=0;i<l;i++)
	{

		if (exp[i]=='['||exp[i]=='{'||exp[i]=='(')
		{
	s.push(exp[i]);
		}
		else
			if (exp[i]==']'||exp[i]=='}'||exp[i]==')')
			{
			s.Top(data);
			if (data=='[')
			{	if(exp[i]==']')
			  s.pop();
			}
			else
				if (data=='(')
			{	if(exp[i]==')')
			          s.pop();
			}
				else
				if (data=='{')
				{	if(exp[i]=='}')
			         s.pop();
			   }

	}


}
return s.isEmpty();
}
int main ()
{
	string st="{[{}{}]}[()]";
	cout<<isBalanced(st)<<endl;
	string st2="{{}{}}";
		cout<<isBalanced(st2)<<endl;
	string st3="[]{}()";
		cout<<isBalanced(st3)<<endl;
			string st4="{()}[)";
		cout<<isBalanced(st4)<<endl;
		string st5="{(})";
		 cout<<isBalanced(st5)<<endl;
system("pause");
return 0;
}