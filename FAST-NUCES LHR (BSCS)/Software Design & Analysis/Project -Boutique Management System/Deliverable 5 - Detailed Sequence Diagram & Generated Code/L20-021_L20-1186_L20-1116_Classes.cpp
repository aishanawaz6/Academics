//L20-1116, L20-1186, L20-0921 SDA DELIVERABLE 5 CODE OF CLASSES
#include <iostream>
#include <string>
using namespace std;

class Customer {
private:
	int CustomerID;
	string Name;
	string Address;
	string Contact;
	int No_of_itemsBought;
	int No_of_Returns;
	string TypeofCardHolder;
	int LoyaltyCardId;

public:
	int getCustomerID() {};
	string getName() {};
	string getAddress() {};
	string getContact() {};
	int getNo_of_itemsBought() {};
	int getNo_of_Returns() {};
	string getTypeofCardHolder() {};
	int getLoyaltyCardId() {};
	
	Customer() {};
	Customer(Customer& obj) {};
	Customer(int ID, string name, string address, string Contact) {};
	int updateCustomerID(int i) {};
	string updateName(string a) {};
	string updateAddress(string a) {};
	string updateContact(string a) {};
	string updateTypeofCardHolder(string a) {};
	int updateNo_of_itemsBought(int n) {};
	int updateNo_of_Returns(int n) {};
	int updateLoyaltyCardId(string a) {};

	void DeleteCustomer(int ID) {};
	void UpdateCustomerINFO() {};
	void viewDetails(int ID) {};
	void viewItemsBought(int ID) {};
	void ViewReturnItems(int ID) {};
	void viewTypeofCardHolder(int ID) {};

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
	void MakePayment(float totalBill, string modeOfPayement, int userId) {};
	void  changeuserid(int Billid, int userid) {};
	void changeMOdeofPayment(string modeofPayement) {};
	void viewfulluserhistory(int userid) {};
	void viewhistorybydate(string dateofpurchase) {};
};
class CustomerCart
{
private:
	int id;
	int NumberofItems;
	int customerId;
	string items;
	Payment Pay;
public:
	CustomerCart() {};
	CustomerCart(string a) : Pay() {};
	void addTocart(string items) {};
	void removeFromCart(string items) {};
	void checkout() {
		//Calculates total bill then call make payment function of payment class.
	};
};
class Product {
private:
	string productName;
	string dateAdded;
	int quantityInStock;
	string category;
	string sizesAvailable;
	string AgeGroup;
	CustomerCart cart;
public:
	int price;
	Product() {};
	Product(string a) :cart() {};
	int productNumber;
	void decreaseStock(int prouductNum, int num) {};
	void viewDetails(int productNum) {};
	void changeSizes(int productNum, string newSizes) {};
	void changecategory(int productNum, string categ) {};
	void changeageGroup(int productNum, string age) {};
	void addOrremoveFromCart() {};
};
class OnlineStore {

protected:
	int id;
	string name;
	Product Collection;
private:
	Customer customer;
public:
	OnlineStore() {};
	OnlineStore(int id, string n);
	void DisplayCollectionOnline() {};
	void Login(Customer customer) {};
	void Signup(Customer customer) {};
};
class saleRecord
{
private:
	int productNumber;
	int numberofsales;
	int totalRevenue;
public:
	saleRecord() {};
	void showSaleRecord(int productNumber, Product& Productinfo) {};
};
class storeInventory
{
public:
	int Product_id;
	int Quantity;
	int Outlet_id;

	storeInventory() {};
	void Assign_Inventory(int Product_id, int Quantity, int Outlet_id) {};
	void Update_Inventory(int Product_id, int Quantity) {};
	void  Delete_Inventory(int Product_id, int Quantity) {};
	void View_Inventory(int Product_id) {};
	void Check_Quantity(int Product_id) {};
};
class ReturnItem
{
private:
	int productNumber;
	string dateOfReturn;
	int quantity;
	int userID;
	int billID;
public:
	ReturnItem() {};
	void returnanItem(int productNum, storeInventory& restock, int billID, int quantity) {};
};
class BestSelling
{
private:
	int Product_id;
	string Product_Name;
	float Ratings;
	void AddProduct(int Product_id) {};
public:
	BestSelling() {};
	float CheckRatings(int Product_id, float Ratings, saleRecord& SR) {};
	void ApplyPromotions(int Product_id) {};
	void  DisplayBestSelling(int Product_id, string Product_Name, float Ratings, saleRecord& SR) {};
	void SearchbyCategory() {};
};



class User {
private:
	int ID;
	string  Name;
	string Address;
	string Contact;
	int WarningCount;
public:
	User() {};
	User(User& obj) {};
	User(int i, string n, string a, string c) {};
	void setID(int i) {};
	void setName(string n) {};
	void setAddress(string a) {};
	void setContact(string c) {};
	void setWarningCount(int c) {};
	int getID() {};
	int getWaningCount() {};
	string getName() {};
	string getAddress() {};
	string getContact() {};

