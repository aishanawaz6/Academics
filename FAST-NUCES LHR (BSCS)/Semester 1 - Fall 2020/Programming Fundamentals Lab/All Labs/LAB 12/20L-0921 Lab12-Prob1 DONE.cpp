#include <iostream>
#include <cstring>
using namespace std;

int vowel (char usser[],int v, int i) {
	
	if (usser[i]=='\0')
		return v;
	else
		if (usser[i]=='A'||usser[i]=='E'||usser[i]=='I'||usser[i]=='O'||usser[i]=='U'||usser[i]=='a'||usser[i]=='e'||usser[i]=='i'||usser[i]=='o'||usser[i]=='u'){
		v=v+1;
		i++;
		return vowel(usser,v,i);
	}
	else
		if (usser[i]!='\0'){
			i++;
return 	vowel(usser,v,i);
		}
		


}




int main () {
char user[150];
int v=0,i=0;
	cout<<"Please enter string : ";
	cin.getline(user,150);

	
	cout <<"Number of Vowel : "<<vowel(user,v,i)<< endl;
	system ("pause");
	return 0;
}