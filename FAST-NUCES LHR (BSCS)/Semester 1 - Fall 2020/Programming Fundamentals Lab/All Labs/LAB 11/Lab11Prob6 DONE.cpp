#include <iostream>
#include <vector>
using namespace std;

int main () {
	int sum,range,c=0;
	cout<<"Please enter the range to check prime numbers from : "<<endl;
	cin>>range;
	cout<<"Please enter value of sum: "<<endl;
	cin>>sum; 
	vector <int>v1;
	v1.push_back(2);
	for (int i=2; i<range; i++)  {
        for (int j=2; j<i; j++)
        {
            if (i % j == 0) 
                break;
            else if (i == j+1)
               v1.push_back(i);

		}
	}
	int l=v1.size();
	
	for (int i=0; i<l ;i++){
		for (int j=(l-1); j>0; j--){
	if (v1[i]+v1[j]==sum){
		cout<<"The pair is : "<<endl;
		cout<<v1[i]<<" & "<<v1[j]<<endl;
		c=c+1;
	}

		}

	}
	if (c==0)
		cout<<"Sorry no such pair exists!"<<endl;
	
system ("pause");
return 0;
	}