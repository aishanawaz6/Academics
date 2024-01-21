#include <iostream>
using namespace std;

class Student {
char rollNo[8];
	char name[50];
float cgpa;

public:
	Student (char r[],char n[],float c)
	{
		int ri;
		for (ri=0;n[ri]!='\0';ri++)
		this->name[ri]=n[ri];
		this->name[ri]='\0';

		for (int i=0;i<8;i++)
	this->rollNo[i]=r[i];
		this->cgpa=c;
	}
	void print ()
	{
	for(int i=0;name[i]!='\0';i++)
		cout<<this->name[i];
cout<<" (";
for (int j=0;j<8;j++)
	cout<<this->rollNo[j];
cout<<")"<<endl;
	}

	// WE definitely do not need a destructor as nothing is made dynamically.
	float getCGPA(){
	return this->cgpa;
	}
	char* getName(){
	return this->name;}
	
};

class Society {
	char name[50];	
Student* president;	
Student* members[5];
static int currentMembersCount;  //You may keep currentMembersCount in your Society class. Should it be a static data member or non-static? ANS: It should be static becuase its the same for a particular society.
public :
	void incrementCount(){
	currentMembersCount++;
	}
	Society (char nm[])
	{
		int r;
	for (r=0;nm[r]!='\0';r++)
		this->name[r]=nm[r];
	this->name[r]='\0';

	this-> president=NULL;
	for (int i=0;i<5;i++)
	{
	members[i]= NULL;
	
	}
	
	}
	int getcurrentMembersCount()
	{
		return currentMembersCount;
	}
	void PrintInfo ()
	{   
		cout<<"Society Name: ";
		for (int i=0;name[i]!='\0';i++)
		cout<<this->name[i];
	cout<<endl;
	cout<<"President: ";
		if (president!=NULL)
		(*president).print();
		else
			cout<<"Not Available!"<<endl;
		for (int i=0;i<5;i++){
			cout<<"Member "<<i+1<<" : ";
			if (members[i]!=NULL){
		members[i]->print();
			}
			else
				cout<<"Not Avaliable!"<<endl;
			// Print function should give error if member does not exist 

		}
		
		cout<<"Current Members Count : "<<getcurrentMembersCount()<<endl;
	
	}
	// We are keeping the student pointer in society class as each society is joined by a specific student who in turn has thier own informatiom
	// such as name, rollno & cgpa the constructor should make sure pointer are pointing to NULL
	void AppointPresident (Student&obj) 
	{
		for (int i=0;obj.getName()[i]!='\0';i++)
		cout<<obj.getName()[i];
		if (president==NULL)
		{
	if ((obj.getCGPA())>3.00)
	{
		this->president=&obj;
		cout<<" has been appointed as President."<<endl;
	}
	else
		cout<<" cannot be appointed as President. CGPA criteria not met."<<endl;
		}
		else
			cout<<" cannot be appointed as President. President position is NOT vacant."<<endl;
		// Yes we need to add getters
	
	}
	void AddMember (Student&stu)
	{
		
		int ch=0;
		if (this->president==&stu)
		{
			cout<<"President cannot be added in Members list."<<endl;
		}
		else 
		{
			for (int i=0;stu.getName()[i]!='\0';i++)
		cout<<stu.getName()[i];
			int point =0;
			for (int i=0;i<5;i++)
			{
				if (members[i]==&stu)
					point=1;
			}
			if (point!=1){
		for (int i=0;i<5;i++)
		{
	if (this->members[i]==NULL)
	{
			members[i]=&stu;
			cout<<" has been added to members list successfully."<<endl;
			this->incrementCount();
		   ch=1;
		   break;
	}
	}
		if (ch==0)
			cout<<" cannot be added to members list. Member position is NOT vacant."<<endl;
		}
			else
			cout<<" already exists in Members list."<<endl;
	}
		
	
	}


};
int Society :: currentMembersCount=0;

int main (){

Student s1("12L1111", "Hashim Amla", 3.99);
Student s2("13L1121", "Virat Kohli", 3.45);
Student s3("13L1126", "Quinton de Kock", 2.98);
Student s4("14L1361", "Joe Root", 2.99);
Student s5("14L1124", "Martin Guptil", 3.09);
Student s6("15L1314", "Rohit Sharma", 3.19);

Society sports ("Sports");


sports.PrintInfo();
sports.AppointPresident(s3);
sports.AppointPresident(s1);
sports.AppointPresident(s2);

cout << endl << endl << endl;
Student s7("15L1334", "Robert Elen", 2.19);
sports.AddMember(s3);
sports.AddMember(s2);
sports.AddMember(s3);
sports.AddMember(s1);
sports.AddMember(s4);
sports.AddMember(s5);
sports.AddMember(s6);
sports.AddMember(s7);
sports.PrintInfo();

system ("pause");
return 0;
}