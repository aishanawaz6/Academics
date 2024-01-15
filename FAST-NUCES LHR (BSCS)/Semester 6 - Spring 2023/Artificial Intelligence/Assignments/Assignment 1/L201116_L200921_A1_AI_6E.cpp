/*   BSCS 6E1 ARTIFICIAL INTELLIGENCE ASSIGNMENT #1  SPRING 2023
     MEMBERS: FAIQA ADNAN (20L-1116), AISHA MUHAMMAD NAWAZ (20L-0921) 
*/
#include <vector>
#include <iostream>
#include<cstdlib>
#include <time.h>
#include <queue>
#include <stack>

using namespace std;
char Final_[3][3] = { ' ','1','2','3','4','5','6','7','8' };

void copyIt(char org[][3], char newArr[][3]) // For copying one array to another
{
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			newArr[i][j] = org[i][j];
}
struct Node 
{
	char key[3][3]; //Each node's key is a 2-D array
	vector<Node*>child;
};

Node* newNode(char newkey[][3])
{
	Node* temp;
	if(newkey==NULL)
	 temp= NULL;
	else 
	{
		temp = new Node;
		copyIt(newkey, temp->key);
	}
	return temp;
}
bool same(char arr1[][3],char arr2[][3])
	{
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			if (arr1[i][j] != arr2[i][j])
				return false;
  return true;
}
void findBlank(int& row, int& col,char arr[][3]) // SAVES ROW AND COLUMN INDEX OF WHERE BLANK IS CURRENTLY IN VARIABLES row AND col
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (arr[i][j] == ' ')
			{
				row = i;
				col = j;
				break;
			}
		}
	}
}
void printIt(char myarr[][3]) //PRINTS THE WHOLE 2-D ARRAY
{
	if(myarr)
	for (int i = 0; i < 3; i++)
	{
		cout << "                 ";
		for (int j = 0; j < 3; j++)
		{
			cout << myarr[i][j] << ' ';
		}
		cout << endl;
	}
}
stack<Node*>BFSSolution;
struct path
{
	int parentKey=0;
	vector<Node*>solutionPath;
	int printPath()
	{
		if(solutionPath[0])
			BFSSolution.push(solutionPath[0]);
			
		return parentKey;
	}
};
//FUNCTIONS FOR MOVES:
int moveRight(int &r,int&c,char Initial_2[][3]) 
{
	//If next move Right:
	findBlank(r, c, Initial_2);
	if (c + 1 <= 2)
	{
		swap(Initial_2[r][c], Initial_2[r][c + 1]);
		return 1;
	}
	else
		return -1;
}
int moveLeft(int& r, int& c, char Initial_2[][3]) 
{
	//If next move Left
	findBlank(r, c, Initial_2);
	if (c - 1 >= 0)
	{
		swap(Initial_2[r][c], Initial_2[r][c - 1]);
		return 1;
	}
	else
		return -1;
}
int moveUp(int& r, int& c, char Initial_2[][3]) 
{
	//If next move Up
	findBlank(r, c, Initial_2);
	if (r - 1 >= 0)
	{
		swap(Initial_2[r][c], Initial_2[r - 1][c]);
		return 1;
	}
	else 
		return -1;
}
int moveDown(int& r, int& c, char Initial_2[][3]) 
{
	//If next move Down
	findBlank(r, c, Initial_2);
	if (r + 1 <= 2)
	{
		swap(Initial_2[r][c], Initial_2[r + 1][c]);
		return 1;
	}
	else
		return -1;
}

