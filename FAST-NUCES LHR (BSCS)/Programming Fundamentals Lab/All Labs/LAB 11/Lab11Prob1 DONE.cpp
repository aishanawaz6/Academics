#include <iostream>
#include <vector>
using namespace std;

int main () {
	
	 vector <int> myList(5);
	 int length;
	 myList[0]=3;
	 for (int i=1;i<4;i++)
		myList[i]=2*myList[i-1]-5;
	 myList.push_back(46);
	  myList.push_back(57);
	   myList.push_back(35);

	   //* Ans to part a
	  vector<int> :: iterator it;
	  it=myList.begin();
	  cout<<"First Element is: "<<*it<<endl;
	  it=(myList.end()-1);
	    cout<<"Last Element is: "<<*it<<endl;



		//*Ans to part b
		length = myList.size();
		cout<<"Length is: "<<length<<endl;
		//* Ans to part c
		for(it=myList.begin();it!=myList.end();it++)
			cout<<*it<<" ";
cout<<endl;

	system ("pause");
		return 0;
}