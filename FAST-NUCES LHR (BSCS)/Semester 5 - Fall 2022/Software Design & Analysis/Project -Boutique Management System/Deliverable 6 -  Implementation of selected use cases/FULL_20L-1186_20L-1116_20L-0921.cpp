#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <cstdlib>
#include <time.h>
#include <fstream>
#include "myconsole.h"
#include "mygraphics.h"
#include <conio.h>
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
class LoyaltyCard
{
private:
	int LoyaltyId;
	int LoyaltyPoints;
	string DateJoined;
	string DateofLastScan;
	string TimeofScan;
	string Expiry_Date;
	int RFID_no;
	int DiscountVal;
	string CardType;
public:
	Customer cust_obj;
	LoyaltyCard()
	{
		LoyaltyId = 0;
		LoyaltyPoints = 0;
		DateJoined = " ";
		DateofLastScan = " ";
		TimeofScan = " ";
		Expiry_Date = " ";
		RFID_no = 0;
		DiscountVal = 0;
		CardType = " ";
	}
	LoyaltyCard(int LID, int LPoints, int rfid, string CardType, string ExpDate, string DateJoin, int disVal)
	{
		this->LoyaltyId = LID;
		this->LoyaltyPoints = LPoints;
		this->RFID_no = rfid;
		this->CardType = CardType;
		this->Expiry_Date = ExpDate;
		this->DateJoined = DateJoin;
		this->DiscountVal = disVal;
	}
	void setCardType(string s)
	{
		this->CardType = s;
	}
	string getCardType()
	{
		return this->CardType;
	}
	void setLoyaltyID(int id)
	{
		this->LoyaltyId = id;
	}
	void setLoyaltyPoints(int num)
	{
		this->LoyaltyPoints = num;
	}
	void setDateJoined(string date)
	{
		this->DateJoined = date;
	}
	string getDateJoined()
	{
		return this->DateJoined;
	}
	string getExpDate()
	{
		return this->Expiry_Date;
	}
	void setExpiryDate(string expDate)
	{
		this->Expiry_Date = expDate;
	}
	void setRFID(int rfid)
	{
		this->RFID_no = rfid;
	}
	int getRFID()
	{
		return this->RFID_no;
	}
	void setCardDiscount(int DisVal)
	{
		this->DiscountVal = DisVal;
		//cout<<"Customer got a Discount of "<<this->DiscountVal<<" on their Current Card"<<endl;

	}
	int getDiscountVal()
	{
		return DiscountVal;
	}
	virtual void AssignCard(Customer cust_obj, string Datejoined, int val, string Expiry_Date)
	{
		int LID;
		int rfid;
		int Custid;
		//assigning Customer Object 
		Custid = cust_obj.getCustomerID();
		this->cust_obj = cust_obj;

		//Assigning Loyalty ID
		srand(time(0));
		LID = rand();
		this->LoyaltyId = LID;

		//Assigning RFID
		rfid = rand();
		this->RFID_no = rfid;

		//assiging Date Joined
		this->DateJoined = Datejoined;

		//assigning Date Expire
		this->Expiry_Date = Expiry_Date;
	}
	void AssignPoints(int LIP)
	{
		this->LoyaltyPoints = LIP;
	}
	void UpdatePoints(int LID)
	{
		int LIP;
		cout << "Enter Points to Assign: ";
		cin >> LIP;
		this->LoyaltyPoints = this->LoyaltyPoints + LIP;
	}
	int getLoyaltyPoints()
	{
		return this->LoyaltyPoints;
	}
	int getLoyaltyID()
	{
		return this->LoyaltyId;
	}
	Customer* getcustobj()
	{
		return &cust_obj;
	}
	void RedeemPoints(Customer cust_obj, int LID, int LPoints);
	void viewDateofScan(int rfid, Customer cust_obj);
	void EnterCustomer(string ScanTime, Customer cust_obj, string ScanDate);
	void ExitCustomer(string ScanTime, Customer cust_obj, string ScanDate);
	void checkCardValidity(int LID, string ExpDate);
	virtual void printDetails()
	{
		cout << "Card Type:" << this->CardType << endl;
		cout << "Customer ID:" << cust_obj.getCustomerID() << endl;
		cout << "Loyalty Card ID:" << this->LoyaltyId << endl;
		cout << "RFID No:" << this->RFID_no << endl;
		cout << "Loyalty Points:" << this->LoyaltyPoints << endl;
		cout << "Discount Val:" << this->DiscountVal << endl;
		cout << "Date Joined:" << this->DateJoined << endl;
		cout << "Expiry Date:" << this->Expiry_Date << endl;
	}
	virtual void viewDiscounts() {};
	virtual float ApplyDiscounts(float Disval) { return Disval; };
	/*
		virtual void DiscountsUsed(Customer cust_obj, int LID, int Disval);
		virtual void UpdateDiscounts(int LID, int Disval);
		*/
};
class GoldCard :public LoyaltyCard
{
private:
	int GoldId;
public:
	GoldCard()
	{
		GoldId = 0;
	}
	GoldCard(int GID)
	{
		this->GoldId = GID;
	}
	void setGoldID(int GID)
	{
		this->GoldId = GID;
	}
	int getGoldID()
	{
		return this->GoldId;
	}
	void AssignCard(Customer cust_obj, string DateJoin, int val, string expiryDate)
	{
		//Assigning CardType
		this->setCardType("Gold");
		//Assigning ID
		int gid;
		srand(time(0));
		gid = rand();
		setLoyaltyID(gid);

		//Assigning RFID
		int rfid = rand();
		this->setRFID(rfid);

		this->cust_obj = cust_obj;
		//assigning Card Discount
		this->setCardDiscount(val);
		//Assigning Exp Date
		this->setExpiryDate(expiryDate);
		//Assigning Date Join
		this->setDateJoined(DateJoin);
	}
	void viewDiscounts()
	{
		cout << "YOUR GOLD CARD HAS THE FOLLOWING DISCOUNTS: " << endl;
		cout << "---> 20 % off on purchases worth 5000rs or more" << endl;
		cout << "---> 30 % off on purchases worth 10000rs or more" << endl;
	};
	void DiscountsUsed(Customer cust_obj, int GId, int val);
	void UpdateDiscounts(int GID, int val);
	float ApplyDiscounts(float Disval)
	{
		float newdis;
		if (Disval >= 10000)
		{
			newdis = 0.70 * Disval;
			cout << "DISCOUNT APPLIED! 30 % off on purchases worth 10000rs or more" << endl;
		}

		else
			if (Disval >= 5000)
			{
				newdis = 0.80 * Disval;
				cout << "DISCOUNT APPLIED! 20 % off on purchases worth 5000rs or more" << endl;
			}
			else
			{
				cout << "NO CRITERIA SATISFIED CAN'T APPLY DISCOUNT" << endl;
				newdis = Disval;
			}
		return newdis;

	};
	void printDetails()
	{
		cout << "GoldID:" << this->GoldId << endl;
		cout << "RFID:" << this->getRFID() << endl;
		cout << "Loyalty Points:" << this->getLoyaltyPoints() << endl;
		cout << "Discount Value:" << this->getDiscountVal() << "% " << endl;
		cout << "Date Joined:" << this->getDateJoined() << endl;
		cout << "Expiry Date:" << this->getExpDate() << endl;
	}
};
class SilverCard :public LoyaltyCard
{
private:
	int SilverId;
public:
	SilverCard()
	{
		this->SilverId = 0;
	}
	SilverCard(int SID)
	{
		this->SilverId = SID;
	}
	void setSilverID(int id)
	{
		this->SilverId;
	}
	int getSilverID()
	{
		return this->SilverId;
	}
	void AssignCard(Customer cust_obj, string Datejoined, int val, string expDate)
	{
		//assigning card type;
		this->setCardType("Silver");
		//assigning ID

		int sid;
		srand(time(0));
		sid = rand();
		setLoyaltyID(sid);

		this->SilverId = getLoyaltyID();

		//Assigning RFID
		int rfid = rand();
		this->setRFID(rfid);

		this->cust_obj = cust_obj;
		//Assigning Card Discount
		this->setCardDiscount(val);
		//Assigning Expiry Date
		this->setExpiryDate(expDate);
		//Assigning Date Joined
		this->setDateJoined(Datejoined);
	}
	void viewDiscounts()
	{
		cout << "YOUR SILVER CARD HAS THE FOLLOWING DISCOUNTS: " << endl;
		cout << "---> 15 % off on purchases worth 5000rs or more" << endl;
		cout << "---> 20 % off on purchases worth 10000rs or more" << endl;
	};
	void DiscountsUsed(Customer cust_obj, int SId, int val);
	void UpdateDiscounts(int SID, int val);
	float ApplyDiscounts(float Disval)
	{
		float newdis;
		if (Disval >= 10000)
		{
			newdis = 0.80 * Disval;
			cout << "DISCOUNT APPLIED! 20 % off on purchases worth 10000rs or more" << endl;
		}

		else
			if (Disval >= 5000)
			{
				newdis = 0.85 * Disval;
				cout << "DISCOUNT APPLIED! 15 % off on purchases worth 5000rs or more" << endl;
			}
			else
			{
				cout << "NO CRITERIA SATISFIED CAN'T APPLY DISCOUNT" << endl;
				newdis = Disval;
			}
		return newdis;

	};
	void printDetails()
	{
		cout << "SilverID:" << this->SilverId << endl;
		cout << "RFID:" << this->getRFID() << endl;
		cout << "Loyalty Points:" << this->getLoyaltyPoints() << endl;
		cout << "DiscountVal:" << this->getDiscountVal() << "% " << endl;
		cout << "Date Joined:" << this->getDateJoined() << endl;
		cout << "Expiry Date:" << this->getExpDate() << endl;
	}
};
class PlatinumCard :public LoyaltyCard
{
private:
	int PlatinumId;
public:
	PlatinumCard()
	{
		this->PlatinumId = 0;
	}
	PlatinumCard(int PID)
	{
		this->PlatinumId = PID;
	}
	void setPlatinumID(int PID)
	{
		this->PlatinumId = PID;
	}
	int getPlatinumID()
	{
		return this->PlatinumId;
	}
	void AssignCard(Customer cust_obj, string DateJ, int val, string expDate)
	{
		//Assigning Card Type;
		this->setCardType("Platinum");

		//Assigning Card ID
		int pid;
		srand(time(0));
		pid = rand();
		setLoyaltyID(pid);
		this->PlatinumId = this->getLoyaltyID();

		//Assigning RFID
		int rfid = rand();
		this->setRFID(rfid);

		this->cust_obj = cust_obj;
		//Assigning Card Discount
		this->setCardDiscount(val);
		//Assigning Expiry Date
		this->setExpiryDate(expDate);
		//Assigning Date Joined
		this->setDateJoined(DateJ);
	}
	void viewDiscounts() {
		cout << "YOUR PLATINUM CARD HAS THE FOLLOWING DISCOUNTS: " << endl;
		cout << "---> 30 % off on purchases worth 5000rs or more" << endl;
		cout << "---> 40 % off on purchases worth 10000rs or more" << endl;
	};
	void DiscountsUsed(Customer cust_obj, int PId, int val);
	void UpdateDiscounts(int PID, int val);
	float ApplyDiscounts(float Disval)
	{
		float newdis;
		if (Disval >= 10000)
		{
			newdis = 0.60 * Disval;
			cout << "DISCOUNT APPLIED! 40 % off on purchases worth 10000rs or more" << endl;
		}

		else
			if (Disval >= 5000)
			{
				newdis = 0.70 * Disval;
				cout << "DISCOUNT APPLIED! 30 % off on purchases worth 5000rs or more" << endl;
			}
			else
			{
				cout << "NO CRITERIA SATISFIED CAN'T APPLY DISCOUNT" << endl;
				newdis = Disval;
			}
		return newdis;

	};
	void printDetails()
	{
		cout << "PlatinumID:" << this->PlatinumId << endl;
		cout << "RFID:" << this->getRFID() << endl;
		cout << "Loyalty Points:" << this->getLoyaltyPoints() << endl;
		cout << "Discount Value:" << this->getDiscountVal() << "% " << endl;
		cout << "Date Joined:" << this->getDateJoined() << endl;
		cout << "Expiry Date:" << this->getExpDate() << endl;
	}
};
class Payment
{
private:
	int BillID;
	int UserID;
	float TotalBill;
	string  Dateofpurchase;
	string modeOfpayment;
	string Itemsbought;
	int NumberOfitems;
public:
	Payment() {};
	Payment(string a) {};
	void changeMOdeofPayment(string modeofPayement)
	{
		char ans;
		cout << "Confirm Mode of Payment (Y/N)? ";
		cin >> ans;
		if (ans == 'N' || ans == 'n')
		{
			cout << "Kindly Enter Your Mode of Payment " << endl;
			cout << "Enter COD for Cash On Delivery " << endl;
			cout << "Enter CARD for Debit Card " << endl;
			cin >> modeofPayement;
			this->modeOfpayment = modeofPayement;
		}
	}
	void MakePayment(float totalBill, string modeOfPayement)
	{
		ofstream receipt; //To save copy of customer receipt in record.
		receipt.open("CustomerBill.txt", ios::app);
		string cardnum;
		cout << "Kindly Enter Your Mode of Payment " << endl;
		cout << "Enter COD for Cash On Delivery " << endl;
		cout << "Enter CARD for Debit Card " << endl;
		cin >> modeOfPayement;
		this->modeOfpayment = modeOfPayement;
		changeMOdeofPayment(" ");
		if (this->modeOfpayment == "COD" || this->modeOfpayment == "cod")
		{
			cout << "Congratulations! Your order Has Been Placed " << endl;
			cout << "Delivery Time is 5-6 Business Days" << endl;
			cout << "Thank you for Shopping at S&J Boutique" << endl;
			time_t timetoday;
			time(&timetoday);
			receipt << "Mode of Payment: Cash On Delivery" << endl;
			receipt << "Order Successfully received." << endl;
			receipt << "Order Date and Time:		" << asctime(localtime(&timetoday)) << endl;
			receipt << "Thank you For Shopping at S&J Boutique" << endl;
		}
		if (this->modeOfpayment == "CARD" || this->modeOfpayment == "card")
		{
			cout << "Redirecting you to portal" << endl;
			do
			{
				cout << "Kindly Enter Your 16-Digit Card Number: ";
				cin >> cardnum;
				if (cardnum.size() != 16)
				{
					cout << "Enter Correct 16-Digit Card Number ";
					cin >> cardnum;
				}
			} while (cardnum.size() != 16);
			cout << "Transaction Successful" << endl;
			cout << "Congratulations! Your order Has Been Placed" << endl;
			cout << "Delivery Time is 5-6 Business Days" << endl;
			cout << "Thank you for Shopping at S&J Boutique" << endl;
			time_t timetoday;
			time(&timetoday);
			receipt << "Order Paid via Card Number " << cardnum << endl;
			receipt << "Transaction Successfull" << endl;
			receipt << "Order Successfully received." << endl;
			receipt << "Transaction Date and Time:		" << asctime(localtime(&timetoday)) << endl;
			receipt << "Thank you For Shopping at S&J Boutique" << endl;

		}

	}
	string getPaymentMode()
	{
		return this->modeOfpayment;
	}
	void  changeuserid(int Billid, int userid) {};
	void viewfulluserhistory(int userid) {};
	void viewhistorybydate(string dateofpurchase) {};
};
class Product {
private:
	string productName;
	string dateAdded;
	int quantityInStock;
	string category;
	string sizesAvailable;
	string AgeGroup;
	//	CustomerCart cart; removed
public:
	float price;
	Product() {};
	//Product(string a) :cart() {};
	int productNumber;
	//New for d6
	void setProduct(float pr, int prodNum, string prodName, string datecurr, int quantInStock, string categ, string SizezAvail, string AgeG)
	{	//New for d6
		price = pr;
		productName = prodName;
		dateAdded = datecurr;
		quantityInStock = quantInStock;
		category = categ;
		sizesAvailable = SizezAvail;
		AgeGroup = AgeG;
		productNumber = prodNum;


	};
	//NEW ADDED
//--------------------------HB-------------------------------------
	//setters 
	void setproductName(string n)
	{
		this->productName = n;
	}
	void setdateAdded(string d)
	{
		this->dateAdded = d;
	}
	void setquantityInStock(int s)
	{
		this->quantityInStock = s;
	}
	void setcategory(string c)
	{
		this->category = c;
	}
	void setsizesAvailable(string s)
	{
		this->sizesAvailable = s;
	}
	void setAgeGroup(string a)
	{
		this->AgeGroup = a;
	}
	//getters
	string getsizesAvailable()
	{
		return this->sizesAvailable;
	}
	string getAgeGroup()
	{
		return this->AgeGroup;
	}
	string getproductName()
	{
		return this->productName;
	}
	string getdateAdded()
	{
		return this->dateAdded;
	}
	int getquantityInStock()
	{
		return this->quantityInStock;
	}
	string getcategory()
	{
		return this->category;
	}
	void Display()
	{
		cout << "---> ";
		cout << this->productNumber << " || " << this->productName << endl;
		cout << "Price: Rs. " << price << " || Category:  " << category << " || Size: " << sizesAvailable << " || Age Group: " << AgeGroup << endl << endl;

	}
//--------------------------HB-------------------------------------

