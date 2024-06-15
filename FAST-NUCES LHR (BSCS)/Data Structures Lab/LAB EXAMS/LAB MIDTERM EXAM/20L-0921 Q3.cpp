#include <iostream>
#include <string>
#include <stack>
#include <queue>
using namespace std;

bool checkPalindrome(int v)
{
	int num=v,r;
	stack<int> q;
	queue<int> q2;
	int i=0;
	while (v/10)
	{
	r=v%10;
	v=v/10;
	q.push(r);
	q2.push(r);
	i++;
	}
	q.push(v);
	q2.push(v);
	i++;
	
	int j=i/2;
	int t;
	int f=1;
	while(j)
	{
	if (q.top()==q2.front())
	{
		q.pop();
		t=q2.front();
		q2.pop();
		q2.push(t);
	j--;
	f=1;

	}
	else
	{f=0;
	break;
	}
	}
	if(f==0)
	{cout<<"NOT PALINDROME!"<<endl;
		return false;
	}
	else{
		cout<<"PALINDROME!"<<endl;
	return true;
	}
}
bool checkPalindrome(string v)
{
	int l=v.length();
	int c=l/2;
	int i=0;
	int f=1;
	int j=1;
	while(i<c)
	{
	if (v[i]==v[l-j])
		{f=1;
			i++;
			j++;
	}
	else
		{f=0;
			break;
	}
	
	}
	if(f==0)
	{cout<<"NOT PALINDROME!"<<endl;
		return false;
	}
	else{
		cout<<"PALINDROME!"<<endl;
	return true;
	}
}
int main ()
{
checkPalindrome("1122");
checkPalindrome("1212");
 checkPalindrome("1221");
 checkPalindrome("121");
checkPalindrome("11");
 checkPalindrome("1");
 checkPalindrome(" ");
 checkPalindrome(1122);
 checkPalindrome(1212);
 checkPalindrome(1221);
 checkPalindrome(121);
 checkPalindrome(11);
 checkPalindrome(1);


system ("pause");
return 0;
}