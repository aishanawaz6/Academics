// Aisha Muhammad Nawaz 20L-0921 BSCS FALL 2021 SECTION 3E1 DATA STRUCTURES ASSIGNMENT # 4
#include <iostream>
#include <vector>
#include <queue>
#include<string>
using namespace std;


//part (a) functions
template <typename k, typename v>
struct Node {
	k key;
	v value;
Node<k,v>*lchild;
Node<k,v>*rchild;
Node()
{
lchild=nullptr;
rchild=nullptr;
}
Node(k k, v v)
{	
	key=k;
	value=v;
	lchild=rchild=nullptr;
}
bool isleaf()
{
return (lchild==nullptr&&rchild==nullptr);
}
};

template <typename k, typename v>
class SpecialBST {

Node<k,v>*root;
int total;
private:
	void deleteAll(Node<k,v>*ptr)
	{if(ptr){

	deleteAll(ptr->lchild);
	deleteAll(ptr->rchild);
	delete ptr;
	}
	}
	void getValuesInOrder(Node<k,v>*ptr, vector<v>*&vec)
	{
		if(ptr)
		{
		getValuesInOrder(ptr->lchild,vec);
			vec->push_back(ptr->value);
		getValuesInOrder(ptr->rchild,vec);
		}
	}
	void getKeysInOrder(Node<k,v>*ptr, vector<k>*&vec)
	{
		if(ptr)
		{
		getKeysInOrder(ptr->lchild,vec);
		vec->push_back(ptr->key);
		getKeysInOrder(ptr->rchild,vec);
		}
	}

	
bool insert(k key, v value, Node<k,v>*&ptr)
{
	if(ptr==nullptr)
	{
	ptr=new Node<k,v>(key,value);
	lastAccessedNode(ptr);
	total++;
	return true;
	}

	if (key<ptr->key)
		return insert(key,value,ptr->lchild);
	else
		if (key>ptr->key)
			return insert(key,value,ptr->rchild);
		else
			if (key==ptr->key)
			{cout<<"Roll Number already exists!"<<endl;
				return false;
			}

}
v const* search(k key, Node<k,v>*ptr,Node<k,v>*&prev)
{
if (ptr==nullptr)
	return nullptr;
else
	if (key<ptr->key)
     {   prev=ptr;
		return search(key,ptr->lchild,prev);
   	}
	else
		if (key>ptr->key)
		{prev=ptr;
			return search(key,ptr->rchild,prev);
		}
		else
	    {prev=ptr;
		return &ptr->value;
		}
}
bool delete_(k key, Node<k,v>*&ptr,Node<k,v>*&prev)
{
	if (ptr==nullptr)
		return false;
	else
		if (key<ptr->key)
		{ prev=ptr;
	     delete_(key,ptr->lchild,prev);
	    }
		else
			if (key>ptr->key)
			{   prev=ptr;
				delete_(key,ptr->rchild,prev);
			}
			else
				if(ptr->key==key)
				{
				//leaf case
					if (ptr->isleaf())
					{
						delete ptr;
						ptr=nullptr;
						total--;
						return true;
					}
					else // only child that exists is left child
						if(ptr->lchild!=nullptr && ptr->rchild==nullptr)
						{
						Node<k,v>*del=ptr;
						ptr=ptr->lchild;
						delete del;
						total--;
						return true;
						}
						else // only child that exists is right child
							if (ptr->rchild!=nullptr && ptr->lchild==nullptr)
							{
							Node<k,v>*del=ptr;
							ptr=ptr->rchild;
							delete del;
							total--;
							return true;
							}
							else
								//both child exists 
							{
								Node<k,v>*suc=ptr->rchild;
while(suc->lchild)
suc=suc->lchild;

ptr->key=suc->key;
ptr->value=suc->value;
delete_(suc->key,ptr->rchild,prev);
total--;
return true;
							}
				
				}
}
public:
SpecialBST()
{
root=nullptr;
total=0;
}

bool insert(k key,v value)
{
	return insert(key,value,root);
}
v const*search (k key)
{
	Node<k,v>*prev=root;
	v const *retv=search(key,root,prev);
	lastAccessedNode(prev);
	return retv;
}
bool delete_(k key)
{
	Node<k,v>*prev=root;
	bool f=delete_(key,root,prev);
	lastAccessedNode(prev);
	return f;
}


vector <v>*getValuesLevelWise()
{
	if(root==nullptr)
		return nullptr;
	vector<v> *vec=new vector<v>;
	queue<Node<k,v>*> q;
	q.push(root);

	

	while(!q.empty())
	{
	Node<k,v>*temp=q.front();
	vec->push_back(temp->value);
	q.pop();
	if(temp->lchild)
		q.push(temp->lchild);
	if(temp->rchild)
		q.push(temp->rchild);
	}

	return vec;
}
vector <k>*getKeysInOrder()
{
	vector<k>*vec=new vector<k>;
	 getKeysInOrder(root,vec);
	 return vec;
}
vector <v>*getValuesInOrder()
{
	vector<v>*vec=new vector<v>;
	 getValuesInOrder(root,vec);
	 return vec;
}

~SpecialBST()
{
deleteAll(root);
total=0;
}

void leftRotate(Node<k,v>*&ptr)
{
	Node<k,v>*x=ptr;
	if(x->rchild==nullptr)
	{
	//cout<<"Left Rotation not possible, right child does not exist of node!"<<endl;
	return;
	}
	Node<k,v>*y=x->rchild;
	Node<k,v>*t1=y->lchild;

	ptr=y;
	y->lchild=x;
	x->rchild=t1;
}
int gettotal()
{
return total;
}
void rightRotate(Node<k,v>*&ptr)
{
Node<k,v>*x=ptr;
if(x->lchild==nullptr)
	{
//	cout<<"Left Rotation not possible, left child does not exist of node!"<<endl;
	return;
	}
Node<k,v>*y=x->lchild;
Node<k,v>*t1=y->rchild;

ptr=y;
y->rchild=x;
x->lchild=t1;
}
void moveToRoot(Node<k,v>*&child,Node<k,v>*&ptr,int&l)
{  
	 if(ptr==nullptr)
		return;

		if(child->key<ptr->key)
	{
		moveToRoot(child,ptr->lchild,l);	
	if(ptr){	
				rightRotate(ptr);
				l--;
					if(l!=0)
					{
						return;
				}
				moveToRoot(ptr,root,l);
	}
	}
	else
		if(child->key>ptr->key)
		{
	moveToRoot(child,ptr->rchild,l);
	if(ptr){
			leftRotate(ptr);
			l--;
			if(l!=0)
				return;
		moveToRoot(ptr,root,l);
	}
		}
			if(child->key==ptr->key)
				return;
	
}
int getLevel(Node<k,v> *node, k key, int level)
{
    if (node == NULL)
        return 0;
 
    if (node -> key== key)
        return level;
 
    int downlevel = getLevel(node -> lchild,key, level + 1);
    if (downlevel != 0)
        return downlevel;
 
    downlevel = getLevel(node->rchild,key, level + 1);
    return downlevel;
}
int getLevel(Node<k,v>*node, k key)
{
    return getLevel(node, key, 0);
}
k getRootKey()
{
	return root->key;
}
void lastAccessedNode(Node<k,v>*&ptr)
{
int l=0;
l=getLevel(root,ptr->key);
moveToRoot(ptr,root,l);
}
void printin()
{
printin(root);
}

};


