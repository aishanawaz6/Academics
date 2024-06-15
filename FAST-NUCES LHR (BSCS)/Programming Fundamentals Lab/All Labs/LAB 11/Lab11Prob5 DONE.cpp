#include <iostream>
#include <vector>
using namespace std;

int main () {
	vector <int> vec1(3);
	cout<<"Please enter values of vector 1: "<<endl;
	for (int i=0; i<vec1.size();i++) 
		cin>>vec1[i];
	cout<<"Please enter values of vector 2: "<<endl;
	vector <int> vec2(3);
	for (int i=0; i<vec2.size();i++) 
		cin>>vec2[i];
	vector <float> vec3(3);
	for (int d=0;d<vec3.size();d++)
		vec3[d]=vec1[d]/vec2[d];

		cout<<"Now printing vector 3 (which is vector 1 divide by vector 2): "<<endl;
			for (int p=0;p<vec3.size();p++)
	cout<<vec3[p]<<" ";
			cout<<endl;



system ("pause");
return 0;
}