bool contains(queue<Node*> q2, char myArr[][3]) 
{
	queue<Node*> q = q2;
	while (!q.empty()) {
		Node* temp = q.front();
		if(temp!=NULL)
			if (same(temp->key,myArr))
				return true;
		q.pop();
	}
	return false;
}
void printQ(char array[][3])
{
	for(int i=0;i<3;i++)
	{
		for (int j=0;j<3;j++)
		{
			cout<<array[i][j]<<" ";
		}
		cout<<endl;
	}
}
int generatedNodes = 0;
void Bfs(Node *myRoot) {

	if (myRoot == NULL)
		return;

	generatedNodes++;//For root
	queue<Node*>myQ;
	queue<Node*>visited;
	int totalStates = 0;
	int pkey = 0;

	myQ.push(myRoot);
	path *solutionP=new path[10000];

	// Successor function (Actions): Move blank Tile: Left, Right, up, down
	int r = 0, c = 0; //To maintain the position of blank
	int level = -1;
	while (!myQ.empty())
	{
		
		int discard = 0;
		int size = myQ.size();
		int stop = 0;
		level++;
		cout << "LEVEL " << level << " ->" << endl;
		while (size > 0)
		{
			discard = 0;
			Node* deQ = myQ.front();
			myQ.pop();
			pkey++;
	
				if (deQ != NULL) //IF NOT NULL
				{

					if (contains(visited, deQ->key) || contains(myQ, deQ->key))
					{
						discard = 1;
						generatedNodes--;
					}
					if(discard==0) //If not already generated state
					{
			         
						printIt(deQ->key); //Print state
					
					  if (same(deQ->key, Final_) == true) //Stop right here if it is goal state
					  {
						  cout << "GOAL STATE FOUND ON LEVEL "<<level << endl;
						  cout << "Total states generated: " <<generatedNodes << endl;
						  cout << "Path Cost: " << level << endl;
						  cout << "SOLUTION PATH: " << endl;
					
						  BFSSolution.push(deQ);


						  cout << "->" << endl;
						  int nxt=solutionP[pkey-1].printPath();
							  
							  
							  if(nxt>1)
							  while (true)
							  {
								  
								  nxt = solutionP[nxt].printPath();

								  if (nxt<=1)
									  break;
							  }
							  while (!BFSSolution.empty())
							  {
								  Node* sol = BFSSolution.top();
								  if(sol)
								  printIt(sol->key);
								  cout << "->" << endl;
								  BFSSolution.pop();
							  }
						  stop = 1;
						  break;
					  }
					 
					//Expand it further
					char tempLeft[3][3];
					copyIt(deQ->key, tempLeft);
					if (moveLeft(r, c, tempLeft) == 1)
					{
						(deQ->child).push_back(newNode(tempLeft));
					
						if (!(contains(visited, tempLeft) || contains(myQ, tempLeft)))
						{
							generatedNodes++;
						}
						totalStates++;
						(solutionP[totalStates].solutionPath).push_back(newNode(deQ->key));
						solutionP[totalStates].parentKey = pkey;
					}
					
					char tempRight[3][3];
					copyIt(deQ->key, tempRight);
					if (moveRight(r, c, tempRight) == 1)
					{
						(deQ->child).push_back(newNode(tempRight));
						

						if (!(contains(visited, tempRight) || contains(myQ, tempRight)))
						{
							generatedNodes++;
						}
							totalStates++;
						
						(solutionP[totalStates].solutionPath).push_back(newNode(deQ->key));
						solutionP[totalStates].parentKey = pkey;
					}
					

					char tempUp[3][3];
					copyIt(deQ->key, tempUp);
					if (moveUp(r, c, tempUp) == 1)
					{
						(deQ->child).push_back(newNode(tempUp));
						

						if (!(contains(visited, tempUp) || contains(myQ, tempUp)))
						{
							generatedNodes++;
						}
							totalStates++;
						
						
						(solutionP[totalStates].solutionPath).push_back(newNode(deQ->key));
						solutionP[totalStates].parentKey = pkey;
					}
					
					char tempDown[3][3];
					copyIt(deQ->key, tempDown);
					if (moveDown(r, c, tempDown) == 1)
					{
						(deQ->child).push_back(newNode(tempDown));

						if (!(contains(visited, tempDown) || contains(myQ, tempDown)))
						{
							generatedNodes++;
						}
							totalStates++;
							
						
						(solutionP[totalStates].solutionPath).push_back(newNode(deQ->key));
						solutionP[totalStates].parentKey = pkey;
					}
					
					
					for (int i = 0; i < deQ->child.size(); i++) //Put its children in tree
						myQ.push(deQ->child[i]);

					
				
						visited.push(deQ); // Mark it visited
						cout << endl;
				  }
				 
				}
				size--;
			
		}
		cout << endl;
		if (stop == 1)
			break;

	}
}
int countofNodes = 0;
void DFS(Node*myRoot)
{
	
	
		if(myRoot==NULL)
			return;

		stack<Node*>mystack;
		queue<Node*>visited;

		mystack.push(myRoot);
		int r=0;int c=0;
		int level=-1;
		
		int totalcost=0;
		while(!mystack.empty())
		{
			int discard=0;
			int size=mystack.size();
			int stop=0;

			while(size>0)
			{
				discard=0;
				Node*check=mystack.top();
				check->child.clear();
				mystack.pop();
				countofNodes++;
				if(check!=NULL)
				{
					
						level++;
						cout<<"Level: "<<level<<endl;
						printIt(check->key);
						if(same(check->key,Final_)==true)
						{
							cout<<"Goal State Found On Level:"<<level<<endl;
							Node*print=visited.front();
							cout<<"Overall States generated: "<<countofNodes<<endl;
							cout<<"Final Solution Path"<<endl;
							while(!visited.empty())
							{
								print=visited.front();
								printQ(print->key);
								cout<<"  |"<<endl;
								cout<<"  V"<<endl;
								visited.pop();
							}
							printQ(check->key);
							cout<<endl;
							cout<<"Total Path Cost:"<<level<<endl;
							stop=1;
							break;

						}
						char left[3][3];
						copyIt(check->key,left);
						if(moveLeft(r,c,left)==1)
						{
							if(contains(visited,left)==false)
							{
								(check->child).push_back(newNode(left));
								countofNodes++;
							}
						}
						char right[3][3];
						copyIt(check->key,right);
						if(moveRight(r,c,right)==1)
						{
							if(contains(visited,right)==false)
							{
								(check->child).push_back(newNode(right));
								countofNodes++;
							}
						}

						char up[3][3];
						copyIt(check->key,up);
						if(moveUp(r,c,up)==1)
						{
							if(contains(visited,up)==false)
							{
								(check->child).push_back(newNode(up));
								countofNodes++;
							}
						}
						char down[3][3];
						copyIt(check->key,down);
						if(moveDown(r,c,down)==1)
						{
							if(contains(visited,down)==false)
							{
								(check->child).push_back(newNode(down));
								countofNodes++;
							}
						}
						if(check->child.size()<=0)
							level--;
						
					
						for(int i=check->child.size()-1;i>=0;i--)
						{
							mystack.push(check->child[i]);
						}
						visited.push(check);
					}
				}
				size--;
			
			if(stop==1)
				break;
		}
}

