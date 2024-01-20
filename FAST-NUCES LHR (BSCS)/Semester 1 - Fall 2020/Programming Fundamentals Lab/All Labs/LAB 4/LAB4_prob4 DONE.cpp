#include <iostream>
using namespace std;

int main () {
	int c,cb,bct,numofboxes,numofct;
	float leftbox,leftct;
	cout<<"Enter total number of cookies: ";
	cin>>c;
	cout<<"Enter number of cookies in a box: ";
	cin>>cb;
	cout<<"Enter number of cookie boxes in a container: ";
	cin>>bct;

	numofboxes = c/cb;
	numofct = (numofboxes)/bct;
	leftbox= c%cb;
	leftct= numofboxes%bct;
	cout<<"Number of boxes: "<<numofboxes<<" Boxes and "<<leftbox<<" cookies"<<endl;
	cout<<"Number of containers: "<<numofct<<" Containers and "<<leftct<<" Boxes"<<endl;
		
	system("pause");
	return 0;
}