	int updateID(int i) {};
	int UpdateWarningCount(int wc) {};
	string UpdateName(string n) {};
	string UpdateAddress(string n) {};
	string UpdateContact(string n) {};
	void View(User& obj);
	void delete_(User& obj);
};
//
class Reports
{
private:
	int reportID;
	string reportName;
protected:
	int ProductID;
	string ProductName;
	int UserID;
	string UserName;

public:
	Reports();
	Reports(int RID,string rName,int PID, string Pname, int UID, string Uname);
	void makeProductReport(int rID,string rName,saleRecord& obj);
	void makeUserReport(int rID,string rName,User& userobj);
	void CheckSaleOfProduct(saleRecord& obj);
	void RateOfSaleOfProduct(saleRecord& obj);
	void CheckWarning(User& userobj);
	void CheckRatingsofProduct(saleRecord& obj);
	void CheckReviewsofUser(User& userobj);
};

class Agent :public User
{
private:
	int OutletID;
	string WorkShift;
public:
	Agent() {};
	Agent(Agent& obj) {};
	Agent(int i, string n, string a, string c, int wc, int o, string ws) {};
	void ViewDetails(Agent& obj) {};
	string updateWorkShift(string s) {};
	int updateOutletID(int i) {};
	void DeleteSaleAgent(int ID) {};
	void UpdateSaleAgnetINFO(Agent& obj) {};
	void MarkAttendance(Agent& obj) {};
};
class Attendance {
private:
	//Agent SaleAgent;
	string Time;
	string Date;
	string description;
public:
	Attendance() {};
	Attendance(Attendance& obj) {};
	Attendance( string t, string d) {};
	void MarkAttendance(Agent& s,string t,string d,string disc);
	void updateTime(string t) {};
	void updateDate(string d) {};
	string getTime() {};
	string getDate() {};

};
class FloorManager :public User
{
private:
	int OutletID;
	Attendance A_obj;
	Agent Ag_obj;
public:
	FloorManager() {};
	FloorManager(FloorManager& obj) {};
	FloorManager(int O_ID, Attendance& a_obj, Agent& ag_obj, int i, string n, string a, string c, int wc) {};
	void ViewDetails(FloorManager& obj) {};
	int getOutletID() {};
	int updateOutletID(int i) {};
	void DeleteFloorManager(FloorManager& obj) {};
	void UpdateFloorManagerINFO(FloorManager& obj) {};
	int updateWarningCount(int wc) {};
	void TrackAttendance() {};
	void updateWorkShift(Agent& obj, string newShift) {};
	void RunReport(int ReportID,Reports&obj) {};
	void ReturnItem(int ItemID, int BillNo, int quantity) {};
};
class InventoryManager :public User
{
private:
	int OutletID;
	storeInventory IM_obj;
public:
	InventoryManager() {};
	InventoryManager(InventoryManager& obj) {};
	InventoryManager(int O_ID, storeInventory& si_obj, int i, string n, string a, string c, int wc) {};
	void ViewDetails(InventoryManager& obj) {};
	void DeleteInventoryManager(InventoryManager& obj) {};
	int updateOutletID(int i) {};
	void UpdateInventoryManagerINFO(InventoryManager& obj) {};
	void ReserveStockPolicy() {};
	void ManagingStoreInventory() {};
};

class Outlet {
private:

	int StoreManagerID;
	int InventoryManagerID;
	int FloorManagerID;
	int AdminID;
public:

	string Address;
	string Contact;
	int OutletID;
	Outlet() {};
	Outlet(int oid, string addr, string cnt);
	Outlet(int oID, int smID, int imID, int fmID, int aID, string add, string c);
	int updateOutletID(int i) {};
	int updateStoreManagerID(int i) {};
	int updateInventoryManagerID(int i) {};
	int updateFloorManagerID(int i) {};
	int updateAdminID(int i) {};
	void Display(Outlet& obj) {};
};
//
class StorePolicy
{
private:
	int Policy_Id;
	string Policy_Title;
	bool Validity;
	string Description;
	Outlet otobj;
public:
	StorePolicy();
	StorePolicy(int PolId, string PolDes, bool Val) :otobj() {};
	void definePolicy(int PID, bool Val, string PTitle, string Desc);
	void updatePolicy(int PID, string Desc, bool Val);
	bool checkValidity(int PID);
};

