//L20-1186

#include <iostream>
#include <string>
#include<fstream>
#include<list>
#include<stdio.h>
using namespace std;


class Customer {
private:
	int CustomerID;
	string Name;
	string Address;
	string Contact;
	int No_of_itemsBought;
	int No_of_Returns;
	int LoyaltyCardId;
	string Password;
	int LoyaltyPoints;
public:

	Customer() {
		this->CustomerID = 0;
		this->Name = '\0';
		this->Address = '\0';
		this->Contact = '\0';
		this->No_of_itemsBought = 0;
		this->No_of_Returns = 0;
		this->Password = '\0';
		this->LoyaltyCardId = 0;
		this->LoyaltyPoints = 0;
	};
	Customer(Customer& obj) {
		if (obj.getCustomerID() != 0) {
			this->CustomerID = obj.CustomerID;
			this->Name = obj.Name;
			this->Address = obj.Address;
			this->Contact = obj.Contact;
			this->No_of_itemsBought = obj.No_of_itemsBought;
			this->No_of_Returns = obj.No_of_Returns;
			this->Password = obj.Password;
			this->LoyaltyCardId = obj.LoyaltyCardId;
			this->LoyaltyPoints = obj.LoyaltyPoints;
		}
		else
			cout << "Invalid ID";
	};
	void Copy(Customer& obj)
	{
		this->CustomerID = obj.CustomerID;
		this->Name = obj.Name;
		this->Address = obj.Address;
		this->Contact = obj.Contact;
		this->No_of_itemsBought = obj.No_of_itemsBought;
		this->No_of_Returns = obj.No_of_Returns;
		this->Password = obj.Password;
		this->LoyaltyCardId = obj.LoyaltyCardId;
		this->LoyaltyPoints = obj.LoyaltyPoints;

	}
	Customer(int ID, string n, string a, string c, string p) {
		if (ID != 0) {
			this->CustomerID = ID;
			this->Name = n;
			this->Address = a;
			this->Contact = c;
			this->No_of_itemsBought = 0;
			this->No_of_Returns = 0;
			this->LoyaltyCardId = 0;
			this->Password = p;
			this->LoyaltyPoints = 0;
		}
		else
			cout << "Invalid ID";
	};

	void UpdatePoints(int LID)
	{
		int LIP;
		cout << "\n Enter Points to assign: "; cin >> LIP;
		this->LoyaltyPoints = this->LoyaltyPoints + LIP;
	}
	int getLoyaltyPoints()
	{
		return this->LoyaltyPoints;
	}
	int getCustomerID() {
		return this->CustomerID;
	};
	string getName() {
		return this->Name;
	};
	string getAddress() {
		return this->Address;
	};
	string getContact() {
		return this->Contact;
	};
	int getNo_of_itemsBought() {
		return this->No_of_itemsBought;
	};
	int getNo_of_Returns() {
		return this->No_of_Returns;
	};
	int getLoyaltyCardId() {
		return this->LoyaltyCardId;
	};
	string getPassword()
	{
		return this->Password;
	};

	//setters
	void setCustomerID(int i) {
		this->CustomerID = i;
	};
	void setName(string a) {

		this->Name = a;
	};
	void setAddress(string a) {
		this->Address = a;
	};
	void setContact(string a) {
		this->Contact = a;
	};
	void setNo_of_itemsBought(int n) {
		this->No_of_itemsBought = n;
	};
	void setNo_of_Returns(int n) {
		this->No_of_Returns = n;
	};
	void setLoyaltyCardId(int a) {
		this->LoyaltyCardId = a;
	};
	void setPassword(string p)
	{
		this->Password = p;
	};