//part (b) functions

struct NodeStudent // to store data of student except roll number
{ 
string firstName;
string lastName;
int batch;
string department;
float cgpa;
void printstu() // to print data of student except roll number
{
        cout<<"First Name: "<<firstName<<endl;
		cout<<"Last Name: "<<lastName<<endl;
		cout<<"Batch: "<<batch<<endl;
		cout<<"Department: "<<department<<endl;
		cout<<"CGPA: "<<cgpa<<endl;
}
};
class StudentList
{
	SpecialBST<int,NodeStudent>s; // will store everything related to student
public:
	bool exists(int rol)
	{
		NodeStudent const *v=s.search(rol);
		if (v==nullptr)
			return false;
		else return true;
	}
	bool insertNewStudent(int rollNumber, string firstName, string lastName, int batch, string department, float cgpa)
	{
		NodeStudent obj; // will store all the data of student

		if(rollNumber<0)
	{cout<<"Can't enter data. Roll Number not positive!"<<endl;
		return false;
	}
	if(batch<0)
	{
cout<<"Can't enter data. Year/Batch not positive!"<<endl;
		return false;
	}
	if(cgpa>4)
	{
	cout<<"Can't enter data. cgpa cannot be greater than 4!"<<endl;
		return false;
	}
		obj.firstName=firstName;
		obj.lastName=lastName;
		obj.batch=batch;
		obj.department=department;
		obj.cgpa=cgpa;
	return s.insert(rollNumber, obj);
	}
	bool deleteStudent(int rollNumber)
	{
		return s.delete_(rollNumber);
	}
	bool updateStudent(int oldRollNumber, int newRollNumber, string newFirstName, string newLastName, int newBatch, string newDepartment, float newCgpa)
	{
		NodeStudent obj2; // will store all the data of student
		s.delete_(oldRollNumber);
			if(newRollNumber<0)
	{cout<<"Can't enter data. Roll Number not positive!"<<endl;
		return false;
	}
	if(newBatch<0)
	{
cout<<"Can't enter data. Year/Batch not positive!"<<endl;
		return false;
	}
	if(newCgpa>4)
	{
	cout<<"Can't enter data. cgpa cannot be greater than 4!"<<endl;
		return false;
	}
		obj2.firstName=newFirstName;
		obj2.lastName=newLastName;
		obj2.batch=newBatch;
		obj2.department=newDepartment;
		obj2.cgpa=newCgpa;
	
	return s.insert(newRollNumber,obj2);

	}
	void searchStudent(int rol)
	{
		NodeStudent const *found=s.search(rol);
		if(found) // if rollnumber found
		{	
		cout<<"RollNumber: "<<rol<<endl;
		cout<<"First Name: "<<found->firstName<<endl;
		cout<<"Last Name: "<<found->lastName<<endl;
		cout<<"Batch: "<<found->batch<<endl;
		cout<<"Department: "<<found->department<<endl;
		cout<<"CGPA: "<<found->cgpa<<endl;
		}
		else
		{
		cout<<"Student not found!"<<endl;
		}

	}
void printAllStudents() //prints the students in rollnumber-wise sorted order.
{
	
	vector<int>*vec=s.getKeysInOrder(); // to print roll numbers
	vector<NodeStudent>*vec1=s.getValuesInOrder(); // to print rest of data of student
	cout<<"Total Students: "<<s.gettotal()<<endl;

	for(int i=0;i<s.gettotal();i++)
	{
		cout<<"RollNumber: "<<vec->at(i)<<endl;
		vec1->at(i).printstu();
	}
	
}

};

