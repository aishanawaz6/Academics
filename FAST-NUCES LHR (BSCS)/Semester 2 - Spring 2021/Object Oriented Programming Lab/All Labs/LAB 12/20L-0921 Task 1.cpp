#include <iostream>
using namespace std;
class Organism 
{
public:
	Organism()
	{
	cout<<"Organism() called"<<endl;
	}
void print()
	{
	cout<<"Specific Message Organism"<<endl;
	}
	~ Organism()
	{
	cout<<"~Organism() called"<<endl;
	}
};
class Animal  : public Organism
{ 

public:
	Animal():Organism()
	{
	cout<<"Animal() called "<<endl;
	}
	void print ()
	{
	cout<<"Specific Message Animal "<<endl;
	}
	~ Animal () 
	{
	cout<<"~Animal() called"<<endl;
	}
};
class Mammal : public Animal
{
public:
	Mammal():Animal()
	{
	
	cout<<"Mammal() called"<<endl;
	}
void print ()
	{
	cout<<"Specific Message Mammal"<<endl;
	}
	~ Mammal () 
	{
	cout<<"~Mammal() called"<<endl;
	}

};
int main () 
{
	cout<<"Creating Objects : "<<endl;
	Organism* a=new Organism;
	a->print();
	Animal* b=new Animal;
	b->print();
	Mammal* m=new Mammal;
	m->print();
		cout<<"Deleting Objects : "<<endl;
	delete a;
	delete b;
	delete m;



system ("pause");
return 0;

}