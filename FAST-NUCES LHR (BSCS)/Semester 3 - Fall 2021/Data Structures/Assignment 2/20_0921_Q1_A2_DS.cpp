// Aisha Muhammad Nawaz 20L-0921 BSCS SECTION 3E1 DATA STRUCTURES ASSIGNEMENT 2 FALL 2021 Question 1

// ***ASSUMPTION** While reading data from html file i assumed data is stored in such a way (when in .txt form) that after and before every closing and opening tag there is space 
#include <iostream>
#include <fstream> // for file handling
#include <string> // to use string data type
#include <stack> // to use STL stack
using namespace std;

int main ()
{
stack <string> s1; // stack to maintain opening tags
string temp="temp"; // to store read data
string n; // to store filename that will be read
cout<<"~~~~~~~~~~~~~~~~~ Welcome! This Program checks whether an html file is well-formed or not. ~~~~~~~~~~~~~~~~~"<<endl<<endl; // For decoration purposes
while(n!="done") // checks all filenames user will enter untill user enters done
{
cout<<"Enter done when done checking all files."<<endl;
cout<<"Enter name of file to be read(eg. abc.html) : "; // file handling (Please note the assumption that data will be stored in the file such that there are spaces before and after opening and closing tags)
cin>>n; // filename input from user
if (n=="done")
	break;
ifstream file;  // to create and open file
file.open(n);

if (file.is_open()==true) // checking if file to be read is found
{
	while(!file.eof())// Loop works till end of file reached
	{
file>>temp; // stores file data till space found

//cout<<temp<<endl; wrote this while coding to ensure correct data is read

if (temp=="<html>"||temp=="<head>"||temp=="<title>"||temp=="<body>"||temp=="<h1>"||temp=="<p>") // Logic to store in stack all opening tags as they come
{
	s1.push(temp);
}
else
	if (temp=="</html>"||temp=="</head>"||temp=="</title>"||temp=="</body>"||temp=="</h1>"||temp=="</p>") // Logic to check corresponding closing tags
	{
		if (temp=="</html>")
		{
		if(s1.top()=="<html>") // if match found, opening tag popped from stack else break as html file is not well-formed
			s1.pop();
			else
			break;
		}
		else
if (temp=="</head>")
		{
		if(s1.top()=="<head>")
			s1.pop();
			else
			break;
}
else
	if (temp=="</title>")
		{
		if(s1.top()=="<title>")
			s1.pop();
			else
			break;
		}
	else
		if (temp=="</body>")
		{
		if(s1.top()=="<body>")
			s1.pop();
			else
			break;
	
		}
		else
			if (temp=="</h1>")
		{
		if(s1.top()=="<h1>")
			s1.pop();
			else
			break;
		}
			else
				if (temp=="</p>")
		{
		if(s1.top()=="<p>")
			s1.pop();
		else
			break;
		}
				
	}			
	
	}
	if (s1.empty()) //if stack empty it means all corresponding closing tags were found so html file is well-formed
	cout<<endl<<"html file is well-formed!"<<endl<<endl;
else
   cout<<endl<<"html file is not well-formed!"<<endl<<endl;
	}
else
	cout<<endl<<"Unable to open file!"<<endl<<endl; // incase file to be read not found
}

/*cout<<"Now printing stack"<<endl<<endl; // For the purposes of checking stack to verify if code works (while coding)
while (!s1.empty())
{
cout<<s1.top()<<endl;
s1.pop();
}*/



system("pause");
return 0;
}

// 4 files I read data from to check my code (Please see to understand my assumption about spaces)

/* 1)
<html>
<head>
<title> Page Title </title>
</head>
<body> <h1> This is a Heading </h1>
<p> This is a paragraph. </p>
</body>
</html>
*/

/* 2)
<html>
<head>
<title> Page Title </title>
</head>
<body> <h1> This is a Heading </h1>
<p> This is a paragraph. </p>
</body>
</p>
</html>
*/

/* 3)
<html>
<head>
<title> Page Title </title>
</head>
<body> <h1> This is a Heading </h1>
<p> This is a paragraph. </p>
</html>
*/

/* 4)
<html>
<head>
<title> Page Title
</head>
</title>
<body> <h1> This is a Heading </h1>
<p> This is a paragraph. </p>
<\body>
</html>
*/