	int getCategory() {
		if (category == "Female")
			return 0;
		else if (category == "Male")
			return 1;
		else
			return -1;
	};
	float getprice() {
		return price;

	};
	void decreaseStock(int prouductNum, int num) {};
	void viewDetails() { //New for d6
		cout << "---> ";
		cout << productNumber << " || " << productName << endl;
		cout << "Price: Rs. " << price << " || Category:  " << category << " || Sizes Available: " << sizesAvailable << " || Age Group: " << AgeGroup << endl << endl;
	};
	void printToFileDetails(ofstream& receipt)
	{
		receipt << "---> ";
		receipt << productNumber << " || " << productName << endl;
		receipt << "Price: Rs. " << price << " || Category:  " << category << " || Sizes Available: " << sizesAvailable << " || Age Group: " << AgeGroup << endl << endl;

	};
	void changeSizes(int productNum, string newSizes) {};
	void changecategory(int productNum, string categ) {};
	void changeageGroup(int productNum, string age) {};
	void addOrremoveFromCart() {};
};

//Function to check either this item is availableor not
Product* Check_Item_Availability(int id)
{
	//READING DATA FROM FILE
	ifstream fin;
	fin.open("Products.txt", ios::in);
	//Reading no# of products
	int input;
	fin >> input;
	int product_total = input;
	Product* product = new Product[product_total];//This array will store data of all products
	if (fin) {
		/*
		ASSUMPTION : DATA IN PRDOUCTS FILE WILL ALWAYS BE IN THE ORDER:

		TOTAL NUMBER OF PRODUCTS
		PRODUCT PRICE
		PRODUCT NUMBER/ID
		PRODUCT NAME
		DATE PRODUCT ADDED
		CURRENT QUANTITY IN STOCK
		CATEGORY
		SIZES AVAILABLE
		AGE GROUP

		one line gap & the next product info
		*/
		int i = 0;
		while (i < product_total) {
			//Reading price
			Product obj;
			fin >> input;
			obj.price = input;

			//Reading product ID	
			fin >> input;
			obj.productNumber = input;

			//reading name
			string a;
			getline(fin, a); getline(fin, a);
			obj.setproductName(a);

			//reading date product added
			fin >> a;
			obj.setdateAdded(a);

			//Reading quantity in stock
			fin >> input;
			obj.setquantityInStock(input);

			//reading category
			fin >> a;
			obj.setcategory(a);

			//reading sizes available
			fin >> a;
			obj.setsizesAvailable(a);

			//reading age group
			fin >> a;
			obj.setAgeGroup(a);

			product[i] = obj;
			i++;

		}
		fin.close();

		// Checking either product is available or not
		for (int i = 0; i < product_total; i++)
		{
			if (product[i].productNumber == id)
				return &product[i];
		}
		return nullptr;

	}
	else
	{
		cout << "\nFile did not open"; return nullptr;
	}




}
class CustomerCart
{
private:
	int id;
	int NumberofItems;
	int customerId;
	//	string items;

