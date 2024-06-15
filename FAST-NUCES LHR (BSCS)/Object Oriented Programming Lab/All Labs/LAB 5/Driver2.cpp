#include <iostream>
#include "Player.h"
#include <fstream>
using namespace std;
int convert_cstring_to_int(char *temp)
{
	int multiplier = 1;int target = 0;
	for(int i = 0;i<strlen(temp)-1;i++)
	{
		multiplier*=10;
	}
	for(int i = 0;i<strlen(temp);i++)
	{
		target+=(temp[i]-'0')*multiplier;
		multiplier/=10;
	}
	return target;
}


int readfromindextodelimeter(int start,char delimeter,char* alldata,char* &tdata)
{
	
	int size = 10;
	tdata = new char[size];
	int index = start;
	int myi = 0;
	while(alldata[index]!=delimeter)
	{
		if(myi<size-1)
		{
			tdata[myi]=alldata[index];
			index++;myi++;
		}else
		{
			
			char*temp = new char[size+10];
			for(int i = 0;i<size-1;i++)
			{
				temp[i]=tdata[i];
			}
			temp[myi]=alldata[index];
			delete [] tdata;
			tdata = temp;
			index++;
			myi++;
			size+=10;
		}
		if(index==strlen(alldata))
			break;
	}
	tdata[myi]='\0';
	
	return index+1;
}

void readdata(char*filename,Player &obj)
{
	
	int size = 10,index = 0;char* alldata = new char[size];
	ifstream read;
	char temp;
	read.open(filename);
	while(!read.eof())
	{
		read>>noskipws>>temp;
		if(!read.eof())
		{
		  //cout<<temp;
			if(index<size-1)
			{
			    alldata[index]=temp;
				index++;
			}else
			{
				char* tempdata = new char[size+10];
				for(int i = 0;i<size-1;i++)
				{
					tempdata[i]=alldata[i];
				}
				tempdata[index]=temp;
				delete[]alldata;
				alldata = tempdata;
				index++;
				size+=10;
			}
		}
	}
	alldata[index]='\0';
	
	int count = 0,start = 0;char *tdata;
	while(count<5)
	{
		if(count==0)
		{
			start = readfromindextodelimeter(start,';',alldata,tdata);
			obj.setTeamName(tdata);
			
			count++;
			start++;
		}
		else if(count==1)
		{
			start = readfromindextodelimeter(start,';',alldata,tdata);
			obj.setPlayerName(tdata);
			
			count++;
			start++;
		}
		else if(count==2)
		{
			start = readfromindextodelimeter(start,';',alldata,tdata);
			obj.setnumberofinnings(convert_cstring_to_int(tdata));
			delete [] tdata;
			count++;
			start++;
		}
		else if(count==3)
		{
			start = readfromindextodelimeter(start,';',alldata,tdata);
			obj.setnumberofnotouts(convert_cstring_to_int(tdata));
			delete tdata;
			count++;
			start++;
		}
		else if(count==4)
		{
			int innerindex = 0;
			int listsize = 10;
			int *list = new int[listsize];
			int noo = 0;
			while(start!=strlen(alldata)+1)
			{
				if(innerindex<listsize)
				{
					start = readfromindextodelimeter(start,' ',alldata,tdata);
					list[innerindex]=convert_cstring_to_int(tdata);
					delete tdata;
					innerindex++;
					noo++;
				}
				else
				{
					start = readfromindextodelimeter(start,' ',alldata,tdata);
					int *templist = new int[listsize+10];
					for(int i = 0;i<listsize;i++)
					{
						templist[i]=list[i];
					}
					templist[innerindex]=convert_cstring_to_int(tdata);
					delete tdata;
					delete[]list;
					list = templist;
					innerindex++;
					listsize+=10;
					noo++;
				}
			}
			obj.setscorelist(list,noo);
			count++;
		}
	}
	delete[]alldata;
	 
}  
int main () {

	cout<<"------FROM CONSTRUCTOR ALONE-----------"<<endl;
	Player p0;
	p0.print();
		cout<<"-----------USING SETTERS------"<<endl;
	Player p1;
	char*cptr="AISHA";
	p1.setPlayerName(cptr);
	cptr="Introverts";
	p1.setTeamName(cptr);
	p1.setnumberofinnings(5);
	p1.setnumberofnotouts(2);
	int *pp;
	int pp2[5]={1,2,3,4,5};
	pp=pp2;
	p1.setscorelist(pp2,5);
	p1.print();
	cout<<"-------------BELOW FROM FILE----------"<<endl;
	Player *p2= new Player ();
	char* nameoffile="data1.txt";
readdata(nameoffile,*p2);
p2->print();
cout<<"-----------------"<<endl;

Player *p3=new Player ();
nameoffile ="data2.txt";
readdata(nameoffile,*p3);
p3->print();
cout<<"-----------------"<<endl;

p2->Compare(*p3);

delete p2;
delete p3;









	system("pause");
	return 0;

}