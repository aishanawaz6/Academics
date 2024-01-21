#include <iostream>
#include "20L-0921 Operation.h"
using namespace std;

Operation :: Operation (){
	a=1;
	b=1;
	}
	Operation :: Operation (int aa, int bb){

		a=aa;
		b=bb;
	}

	void Operation :: seta  (int a1){
	a=a1;
	}
	void Operation :: setb(int b1){
	b=b1;
	}
	int Operation :: geta (){
	return a;
	}
	int Operation :: getb(){
	return b;
	}
void Operation ::  sum()
	{
	cout<<"sum = "<<a+b<<endl;
	}
	 void Operation ::  difference(){
	cout<<"Difference = "<<a-b<<endl;
	}
void Operation ::  product(){
	cout <<"Product = "<<a*b<<endl;
	}                                  
	void Operation ::  division(){
	
	cout<<"division = "<<a/b<<endl;
	}                                          


	int main () {
	
		Operation one(2,5);
		one.sum();
		one.difference();
		one.product();
		one.division();

		cout <<"---------------------"<<endl;
			Operation two;
				two.sum();
		two.difference();
		two.product();
		two.division();

		cout <<"After Changing : "<<endl;
		two.seta(one.geta());
		two.setb(one.getb());

			two.sum();
		two.difference();
		two.product();
		two.division();

		system ("pause");
		return 0;
	
	
	}