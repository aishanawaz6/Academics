#pragma once
#include <iostream>
#include "Rectangle.h"
using namespace std;


void Rectangle:: area_calculator ()
{
cout<<"Area : "<<height*width<<endl;
}
void Rectangle:: area_calculator (float heightn, float widthn)
{
cout<<"Area : "<<heightn*widthn<<endl;
}
Rectangle :: Rectangle (float h,float w)
{
height=h;
width=w;

}
Rectangle :: Rectangle ()
{
height=0;
width=0;
}