#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int main () {
	char* str="- This is, my Object Oriented Programming Lab.";
	int i;
for ( i=0;str[i]!='\0';i++);

	char** dy=new char*[4];
	for (int j=0;j<4;j++)
		{
			dy[j]=new char [i];
			
	}

	dy[0]=strtok(str,"-");
			
	dy[1]=strtok(str," ");
				
	dy[2]=strtok(str,",");
					
	dy[3]=strtok(str,".");

for (int j=0;j<4;j++)
		for (int k=0;k<i;k++)
   cout<<dy[j][k];

   

	system("pause");
	return 0;

}