#include <iostream>
using namespace std;

class Matrix {
private:
	int rows;
	int cols;
	int**matrix;

public:
	Matrix(); // Default Constructor
	Matrix (int r,int c); // Parameterized Constructor
	Matrix (const Matrix&m); // Copy Constructor
	void inputMatrix(); // To take user input
	void print (); // To Print Matrix 

	void setrows(int rs); // Setter for rows
	void setcols(int cs); // Setter for cols
	int getrows(); // Getter for rows
	int getcols(); // Getter for cols
	void setmatrix (int**m); // Setter for matrix
	int** getmatrix (); // Getter for matrix

	//~Matrix (); // Destructor to deallocate dynamic memory


	void MatrixAddition(Matrix &obj); // Function to find matrix addition
Matrix MatrixMultiplication(Matrix &obj); //Function to find matrix multiplication.                                     
                
Matrix MatrixTranspose(Matrix &obj); //Function to find Matrix Transpose.

	};
//-----------------------------------------------------CLASS FUNCTION DEFINITIONS-----------------------------------------------


Matrix ::Matrix() // Default Constructor
	{
		cout << "Default Constructor Called "<<endl;
	this->rows=0;
	this->cols=0;
	this->matrix= nullptr;
	}

Matrix :: Matrix (int r,int c) // Parameterized Constructor
{
	cout <<"Parameterized Constructor Called"<<endl;

	this->rows=r;
	this->cols=c;

		// Creating a 2-D Array
	this->matrix=new int* [r];
	for (int i=0;i<r;i++)
	{
		this->matrix[i]=new int [c];
	}

	// Intializing the 2-D Array  
	
	for (int i=0;i<r;i++)
	{
		for (int j=0;j<c;j++)
		{
	this->matrix[i][j]=0;
	
		}
	}


}

Matrix :: Matrix (const Matrix & m) // Copy Constructor
{
	cout <<"Copy Constructor Called"<<endl;
	// Copying number of rows & coloumns
	this->rows=m.rows;
	this->cols=m.cols;

	// Creating a 2-D Array according to data copied 
	this->matrix=new int *[this->rows];
	for (int i=0;i<this->rows;i++)
		this->matrix[i]=new int [this->cols];

	// Copying elements of 2-D Array passed as paramater
	for (int i=0;i<m.rows;i++)
	{
		for (int j=0;j<m.cols;j++)
		{
	this->matrix[i][j]=m.matrix[i][j];
		}
	
	}


}
void Matrix:: print () // To Print Matrix
{
	if (this->rows !=0 || this->cols!=0)
	{
		for (int i=0;i<this->rows;i++)
{
	for (int j=0;j<this->cols;j++)
	{
	cout<<this->matrix[i][j]<<" ";
	}
	cout<<endl;
}
	}
	else
		cout <<"Invalid Matrix!"<<endl;
	
}

void Matrix :: setrows(int rs) // Setter for rows
{
	this->rows=rs;
}

void Matrix :: setcols(int cs) // Setter for cols
{
	this->cols=cs;
}
int Matrix:: getrows() // Getter for rows
{
return this->rows;
}
int Matrix:: getcols() // Getter for cols
{
return this->cols;
}

void Matrix:: setmatrix (int**m) // Setter for matrix
{
this->matrix=m;
}
int** Matrix:: getmatrix () // Getter for matrix
{
return this->matrix;
}

/*Matrix :: ~Matrix  () // Destructor to deallocate dynamic memory
{
	cout<<"I am Going to die x_x"<<endl;
	for (int i=0;i<this->rows;i++)
	delete []this->matrix[i];

	delete []this->matrix;
	this->matrix=NULL;

}*/

