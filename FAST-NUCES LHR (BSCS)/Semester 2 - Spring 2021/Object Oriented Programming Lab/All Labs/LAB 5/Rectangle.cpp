#include <iostream>
#include "Rectangle.h"
using namespace std;

Rectangle::Rectangle (){
	length=0;
	width=0;

}
Rectangle :: Rectangle(int l,int w){
	length=l;
		width=w;

}
int Rectangle :: getWidth(){
	return width;		
}
int Rectangle:: getLength(){
	return length;
}
void Rectangle:: setLength(int le){
if (le>=0)
	length=le;
else
	cout<<"Entered Length not positive!"<<endl;
}
void Rectangle:: setWidth(int wi){
if (wi>=0)
	width=wi;
else
	cout<<"Entered Width not positive!"<<endl;
}
int Rectangle :: getArea() {
	return length*width;
}
void Rectangle :: rotateRectangle () {

	int temp;
	cout<<" After Rotation of Rectangle"<<endl;
	temp=length;
	length=width;
	width=temp;

}
void Rectangle :: draw (){
for (int i=0;i<length;i++)
{
	for (int j=0;j<width;j++)
	{
		cout<<" * ";
	}
	cout<<endl;
}

}
