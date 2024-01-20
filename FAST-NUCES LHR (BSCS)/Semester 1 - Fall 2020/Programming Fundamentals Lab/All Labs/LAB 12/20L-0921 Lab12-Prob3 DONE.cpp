#include <iostream>
#include <cstring>
using namespace std;
bool palindrome (char arr[],int q, int l,int r) {
if (r<(l/2)){
if (arr[r]==arr[l-1-r]){
		r++;
		q=q+1;
	return palindrome (arr,q,l,r);
	}
	
	else 
	{
r++;	
	return palindrome (arr,q,l,r);
	}
}
else 
	{
		if (q==l/2) 
		return true;
		else
			return false;
	}



}
int main () {
	char user[150];
	int l=0;
	int q=0;
	int r=0;
	cout<<"Please enter string: "<<endl;
	cin.getline(user,150);
	for (int i=0; user[i]!='\0';i++)
		l=l+1;
	
if (	palindrome(user,q,l,r)==1)
	cout<< "IS A PALINDROME! "<<endl;
else
	cout <<"NOT A PALINDROME!"<<endl;
	system("pause");
	return 0;


	}