	void setLoyaltyPoints(int p)
	{
		this->LoyaltyPoints = p;
	};
	void DeleteCustomer(Customer& obj) {
		this->CustomerID = 0;
		this->Name = '\0';
		this->Address = '\0';
		this->Contact = '\0';
		this->No_of_itemsBought = 0;
		this->No_of_Returns = 0;
		this->Password = '\0';
		this->LoyaltyCardId = 0;
		this->LoyaltyPoints = 0;
	};
	void UpdateCustomerINFO() {
		int input;
		cout << "\nWhat do you want to update?\n 1->ID\n 2->Name\n 3->Address\n 4->Contact\n 5->No_of_itemsBought\n 6->No_of_Returns\n 7->LoyaltyCardId \n 8->LoyaltyPoints \n";
		cin >> input;
		if (input == 1)
		{
			int id;
			cout << "Enter new ID  =  ";
			cin >> id;
			this->setCustomerID(id);
		}
		else if (input == 2)
		{
			string name;
			cout << "Enter new name  =  ";
			cin >> name;
			this->setName(name);
		}
		else if (input == 3)
		{
			string add;
			cout << "Enter new address  =  ";
			cin >> add;
			this->setAddress(add);
		}
		else if (input == 4)
		{
			string cont;
			cout << "Enter new contact  =  ";
			cin >> cont;
			this->setContact(cont);
		}
		else if (input == 5)
		{
			int no;
			cout << "Enter new No_of_itemsBought  =  ";
			cin >> no;
			this->setNo_of_itemsBought(no);
		}
		else if (input == 6)
		{
			int no;
			cout << "Enter new No_of_Returns  =  ";
			cin >> no;
			this->setNo_of_Returns(no);
		}
		else if (input == 7)
		{
			int lc;
			cout << "Enter new LoyaltyCard_ID  =  ";
			cin >> lc;
			this->setLoyaltyCardId(lc);
		}
		else if (input == 8)
		{
			int p;
			cout << "Enter new Loyalty Points  =  ";
			cin >> p;
			this->setLoyaltyPoints(p);
		}
	};
	void viewDetails() {
		if (this->CustomerID != 0) {
			cout << "\n~        Details of this customer are following           ~\n";
			cout << "\n Customer ID     =  " << this->CustomerID;
			cout << "\n Password        =  " << this->Password;
			cout << "\n Name            =  " << this->Name;
			cout << "\n Address         =  " << this->Address;
			cout << "\n Contact         =  " << this->Contact;
			cout << "\n loyalty card ID =  " << this->LoyaltyCardId;
			cout << "\n Loyaltypoints   =  " << this->LoyaltyPoints;
			cout << endl;
		}
		else
			cout << "\nThis customer is not registered\n";
	};

};
class User {
private:
	int ID;
	string  Name;
	string Address;
	string Contact;
	int WarningCount;
	string Password;
public:
	User() {
		this->ID = 0;
		this->Name = '\0';
		this->Address = '\0';
		this->Contact = '\0';
		this->WarningCount = 0;
		this->Password = '\0';
	};
	User(User& obj) {
		if (obj.getID() != 0) {
			this->ID = obj.getID();
			this->Name = obj.getName();
			this->Address = obj.getAddress();
			this->Contact = obj.getContact();
			this->WarningCount = obj.getWaningCount();
			this->Password = obj.getPassword();
		}
		else
			cout << "Invalid ID";
	};
	User(int i, string n, string a, string c, string p) {
		if (i != 0) {
			this->ID = i;
			this->Name = n;
			this->Address = a;
			this->Contact = c;
			this->WarningCount = 0;
			this->Password = p;
		}
		else
			cout << "Invalid ID";
	};
	void setID(int i) {
		this->ID = i;
	};
	void setName(string n) {
		this->Name = n;
	};
	void setAddress(string a) {
		this->Address = a;
	};
	void setContact(string c) {
		this->Contact = c;
	};
	void setWarningCount(int c) {
		this->WarningCount = c;
	};
	void setPassword(string p)
	{
		this->Password = p;
	}
	int getID() {
		return this->ID;
	};
	int getWaningCount() {
		return this->WarningCount;
	};
	string getName() {
		return this->Name;
	};
	string getAddress() {
		return this->Address;
	};
	string getContact() {
		return this->Contact;
	};
	string getPassword()
	{
		return this->Password;
	}
	void ViewDetails() {
		if (this->ID != 0) {
			cout << "\n~        Details of this User are following           ~\n";
			cout << "\n User ID         =  " << this->ID;
			cout << "\n Name            =  " << this->Name;
			cout << "\n Address         =  " << this->Address;
			cout << "\n Contact         =  " << this->Contact;
			cout << "\n Warning Count   =  " << this->WarningCount;
			cout << "\n Password        =  " << this->Password;
			cout << endl;
		}
		else
			cout << "\nThis User is not registered\n";
	}
	void delete_() {
		this->ID = 0;
		this->Name = '\0';
		this->Address = '\0';
		this->Contact = '\0';
		this->WarningCount = 0;
		this->Password = '\0';
	}
};

