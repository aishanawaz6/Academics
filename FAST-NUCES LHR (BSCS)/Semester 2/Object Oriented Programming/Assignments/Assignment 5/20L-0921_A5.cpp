#include <iostream>
using namespace std;
int divideit (int num); // For the purpose of obtaining carry (right)
int remainderAdd(int num); // For the purpose of obtaining remainder (left)
int* ConverttoDec (char*c); // To convert a whole char array of hex numbers to integer array of decimal numbers
char* ConverttoHex(int *arr,int size);// To convert a whole int array of decimal numbers to char array of hex numbers

class Hex {
private:
char* number;
int length; // To store length of hex numbers
public:
Hex(char*n)
{
number=n;
for (length=0;number[length]!='\0';length++); // To calculate length of hex numbers
}
Hex(Hex&b)
{
number=b.number;
for (length=0;number[length]!='\0';length++); // To calculate length of hex numbers
}

Hex operator + (Hex&b)
{
	Hex ans(*this);
	int *arint=ConverttoDec(number);
	int *arint2=ConverttoDec(b.number);
	int *arans=new int [length];
	for (int i=length-1,j=b.length-1;i>=0;i--,j--)
	{
		if (j>=0)
	   arans[i]=arint[i]+arint2[j];
		else
			arans[i]=arint[i];
	}
	ans.number=ConverttoHex(arans,length);
	cout<<"Addition of two hex numbers successful!"<<endl;
return ans;
}
Hex operator ++ (int)
{
	Hex ans(*this);
	int *ar1=new int [ans.length];
		ar1=ConverttoDec(ans.number);
		ar1[ans.length-1]++;
		this->number=ConverttoHex(ar1,ans.length);
		cout<<"Increment of hex number successful!"<<endl;
	return ans;
	
}
Hex operator ++ ()  //Pre-increment Function
{
	Hex ans(*this);
	int *ar1=new int [ans.length];
		ar1=ConverttoDec(ans.number);
	ar1[ans.length-1]=++ar1[ans.length-1];
		ans.number=ConverttoHex(ar1,ans.length);
			this->number=ans.number;
		cout<<"Increment of hex number successful!"<<endl;
	return ans;
	
}
friend ostream& operator << (ostream&out,Hex&h); // << overloaded
/*~Hex()   // Destructor
{
delete []number;
number=NULL;
}*/
};
ostream& operator << (ostream&out,Hex&h) // << overloaded
{
	for (int i=0;h.number[i]!='\0';i++)
		out<<h.number[i];
	return out;
}
int main () {
Hex a("1F24A0"), b("7E3C");
cout<<a++<<endl;
cout<<a<<endl;
cout<<++b<<endl;
cout<<b<<endl;
cout << (a + b) << endl;


system("pause");
return 0;
}
int divideit (int num) // For the purpose of obtaining carry
{
while(num/16!=0)
	num=num/16;
return num;

}
int remainderAdd(int num) // For the purpose of obtaining remainder
{
	int r=0;
while (num/16!=0)
	{	r=num%16;
		num=num/16;       
    }
return r;
}
int* ConverttoDec (char*c) // To convert a whole char array of hex numbers to integer array of decimal numbers
{
	int l;
	for (l=0;c[l]!='\0';l++);
	int*a=new int[l];
	
for (int i=0;i<l;i++)
	{ 
if (c[i]<'A')
	a[i]=c[i]-48;
else
	if (c[i]>'9')
	{
	    if (c[i]=='A')
		a[i]=10;
	else
		if (c[i]=='B')
	a[i]=11;
	else
		if (c[i]=='C')
		a[i]=12;
	else
	    if (c[i]=='D')
		a[i]=13;
	else
	    if (c[i]=='E')
		a[i]=14;
    else
	    if (c[i]=='F')
		a[i]=15;
	
	}
	}
return a;
}
char* ConverttoHex(int *arr,int size)// To convert a whole int array of decimal numbers to char array of hex numbers
{

	char* n=new char[size+1];
	for (int i=size-1;i>=0;i--)
	{
	if (arr[i]<10)
	n[i]=arr[i]+48;
	else
	if (arr[i]>9 && arr[i]<16)
	{
    	if (arr[i]==10)
		n[i]='A';
	else
    	if (arr[i]==11)
		n[i]='B';
	else
    	if (arr[i]==12)
		n[i]='C';
	else
     	if (arr[i]==13)
		n[i]='D';
	else
	    if (arr[i]==14)
		n[i]='E';
	else
		if (arr[i]==15)
        n[i]='F';
   }
	else
		if (arr[i]>16)
		{
			n[i]=remainderAdd(arr[i])+48;
		    arr[i-1]=divideit(arr[i])+arr[i-1];
	    }
}
	n[size]='\0';

return n;

}