int countofNodes2 = 0;
bool new_ids(Node*myRoot,int limit)
{
	cout<<"Limit"<<limit<<endl;
	int stop=0;
	for(int i=0;i<=limit;i++)
	{
		countofNodes2 = 0;
		
		int r=0,c=0;

		queue<Node*>visited;
		stack<Node*>mystack;
		vector<int>mylevel;
	
		
		mystack.push(myRoot);
		mylevel.insert(mylevel.begin(),0);
		while(!mystack.empty())
		{
			Node*check=mystack.top();
			mystack.pop();
			countofNodes2++;
			int level=mylevel.front();
		
			if(same(check->key,Final_))
			{
				cout<<"Level: "<<level<<endl;
				printIt(check->key);
				cout<<"Goal Found on Level:"<<level<<endl;
				stop=1;
				cout<<"Total Nodes Generated:"<<countofNodes2<<endl;
				cout<<"Total Cost:"<<level<<endl;
				Node*print=visited.front();
				cout<<"Final Solution Path"<<endl;
				while(!visited.empty())
				{
					print=visited.front();
					printQ(print->key);
					cout<<"  |"<<endl;
					cout<<"  V"<<endl;
					visited.pop();
				}
				printQ(check->key);
				return true;
				break;
			}
			if(level==i)
			{
				cout<<"Level:"<<level<<endl;
				if (i==0)
				{
					printIt(check->key);
					break;
				}

				bool flag=false;
				for(int i=0;i<mylevel.size();i++)
				{
					if(level!=mylevel[i])
						flag=true;
					else
					{
						mylevel.erase(mylevel.begin());
						break;
					}
				}
				if(flag==true)
					break;
				

			}
			if(level<i)
			{
				mylevel.erase(mylevel.begin());
				char left[3][3];
				copyIt(check->key,left);
				if(moveLeft(r,c,left)==1)
				{
					if(contains(visited,left)==false)
					{
						(check->child).push_back(newNode(left));
						mylevel.insert(mylevel.begin(),level+1);
						countofNodes2++;
					}
				}
				char right[3][3];
				copyIt(check->key,right);
				if(moveRight(r,c,right)==1)
				{
					if(contains(visited,right)==false)
					{
						(check->child).push_back(newNode(right));
						mylevel.insert(mylevel.begin(),level+1);
						countofNodes2++;
					}
				}

				char up[3][3];
				copyIt(check->key,up);
				if(moveUp(r,c,up)==1)
				{
					if(contains(visited,up)==false)
					{
						(check->child).push_back(newNode(up));
						mylevel.insert(mylevel.begin(),level+1);
						countofNodes2++;
					}
				}
				char down[3][3];
				copyIt(check->key,down);
				if(moveDown(r,c,down)==1)
				{
					if(contains(visited,down)==false)
					{
						(check->child).push_back(newNode(down));
						mylevel.insert(mylevel.begin(),level+1);
						countofNodes2++;
					}
				}
				for(int i=check->child.size()-1;i>=0;i--)
				{
					mystack.push(check->child[i]);
				}
				for(int i=0;i<check->child.size();i++)
					check->child.clear();

				visited.push(check);
				

			}
			else
			{
				printIt(check->key);
			}
		}
		if(stop==1)
			return true;
		
	}
	return false;
}
void IDS(Node*myRoot)
{
	if(myRoot)
	{
	//Visited, Stack maintain
	int length=0;
	while(true)
	{
		cout<<"LIMIT = "<<length<<endl;
		if(!new_ids(myRoot,length))
			length++;
		else
			break;
	}
	}
}
int getinv(int mYarr[])
{
	int inv = 0;
	for (int i = 0; i < 9 - 1; i++)
		for (int j = i + 1; j < 9; j++)
			if (mYarr[j] && mYarr[i] && mYarr[i] > mYarr[j])
				inv++;
	return inv;
}

