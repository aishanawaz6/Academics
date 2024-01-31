#include <iostream>
#include <cstring>
using namespace std;
int stringCompare (char const* string1, char const* string2)
{
	
if(*(string1)!=*(string2))
{
if (*string1>*string2)
	return 1;
else
	return -1;
}
	
	if(strlen(string1)==strlen(string2))
	{
if (*string1=='\0' || *string2=='\0')
return 0;
	}
	string1=string1++;
	string2=string2++;
	stringCompare(string1,string2);

}
int main ()
{
	char *s1="ab";
	char *s2="abC";


	cout<<"Comparing ab and abC : "<<stringCompare(s1,s2)<<endl;

	char *s3="abc";
	char *s4="ab";
	cout<<"Comparing abc and ab : "<<stringCompare(s3,s4)<<endl;

		char *s5="abc";
	char *s6="abc";
	cout<<"Comparing abc and abc : "<<stringCompare(s5,s6)<<endl;



	system("pause");
	return 0;
}