//------------------------Functions-------------------------------------
Customer* cust_check_for_login(int id)
{
	//READING DATA FROM FILE
	ifstream fin;
	fin.open("Customer.txt", ios::in);
	//Reading no# of customers
	int input;
	fin >> input;
	int customer_total = input;
	Customer* cust = new Customer[customer_total];
	if (fin) {
		/*
		ASSUMPTION : DATA IN CUSTOMER FILE WILL BE IN THE ORDER:
		 total number of Customers(next line)
		 ID name address contact password   TotaoNumberOfItemsBought  TotaoNumberOfItemsReturn LoyaltyCardID LOyaltyPoints */
		int i = 0;
		while (i < customer_total) {


			//Reading customer id
			Customer obj;
			fin >> input;
			obj.setCustomerID(input);

			//Reading name
			string a;
			fin >> a;
			obj.setName(a);

			//reading address
			fin >> a;
			obj.setAddress(a);

			//reading Contact
			fin >> a;
			obj.setContact(a);

			//Reading password
			fin >> a;
			obj.setPassword(a);

			//reading total no of items bought
			fin >> input;
			obj.setNo_of_itemsBought(input);

			//reading total no of items return
			fin >> input;
			obj.setNo_of_Returns(input);

			//reading loyalty card id
			fin >> input;
			obj.setLoyaltyCardId(input);

			//reading loyaltypoints
			fin >> input;
			obj.setLoyaltyPoints(input);

			cust[i] = obj;
			i++;

		}
		fin.close();

		// Checking either customer is registered
		for (int i = 0; i < customer_total; i++)
		{
			if (cust[i].getCustomerID() == id)
				return &cust[i];
		}
		return nullptr;

	}
	else
	{
		cout << "\nFile did not open"; return nullptr;
	}




}
void Customer_login(int id, string p)
{
	//READING DATA FROM FILE

	ifstream fin;
	fin.open("Customer.txt", ios::in);
	if (fin) {
		/*
		ASSUMPTION : DATA IN CUSTOMER FILE WILL BE IN THE ORDER:
		 total number of Customers(next line)
		 ID name address contact password   TotaoNumberOfItemsBought  TotaoNumberOfItemsReturn LoyaltyCardID LOyaltyPoints */

		//Reading no# of customers
		int input;
		fin >> input;
		int customer_total = input;
		Customer* cust = new Customer[input];
		int i = 0;
		while (i < customer_total) {


			//Reading customer id
			Customer obj;
			fin >> input;
			obj.setCustomerID(input);

			//Reading name
			string a;
			fin >> a;
			obj.setName(a);

			//reading address
			fin >> a;
			obj.setAddress(a);

			//reading Contact
			fin >> a;
			obj.setContact(a);

			//Reading password
			fin >> a;
			obj.setPassword(a);

			//reading total no of items bought
			fin >> input;
			obj.setNo_of_itemsBought(input);

			//reading total no of items return
			fin >> input;
			obj.setNo_of_Returns(input);

			//reading loyalty card id
			fin >> input;
			obj.setLoyaltyCardId(input);

			//reading Loyalty Points
			fin >> input;
			obj.setLoyaltyPoints(input);

			cust[i] = obj;
			i++;

		}
		fin.close();

		/*for (int i = 0; i < customer_total; i++)
			cust[i].viewDetails();*/

		//other checks

		Customer* obj = cust_check_for_login(id);
		if (obj)
		{   //CORRECT PASSWORD
			if (p == obj->getPassword())
			{
				string z;
				cout << "\nLogged in Successfully\n";
			}
			else  //INCORRECT PASSWORD
			{
				string a;
				cout << "\n Incorrect Password\n";
				cout << "\n Forgot Password?  [y/n]   "; cin >> a;

				if (a == "y")//CHANGE PASSWORD
				{
					string b;
					cout << "\n Change password ";
					cout << "\n Enter new Password  =   "; cin >> b;
					obj->setPassword(b);
					cout << "\n Saving your new password";
					//Write update password int the file
					ofstream fout;
					fout.open("Customer.txt", ios::out|ios::trunc);
					if (fout)
					{
/*
ASSUMPTION : DATA IN CUSTOMER FILE WILL BE IN THE ORDER:
 total number of Customers(next line)
 ID name address contact password   TotaoNumberOfItemsBought  TotaoNumberOfItemsReturn LoyaltyCardID LOyaltyPoints */

						//write total number of customers
						fout << customer_total;
						fout << "\n";
						for (int i = 0; i < customer_total; i++)
						{

							fout << cust[i].getCustomerID();
							fout << " ";
							fout << cust[i].getName();
							fout << " ";
							fout << cust[i].getAddress();
							fout << " ";
							fout << cust[i].getContact();
							fout << " ";
							if (id == cust[i].getCustomerID())
							{
								fout << b;
							}
							else
								fout << cust[i].getPassword();
							fout << " ";
							fout << cust[i].getNo_of_itemsBought();
							fout << " ";
							fout << cust[i].getNo_of_Returns();
							fout << " ";
							fout << cust[i].getLoyaltyCardId();
							fout << " ";
							fout << cust[i].getLoyaltyPoints();
							fout << "\n";
						}

						fout.close();
						cout << "\n Your password has been changed and new password is  '" << b; cout << "'\n";
						//cout << "\n logged in with updated password Password";
						Customer_login(id, b);
					}
					else
						cout << "\nFile not opened!";


				}
				else
				{
					cout << "\n Try again  ";
					string b;
					cout << "\n Enter new Password  =   "; cin >> b;
					Customer_login(id, b);
				}
			}
		}
		else
		{

			int input = 0;
			cout << "\n This Customer is not registered\n\n Press 1 to Create Account    "; cin >> input;
			if (input == 1)
			{
				string n;
				string a;
				string c;
				string pass;
				cout << "\nEnter Details";
				cout << "\nEnter name"; cin >> n;
				cout << "\nEnter address"; cin >> a;
				cout << "\nEnter contact"; cin >> c;
				cout << "\nEnter password"; cin >> pass;
				Customer temp(id, n, a, c, pass);
				customer_total++;
				cout << "\nSaving your data!  ";
				//saving new customers data into the file
				ofstream fout;
				fout.open("Customer.txt", ios::out|ios::trunc);
				if (fout)
				{
/*
ASSUMPTION : DATA IN CUSTOMER FILE WILL BE IN THE ORDER:
 total number of Customers(next line)
 ID name address contact password   TotaoNumberOfItemsBought  TotaoNumberOfItemsReturn LoyaltyCardID LOyaltyPoints */

					//write total number of customers
					fout << customer_total;
					fout << "\n";
					for (int i = 0; i < customer_total - 1; i++)
					{
						fout << cust[i].getCustomerID();
						fout << " ";
						fout << cust[i].getName();
						fout << " ";
						fout << cust[i].getAddress();
						fout << " ";
						fout << cust[i].getContact();
						fout << " ";
						fout << cust[i].getPassword();
						fout << " ";
						fout << cust[i].getNo_of_itemsBought();
						fout << " ";
						fout << cust[i].getNo_of_Returns();
						fout << " ";
						fout << cust[i].getLoyaltyCardId();
						fout << " ";
						fout << cust[i].getLoyaltyPoints();
						fout << "\n";
					}
					fout << temp.getCustomerID();
					fout << " ";
					fout << temp.getName();
					fout << " ";
					fout << temp.getAddress();
					fout << " ";
					fout << temp.getContact();
					fout << " ";
					fout << temp.getPassword();
					fout << " ";
					fout << temp.getNo_of_itemsBought();
					fout << " ";
					fout << temp.getNo_of_Returns();
					fout << " ";
					fout << temp.getLoyaltyCardId();
					fout << " ";
					fout << temp.getLoyaltyPoints();
					fout << "\n";
					fout.close();
					cout << "\n~       Welcome To Our Boutique        ~\n Your Account has been created successfully!\n";
				}
				else
					cout << "\nFile not opened!";			
			}
			else
				return;
		}
	}
	else
	{
		cout << "\nFile did not open"; return;
	}




}