bool isSolvable(char value[3][3])
{
	int puzzle[3][3];
	// convert from ASCII digit to integer
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (value[i][j] == '1')
				puzzle[i][j] = 1;
			else
				if (value[i][j] == '2')
					puzzle[i][j] = 2;
				else
					if (value[i][j] == '3')
						puzzle[i][j] = 3;
					else
						if (value[i][j] == '4')
							puzzle[i][j] = 4;
						else
							if (value[i][j] == '5')
								puzzle[i][j] = 5;
							else
								if (value[i][j] == '6')
									puzzle[i][j] = 6;
								else
									if (value[i][j] == '7')
										puzzle[i][j] = 7;
									else
										if (value[i][j] == '8')
											puzzle[i][j] = 8;
										else
											puzzle[i][j] = 0;

		}
	}

	int co = getinv((int*)puzzle);

	return (co % 2 == 0);
}


int main()
{
	srand(time(0));
	char Final_2[3][3];  //Will be used to generate random intial state configuration

	char Initial_[3][3];

/*	
//THIS CODE WAS TO GENERATE RANDOM INTIAL STATE

//Creating Intial State..
	do {
		cout << "Generating random intial state..." << endl;
		//Making a second copy of original final goal state configuration
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				Final_2[i][j] = Final_[i][j];


		
		/*int row, col;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				row = rand() % (2 + 1 - 0) + 0; //Random row and column indexes generated between 0 and 2
				col = rand() % (2 + 1 - 0) + 0;

				if (Final_2[row][col] != '-') // If cell already not copied from
				{
					Initial_[i][j] = Final_2[row][col];
					Final_2[row][col] = '-';
				}
				else
					j--; //Generate again incase a combination of row and col already copied from comes again
			}
		}
	} while (!isSolvable(Initial_));
	
		//Will be used to generate moves from intial state configuration
	char Initial_2[3][3];
	//Making a second copy of original Initial goal state configuration
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			Initial_2[i][j] = Initial_[i][j];
	
	*/
	
	//Uncomment an array to check solution
	//char Initial_2[3][3]={'1',' ','2','3','4','5','6','7','8'};	//dfs with sol on level 1
	char Initial_2[3][3] = { '3','1','2','4',' ','5','6','7','8' };	//dfs with sol on level 2
	//char Initial_2[3][3]={'3','1','2','4','5',' ','6','7','8'};	//dfs with sol on level 3
	cout << "Printing 8-Tile Puzzle..." << endl;
	cout << "GOAL STATE(FIXED):" << endl;
	printIt(Final_);
	cout << endl << "INITIAL STATE:" << endl;
	printIt(Initial_2);




			

	Node* myRoot1 = newNode(Initial_2);
	cout << endl<<"                ~~~~~~~~~~~          USING BFS TRAVERSAL           ~~~~~~~~             " << endl;
 Bfs(myRoot1);
	
	cout << endl<<endl<<"                ~~~~~~~~~~~          USING DFS TRAVERSAL           ~~~~~~~~             " << endl;
	Node* myRoot2 = newNode(Initial_2);
		DFS(myRoot2);

	cout << endl<<endl<<"                ~~~~~~~~~~~          USING IDS TRAVERSAL           ~~~~~~~~             " << endl;
	Node* myRoot3 = newNode(Initial_2);
	IDS(myRoot3);

	cout <<endl<<"                                      ~~~ IN CONCLUSION  ~~~                   " << endl;
	int minNodes=min(countofNodes, countofNodes2);
	minNodes = min(minNodes, generatedNodes);

	cout <<"                          MINIMUM NUMBER OF NODES GENERATED ARE: " << minNodes << endl;
	     
	if(minNodes== generatedNodes)
	cout <<"                          HENCE, THE LEAST NUMBER OF NODES IS GENERATED BY BFS TRAVERSAL" << endl;
	else
		if (minNodes == countofNodes)
			cout <<"                          HENCE, THE LEAST NUMBER OF NODES IS GENERATED BY DFS TRAVERSAL" << endl;
	else
	    if (minNodes == countofNodes2)
	cout <<"                          HENCE, THE LEAST NUMBER OF NODES IS GENERATED BY IDS TRAVERSAL" << endl;

	system("pause");
	return 0;
}