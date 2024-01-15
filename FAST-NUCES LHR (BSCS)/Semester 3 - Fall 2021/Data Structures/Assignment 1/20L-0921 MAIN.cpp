// 20L-0921 Aisha Muhammad Nawaz section 3E1 BSCS Assignment 1 DATA STRUCTURES FALL 2021
#include <iostream>
#include "20L-0921.h"
using namespace std;
int main () {


	SortedSet<int> s; 
	//Checking insert function
    s.insert(5);
	s.insert(3);
	s.insert(7);
	s.insert(6);
    s.insert(9);
	cout<<"Original list 1: "<<endl;
	s.print();
	
	// Checking delete function at random indexes
	cout<<"After deleting element at index 1: "<<endl;
	s.deletee(1);
	s.print();

	cout<<"After deleting element at index 3: "<<endl;
	s.deletee(3);// delete at end
	s.print();

	cout<<"After deleting element at index 1: "<<endl;
	s.deletee(1);// delete mid somewhere
	s.print();

	cout<<"After deleting element at index 0: "<<endl;
	s.deletee(0);// delete at head
	s.print();
		

	cout<<"                                     ----------------UNION---------                            "<<endl;


 // Now checking union function
	SortedSet<int> s2;
	s2.insert(1);
	s2.insert(2);
	s2.insert(50);
	s2.insert(4);
	s2.insert(10);
	s2.insert(3);
	cout<<"Original list 2: "<<endl;
	s2.print();
		
	SortedSet<int> s3;
	s3.insert(6);
	s3.insert(11);
	s3.insert(10);
	cout<<"Original list 3: "<<endl;
	s3.print();


	s2.unionn(s3);
	cout<<"After Union->"<<endl;
	s2.print();

	cout<<"                                     ----------------INTERSECT---------                            "<<endl;
	// Now checking intersect function


	SortedSet<int> s4;
	s4.insert(2);
	s4.insert(4);
	s4.insert(8);
	s4.insert(7);
	s4.insert(1);
	cout<<"Original list 4: "<<endl;
	s4.print();
		
	SortedSet<int> s5;
	s5.insert(8);
	s5.insert(1);
    s5.insert(7);
    s5.insert(5);
	s5.insert(3);
	cout<<"Original list 5: "<<endl;
	s5.print();

	s4.intersect(s5);
	cout<<"After instersection->"<<endl;
	s4.print();
	
/*	// Extra (Input from user)

	cout<<"Enter a list size: ";
	int sz;
	int d;
	cin>>sz;
	SortedSet<int> e;
	cout<<"Enter elements: "<<endl;
	for (int i=0;i<sz;i++)
	{	cin>>d;
		e.insert(d);
	}
	cout<<"Printing your list..."<<endl;
	e.print();
	
	*/



system("pause");
return 0;
}