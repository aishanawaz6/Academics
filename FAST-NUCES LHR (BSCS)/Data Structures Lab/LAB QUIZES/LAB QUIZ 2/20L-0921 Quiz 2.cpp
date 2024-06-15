//20L-0921 Aisha Muhammad Nawaz Section 3E1 BSCS FALL 2021 DATA STRUCTURES Quiz # 2 (20th December 2021)
#include <iostream>
using namespace std;

template <typename k, typename v>
struct Node
{
k rollNumber;
v marks;
Node<k,v>*lchild;
Node<k,v>*rchild;

Node() // Default Constructor
{
	lchild=rchild=nullptr;
}
Node (k roll,v mrks) // Parametrized Constructor
{
rollNumber=roll;
marks=mrks;
lchild=rchild=nullptr;
}

};


template <typename k, typename v>
class BST 
{
	Node<k,v>*root;
	int totalE; // to store total number of students
	int passed; // to store count of students passed

public:
	BST() // Default Constructor
	{
	root=nullptr;
	totalE=0;
	passed=0;
	}
	void insertRecord(k roll, v mrks)
	{
		insertRecord(root,roll,mrks);
	}
	void updateRecord (k r, v nm)
	{
		updateRecord(root,r,nm);
	}
	int countOfPassedStudents() //Both printing and returning count of students passed
    {
	cout<<"Count Of Passed Students = "<<passed<<endl;
	return passed;
   }
	void showData()
	{cout<<"Total Students are: "<<totalE<<" List is as follows: "<<endl;
	showData(root);
	}

private:
	void insertRecord(Node<k,v>*&ptr, k roll, v mrks)
	{
		if(ptr==nullptr)
		{
		ptr=new Node<k,v>(roll,mrks);
		totalE++;
		if(mrks>=50)
			passed++;
		return;
		}

		    if (roll<ptr->rollNumber)
			insertRecord(ptr->lchild,roll,mrks);
		else
			if (roll>ptr->rollNumber)
			insertRecord(ptr->rchild,roll,mrks);
		else
			if(roll==ptr->rollNumber)
			{
			    cout<<"Insertion Failed! Existing Roll Number cannot be inserted again."<<endl;
				return;
			}
	
	}
	void updateRecord(Node<k,v>*&ptr, k roll, v mrks)
	{
		if(ptr==nullptr)
		{
	    cout<<"Update Failed! Roll Number not found."<<endl;
		return;
		}

		if (roll<ptr->rollNumber)
			updateRecord(ptr->lchild,roll,mrks);
		else
			if (roll>ptr->rollNumber)
			updateRecord(ptr->rchild,roll,mrks);
		else
			if(roll==ptr->rollNumber)
			{   
					if(mrks>=50 && ptr->marks<50) // if previous marks were not passing but new ones are passed++
			        passed++;
					if(mrks<50 && ptr->marks>=50) // if previous marks were passing but new ones are not passed--
			        passed--;

			     	ptr->marks=mrks; // updating marks
				    return;
			}
	
	}
	void showData (Node<k,v>*ptr) // To display all the records of BST in preorder traversal.
	{
		if(ptr)
		{
			cout<<"Roll Number: 19L-"<<ptr->rollNumber<<" Marks: "<<ptr->marks<<endl;
			showData(ptr->lchild);
			showData(ptr->rchild);
		}
	}

};


int main ()
{

	BST <int, int>obj; // BST Class object declared

	obj.insertRecord(1941, 71); //Insertions
    obj.insertRecord(1942, 62);
    obj.insertRecord(1943, 67);
    obj.insertRecord(1944, 54);
    obj.insertRecord(1945, 58);
    obj.insertRecord(1946, 45);
    obj.insertRecord(1947, 29);
    obj.insertRecord(1948, 76);
    obj.insertRecord(1949, 81);
    obj.insertRecord(1950, 92);

    obj.updateRecord(1944,47);  // Updating Marks
    obj.updateRecord(1949,85);

    obj.countOfPassedStudents(); // Count of Passed Students

    obj.showData(); // to display all the records of BST in preorder traversal.

	

system("pause");
return 0;
}