	Payment Pay;
public:
	//----------------------------------HB-----------------------------
			//Maximum items in a cart
	Product items[100];
	//NEW ADDED
	CustomerCart(int id, int n, int cid)
	{
		this->id = id;
		this->NumberofItems = n;
		this->customerId = cid;
	}
	void checkout() {

		//Calculates total bill then call make payment function of payment class.

		ofstream receipt; //To save copy of customer receipt in record.
		receipt.open("CustomerBill.txt", ios::app);
		time_t timetoday;
		time(&timetoday);

		cout << "--------------------------Welcome to checkout!---------------------------------" << endl;
		cout << "Now printing Receipt..." << endl;

		receipt << endl << "                        -     CUSTOMER RECEIPT  -                 " << endl;
		cout << "                               S&J BOUTIQUE                         " << endl;
		receipt << "                               S&J BOUTIQUE                         " << endl;
		cout << "                        Online Transaction      " << endl;
		receipt << "                        Online Transaction      " << endl;
		receipt << "Bill Date and Time			" << asctime(localtime(&timetoday)) << endl;
		cout << "   CUSTOMER ID: " << customerId << endl;
		receipt << "   CUSTOMER ID: " << customerId << endl;

		float totalBill = 0;

		for (int i = 0; i < NumberofItems; i++)
		{
			cout << "Product # " << i + 1 << endl;
			receipt << "Product # " << i + 1 << endl;
			items[i].viewDetails();
			items[i].printToFileDetails(receipt);
			totalBill = totalBill + items[i].getprice();
		}

		cout << "---------------------------------YOUR TOTAl BILL IS: Rs. " << totalBill << endl << endl;
		receipt << "---------------------------------YOUR TOTAl BILL IS: Rs. " << totalBill << endl << endl;

		int type;
		cout << "Please enter your Type Of Card to avail discounts (1 for Gold, 2 for silver , 3 for Platinum, 4 for none) : ";
		cin >> type;

		float dtotalBill = totalBill;
		bool discounted = false;

		if (type == 1)
		{
			discounted = true;
			GoldCard goldobj;
			cout << endl << "SHOWING AVAILABLE DISCOUNTS.." << endl;
			goldobj.viewDiscounts();
			cout << endl << "APPLYING DISCOUNT..." << endl;
			dtotalBill = goldobj.ApplyDiscounts(totalBill);
		}
		else
			if (type == 2)
			{
				discounted = true;
				SilverCard silverobj;
				cout << endl << "SHOWING AVAILABLE DISCOUNTS.." << endl;
				silverobj.viewDiscounts();
				cout << endl << "APPLYING DISCOUNT..." << endl;
				dtotalBill = silverobj.ApplyDiscounts(totalBill);
			}
			else
				if (type == 3)
				{
					discounted = true;
					PlatinumCard platobj;
					cout << endl << "SHOWING AVAILABLE DISCOUNTS.." << endl;
					platobj.viewDiscounts();
					cout << endl << "APPLYING DISCOUNT..." << endl;
					dtotalBill = platobj.ApplyDiscounts(totalBill);
				}
				else
					if (type == 4)
						cout << endl << "No card. No additional discounts can be applied." << endl;
					else
						cout << endl << "Invalid Input! No additional discounts can be applied." << endl;
		if (!discounted)
		{
			cout << endl;
			receipt << endl;
			Pay.MakePayment(totalBill, " ");

		}

		else
		{
			if (totalBill != dtotalBill)
			{
				cout << endl << "---------------------------------YOUR TOTAl BILL AFTER DISCOUNT IS: Rs. " << dtotalBill << endl;
				receipt << endl << "---------------------------------YOUR TOTAl BILL AFTER DISCOUNT IS: Rs. " << dtotalBill << endl;
			}
			cout << endl;
			receipt << endl;
			Pay.MakePayment(dtotalBill, " ");
		}
		/*if(Pay.getPaymentMode()=="CARD"||Pay.getPaymentMode=="card")
		{
			receipt<<"Order is Paid via Card"<<endl;
			receipt<<
		}*/

		receipt.close();
	};
	void addTocart() {

		int id;
		cout << "\nEnter Item ID you want  to buy  =  "; cin >> id;
		Product* obj = Check_Item_Availability(id);//check if item is in our store or not
		if (obj)
		{
			if (this->NumberofItems < 100) {

				if (obj->getquantityInStock() > 0)//True if item is in stock
				{

					string size;
					cout << "\nAvailable sizes are        =    "; cout << obj->getsizesAvailable();
					cout << "\nSelect the size you want   =    "; cin >> size;
					//Check if this size is availabe
					obj->setsizesAvailable(size);
					items[NumberofItems] = *obj;
					NumberofItems++;
					cout << "\nThis Item added to your cart\n";
					//----------------------------------------------------------------------------------------
					//updating product stock
										//READING DATA FROM FILE
					ifstream fin;
					fin.open("Products.txt", ios::in);
					//Reading no# of products
					int input;
					fin >> input;
					int product_total = input;
					Product* product = new Product[product_total];//This array will store data of all products
					if (fin) {
						/*
						ASSUMPTION : DATA IN PRDOUCTS FILE WILL ALWAYS BE IN THE ORDER:

						TOTAL NUMBER OF PRODUCTS
						PRODUCT PRICE
						PRODUCT NUMBER/ID
						PRODUCT NAME
						DATE PRODUCT ADDED
						CURRENT QUANTITY IN STOCK
						CATEGORY
						SIZES AVAILABLE
						AGE GROUP

						one line gap & the next product info
						*/
						int i = 0;
						while (i < product_total) {


							//Reading price
							Product obj;
							fin >> input;
							obj.price = input;

							//Reading product ID
							fin >> input;
							obj.productNumber = input;

							//reading name
							string a;
							getline(fin, a); getline(fin, a);
							obj.setproductName(a);

							//reading date product added
							fin >> a;
							obj.setdateAdded(a);

							//Reading quantity in stock
							fin >> input;
							obj.setquantityInStock(input);

							//reading category
							fin >> a;
							obj.setcategory(a);

							//reading sizes available
							fin >> a;
							obj.setsizesAvailable(a);

							//reading age group
							fin >> a;
							obj.setAgeGroup(a);

							product[i] = obj;
							i++;

						}
						fin.close();//readig completed

						//writing updated data into the file
						ofstream fout;
						fout.open("Products.txt", ios::out | ios::trunc);
						if (fout) {
							cout << "\nupdating stock in file\n";
							fout << product_total;//write total products 
							int j = 0;
							while (j < product_total)
							{
								fout << "\n";
								//PRICE OF PRODUCT
								fout << product[j].price;
								fout << "\n";

								//PRODUCT ID
								fout << product[j].productNumber;
								fout << "\n";

								//writing product name
								fout << product[j].getproductName();
								fout << "\n";

								//writing  date at which product was added in stock
								fout << product[j].getdateAdded();
								fout << "\n";

								////writing product stock
								if (obj->productNumber == product[j].productNumber)
									fout << product[j].getquantityInStock() - 1;
								else
									fout << product[j].getquantityInStock();
								fout << "\n";

								//writing product category
								fout << product[j].getcategory();
								fout << "\n";

								//writing sizes available
								fout << product[j].getsizesAvailable();
								fout << "\n";

								//writing age category
								fout << product[j].getAgeGroup();
								fout << "\n";
								j++;
							}
							fout.close();
							//UPDATING DATA INTO THE CUSTOMER FILE
														//READING FROM CUSTOMER FILE
							ifstream fin;
							fin.open("Customer.txt", ios::in);
							if (fin)
							{
								//Reading no# of customers
								int input;
								fin >> input;
								int customer1_total = input;
								Customer* cust1 = new Customer[customer1_total];
								/*
									ASSUMPTION : DATA IN CUSTOMER FILE WILL BE IN THE ORDER:
									 total number of Customers(next line)
									 ID name address contact password   TotaoNumberOfItemsBought  TotaoNumberOfItemsReturn LoyaltyCardID LOyaltyPoints */
								int i = 0;
								while (i < customer1_total) {


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

									//reading loyalty card id
									fin >> input;
									obj.setLoyaltyPoints(input);

									cust1[i] = obj;
									i++;

								}
								fin.close();

								//writing BUY ITE'M IN CUSTOMER RECORD
								ofstream fout;
								fout.open("Customer.txt", ios::out | ios::trunc);
								if (fout)
								{
									/*
									ASSUMPTION : DATA IN CUSTOMER FILE WILL BE IN THE ORDER:
									 total number of Customers(next line)
									ID name address contact password   TotaoNumberOfItemsBought  TotaoNumberOfItemsReturn LoyaltyCardID LOyaltyPoints */

									//write total number of customers
									fout << customer1_total;
									fout << "\n";
									for (int i = 0; i < customer1_total; i++)
									{

										fout << cust1[i].getCustomerID();
										fout << " ";
										fout << cust1[i].getName();
										fout << " ";
										fout << cust1[i].getAddress();
										fout << " ";
										fout << cust1[i].getContact();
										fout << " ";
										fout << cust1[i].getPassword();
										fout << " ";
										if (cust1[i].getCustomerID() == this->customerId)
										{
											fout << (cust1[i].getNo_of_itemsBought() + 1);
										}
										else
											fout << cust1[i].getNo_of_itemsBought();

										fout << " ";
										fout << cust1[i].getNo_of_Returns();
										fout << " ";
										fout << cust1[i].getLoyaltyCardId();
										fout << " ";
										fout << cust1[i].getLoyaltyPoints();
										fout << "\n";
									}

									fout.close();
								}
								else
									cout << "\writing File did not open for updating customer's no of bought items";
							}
							else
								cout << "\nReading File did not open for updating customer's no of bought items";


						}
						else
							cout << "\File did not open for updating stock";
					}
					else
					{
						cout << "\nFile did not open for reading!";
					}
					//----------------------------------------------------------------------------------------
					cout << "\n Total items in cart\n";
					for (int i = 0; i < NumberofItems; i++)
						items[i].Display();
					string c;
					cout << "\nContinue shopping?[y/n]    =    "; cin >> c;
					if (c == "y")
					{
						addTocart();
					}
					else
					{
						if (NumberofItems > 0)
						{
							cout << "\nGo for Checkout\n";
							checkout();
						}
						return;

					}
				}
				else//if item is out of stock
				{
					cout << "\nSorry this item is out of stock\n";
					string c;
					cout << "\nContinue shopping?[y/n]    =    "; cin >> c;
					if (c == "y")
					{
						addTocart();
					}
					else
					{
						if (NumberofItems > 0)
						{
							cout << "\nGo for Checkout\n\n";
							checkout();
						}
						return;
					}
				}
			}
			else
			{
				cout << "\n Can not add to the item your cart reached the maximum limit of items\n Firts pay for them.\n Thank you!";
				cout << "\nGo for Checkout\n";
				return;
			}

		}
		else
		{
			cout << "\n Sorry This item does not exists";
			string c;
			cout << "\nContinue shopping?[y/n]    =    "; cin >> c;
			if (c == "y")
			{
				addTocart();
			}
			else
			{
				cout << "\nGo for Checkout\n";
				return;
			}
		}
	};
	void removeFromCart(string items) {};

};

