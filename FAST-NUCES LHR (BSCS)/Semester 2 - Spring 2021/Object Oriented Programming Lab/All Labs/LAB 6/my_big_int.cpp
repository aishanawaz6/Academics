#include <iostream>
#include "my_big_int.h"
#include <cmath>
using namespace std;

BiggerInt :: BiggerInt() {

	big_int_ = nullptr;


}
BiggerInt::BiggerInt(const int* obj, int size) {

	for (int i = 0; i < int_length_; i++) 
	{
		big_int_ [i] = *(obj+ i);
	}
this->int_length_=size;


}
BiggerInt::BiggerInt(const BiggerInt& obj) {
	cout<<"Copy Constructor Called"<<endl;
	for (int i = 0; i < int_length_; i++)
	{
		*(big_int_ + i) = *(obj.big_int_ + i);
	}
	this->int_length_ = obj.int_length_;


}	
void BiggerInt::assign(const BiggerInt& obj) {

	for (int i = 0; i < int_length_; i++)
	{
		*(big_int_ + i) = *(obj.big_int_ + i);
	}
	this->int_length_ = obj.int_length_;
}
void BiggerInt::assign(const int* big_int, int size) {
	for (int i = 0; i < int_length_; i++)
	{
		*(this->big_int_ + i) = *(big_int + i);
	}
	this->int_length_ = size;
}
void BiggerInt::append(BiggerInt& obj) {
	int t = this->int_length_;
	this->int_length_ = obj.int_length_ + t;
	int j = 0;
	for (int i =t,j=0; j < obj.int_length_;i++,j++) {
		*(this->big_int_ + i) = *(obj.big_int_ + j);
	}
	
}
void BiggerInt::append(const int* big_int, int size) {
	int t = this->int_length_;
	this->int_length_ = size + t;
	int j;
	for (int i = t,j=0; i <size+ t; i++,j++) {
		*(this->big_int_ + i) = *(big_int + j);
	}
	
}
int BiggerInt::compareTo(const BiggerInt& obj) {

 	if (*(big_int_) >*(obj.big_int_))
		return 2;
	else
		if (*(big_int_) < *(obj.big_int_))
			return 1;
		else
			return 0;



}
int BiggerInt::compareTo(const int* big_int, int size) {


	if (*(this->big_int_) < *(big_int) )
		return 2;
	else
		if (*(this->big_int_) < *(big_int))
			return 1;
		else
			return 0;
}
void BiggerInt:: display() {
	if (int_length_ == 0)
		cout << "“No Value Assigned”." << endl;
	else {
		for (int i = 0; i < this->int_length_; i++) {
 
			cout << *(this->big_int_ +i)<< " ";
		}
		cout << endl;
	}

}
BiggerInt::~BiggerInt() {
	delete big_int_;
}