class StoreManager :public User
{
private:
	int OutletID;
	StorePolicy SP_obj;
public:
	StoreManager() {};
	StoreManager(StoreManager& obj) {};
	StoreManager(int oID, Reports& r_obj, StorePolicy& sp_obj, int i, string n, string a, string c, int wc) {};
	void ViewDetails(StoreManager& obj) {};
	void DeleteStoreManagert(StoreManager& obj) {};
	int updateOutletID(int i) {};
	void UpdateStoreManagerINFO(StoreManager& obj) {};
	void ModifyDiscountPolicy() {};
	void ModifyRule() {};
	void RunMonthlyReport(Reports &R_obj) {};
	void RunAnnuallyReport(Reports &R_obj) {};
	int updateWarningCount(int wc) {};
};
class Admin {
private:
	int StoreAdminID;
	string Name;
	string Address;
	string Contact;
	Outlet* outlet;
public:
	Admin() {};
	Admin(Admin& obj) {};
	Admin(int i, string n, string a, string c) {};
	void ViewDetails(Admin& obj) {};
	void DeleteAdmin(Admin& obj) {};
	void UpdateAdminINFO(Admin& obj) {};
	int updateAdminID(int i) {};
	string updateAdminName(string n) {};
	string updateAdminAddress(string a) {};
	string updateAdminContact(string) {};
	void DeActivateAccount(User& obj) {};
	void AssignRolesToUser(User& obj, string role) {};

	void CreateOutlet() {};
	void  UpdateOutlet(Outlet& outlet) {};
	void  BlockOutlet(Outlet& outlet) {};
	void  DeleteOutlet(Outlet& outlet) {};
	void  OpenOutlet(Outlet& outlet) {};
	void CloseOutlet(Outlet& outlet) {};
	void RelocateOutlet(Outlet& outlet) {};
};



class SJBotique
{
private:
	int outletID;
	string Address;
	string Contact;
	int OnlineID;
	string name;
	OnlineStore obj_on;
	Outlet obj_ot;
public:
	SJBotique();
	SJBotique(int on_id, string n) :obj_on(on_id, n) {};
	SJBotique(int outletId, string addr, string cnt) :obj_ot(outletId, addr, cnt) {};
	void ViewallOutlets();
	void ViewallOnline();
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
public:
	Customer cust_obj;
	LoyaltyCard();
	LoyaltyCard(int LID, int LPoints, int rfid);
	int setDiscountVal(int DisVal);
	int getDiscountVal();
	void AssignCard(int LID, int rfid, Customer cust_obj, string Datejoined);
	void AssignPoints(int LID, int LPoints);
	void RedeemPoints(Customer cust_obj, int LID, int LPoints);
	void UpdatePoints(int LID, int LPoints);
	void viewDateofScan(int rfid, Customer cust_obj);
	void EnterCustomer(string ScanTime, Customer cust_obj, string ScanDate);
	void ExitCustomer(string ScanTime, Customer cust_obj, string ScanDate);
	void checkCardValidity(int LID, string ExpDate);
	virtual void printDetails();
	virtual void viewDiscounts(Customer cust_obj, int LID, int Disval);
	virtual void DiscountsUsed(Customer cust_obj, int LID, int Disval);
	virtual void UpdateDiscounts(int LID, int Disval);
	virtual void ApplyDiscounts(int LID, int Disval);
};
class GoldCard :public LoyaltyCard
{
private:
	int GoldId;
public:
	GoldCard();
	GoldCard(int GID);
	void AssignCard(int GId, Customer cust_obj, int val);
	void viewDiscounts(Customer cust_obj, int GId, int val);
	void DiscountsUsed(Customer cust_obj, int GId, int val);
	void UpdateDiscounts(int GID, int val);
	void ApplyDiscounts(int GID, int val);
	void printDetails();
};
class SilverCard :public LoyaltyCard
{
private:
	int SilverId;
public:
	SilverCard();
	SilverCard(int SID);
	void AssignCard(int SId, Customer cust_obj);
	void viewDiscounts(Customer cust_obj, int SId, int val);
	void DiscountsUsed(Customer cust_obj, int SId, int val);
	void UpdateDiscounts(int SID, int val);
	void ApplyDiscounts(int SID, int val);
	void printDetails();
};
class PlatinumCard :public LoyaltyCard
{
private:
	int PlatinumId;
public:
	PlatinumCard();
	PlatinumCard(int PID, int val);
	void AssignCard(int PId, Customer cust_obj, int val);
	void viewDiscounts(Customer cust_obj, int PId, int val);
	void DiscountsUsed(Customer cust_obj, int PId, int val);
	void UpdateDiscounts(int PID, int val);
	void ApplyDiscounts(int PId, int val);
	void printDetails();
};
class Campaign
{
private:
	int Campaign_Id;
	string Name;
	string StartDate;
	string EndDate;
	float DiscountValue;
public:
	Campaign();
	Campaign(int CID, string n, string SDate, string EDate, float DisVal);
	void view_CampaignDetails(int CID, Product& obj, float DisVal);
	void viewDiscountItems(Product& obj);
	void apply_Discount(Product& obj);
	void addCampaign(int CID, string n, string SDate, string EDate, float DisVal);
};


int main()
{
		
	cout << "Hello World!" << endl;
	system("pause");
}