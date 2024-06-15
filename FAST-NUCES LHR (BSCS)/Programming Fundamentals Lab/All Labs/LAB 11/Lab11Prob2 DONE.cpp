#include <iostream>
#include <vector>
using namespace std;
int main () {
	vector <int> vec1(3);
	vector <int> vec2 (3);
	vector <int> vec3 (3);
	cout<<"Please enter values of vector 1 "<<endl;
	for (int i=0;i<vec1.size();i++)
		cin>>vec1[i];
		cout<<"Please enter values of vector 2 "<<endl;
	for (int r=0;r<vec2.size();r++)
		cin>>vec2[r];
		for (int k=0; k<vec3.size();k++)
		vec3[k]=vec1[k]+vec2[k];
		cout<<"Printing values of vector 3 which is addittion of vector 1 and 2"<<endl;
		for (int j=0;j<vec3.size();j++)
			cout<<vec3[j]<<" ";

		cout<<endl;



	system("pause");
	return 0;
}