#include<iostream>
#include <fstream>
#include<cmath>
using namespace std;
int main();
void input (int terms,int deg[],int coef[]) {
	int t,q;
		cout<<"Please enter the number of terms: ";
	cin>>terms;
	cout<<"Please enter coefficients: ";
	for (int i =0;i<terms;i++){
		cin>>coef[i];
	}
	cout<<"Please enter degrees: ";

	for (int j=0;j<terms;j++){
cin>>deg[j];
	}

	for (int u=0;u<terms-1;u++) {      
		for (int s=0;s<terms-u-1;s++){
			if (deg[s]<deg[s+1])
			{ t=deg[s];
			q=coef[s];
			coef[s]=coef[s+1];
				deg[s]=deg[s+1];
				coef[s+1]=q;
				deg[s+1]=t;
			}
		}
	}
	cout<<"The polynomial you entered: "<<endl;
	for (int l=0;l<terms;l++){
		cout<<coef[l]<<"x^"<<deg[l];
		if (l!=(terms-1))
			cout<<" +";
	}
	cout<<endl;
}
void inputFromAFile (char filename[],int&terms,int deg[],int coef[]){
		cout<<"Please enter a filename (eg. abc.txt): "<<endl;
cin.getline(filename,50);
ifstream file;
file.open(filename);
if (file.is_open()==true) {
file.seekg(0)>>terms;
for (int j=0;j<terms;j++){
	file.seekg(1,ios::cur)>>deg[j];}
for (int s =0; s<terms;s++){
file.seekg(1,ios::cur)>>coef[s];
}
file.close();

}
else
	cout<<"File not found!"<<endl;
int t,q;
for (int u=0;u<terms-1;u++) {      
		for (int s=0;s<terms-u-1;s++){
			if (deg[s]<deg[s+1])
			{ t=deg[s];
			q=coef[s];
			coef[s]=coef[s+1];
				deg[s]=deg[s+1];
				coef[s+1]=q;
				deg[s+1]=t;
			}
		}
	}
cout<<"Reading from file.."<<endl;
	for (int l=0;l<terms;l++){
		cout<<coef[l]<<"x^"<<deg[l];
		if (l!=(terms-1))
			cout<<" +";
	}
	cout<<endl;
}


int solve (int terms, int deg[],int coef[],int variable){ 
	cout<<"Please enter the value of x (variable): "<<endl;
	cin>>variable;
int result=0;
	for (int i=0;i<terms;i++) {
		result=coef[i]*pow(variable,deg[i])+result;}
	
	return result;

}
void add (int aterms,int adeg[],int acoef[],int bterms,int bdeg[],int bcoef[],int&rterms,int rdeg[],int rcoef[]) {
	int i=0,ter=0;
	while(i<aterms){
		if (adeg[i]==bdeg[i]){
			rcoef[i]=acoef[i]+bcoef[i];
				rdeg[i]=adeg[i];
				ter=ter+1;
		}
	i++;
	}
	rterms=ter;
	cout<<"Resulting Polynomial After Addition: "<<endl;
	for (int l=0;l<rterms;l++){
		cout<<rcoef[l]<<"x^"<<rdeg[l];
		if (l!=(rterms-1))
			cout<<" +";
	}
	cout<<endl;

}

void multiply (int aterms,int adeg[],int acoef[],int bterms,int bdeg[],int bcoef[],int&rterms,int rdeg[],int rcoef[]){
	int i=0,ter=0;
	while(i<aterms){
		if (adeg[i]==bdeg[i]){
			rcoef[i]=acoef[i]*bcoef[i];
				rdeg[i]=adeg[i];
				ter=ter+1;
		}
	i++;
	}
	rterms=ter;
	cout<<"Resulting Polynomial After Multiplication: "<<endl;
	for (int l=0;l<rterms;l++){
		cout<<rcoef[l]<<"x^"<<rdeg[l];
		if (l!=(rterms-1))
			cout<<" +";
	}
	cout<<endl;
}
void subtract (int aterms,int adeg[],int acoef[],int bterms,int bdeg[],int bcoef[],int&rterms,int rdeg[],int rcoef[]){
	int i=0,ter=0;
	while(i<aterms){
		if (adeg[i]==bdeg[i]){
			rcoef[i]=acoef[i]-bcoef[i];
				rdeg[i]=adeg[i];
				ter=ter+1;
		}
	i++;
	}
	rterms=ter;
	cout<<"Resulting Polynomial After Subtraction: "<<endl;
for (int l=0;l<rterms;l++){
		cout<<rcoef[l]<<"x^"<<rdeg[l];
		if (l!=(rterms-1))
			cout<<" +";
	}
	cout<<endl;
}
bool equal (int aterms,int adeg[],int acoef[],int bterms,int bdeg[],int bcoef[]) {
	int q=0;
	while (q<aterms || q<bterms){
if ((acoef[q]==bcoef[q]) && (adeg[q]==bdeg[q]))
	q++; 
	}
	if (q==aterms || q==bterms) {
		return true;
	}
	else 
		return false;
}
void print (int terms, int deg[],int coef[]) {
	for (int l=0;l<terms;l++){
		cout<<coef[l]<<"x^"<<deg[l];
		if (l!=(terms-1))
			cout<<" +";
	}
	cout<<endl;
}