//For Staff
User* user_check_for_login(int id)
{
	//READING DATA FROM FILE
	ifstream fin;
	fin.open("User.txt", ios::in);
	//Reading no# of staff
	int input;
	fin >> input;
	int user_total = input;
	User* user = new User[user_total];
	if (fin) {
/*
ASSUMPTION : DATA IN USER FILE WILL BE IN THE ORDER:
 total number of users(next line)
 ID name address contact password warning count   */
		int i = 0;
		while (i < user_total) {


			//Reading user id
			User obj;
			fin >> input;
			obj.setID(input);

			//Reading name
			string a;
			fin >> a;
			obj.setName(a);

			//reading address
			fin >> a;
			obj.setAddress(a);

			//reading Contact
			fin >> a;
			obj.setContact(a);

			//Reading password
			fin >> a;
			obj.setPassword(a);

			//reading warning counts
			fin >> input;
			obj.setWarningCount(input);
            //storing data in array
			user[i] = obj;
			i++;

		}
		fin.close();

		// Checking either customer is registered
		for (int i = 0; i < user_total; i++)
		{
			if (user[i].getID() == id)
				return &user[i];
		}
		return nullptr;

	}
	else
	{
		cout << "\nFile did not open"; return nullptr;
	}




}
void User_login(int id, string p)
{
	//READING DATA FROM FILE

	ifstream fin;
	fin.open("User.txt", ios::in);
	if (fin) {

		/*
		ASSUMPTION : DATA IN USER FILE WILL BE IN THE ORDER:
		 total number of users(next line)
		 ID name address contact password warning count   */

		//Reading no# of customers
		int input;
		fin >> input;
		int user_total = input;
		User* user = new User[input];
		int i = 0;
		while (i < user_total) {


			//Reading user id
			User obj;
			fin >> input;
			obj.setID(input);

			//Reading name
			string a;
			fin >> a;
			obj.setName(a);

			//reading address
			fin >> a;
			obj.setAddress(a);

			//reading Contact
			fin >> a;
			obj.setContact(a);

			//Reading password
			fin >> a;
			obj.setPassword(a);

			//reading warning counts
			fin >> input;
			obj.setWarningCount(input);

           //Storing data      
			user[i] = obj;
			i++;

		}
		fin.close();

		for (int i = 0; i < user_total; i++)
			user[i].ViewDetails();

			//other checks

		User* obj = user_check_for_login(id);
		if (obj)
		{   //CORRECT PASSWORD
			if (p == obj->getPassword())
			{
				cout << "\nLogged in Successfully\n";
			}
			else  //INCORRECT PASSWORD
			{
				string a;
				cout << "\n Incorrect Password\n";
				cout << "\n Forgot Password?  [y/n]   "; cin >> a;

				if (a == "y")//CHANGE PASSWORD
				{
					string b;
					cout << "\n Change password ";
					cout << "\n Enter new Password  =   "; cin >> b;
					obj->setPassword(b);
					cout << "\n Saving your new password";
					//Write update password int the file
					ofstream fout;
					fout.open("User.txt", ios::out | ios::trunc);
					if (fout)
					{

/*
ASSUMPTION : DATA IN USER FILE WILL BE IN THE ORDER:
 total number of users(next line)
 ID name address contact password warning count   */

						//write total number of customers
						fout << user_total;
						fout << "\n";
						for (int i = 0; i < user_total; i++)
						{

							fout << user[i].getID();
							fout << " ";
							fout << user[i].getName();
							fout << " ";
							fout << user[i].getAddress();
							fout << " ";
							fout << user[i].getContact();
							fout << " ";
							if (id == user[i].getID())
							{
								fout << b;
							}
							else
								fout << user[i].getPassword();
							fout << " ";
							fout << user[i].getWaningCount();
							fout << "\n";
						}

						fout.close();
						cout << "\n Your password has been changed and new password is  '" << b; cout << "'\n";
						cout << "\n login with updated password Password";
						//Customer_login(id, b);
					}
					else
						cout << "\nFile not opened!";


				}
				else
				{
					cout << "\n Try again  ";
					string b;
					cout << "\n Enter new Password  =   "; cin >> b;
					User_login(id, b);
				}
			}
		}
		else
		{

			int input = 0;
			cout << "\n This user is not registered\n\n Press 1 to Create Account    "; cin >> input;
			if (input == 1)
			{
				string n;
				string a;
				string c;
				string pass;
				cout << "\nEnter Details";
				cout << "\nEnter name"; cin >> n;
				cout << "\nEnter address"; cin >> a;
				cout << "\nEnter contact"; cin >> c;
				cout << "\nEnter password"; cin >> pass;
				User temp(id, n, a, c, pass);
				user_total++;
				cout << "\nSaving your data!  ";
				//saving new customers data into the file
				ofstream fout;
				fout.open("User.txt", ios::out | ios::trunc);
				if (fout)
				{
/*
ASSUMPTION : DATA IN USER FILE WILL BE IN THE ORDER:
 total number of users(next line)
 ID name address contact password warning count   */

					//write total number of customers
					fout << user_total;
					fout << "\n";
					for (int i = 0; i < user_total - 1; i++)
					{
						fout << user[i].getID();
						fout << " ";
						fout << user[i].getName();
						fout << " ";
						fout << user[i].getAddress();
						fout << " ";
						fout << user[i].getContact();
						fout << " ";
						fout << user[i].getPassword();
						fout << " ";
						fout << user[i].getWaningCount();
						fout << "\n";
					}
					fout << temp.getID();
					fout << " ";
					fout << temp.getName();
					fout << " ";
					fout << temp.getAddress();
					fout << " ";
					fout << temp.getContact();
					fout << " ";
					fout << temp.getPassword();
					fout << " ";
					fout << temp.getWaningCount();
					fout << "\n";
					fout.close();
					cout << "\n~       Welcome To Our Boutique        ~\n Your Account has been created successfully!\n";
				}
				else
					cout << "\nFile not opened!";
			}
			else
				return;
		}
	}
	else
	{
		cout << "\nFile did not open"; return;
	}




}
int main()
{
	int inp = 0;
	cout << "\n Who are you?\n1->CUSTOMER\n2->STAFF\n Please enter option =  ";
	cin >> inp;
	//-------------------CUSTOMER LOGIN-SIGNUP TEST----------------------------------
	if (inp == 1) {
		int id; string password;
		cout << "\n~        Enter details to login        ~";
		cout << "\nEnter ID            =      "; cin >> id;
		cout << "\nEnter PASSWORD      =      "; cin >> password;
		Customer_login(id, password);
	}
	//-------------------STAFF LOGIN-SIGNUP TEST----------------------------------
	else if (inp == 2) {
		int id; string password;
		cout << "\n~        Enter details to login        ~";
		cout << "\nEnter ID            =      "; cin >> id;
		cout << "\nEnter PASSWORD      =      "; cin >> password;
		User_login(id, password);
	}
	
	system("pause");
}