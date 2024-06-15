#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <time.h>
using namespace std;

////-----------------------------------------------------classes-------------------------------------------------------------------
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
		LoyaltyId=0;
		LoyaltyPoints=0;
		DateJoined=" ";
		DateofLastScan=" ";
		TimeofScan=" ";
		Expiry_Date=" ";
		RFID_no=0;
		DiscountVal=0;
		CardType=" ";
	}
	LoyaltyCard(int LID, int LPoints, int rfid,string CardType,string ExpDate,string DateJoin,int disVal)
	{
		this->LoyaltyId=LID;
		this->LoyaltyPoints=LPoints;
		this->RFID_no=rfid;
		this->CardType=CardType;
		this->Expiry_Date=ExpDate;
		this->DateJoined=DateJoin;
		this->DiscountVal=disVal;
	}
	void setCardType(string s)
	{
		this->CardType=s;
	}
	string getCardType()
	{
		return this->CardType;
	}
	void setLoyaltyID(int id)
	{
		this->LoyaltyId=id;
	}
	void setLoyaltyPoints(int num)
	{
		this->LoyaltyPoints=num;
	}
	void setDateJoined(string date)
	{
		this->DateJoined=date;
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
		this->Expiry_Date=expDate;
	}
	void setRFID(int rfid)
	{
		this->RFID_no=rfid;
	}
	int getRFID()
	{
		return this->RFID_no;
	}
	void setCardDiscount(int DisVal)
	{
		this->DiscountVal=DisVal;
		//cout<<"Customer got a Discount of "<<this->DiscountVal<<" on their Current Card"<<endl;
		
	}
	int getDiscountVal()
	{
		return DiscountVal;
	}
	virtual void AssignCard(Customer cust_obj, string Datejoined,int val,string Expiry_Date)
	{
		int LID;
		int rfid;
		int Custid;
		//assigning Customer Object 
		Custid=cust_obj.getCustomerID();
		this->cust_obj=cust_obj;

		//Assigning Loyalty ID
		srand(time(0));
		LID=rand();
		this->LoyaltyId=LID;

		//Assigning RFID
		rfid=rand();
		this->RFID_no=rfid;
		
		//assiging Date Joined
		this->DateJoined=Datejoined;

		//assigning Date Expire
		this->Expiry_Date=Expiry_Date;
	}
	void AssignPoints(int LIP)
	{
		this->LoyaltyPoints=LIP;
	}
	void UpdatePoints(int LID)
	{
		int LIP;
		cout<<"Enter Points to Assign: ";
		cin>>LIP;
		this->LoyaltyPoints=this->LoyaltyPoints+LIP;
	}
	int getLoyaltyPoints()
	{
		return this->LoyaltyPoints;
	}
	int getLoyaltyID()
	{
		return this->LoyaltyId;
	}
	Customer*getcustobj()
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
		cout<<"Card Type:"<<this->CardType<<endl;
		cout<<"Customer ID:"<<cust_obj.getCustomerID()<<endl;
		cout<<"Loyalty Card ID:"<<this->LoyaltyId<<endl;
		cout<<"RFID No:"<<this->RFID_no<<endl;
		cout<<"Loyalty Points:"<<this->LoyaltyPoints<<endl;
		cout<<"Discount Val:"<<this->DiscountVal<<endl;
		cout<<"Date Joined:"<<this->DateJoined<<endl;
		cout<<"Expiry Date:"<<this->Expiry_Date<<endl;
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
		GoldId=0;
	}
	GoldCard(int GID)
	{
		this->GoldId=GID;
	}
	void setGoldID(int GID)
	{
		this->GoldId=GID;
	}
	int getGoldID()
	{
		return this->GoldId;
	}
	void AssignCard(Customer cust_obj,string DateJoin, int val,string expiryDate)
	{
		//Assigning CardType
		this->setCardType("Gold");
		//Assigning ID
		int gid;
		srand(time(0));
		gid=rand();
		setLoyaltyID(gid);

		//Assigning RFID
		int rfid=rand();
		this->setRFID(rfid);

		this->cust_obj=cust_obj;
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
		if (Disval >=10000)
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
		cout<<"GoldID:"<<this->GoldId<<endl;
		cout<<"RFID:"<<this->getRFID()<<endl;
		cout<<"Loyalty Points:"<<this->getLoyaltyPoints()<<endl;
		cout<<"Discount Value:"<<this->getDiscountVal()<<"% "<<endl;
		cout<<"Date Joined:"<<this->getDateJoined()<<endl;
		cout<<"Expiry Date:"<<this->getExpDate()<<endl;
	}
};
class SilverCard :public LoyaltyCard
{
private:
	int SilverId;
public:
	SilverCard()
	{
		this->SilverId=0;
	}
	SilverCard(int SID)
	{
		this->SilverId=SID;
	}
	void setSilverID(int id)
	{
		this->SilverId;
	}
	int getSilverID()
	{
		return this->SilverId;
	}
	void AssignCard(Customer cust_obj,string Datejoined,int val,string expDate)
	{
		//assigning card type;
		this->setCardType("Silver");
		//assigning ID
		
		int sid;
		srand(time(0));
		sid=rand();
		setLoyaltyID(sid);

		this->SilverId=getLoyaltyID();

		//Assigning RFID
		int rfid=rand();
		this->setRFID(rfid);

		this->cust_obj=cust_obj;
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
			newdis = 0.80* Disval;
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
		cout<<"SilverID:"<<this->SilverId<<endl;
		cout<<"RFID:"<<this->getRFID()<<endl;
		cout<<"Loyalty Points:"<<this->getLoyaltyPoints()<<endl;
		cout<<"DiscountVal:"<<this->getDiscountVal()<<"% "<<endl;
		cout<<"Date Joined:"<<this->getDateJoined()<<endl;
		cout<<"Expiry Date:"<<this->getExpDate()<<endl;
	}
};
class PlatinumCard :public LoyaltyCard
{
private:
	int PlatinumId;
public:
	PlatinumCard()
	{
		this->PlatinumId=0;
	}
	PlatinumCard(int PID)
	{
		this->PlatinumId=PID;
	}
	void setPlatinumID(int PID)
	{
		this->PlatinumId=PID;
	}
	int getPlatinumID()
	{
		return this->PlatinumId;
	}
	void AssignCard(Customer cust_obj,string DateJ, int val,string expDate)
	{
		//Assigning Card Type;
		this->setCardType("Platinum");

		//Assigning Card ID
		int pid;
		srand(time(0));
		pid=rand();
		setLoyaltyID(pid);
		this->PlatinumId=this->getLoyaltyID();

		//Assigning RFID
		int rfid=rand();
		this->setRFID(rfid);

		this->cust_obj=cust_obj;
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
		cout<<"PlatinumID:"<<this->PlatinumId<<endl;
		cout<<"RFID:"<<this->getRFID()<<endl;
		cout<<"Loyalty Points:"<<this->getLoyaltyPoints()<<endl;
		cout<<"Discount Value:"<<this->getDiscountVal()<<"% "<<endl;
		cout<<"Date Joined:"<<this->getDateJoined()<<endl;
		cout<<"Expiry Date:"<<this->getExpDate()<<endl;
	}
};
int main()
{
	//READING DATA FROM FILE
	ifstream fin;
	int size;
	Customer* cust=NULL;
	fin.open("Customer.txt", ios::in);	//reading from customer's file
	if (fin) {
		//Reading no# of customers
		fin >> size;
		const int customer_total = size;
		cust = new Customer[customer_total];
		int i = 0;
		while (!(fin.eof())) {

			int input=0;
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
			fin>>input;
			obj.setLoyaltyPoints(input);

			cust[i] = obj;
			i++;

		}
		fin.close();
		for (int i = 0; i < customer_total; i++)	//Printing Record of Customer
			cust[i].viewDetails();
	}
	if(!fin)
	{
		cout<<"File Doesn't Exists"<<endl;
	}
	int LID=0;
	
	int card_total=0;
	char ans=' ';
	char ch=' ';
	LoyaltyCard *obj=NULL;/*=new LoyaltyCard[size];*/	//declaring a pointer of LoyaltyCard class to read and store data from file into the pointer
	int size2=0;
	ifstream myfile;
	myfile.open("card.txt", ios::in);
	if(myfile)
	{
		//Reading no# of cards
		myfile >> size2;
		card_total = size2+size;
		obj=new LoyaltyCard[card_total];
		int l = 0;
		while(!(myfile.eof()))
		{
			int num=0;
			LoyaltyCard l1;
			string s;
			//reading card type;
			myfile>>s;
			l1.setCardType(s);

			myfile>>num;
			//read card id
			l1.setLoyaltyID(num);

			//reading rfid
			myfile>>num;
			l1.setRFID(num);

			//reading points
			myfile>>num;
			l1.setLoyaltyPoints(num);

			//reading discount value
			myfile>>num;
			l1.setCardDiscount(num);

			//reading joining date;
			myfile>>s;
			l1.setDateJoined(s);

			//reading expiry date
			myfile>>s;
			l1.setExpiryDate(s);

			obj[l]=l1;
			//obj[l].printDetails();
			l++;	
		}
		myfile.close();
	}
	else
	{
		cout<<"File Doesn't Exists"<<endl;
	}
	int card_count=size2;	//total cards in file
	
	char up_point;

	int CID=0;
	do
	{
	bool foundCID=false;
	cout<<"Enter L To Update Loyalty Points"<<endl;
	cout<<"Enter Q To Quit"<<endl;
	cout<<"Enter Your Option:";
	cin>>up_point;
	if(up_point=='L'||up_point=='l')
	{
		int j=0;
		cout<<"Enter Customer ID to Update Loyalty Points:"	;//Asking Admin To Provide Customer ID
		cin>>CID;
		for(;j<size;j++)
		{
			if(cust[j].getCustomerID()==CID)	//Verifiyng if the Customer ID is Valid or not
			{
				foundCID=true;
				break;
			}
		}
		if(foundCID==true)	//if customer ID is Valid then we will further assign him a card or update his points based on the value admin provides to update loyalty points
		{
			int ID=cust[j].getLoyaltyCardId();
			cust[j].UpdatePoints(ID);	//Updating customer's Loyalty Points
			int LP=cust[j].getLoyaltyPoints();
			//cout<<LP<<endl;
			int x=card_count;
			for(;x<size;x++)
			{
				if(LP>=500&&LP<1500)	//Limit of Loyalty Points to be assigned a Silver Card
				{
					cout<<"Customer has been Assigned a Silver Card"<<endl;
					int ID=cust[j].getLoyaltyCardId();
					if(ID==0)	//If customer is previously not assigned a loyalty card,here in this condition he/she will be assigned a new loyalty card
					{
						SilverCard s1;	//child class object called to assign the card
						s1.AssignCard(cust[j],"2-Dec-2022",20,"2-Dec-2024");	
						cust[j].setLoyaltyCardId(s1.getLoyaltyID());
						s1.AssignPoints(LP);
						s1.printDetails();
						obj[x]=s1;	//child class object assigned to parent class pointer to store data in the array for data management
						card_count++;	//	card count increases by 1 as a new card is assigned
						break;
					}
					else if(ID!=0)//if customer has been assigned a card previously,here we will only update his loyalty points
					{
						int i=0;
						for(;i<card_count;i++)
						{
							if(obj[i].getLoyaltyID()==ID)
								break;
						}
						if(obj[i].getCardType()=="Silver")
						{
							obj[i].setLoyaltyPoints(LP);
							break;
						}	
					}
				}
				if (LP>=1500&&LP<3000)  //Limit of Loyalty Points to be assigned a Gold Card
				{
					cout<<"Customer has been Assigned a Gold Card"<<endl;
					int ID=cust[j].getLoyaltyCardId();
					if(ID==0)	//If customer is previously not assigned a loyalty card,here in this condition he/she will be assigned a new loyalty card
					{
						GoldCard g1;	//child class object called to assign the card
						g1.AssignCard(cust[j],"2-Dec-2022",30,"2-Dec-2024");
						cust[j].setLoyaltyCardId(g1.getLoyaltyID());
						g1.AssignPoints(LP);
						g1.printDetails();
						obj[x]=g1;	//child class object assigned to parent class pointer to store data in the array for data management
						card_count++;	//	card count increases by 1 as a new card is assigned
						break;
					}
					else if(ID!=0)//if customer has been assigned a card previously,here we will only update his loyalty points
					{
						int i=0;
						for(;i<card_count;i++)
						{
							if(obj[i].getLoyaltyID()==ID)
								break;
						}
						if(obj[i].getCardType()=="Gold")//if the card type of customer previously is gold,we will update points for same id
						{
							obj[i].setLoyaltyPoints(LP);
							break;
						}
						else	//if the card type of customer previously is not gold and is silver instead,we will upgrade his card and assign him a new gold card with a unique id
						{
							GoldCard g1;
							g1.AssignCard(cust[j],"2-Dec-2022",30,"2-Dec-2024");
							cust[j].setLoyaltyCardId(g1.getLoyaltyID());
							g1.AssignPoints(LP);
							g1.printDetails();
							obj[i]=g1;	//since we're assigning the same customer a new card the old information of card will be replaced by the new card information
							break;
						}
					}
				}
				if(LP>=3000) //Limit of Loyalty Points to be assigned a Platinum Card
				{
					cout<<"Customer has been Assigned a Platinum Card"<<endl;
					int ID=cust[j].getLoyaltyCardId();
					if(ID==0)	//If customer is previously not assigned a loyalty card,here in this condition he/she will be assigned a new loyalty card
					{
						PlatinumCard p1;	//child class object called to assign the card
						p1.AssignCard(cust[j],"2-Dec-2022",50,"2-Dec-2024");
						cust[j].setLoyaltyCardId(p1.getLoyaltyID());
						p1.AssignPoints(LP);
						p1.printDetails();
						obj[x]=p1;	//child class object assigned to parent class pointer to store data in the array for data management
						card_count++;//	card count increases by 1 as a new card is assigned
						break;
					}
					else if(ID!=0)//if customer has been assigned a card previously,here we will only update his loyalty points
					{
						int i=0;
						for(;i<card_count;i++)
						{
							if(obj[i].getLoyaltyID()==ID)
								break;
						}
						if(obj[i].getCardType()=="Platinum")//if the card type of customer previously is Platinum,we will update points for same id
						{
							obj[i].setLoyaltyPoints(LP);
							break;
						}
						else	//if the card type of customer previously is not Platinum and is Gold/Silver instead,we will upgrade his card and assign him a new gold card with a unique id
						{
							PlatinumCard p1;
							p1.AssignCard(cust[j],"2-Dec-2022",50,"2-Dec-2024");
							cust[j].setLoyaltyCardId(p1.getLoyaltyID());
							p1.AssignPoints(LP);
							p1.printDetails();
							obj[i]=p1;//since we're assigning the same customer a new card the old information of card will be replaced by the new card information
							break;
						}
					}
				}
			}
		}
		else
		{
			cout<<"Cannot Find The Customer"<<endl;
		}
	}
	if(up_point=='Q'||up_point=='q')
	{
		break;
	}
	}while(up_point!='Q'||up_point!='q');
	
	//--------------------------------FILE WRITING----------------------------------------
	//

	//------------------------------------------code for writing-------------------------------------------------------//
	//----------------------------------------writing in card file--------------------------------------------------//
	ofstream myfile2;
	myfile2.open("card.txt",ios::out|ios::trunc);
	if(myfile2)
	{
		myfile2<<card_count<<endl;
		for(int i=0;i<card_count;i++)
		{
			//writing Card type
			myfile2<<obj[i].getCardType()<<" ";
			//writing Loyalty ID
			myfile2<<obj[i].getLoyaltyID()<<" ";
			//writing RFID
			myfile2<<obj[i].getRFID()<<" ";
			//writing Loyalty Points
			myfile2<<obj[i].getLoyaltyPoints()<<" ";
			//writing Discount Value
			myfile2<<obj[i].getDiscountVal()<<" ";
			//writing Date Joined
			myfile2<<obj[i].getDateJoined()<<" ";
			//writing Expiry Date
			myfile2<<obj[i].getExpDate()<<endl;
		}
		myfile2.close();
	}
	else
	{
		cout<<"File Doesn't Exists"<<endl;
	}
//	---------------------------------------------------------------writing in customer file--------------------------------------------
	ofstream fout;
	fout.open("Customer.txt",ios::out|ios::trunc);
	if(fout)
	{
		fout<<size<<endl;
		for (int i=0;i<size;i++)
		{
			//writing Customer ID;
			fout<<cust[i].getCustomerID()<<" ";
			//writing Name
			fout<<cust[i].getName()<<" ";
			//writing Address
			fout<<cust[i].getAddress()<<" ";
			//writing Contact
			fout<<cust[i].getContact()<<" ";
			//writing Password
			fout<<cust[i].getPassword()<<" ";
			//writing Items Bought
			fout<<cust[i].getNo_of_itemsBought()<<" ";
			//writing Items Returned
			fout<<cust[i].getNo_of_Returns()<<" ";
			//writing Loyalty Card ID
			fout<<cust[i].getLoyaltyCardId()<<" ";
			//writing Loyalty Points
			fout<<cust[i].getLoyaltyPoints();
			if(i<(size-1))
			{
				fout<<"\n";
			}
		}
		fout.close();
	}
	else
	{
		cout<<"File Doesn't Exists"<<endl;
	}


	system("pause");
	return 0;
}