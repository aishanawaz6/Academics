#include <iostream>
#include "Rectangle.h"
using namespace std;

int main() {
	int l,w;
	Rectangle r1;
	r1.draw();
r1.rotateRectangle();
r1.draw();
cout<<"Area of Rectangle 1 = "<<r1.getArea()<<endl;
cout<<"-------------------"<<endl;
Rectangle r2(5,4);
	r2.draw();
r2.rotateRectangle();
r2.draw();
cout<<"Area of Rectangle 2 = "<<r2.getArea()<<endl;
cout<<"-------------------"<<endl;
Rectangle r3;
cout<<"Enter Length: ";
cin>>l;
cout<<"Enter Width: ";
cin>>w;
r3.setLength(l);
r3.setWidth(w);
r3.draw();
r3.rotateRectangle();
r3.draw();
cout<<"Area of Rectangle 3 = "<<r3.getArea()<<endl;
cout<<"-------------------"<<endl;
Rectangle r4;
l=r2.getLength();
w=r2.getWidth();
r4.setLength(l);
r4.setWidth(w);
r4.draw();
r4.rotateRectangle();
r4.draw();
cout<<"Area of Rectangle 4 = "<<r4.getArea()<<endl;

system("pause");
return 0;
}