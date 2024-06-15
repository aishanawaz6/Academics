#include <iostream>
using namespace std;

int main () {
	char o='i';
	int h;
	while (o!='q') {
	cout<<"Please enter order of pattern: ";
	cin>>o;

	if (o!='q')
	{
	if (o!='0'&& o!='1'&& o!='a'&& o!='d')
	{
		do
		{
			cout<<endl<<endl;
		cout<<"Invalid! enter again.... "<<endl;
		cout<<endl;
		cout<<"Please enter order of pattern: ";
	    cin>>o;
		if (o=='q')
			break;
	    } while (o!='0'&& o!='1'&& o!='a'&& o!='d');
	}
	if (o=='q')
		break;
	cout<<"Please enter height of pattern: ";
	cin>>h;
	if (o=='0'||o=='a')
	{
		for(int i=1;i<=h;i++)
		{
           for (int j=1;j<=i;j++)
        	cout<<j<<" ";
          cout<<endl;
		}
	}
	else
	{
		for(int i=1;i<=h;i++)
		{
			for (int j=1,r=h;j<=i;r--,j++)
			cout<<r<<" ";
			cout<<endl;
	    }
	}
	
	
	}
	else
		break;

}
	system ("pause");
	return 0;
}