int main () {
	int aterms, adeg[50], acoef[50], bterms,bdeg[50], bcoef[50],rterms, rdeg[50],rcoef[50],variable=1;
	char afilename[50],bfilename[50];
		int choice,ch,n=1;
	cout<<"0. Input two polynomials from files."<<endl;
cout<<"1. Input two polynomials from the user."<<endl;
cout<<"2. Solve one of the polynomials for a value. (prints the result as well)."<<endl;
cout<<"3. Print the polynomials. (if this option entered the user will be asked for selection of any one of these options"<<endl;
cout<<"4. Multiply the polynomials. (prints the result as well)."<<endl;
cout<<"5. Subtract the polynomials.(prints the result as well)."<<endl;
cout<<"6.Add the polynomials (prints the result as well)."<<endl;
cout<<"7. Exit the program."<<endl;
while (n!=0)   {

	cout<<"Please enter you choice: ";
	cin>>choice;
	cin.ignore();

if (choice==0){

	cout<<"Entering Data for Polynomial 1 "<<endl;
	inputFromAFile(afilename,aterms, adeg,acoef);
	cout<<"Entering Data for Polynomial 2  "<<endl;
		inputFromAFile(bfilename,bterms, bdeg,bcoef);
}
else
	if (choice==1)
	{
		cout<<"Enter data for Polynomial 1"<<endl;
	input (aterms, adeg, acoef);
	cout<<"Enter data for Polynomial 2"<<endl;
input(bterms,bdeg,bcoef);
	}
else
		if (choice==2){
			cout<<"Please Enter Polynomial number to solve(1 or 2): ";
			cin>>ch;
			if (ch==1)
cout<<"Result is: "<<solve( aterms,  adeg,acoef,variable)<<endl;
			else
cout<<"Result is: "<<solve( bterms,  bdeg,bcoef,variable)<<endl;
		}
else
			if (choice==3) {
	cout<<"i. First polynomial."<<endl;
	cout<<"ii. Second polynomial"<<endl;
	cout<<"iii. Both"<<endl;
cout<<"Please Enter Polynomial number to print(Enter 1 for one, 2 for two and 3 for both): ";
			cin>>ch;
			if (ch==1){
				cout<<"Printing Polynomial 1.. "<<endl;
print(aterms, adeg,acoef);
			}
			else
				if (ch==2){
						cout<<"Printing Polynomial 2.. "<<endl;
print(bterms, bdeg,bcoef);
				}
				else
					if (ch==3) {
						cout<<"Printing Polynomial 1.. "<<endl;
						print(aterms, adeg,acoef);
						cout<<"Printing Polynomial 2.. "<<endl;
						print(bterms, bdeg,bcoef);
					}
					else
						cout<<"INVALID INPUT!"<<endl;
					}
else
			if (choice==4)
				multiply( aterms, adeg, acoef, bterms,bdeg, bcoef,rterms, rdeg,rcoef);
else
			if (choice==5)
					subtract( aterms, adeg, acoef, bterms,bdeg, bcoef,rterms, rdeg,rcoef);
else
					if (choice==6)
add(aterms, adeg, acoef, bterms,bdeg, bcoef,rterms, rdeg,rcoef);
else 
						if (choice==7)
							n=0;
					
						
}

	system("pause");
	return 0;
}