//Aisha Muhammad Nawaz 20L-0921 DATA STRUCTURES BSCS FALL 2021 SECTION 3E1 LAB 12 Question 1
#include <iostream>
#include<string>
#include <fstream>
using namespace std;

//Question 1 Design a class that will store a weighted directed graph using adjacency Matrix with following functions.
//1- Count the out-degree of all nodes.  2- Count the in-degree of all nodes.
//3- Print all neighboring vertices of a particular vertex.
//4- Check if two vertices are directly connected if their indices are provided.

class weightedDirectedGraph
{
int **arr;
int size;
public:
	weightedDirectedGraph()
	{
	arr=nullptr;
	size=0;
	}
	weightedDirectedGraph(int s)
	{size=s;
		arr=new int*[s];
		for(int i=0;i<s;i++)
		 arr[i]=new int[s];	

		for (int i=0;i<size;i++) // intializing array to zero
			for(int j=0;j<size;j++)
				arr[i][j]=0;
	}
 void insert(int n1,int n2,int w)
 {
 n1--; // Becuase index starts with zero
 n2--;
 arr[n1][n2]=w; // weight entered
 }
	int outdegree()
	{
		int *count=new int(size);
		for(int i=0;i<size;i++) //Initializing count to zero of all nodes
			count[i]=0;

		for (int i=0;i<size;i++) // counting individually outdegree of each node
		{
		for(int j=0;j<size;j++)
		{
		if(arr[i][j]!=0)
			count[i]++;
		}
		cout<<"Out-degree of "<<i+1<<" is: "<<count[i]<<endl;
		}

		int totalsum=0;
		for (int i=0;i<size;i++) //Counting total out degree of all nodes
		totalsum=totalsum+count[i];
		
		cout<<"TOTAL OUT-DEGREE= "<<totalsum<<endl;

		return totalsum;
	}
	int indegree()
	{
		int *count=new int[size];
		for(int i=0;i<size;i++) //Initializing count to zero of all nodes
			count[i]=0;

		for (int i=0;i<size;i++) // counting individually outdegree of each node
		{
		for( int j=0;j<size;j++)
		{
		if(arr[j][i]!=0)
			count[i]++;
		}
		cout<<"In-degree of "<<i+1<<" is: "<<count[i]<<endl;
		}

		int totalsum=0;
		for (int i=0;i<size;i++) //Counting total out degree of all nodes
		totalsum=totalsum+count[i];
		
		cout<<"TOTAL IN-DEGREE= "<<totalsum<<endl;

		return totalsum;
	}
	void neighboringVertices(int v)
	{
		
		cout<<"Neighbouring Vertices of "<<v<<" are: "<<endl;
		v--; //Because index starts with 0
	cout<<"Outward: ";
		for(int j=0;j<size;j++)
		    {
		if(arr[v][j]!=0)
			cout<<j+1<<" ";
		   }
			cout<<endl<<"Inward: ";
	        for(int j=0;j<size;j++)
		    {
		if(arr[j][v]!=0)
			cout<<j+1<<" ";
		   }
			
		cout<<endl;
}
	
	bool directlyConnected(int i1,int i2)
	{bool flag=false;

	i1--; //Becuase indexes start with 0
	i2--; 
		for (int i=0;i<size;i++) 
		{
			if (i==i1)
		{
		for(int j=0;j<size;j++)
		    {
		if(arr[i][j]!=0&&i2==j)
			flag=true;
		   }
		}

		}


		for (int i=0;i<size;i++) 
		{
			if (i==i2)
		{
		for(int j=0;j<size;j++)
		    {
		if(arr[i][j]!=0&&i1==j)
			flag=true;
		   }
		}

		}

	return flag;
	}
void print()
{
for (int i=0;i<size;i++)
{	for(int  j=0;j<size;j++)
		cout<<arr[i][j]<<" ";
cout<<endl;
}

}

};

int main ()
{

	ifstream file;
	string name;
	cout<<"Enter name of file to read data from (eg. abc.txt): "<<endl;
	cin>>name;


	file.open(name);

	if (file.is_open())
{	// Reading data from file
	int c;
	file>>c; // takes size of adjacency matrix
	
	weightedDirectedGraph obj(c);
	int n1,n2,w;
	while(!file.eof())
	{
	file>>n1;
	file>>n2;
	file>>w;
	obj.insert(n1,n2,w);
	}
	//Till here all data read from file and inserted in obj object

	//Checking function : Count the out-degree of all nodes.
	obj.outdegree();

	//Checking function : Count the in-degree of all nodes.
	obj.indegree();

	//Checking function : Print all neighboring vertices of a particular vertex.
	obj.neighboringVertices(1);
	obj.neighboringVertices(2);
	obj.neighboringVertices(3);
	obj.neighboringVertices(4);
	obj.neighboringVertices(5);

	//Checking function : Check if two vertices are directly connected if their indices are provided 
	cout<<"Are 2 and 4 directly connected?"<<endl;
	if(obj.directlyConnected(2,4))
		cout<<"True!"<<endl;
	else
		cout<<"False!"<<endl;

	cout<<"Are 1 and 3 directly connected?"<<endl;
	if(obj.directlyConnected(1,3))
		cout<<"True!"<<endl;
	else
		cout<<"False!"<<endl;

	cout<<"Are 1 and 5 directly connected?"<<endl;
	if(obj.directlyConnected(1,5))
		cout<<"True!"<<endl;
	else
		cout<<"False!"<<endl;

	cout<<"Are 1 and 4 directly connected?"<<endl;
	if(obj.directlyConnected(1,4))
		cout<<"True!"<<endl;
	else
		cout<<"False!"<<endl;

	cout<<"Are 2 and 3 directly connected?"<<endl;
	if(obj.directlyConnected(2,3))
		cout<<"True!"<<endl;
	else
		cout<<"False!"<<endl;

	}
	else
		cout<<"Unable to open file!"<<endl;




	system("pause");
	return 0;
}