#include <iostream>
#include <conio.h>
using namespace std;

class Animal{

public :
	Animal()
	{
	cout<<"Animal() called!"<<endl;
	}
virtual char* speak()
	{
	
	
	return "speak()called";
	}
	virtual ~Animal()
	{
	cout<<"~Animal() called!"<<endl;
	}


};
class Dog : public Animal
{

public:
	Dog()
	{
	cout<<"Dog() called!"<<endl;
	}
	char* speak()
	{
	
	return "woof!";
	}
	~Dog()
	{
	cout<<"~Dog() called!"<<endl;
	}

};
class Cat : public Animal 
{
public:
	Cat()
	{
	cout<<"Cat() called!"<<endl;
	}
	char* speak()
	{
	
	return "Mew!";
	}
	~Cat()
	{
	cout<<"~Cat() called!"<<endl;
	}


};



class Sheep  : public Animal 
{

public:
	Sheep()
	{
	cout<<"Sheep() called!"<<endl;
	}
	char* speak()
	{
	
	return "bleat!";
	}
	~Sheep()
	{
	cout<<"~Sheep() called!"<<endl;
	}
};
class cows : public Animal {
	public:
	cows()
	{
	cout<<"cows() called!"<<endl;
	}
	char* speak()
	{
	
	return "moo!";
	}
	~cows()
	{
	cout<<"~cows() called!"<<endl;
	}

};
		class horses : public Animal 
		{
		public:
	horses()
	{
	cout<<"Cat() called!"<<endl;
	}
	char* speak()
	{
	
	return "neigh!";
	}
	~horses()
	{
	cout<<"~horses() called!"<<endl;
	}
		
		};


int main ()
{
const int size = 5;
	Animal * myPets[size];
	

	
	

	int i = 0;
while (i<size)
{
	cout << "Press 1 for a Dog and 2 for a Cat, 3 for sheep , 4 for cows,  5 for horses" << endl ;
	switch (getch())
	{
		case '1':
			myPets[i] = new Dog;
			cout << "Dog added at position "<< i <<endl<<endl;
			i++;
			break;
		case '2':
			myPets[i] = new Cat;
			cout << "Cat added at position "<< i <<endl<<endl;
			i++;
			break;
		case '3':
				myPets[i] = new Sheep;
			cout << "Sheep added at position "<< i <<endl<<endl;
			i++;
			break;
case '4':
				myPets[i] = new cows;
			cout << "cows added at position "<< i <<endl<<endl;
			i++;
			break;
			case '5':
				myPets[i] = new horses;
			cout << "horses added at position "<< i <<endl<<endl;
			i++;
			break;
	default:
			cout<<"Invalid input. Enter again." <<endl<<endl;
			break;
	}		
}

for(int i=0; i<size; i++)
		cout << myPets[i]->speak() << endl;

for (int i=0;i<size;i++)
	delete myPets[i];


system("pause");
return 0;
}