class OnlineStore {

protected:
	int id;
	string name;
	Product Collection;
	Product* CollectionAll; //New for d6
	int Num;//New for d6
	OnlineStore() {};
	OnlineStore(int id, string n);
private:
	Customer customer;
	static  OnlineStore* _Instance;
public:
	static OnlineStore* Instance();
	void setAllCollection(Product* newCollec, int sizeColl) //New for d6
	{
		CollectionAll = new Product[sizeColl];
		for (int i = 0; i < sizeColl; i++)
			CollectionAll[i] = newCollec[i];
		Num = sizeColl;

	};
	void DisplayCollectionOnline() {
		//L20-0921 Implementation of use case Display Collection. (D6)
		if (CollectionAll != NULL) {
			int n; //For taking user input.



			do {
				cout << "What kind of apparels do you wish to view?" << endl;
				cout << "Please enter 0 for All, 1 for male apparels & 2 for female apparels. & 3 to exit browsing." << endl;
				cin >> n;
				if (n == 3)
					break;

				if (n == 0)
				{
					//ALL Apparels
					cout << "Showing ALL " << Num << " Apparels..." << endl << endl;
					for (int i = 0; i < Num; i++)
						CollectionAll[i].viewDetails();
				}
				else
					if (n == 1)
					{
						//Male Apparels
						cout << "Showing Male Apparels..." << endl << endl;
						for (int i = 0; i < Num; i++)
						{
							if (CollectionAll[i].getCategory() == 2 || CollectionAll[i].getCategory() == 1)
								CollectionAll[i].viewDetails();
						}

					}
					else if (n == 2)
					{
						//Female Apparels
						cout << "Showing Female Apparels..." << endl << endl;
						for (int i = 0; i < Num; i++)
						{
							if (CollectionAll[i].getCategory() == 2 || CollectionAll[i].getCategory() == 0)
								CollectionAll[i].viewDetails();
						}
					}
					else
					{
						cout << "Invalid input!" << endl;

					}
				cout << "Please enter 3 to exit browsing collection OR 4 to go back to browsing collection." << endl;
				cin >> n;
			} while (n != 3);
		}
	};
	void Login(Customer customer) {};
	void Signup(Customer customer) {};
};
OnlineStore* OnlineStore::_Instance = 0;
OnlineStore* OnlineStore::Instance()
{
	if (_Instance == 0)
	{
		_Instance = new OnlineStore();

	}
	return _Instance;

}

