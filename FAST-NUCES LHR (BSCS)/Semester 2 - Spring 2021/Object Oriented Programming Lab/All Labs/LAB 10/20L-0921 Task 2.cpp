#include<iostream>
using namespace std;

class Tyre
{
private:
int* width;
int* aspect_ratio;
int* diameter;
public:
//Constructors, Getters and Destructor
	Tyre ()
	{
	this->width=NULL;
	this->aspect_ratio=NULL;
	this->diameter=NULL;
	}
	Tyre (int wi,int ar,int d)
	{
	this->width=&wi;
	this->aspect_ratio=&ar;
	this->diameter=&d;
	}
int *	getWidth ()
{
return this->width;	
	}
int* getAspect_ratio ()
{
	return this->aspect_ratio;
}
int*getDiameter()
{
	return this->diameter;
}
/*~Tyre ()
{
	delete width;
	delete aspect_ratio;
	delete diameter;
}*/
void PrintTyre()
{
cout<<"Width : "<<*width<<endl;
cout<<"Aspect ratio : "<<*aspect_ratio<<endl;
cout<<"Diameter : "<<*diameter<<endl;
}
};
class Car
{
 private:
int* model;
char* company;
Tyre* t1;
public:
//Constructors, Destructor
	Car ()
	{
		this->model=NULL;
		this->company=NULL;
		this->t1=NULL;
	}
	Car (int md,char *c,Tyre t)
	{
		model=&md;
		this->company=c;
		this->t1=&t;
	}
	void PrintCar()
	{
	cout<<"Model: "<<*model<<endl;
	cout<<"Company: ";
	for (int i=0;*(company+i)!='\0';i++)
	cout<<*(company+i);
	cout<<endl;
	t1->PrintTyre();
	}
	/*~ Car () 
	{
	delete model;
	delete company;
	delete t1;
	}*/
};
int main()
{
	Tyre tNew(12,10,13);
Car cNew(2016,"Honda",tNew);
cNew.PrintCar();

system ("pause");
return 0;

}