#include <iostream>
#include <fstream>
using namespace std;
class Voter 
{
private:
 static int totalvotes;
	int id;
	int votes;
	char*name;
	char* CNIC;
public:
	Voter() // Default Constructor
	{
	id=0;
	votes=0;
	this->name=new char[15];
	this->CNIC=new char [5];
	}
	Voter(int id,char*name,char* CNIC,int votes) //Parameterized Constructor
	{
	this->id=id;
	this->name=name;
	this->CNIC=CNIC;
	this->votes=votes;
	
	}
	// SETTERS-------------->
	void setid(int i) // Setter for id
	{
	this->id=i;
	}
	void setname(char*n)// Setter for name
	{
		
	this->name=n;
	}
	void setCNIC(char* C_N_I_C) //Setter for CNIC
	{
		this->CNIC=C_N_I_C;
	}
	void setVotes(int votes) // Setter for votes
	{
	this->votes=votes;
	}
	//GETTERS --------------------->
	int getid () // Getter for id
	{
	return this->id;
	}
	char* getname() // Getter for name
	{
	return this->name;
	}
	char* getCNIC () // Getter for CNIC
	{
		return this->CNIC;
	}
	int getvotes () 
	{
		return this->votes;
	}
	static  int gettotalvotes() // Function to get total votes casted by a voter
	{
		totalvotes++;
	return totalvotes;
	}
	~Voter () // Destructor
	{
	delete name;
	name=NULL; 
	delete CNIC;
	CNIC=NULL;
	}
	friend bool castvote(char* filename,int id);
	void print() 
	{
		cout<<"------------------------->"<<endl;;
		cout<<"id: "<<(char)this->id<<endl;
		cout<<"name: "<<this->name<<endl;
		cout<<"CNIC: "<<this->CNIC<<endl;
		  cout<<"Total Votes of ID "<<(char)this->id<<" is: "<<this->votes<<endl; 
		  cout<<"------------------------->"<<endl;
	}

	
};
int Voter:: totalvotes=0;
bool castvote(char* filename,int id)
{

  //---------------------------- CODE FOR DISPLAYING Political Parties --------------------------------------->
	char nw;
 ifstream s;
  s.open(filename);
  while (!s.eof())
  {
	  s.get(nw);
      cout<<nw;
  }
  cout<<endl;
  s.close();
  //-------------------------------------------------------------------------------------------------------------->

 // Creating a 2D dynamic array to store data of VotersList.txt
  char **list=new char *[6];
   for (int i=0;i<6;i++)
	   list[i]=new char [25];
   // Storing data from VotersList.txt
ifstream l;
  l.open("VotersList.txt");
  Voter v[5];
   
  for( int i=0;!l.eof();i++)
 {
	  
   l.seekg(0,ios::cur)>>list[i]; 
   if (i>0)
   {
 v[i-1].id=list[i][0];

 int a2=0;
   for (int a=2;list[i][a]!=',';a++,a2++)
   { 
	v[i-1].name[a2]=list[i][a]; 
	v[i-1].name[a2+1]='\0';
  for (int j=a+2,j2=0;j2<4;j++,j2++)
  {
        v[i-1].CNIC[j2]=list[i][j];
		v[i-1].CNIC[j2+1]='\0';
  }
   }
  }
  }
  l.close();
  // Done storing data from VotersList.txt

  // Now taking input/vote from user
  int vo,num,flag=-1;
 while (id!=-1)
 {
 cout<<"Please enter ID: ";
  cin>>id;
  if (id==-1)
	  break;
 // Finding whether user-entered id exists in VotersList.txt
  for (int i=0;i<5;i++)
  {
  if (id==v[i].id-48)
             {  cout<<"ID found!"<<endl;
                flag=i;
               cout<<"How many votes do you wish to cast? ";
			   cin>>num;
			   v[i].votes=num;
                for (int j=0;j<num;j++)
                              {
                               cout<<"Who would you like to vote? (1-3): ";
							   cin>>vo;
							   if (vo<1 || vo>3)
							   {
								   cout<<"Invalid # Please enter again !"<<endl;
								   j--;
							   }
							   else
                                v[i].gettotalvotes();
							   
                              }
                v[i].print();
                break;
             }
  }
    if (flag==-1) // Incase user-entered id is not found
	  cout<<"Sorry Id not found!"<<endl;
 }
Voter m;
 cout<<"total votes from all users= "<<m.gettotalvotes()-1<<endl;

 // Deleting dynamically created array
 for (int i=0;i<5;i++)
	 delete []list[i];
 delete []list;
 list =NULL;
  return true;
}

int main ()
{
	char*filename=new char[50];
	cout<<"Enter Filename: ";
	cin.getline(filename,50);
	cout<<filename<<endl;

	Voter v;
castvote(filename,0);

	// code to test rest of functions
	char *CNIC=new char [5];
	CNIC[0]='1',CNIC[1]='2',CNIC[2]='3',CNIC[3]='4',CNIC[4]='\0';

	char *Name=new char [4];
	Name[0]='L',Name[1]='O',Name[2]='L',Name[3]='\0';

	Voter a1;
	a1.setCNIC(CNIC);
	a1.setname(Name);
	a1.setVotes(9);
	a1.setid(49);
	a1.print();

 
	

system("pause");
return 0;
}