void Matrix:: MatrixAddition(Matrix &obj) // Function to find matrix addition
{
	if (this->rows==obj.rows && this->cols==obj.cols)
	{

// This function adds the elements of obj and calling object then stores the result in the calling object

		for (int i=0;i<this->rows;i++)
		{
			for (int j=0;j<this->cols;j++)
	        this->matrix[i][j]=obj.matrix[i][j]+this->matrix[i][j];
		}
		cout<<"Matrix has been successfully Added"<<endl;
	}
	else
		cout<<"ERROR! the dimensions of both the matrixes must be equal to ADD them!"<<endl;
		
}
Matrix Matrix ::  MatrixMultiplication(Matrix &obj) //Function to find matrix multiplication.
{
	Matrix ans(this->rows,obj.cols);
	int i1=0,j1=0;
	if (this->cols==obj.rows)
	{

	for (int i=0;i<ans.rows;i++)
	{
	for (int j=0;j<ans.cols;j++)
	{
	for (;j1<this->cols;i1++,j1++)
	{
	ans.matrix[i][j]=this->matrix[i][j1]*obj.matrix[i1][j]+	ans.matrix[i][j];
	}
	i1=0;
	j1=0;
	}
	i1=0;
	j1=0;
	}
	cout<<"Matrix has been successfully Multiplied"<<endl;
	}
else
{	cout<<"Error! For matrix multiplication, the number of columns in the first matrix";
	cout<<" must be equal to the number of rows in the second matrix. "<<endl;
	}
	//The result matrix has the number of rows of the first and the number of columns of the second matrix.
	return ans;
}
void Matrix:: inputMatrix() // To take user input
{ 

	cout<<"Input rows of Matrix : ";
		cin>>this->rows;
	cout<<"Input coloumns of Matrix : ";
	cin>>this->cols;
	
	this->matrix=new int*[this->rows];
	cout<<"Input values of matrix "<<endl;
	for (int i=0;i<this->rows;i++)
	{
	this->matrix[i]=new int [this->cols];
	cout<<"Enter values for row "<<i<<endl;
	for (int j=0;j<this->cols;j++)

		cin>>this->matrix[i][j];
	}




}
Matrix Matrix:: MatrixTranspose(Matrix &obj) //Function to find Matrix Transpose.
{
	
	this->cols=obj.rows;
	this->rows=obj.cols;
	this->matrix=new int*[this->rows];
	for (int i=0;i<this->rows;i++)
	{ 
		this->matrix[i]=new int[this->cols];
		for(int j=0;j<this->cols;j++)
		{
		this->matrix[i][j]=obj.matrix[j][i];
		}

	}


		cout<<"Matrix has been successfully transposed"<<endl;

return *this;
}


//---------------------DRIVER TO TEST THE FUNCTIONS------------------------------------
int main () {


	Matrix m1; // Default Construtor Called
	m1.print();
	Matrix m2(2,2); // Parameterized Construtor Called
	m2.print();
	Matrix m3=m2; //Copy Construcor Called
	m3.print();
	// ----------------------USING SETTERS & GETTERS----------------------------------->
	cout<<"Now using setters & getters "<<endl;
		Matrix m4;
		m4.print();
	m4.setrows(m2.getrows());
	m4.setcols(m2.getcols());
	int**p;
	p=new int* [2];
	for (int i=0;i<m2.getrows();i++)
		*(p+i)=new int [2];
	for (int i=0;i<2;i++)
	{
	for (int j=0;j<m2.getcols();j++)
		p[i][j]=-4+j;
	}

	m4.setmatrix(p);
	m4.print();
	m4.setmatrix(m2.getmatrix());
	m4.print();
	
//----------------------------------------------------------------------------------------------------------------------------->
	cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
	// To test Addition function
	Matrix a1,a2;
	cout<<"Please enter data for two matrixes inorder to add them: "<<endl;
	cout<<"-------------------------------------------Enter 1st Matrix data ------------------------------ "<<endl;
	a1.inputMatrix();
		cout<<"-------------------------------------------Enter 2nd Matrix data ------------------------------ "<<endl;
	a2.inputMatrix();
	cout<<"Now displaying the two entered matrixes--->"<<endl;
	cout<<"Matrix 1---->"<<endl;
	a1.print();
	cout<<"Matrix 2---->"<<endl;
	a2.print();
	a1.MatrixAddition(a2);
	cout<<"Now displaying resultant matrix--->"<<endl;
	a1.print();

	cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
	// TO test multiplication function
Matrix t1,t2;
cout<<"Please enter data for two matrixes inorder to multiply them: "<<endl;
cout<<"-------------------------------------------Enter 1st Matrix data ------------------------------ "<<endl;
t1.inputMatrix();
cout<<"-------------------------------------------Enter 2nd Matrix data ------------------------------ "<<endl;
t2.inputMatrix ();
cout<<"Now displaying the two entered matrixes--->"<<endl;
cout<<"Matrix 1---->"<<endl;
t1.print();
cout<<"Matrix 2---->"<<endl;
t2.print();
Matrix test=t1.MatrixMultiplication(t2);
cout<<"Now displaying resultant matrix--->"<<endl;
test.print();

cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;

// To test transpose function

Matrix tranAns,tran;
cout<<"Enter a matrix to transpose it!"<<endl;
tran.inputMatrix();
cout<<"Showing entered matrix-------->"<<endl;
tran.print();
cout<<"Now displaying resultant matrix--->"<<endl;
tranAns.MatrixTranspose(tran);
tranAns.print();



system ("pause");
return 0;

}