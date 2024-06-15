#include <iostream>
#include "Point.h"
using namespace std;

	Point :: Point (int x2,int y2)
	{
		this->x=x2;
		this->y=y2;
	cout<<"Point() called"<<endl;

	}
	
		void Point :: Print1 ()
		{
          cout<<"("<<x<<","<<y<<")"<<endl;
	    }
         Point :: ~Point ()
			{
	          cout<<"~Point() called"<<endl;
	        }