//----------------------------------------HB------------------------------------
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

			//reading loyalty points
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

			//other checks

		Customer* obj = cust_check_for_login(id);
		if (obj)
		{   //CORRECT PASSWORD
			if (p == obj->getPassword())
			{
				string z;
				cout << "\n\nLogged in Successfully\n\n";

//__________________________________________AISHA_______________________________________________
				int n;
				OnlineStore* onlinestr = OnlineStore::Instance(); //SINGELTON DESIGN PATTERN APPLIED BEACUSE ONLY ONE INSTANCE OF ONLINE STORE.
				cout << "----------------------- WELCOME TO S &J ONLINE STORE PRESS 1 TO BROWSE COLLECTION AND 2 TO EXIT! --------------" << endl;
				cin >> n;
				//To Read data from products.txt file

				ifstream productFile;
				productFile.open("products.txt", ios::in);
				/*
				ASSUMPTION : DATA IN PRDOUCTS FILE WILL ALWAYS BE IN THE ORDER:

				TOTAL NUMBER OF PRODUCTS
				PRODUCT PRICE
				PRODUCT NUMBER/ID
				PRODUCT NAME
				DATE PRODUCT ADDED
				CURRENT QUANTITY IN STOCK
				CATEGORY
				SIZES AVAILABLE
				AGE GROUP

				one line gap & the next product info
				*/

				int TotalProducts;
				productFile >> TotalProducts; //First line of file will always have the total number of products.
				//Product* myCollections = new Product[TotalProducts]; //This array will store information of products read from file products.txt
				Product* myCollections = new Product[TotalProducts];
				for (int i = 0; i < TotalProducts; i++)
				{
					float  price;
					int prodNum, quantInStock;
					string prodName, datecurr, categ, SizezAvail, AgeG, testNext;

					productFile >> price;
					productFile >> prodNum;
					getline(productFile, prodName);
					getline(productFile, prodName);
					getline(productFile, datecurr);
					productFile >> quantInStock;
					getline(productFile, categ);
					getline(productFile, categ);
					getline(productFile, SizezAvail);
					getline(productFile, AgeG);
					getline(productFile, testNext);

					if (!testNext.size())
						myCollections[i].setProduct(price, prodNum, prodName, datecurr, quantInStock, categ, SizezAvail, AgeG); //Storing data read from file in array
					else
						break;
				}

				productFile.close(); //Closing file

			//	Setting up collection of store using data read from file.
				onlinestr->setAllCollection(myCollections, TotalProducts);
				if (n == 1) {
					//To Display Collection
					char c = 'Y';
					if (c == 'Y')
					{
						onlinestr->DisplayCollectionOnline();
						CustomerCart cart(1, 0, id);
						cart.addTocart();
					}
				}
				else
					cout << "BYE!" << endl;
//__________________________________________AISHA_______________________________________________



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
					fout.open("Customer.txt", ios::out | ios::trunc);
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
						cout << "\n login with updated password Password";
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
				//saving new customers data into the file
				ofstream fout;
				fout.open("Customer.txt", ios::out | ios::trunc);
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
					fout << "\n";
					fout.close();
					cout << "\n\n Your Account has been created successfully!\n\n";
					Customer_login(id,pass);
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
//----------------------------------------HB------------------------------------



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
	//* COLOR DECLARTIONS--------------------------------------------------------------
	COLORREF White = RGB(255, 255, 255);
	COLORREF Black = RGB(0, 0, 0);
	COLORREF Pink = RGB(255, 182, 193);
	COLORREF Red = RGB(255, 0, 0);
	COLORREF Grey = RGB(128, 128, 128);
	COLORREF Green = RGB(34, 139, 34);
	COLORREF Yellow RGB(255, 255, 0);

	int n;
	bool exit = false;
	system("Color E7");
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

	char str[] = { "~ Welcome to S & J Boutique ~ " };
	myDrawTextWithFont(280, 100, 40, str, Pink, White);
	Sleep(500);
	char str2[] = { "-> To Browse Collection enter 0 " };
	myDrawTextWithFont(320, 160, 30, str2, Pink, White);
	Sleep(500);
	char str3[] = { "-> To Login/Sign Up enter 1" };
	myDrawTextWithFont(320, 220, 30, str3, Pink, White);
	Sleep(500);
	char str4[] = { "->To Place an order enter 2 " };
	myDrawTextWithFont(320, 280, 30, str4, Pink, White);
	Sleep(500);
	char str5[] = { "-> To issue card enter 3 (FOR ADMIN ONLY) " };
	myDrawTextWithFont(320, 340, 30, str5, Pink, White);
	char str6[] = { "-> To Exit enter 4 " };
	myDrawTextWithFont(320, 400, 30, str6, Pink, White);

	cin >> n;
	ClearScreen();
	if (n == 0)
	{
		system("Color C7");
		cout << "You have decided to browse collection." << endl<<endl;
		ifstream broproductFile;
		broproductFile.open("products.txt", ios::in);
		/*
		ASSUMPTION : DATA IN PRDOUCTS FILE WILL ALWAYS BE IN THE ORDER:

		TOTAL NUMBER OF PRODUCTS
		PRODUCT PRICE
		PRODUCT NUMBER/ID
		PRODUCT NAME
		DATE PRODUCT ADDED
		CURRENT QUANTITY IN STOCK
		CATEGORY
		SIZES AVAILABLE
		AGE GROUP

		one line gap & the next product info
		*/

		int broTotalProducts;
		broproductFile >> broTotalProducts; //First line of file will always have the total number of products.
		Product* myCollections = new Product[broTotalProducts];
		for (int i = 0; i < broTotalProducts; i++)
		{
			float  price;
			int prodNum, quantInStock;
			string prodName, datecurr, categ, SizezAvail, AgeG, testNext;

			broproductFile >> price;
			broproductFile >> prodNum;
			getline(broproductFile, prodName);
			getline(broproductFile, prodName);
			getline(broproductFile, datecurr);
			broproductFile >> quantInStock;
			getline(broproductFile, categ);
			getline(broproductFile, categ);
			getline(broproductFile, SizezAvail);
			getline(broproductFile, AgeG);
			getline(broproductFile, testNext);

			if (!testNext.size())
				myCollections[i].setProduct(price, prodNum, prodName, datecurr, quantInStock, categ, SizezAvail, AgeG); //Storing data read from file in array
			else
				break;
		}

		broproductFile.close(); //Closing file
		OnlineStore* broonlinestr = OnlineStore::Instance(); //SINGELTON DESIGN PATTERN APPLIED BEACUSE ONLY ONE INSTANCE OF ONLINE STORE.
		//	Setting up collection of store using data read from file.
		broonlinestr->setAllCollection(myCollections, broTotalProducts);
					broonlinestr->DisplayCollectionOnline();

	}
	else
		if (n == 1 || n==2 || n==3)
		{
			//system("Color 07");
			int inp = 1;
			if (n == 1)
			{
				system("Color 30");
				cout << "You have decided to Login/Signup" << endl;
				cout << "\n ENTER 1 TO LOGIN/SIGNUP AS CUSTOMER OR 2 AS STAFF\n =  ";
				cin >> inp;
			}
			if (n == 2)
			{
				system("Color E0");
				cout << "You have decided to Place an order. You have to login/signup first!" << endl;
			}
			if (n == 3)
			{
				system("Color F0");
				cout << "You have decided to issue card. You have to login/signup first!" << endl;
				inp = 2;
			}

			//-------------------CUSTOMER LOGIN-SIGNUP TEST----------------------------------
			if (inp == 1 && n!=3) {
				int id; string password;
				cout << "\n~        Enter details to login as Customer       ~";
				cout << "\nEnter ID            =      "; cin >> id;
				cout << "\nEnter PASSWORD      =      "; cin >> password;
				Customer_login(id, password);
			}
			
			//-------------------STAFF LOGIN-SIGNUP TEST----------------------------------
			else 
				if (inp == 2)
				{
				int id; string password;
				cout << "\n~        Enter details to login as Admin     ~";
				cout << "\nEnter ID            =      "; cin >> id;
				cout << "\nEnter PASSWORD      =      "; cin >> password;
				User_login(id, password);

				cout << "Redirecting You To Portal" << endl;
				//READING DATA FROM FILE
				ifstream fin;
				int size;
				Customer* cust = NULL;
				fin.open("Customer.txt", ios::in);	//reading from customer's file
				if (fin) {
					//Reading no# of customers
					fin >> size;
					const int customer_total = size;
					cust = new Customer[customer_total];
					int i = 0;
					while (!(fin.eof())) {
						int input = 0;
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

						//reading loyalty points 
						fin >> input;
						obj.setLoyaltyPoints(input);

						cust[i] = obj;
						i++;
					}
					fin.close();
					for (int i = 0; i < customer_total; i++)	//Printing Record of Customer
						cust[i].viewDetails();
				}
				if (!fin)
				{
					cout << "File Doesn't Exists" << endl;
				}

				if (n == 3) {

					int LID = 0;
					int card_total = 0;
					char ans = ' ';
					char ch = ' ';
					LoyaltyCard* obj = NULL; //declaring a pointer of LoyaltyCard class to read and store data from file into the pointer
					int size2 = 0;
					ifstream myfile;
					myfile.open("card.txt", ios::in);
					if (myfile)
					{
						//Reading no# of cards
						myfile >> size2;
						card_total = size2 + size;
						obj = new LoyaltyCard[card_total];
						int l = 0;
						while (!(myfile.eof()))
						{
							int num = 0;
							LoyaltyCard l1;
							string s;
							//reading card type;
							myfile >> s;
							l1.setCardType(s);

							myfile >> num;
							//read card id
							l1.setLoyaltyID(num);

							//reading rfid
							myfile >> num;
							l1.setRFID(num);

							//reading points
							myfile >> num;
							l1.setLoyaltyPoints(num);

							//reading discount value
							myfile >> num;
							l1.setCardDiscount(num);

							//reading joining date;
							myfile >> s;
							l1.setDateJoined(s);

							//reading expiry date
							myfile >> s;
							l1.setExpiryDate(s);

							obj[l] = l1;
							//obj[l].printDetails();
							l++;
						}
						myfile.close();
					}
					else
					{
						cout << "File Doesn't Exists" << endl;
					}
					int card_count = size2;	//total cards in file

					char up_point;

					int CID = 0;
					do
					{
						bool foundCID = false;
						cout << "Enter L To Update Loyalty Points" << endl;
						cout << "Enter Q To Quit" << endl;
						cout << "Enter Your Option: ";
						cin >> up_point;
						if (up_point == 'L' || up_point == 'l')
						{
							int j = 0;
							cout << "Enter Customer ID to Update Loyalty Points:";//Asking Admin To Provide Customer ID
							cin >> CID;
							for (; j < size; j++)
							{
								if (cust[j].getCustomerID() == CID)	//Verifiyng if the Customer ID is Valid or not
								{
									foundCID = true;
									break;
								}
							}
							if (foundCID == true)	//if customer ID is Valid then we will further assign him a card or update his points based on the value admin provides to update loyalty points
							{
								int ID = cust[j].getLoyaltyCardId();
								cust[j].UpdatePoints(ID);	//Updating customer's Loyalty Points
								int LP = cust[j].getLoyaltyPoints();
								//cout<<LP<<endl;
								int x = card_count;
								for (; x < size; x++)
								{
									if (LP >= 500 && LP < 1500)	//Limit of Loyalty Points to be assigned a Silver Card
									{
										cout << "Customer has been Assigned a Silver Card" << endl;
										int ID = cust[j].getLoyaltyCardId();
										if (ID == 0)	//If customer is previously not assigned a loyalty card,here in this condition he/she will be assigned a new loyalty card
										{
											SilverCard s1;	//child class object called to assign the card
											s1.AssignCard(cust[j], "2-Dec-2022", 20, "2-Dec-2024");
											cust[j].setLoyaltyCardId(s1.getLoyaltyID());
											s1.AssignPoints(LP);
											s1.printDetails();
											obj[x] = s1;	//child class object assigned to parent class pointer to store data in the array for data management
											card_count++;	//	card count increases by 1 as a new card is assigned
											break;
										}
										else if (ID != 0)//if customer has been assigned a card previously,here we will only update his loyalty points
										{
											int i = 0;
											for (; i < card_count; i++)
											{
												if (obj[i].getLoyaltyID() == ID)
													break;
											}
											if (obj[i].getCardType() == "Silver")
											{
												obj[i].setLoyaltyPoints(LP);
												break;
											}
										}
									}
									if (LP >= 1500 && LP < 3000)  //Limit of Loyalty Points to be assigned a Gold Card
									{
										cout << "Customer has been Assigned a Gold Card" << endl;
										int ID = cust[j].getLoyaltyCardId();
										if (ID == 0)	//If customer is previously not assigned a loyalty card,here in this condition he/she will be assigned a new loyalty card
										{
											GoldCard g1;	//child class object called to assign the card
											g1.AssignCard(cust[j], "2-Dec-2022", 30, "2-Dec-2024");
											cust[j].setLoyaltyCardId(g1.getLoyaltyID());
											g1.AssignPoints(LP);
											g1.printDetails();
											obj[x] = g1;	//child class object assigned to parent class pointer to store data in the array for data management
											card_count++;	//	card count increases by 1 as a new card is assigned
											break;
										}
										else if (ID != 0)//if customer has been assigned a card previously,here we will only update his loyalty points
										{
											int i = 0;
											for (; i < card_count; i++)
											{
												if (obj[i].getLoyaltyID() == ID)
													break;
											}
											if (obj[i].getCardType() == "Gold")//if the card type of customer previously is gold,we will update points for same id
											{
												obj[i].setLoyaltyPoints(LP);
												break;
											}
											else	//if the card type of customer previously is not gold and is silver instead,we will upgrade his card and assign him a new gold card with a unique id
											{
												GoldCard g1;
												g1.AssignCard(cust[j], "2-Dec-2022", 30, "2-Dec-2024");
												cust[j].setLoyaltyCardId(g1.getLoyaltyID());
												g1.AssignPoints(LP);
												g1.printDetails();
												obj[i] = g1;	//since we're assigning the same customer a new card the old information of card will be replaced by the new card information
												break;
											}
										}
									}
									if (LP >= 3000) //Limit of Loyalty Points to be assigned a Platinum Card
									{
										cout << "Customer has been Assigned a Platinum Card" << endl;
										int ID = cust[j].getLoyaltyCardId();
										if (ID == 0)	//If customer is previously not assigned a loyalty card,here in this condition he/she will be assigned a new loyalty card
										{
											PlatinumCard p1;	//child class object called to assign the card
											p1.AssignCard(cust[j], "2-Dec-2022", 50, "2-Dec-2024");
											cust[j].setLoyaltyCardId(p1.getLoyaltyID());
											p1.AssignPoints(LP);
											p1.printDetails();
											obj[x] = p1;	//child class object assigned to parent class pointer to store data in the array for data management
											card_count++;//	card count increases by 1 as a new card is assigned
											break;
										}
										else if (ID != 0)//if customer has been assigned a card previously,here we will only update his loyalty points
										{
											int i = 0;
											for (; i < card_count; i++)
											{
												if (obj[i].getLoyaltyID() == ID)
													break;
											}
											if (obj[i].getCardType() == "Platinum")//if the card type of customer previously is Platinum,we will update points for same id
											{
												obj[i].setLoyaltyPoints(LP);
												break;
											}
											else	//if the card type of customer previously is not Platinum and is Gold/Silver instead,we will upgrade his card and assign him a new gold card with a unique id
											{
												PlatinumCard p1;
												p1.AssignCard(cust[j], "2-Dec-2022", 50, "2-Dec-2024");
												cust[j].setLoyaltyCardId(p1.getLoyaltyID());
												p1.AssignPoints(LP);
												p1.printDetails();
												obj[i] = p1;//since we're assigning the same customer a new card the old information of card will be replaced by the new card information
												break;
											}
										}
									}
								}
							}
							else
							{
								cout << "Cannot Find The Customer" << endl;
							}
						}
						if (up_point == 'Q' || up_point == 'q')
						{
							break;
						}
					} while (up_point != 'Q' || up_point != 'q');

					//--------------------------------FILE WRITING----------------------------------------

					//------------------------------------------code for writing-------------------------------------------------------//
					//----------------------------------------writing in card file--------------------------------------------------//
					ofstream myfile2;
					myfile2.open("card.txt", ios::out | ios::trunc);
					if (myfile2)
					{
						myfile2 << card_count << endl;
						for (int i = 0; i < card_count; i++)
						{
							//writing Card type
							myfile2 << obj[i].getCardType() << " ";
							//writing Loyalty ID
							myfile2 << obj[i].getLoyaltyID() << " ";
							//writing RFID
							myfile2 << obj[i].getRFID() << " ";
							//writing Loyalty Points
							myfile2 << obj[i].getLoyaltyPoints() << " ";
							//writing Discount Value
							myfile2 << obj[i].getDiscountVal() << " ";
							//writing Date Joined
							myfile2 << obj[i].getDateJoined() << " ";
							//writing Expiry Date
							myfile2 << obj[i].getExpDate() << endl;
						}
						myfile2.close();
					}
					else
					{
						cout << "File Doesn't Exists" << endl;
					}
					//	---------------------------------------------------------------writing in customer file--------------------------------------------
					ofstream fout;
					fout.open("Customer.txt", ios::out | ios::trunc);
					if (fout)
					{
						fout << size << endl;
						for (int i = 0; i < size; i++)
						{
							//writing Customer ID;
							fout << cust[i].getCustomerID() << " ";
							//writing Name
							fout << cust[i].getName() << " ";
							//writing Address
							fout << cust[i].getAddress() << " ";
							//writing Contact
							fout << cust[i].getContact() << " ";
							//writing Password
							fout << cust[i].getPassword() << " ";
							//writing Items Bought
							fout << cust[i].getNo_of_itemsBought() << " ";
							//writing Items Returned
							fout << cust[i].getNo_of_Returns() << " ";
							//writing Loyalty Card ID
							fout << cust[i].getLoyaltyCardId() << " ";
							//writing Loyalty Points
							fout << cust[i].getLoyaltyPoints();
							if (i < (size - 1))
							{
								fout << "\n";
							}
						}
						fout.close();
					}
					else
					{
						cout << "File Doesn't Exists" << endl;
					}

				}
			}
		}
				else
			if (n == 4)
			{
				cout << "BYE!" << endl;
			}else
				{
					cout << "INVALID INPUT" << endl;
				}
				ClearScreen();
				system("color 40");
				char strex[] = { "MADE BY HUMAIRA BATOOL , FAIQA ADNAN AND AISHA NAWAZ " };
				myDrawTextWithFont(220, 100, 30, strex, Red, White);
				Sleep(5000);
			
			

	system("pause");
}