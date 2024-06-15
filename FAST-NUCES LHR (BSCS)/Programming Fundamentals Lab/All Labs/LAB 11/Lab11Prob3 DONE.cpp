#include<iostream>
#include <vector>
using namespace std;

int main () {
	vector <int> vec(3,0);
	cout<<"Before Appending value of vector..."<<endl;
		for (int i=0;i<vec.size();i++)
	cout<<vec[i]<<" ";
		cout<<endl;
	cout<<"After Appending value of vector..."<<endl;

	vec.push_back(56);
	for (int i=0;i<vec.size();i++)
	cout<<vec[i]<<" ";
	cout<<endl;






system("pause");
return 0;

}