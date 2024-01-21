#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
using namespace std;

char *inputFirstName(int&size)
{
cout<<"Please enter size of array: ";
cin>>size;

char *array=new char [size];
cout<<"Please enter first name of student : ";
cin>>setw(size)>>array;
 
return array;

}

char *inputLastName(int&size){
	
	cout<<"Please enter size of array 2: ";
cin>>size;

char *array2=new char [size];
cout<<"Please enter last name of student : ";
cin>>setw(size)>>array2;
return array2;

}

void searchStudentByFirstName(char* firstNameList, const int& size){
	int j=0;
char *s=new char [size];
	cout<<"Enter name to be searched: ";
	cin>>setw(size)>>s;

	for (int i=0;i<size;i++)
	{
		if (s[i]==firstNameList[i])
			j++;
		else
			j=0;
	}
	if (j==size)
		cout<<"Found"<<endl;
	else
		cout<<"Not Found"<<endl;

}
char * returnFullNameList(char* firstNameList, char*lastNameList, const int&size){
	  
			char*newarray=new char [size];
			newarray=firstNameList;
		strcat(newarray,lastNameList);
		 return newarray;
}
int main () {
	int size,size2;
	
	char*firstNameList=inputFirstName(size);
		char*lastNameList=inputLastName(size2);
			searchStudentByFirstName(firstNameList,size);
			int size1=size+size2;
char *newarray=returnFullNameList(firstNameList,lastNameList, size1);


	cout<<"Name : ";
		 cout<<newarray<<endl;



	system("pause");
	return 0;

}