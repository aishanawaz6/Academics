#include <iostream>
#include "20L-0921 Box.h"
using namespace std;
int Box::objectCount=0;

Box :: Box (){
	
length=0.0;
breadth=0.0;
height=0.0;
objectCount++;

}

Box :: Box (double l,double b, double h){
	
length=l;
breadth=b;
height=h;
objectCount++;

}
void Box :: setLength(double l){
	
	length=l;

}
void Box :: setBreadth(double b){
	
	breadth=b;

}
void Box :: setHeight(double h){
	
height=h;

}
double Box :: getLength (){
	
	return length;
	
}
double Box :: getBreadth (){
	return breadth;
}
double Box :: getHeight (){
	return height;

}
void Box :: print () {

	cout<<"Length = "<<length<<endl;
	cout<<"Breadth = "<<breadth<<endl;
	cout<<"height= "<<height<<endl;
}
double Box:: Volume(){
	double v=length*breadth*height;
	return v;

 }

double Box :: Area(){
	double a=length*height;
return a;

}
int Box :: getCount (){

return objectCount;
}

void double_data_members (Box&b){
	b.length=b.length*2;
	b.breadth=b.breadth*2;
	b.height=b.height*2;


}
void print_surface_area (Box &b){
	double SA=2*(b.length*b.breadth+b.length*b.height+b.height*b.breadth);

	cout<<"Surface Area : "<<SA<<endl;
}