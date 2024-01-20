#include <iostream>
#include <vector>
using namespace std;

int main () {

	vector <int> vec1(3);
cout<<"Please enter values of Vector 1: "<<endl;
for (int i=0;i<vec1.size();i++)
	cin>>vec1[i];
cout<<"Please enter values of Vector 2: "<<endl;
vector <int> vec2(3);
for(int i=0;i<vec2.size();i++)
	cin>>vec2[i];

vector <int> vec3(3);
for (int m=0;m<vec3.size();m++)
	vec3[m]=vec1[m]*vec2[m];

cout<<"Now Printing vector 3 (Which is multiplication of vector 1 and 2): "<<endl;
for (int j=0;j<vec3.size();j++)
	cout<<vec3[j]<<" ";
cout<<endl;
	system("pause");
	return 0;
}