int main ()
{
	// Assignment main code starts here:

	StudentList s;
while(true)
{	
	char in; 
	//MENU
cout<<"Press I to insert a new student."<<endl;
cout<<"Press D to delete a student."<<endl;
cout<<"Press S to search a student by roll number."<<endl;
cout<<"Press U to update the data of a student."<<endl;
cout<<"Press P to print all students sorted by roll number."<<endl;
cout<<"Press E to exit."<<endl;
cin>>in; //takes input

if(in=='I')
{
cout<<"Please enter the data of new student in the order: Roll Number, First Name, Last Name, Batch, Department, CGPA"<<endl;
NodeStudent enter;
int r;
cin>>r>>enter.firstName>>enter.lastName>>enter.batch>>enter.department>>enter.cgpa;
bool flag=s.insertNewStudent(r,enter.firstName,enter.lastName,enter.batch,enter.department,enter.cgpa);

     if (flag==true)
cout<<"New student inserted successfully!"<<endl;
else
	if (flag==false)
		cout<<"New student not inserted. Failed!"<<endl;
}
else
	if(in=='P')
	{
	cout<<"Printing data"<<endl;
	s.printAllStudents();
	}
	else
		if(in=='S')
		{
		cout<<"Please enter the roll number of the student that you want to search:"<<endl;
		int rn;
		cin>>rn;
		s.searchStudent(rn);
		}
		else
			if(in=='U')
			{
				cout<<"Please enter the roll number of the student whose data you want to update:"<<endl;
				int or;
				cin>>or;

				bool f4=s.exists(or);
					if(f4==false)
					{
					cout<<"Roll Number Does Not Exist!"<<endl;
					continue;
					}
				cout<<"Please enter new data of student in this order: Roll Number, First Name, Last Name, Batch, Department, CGPA"<<endl;
int r2;
NodeStudent enter2;
cin>>r2>>enter2.firstName>>enter2.lastName>>enter2.batch>>enter2.department>>enter2.cgpa;
bool f1=s.updateStudent(or,r2,enter2.firstName,enter2.lastName,enter2.batch,enter2.department,enter2.cgpa);
if(f1==true)
	cout<<"Student data updated successfully.!"<<endl;
else{
cout<<"Student data not updated. Failed!"<<endl;
}

			}
			else
				if(in=='D')
				{
				cout<<"Please enter the roll number of the student that you want to delete: "<<endl;
				int rol;
				cin>>rol; 
				bool f; // to check if  deleted 
				f=s.deleteStudent(rol);
				if(f==true)
				cout<<"Student deleted successfully."<<endl;
				else
					cout<<"Student not deleted. Failed."<<endl;
				}
				else
					if(in=='E') // incase of E entered, immediately breaks out of loop
					{
					cout<<"Exit!"<<endl;
					break;
					}
					else // incase of any other key entered, loop starts again. Asking an input once more.
					{
					cout<<"Incorrect Input! Try Again"<<endl;
					}
					cout<<endl;
}
	system("pause");
	return 0;
}