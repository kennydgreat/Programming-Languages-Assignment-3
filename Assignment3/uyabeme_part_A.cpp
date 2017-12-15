// Assignment3.cpp : Defines the entry point for the console application.
/*Program description: */

#define _CRT_SECURE_NO_WARNINGS
#include "stdafx.h"
#include <iostream>

using namespace std;

/*person is the base class with the private members
	1) name: name of the person(a pointer to a char)
	2) social_insurance_number: the person's sin number
*/
class person {
	char * name;
	long social_insurance_number;
	//constructor and non member functions
public: 
	person();
	person(char * name, long social_insurance_number);
	~person();
	void set_name(char * name);
	char * get_name();
	void set_social_insurance_number(long social_insurance_number);
	long get_social_insurance_number();
	void print();
};

/*This class is derived from Person
	it has a double "rate" memeber and a double "hours" members*/
class HourlyEmployee : public person {
	double rate;
	double hours;
public:
	void set_rate(double rate);
	double get_rate();
	void set_hours(double hours);
	double get_hours();
	double weekly_pay();
};

class SalariedEmployee : public person {
	double salary;
public:
	void set_salary(double salary);
	double get_salary();
	double weekly_pay();
};





int main()
{
//person person1("Ted", 5);
//	person1.print();
//	char * name = person1.get_name();
//	char * name1;
//	//person1.set_name(name);
//	//name1 = person1.get_name();
////	cout << name1 << "\n";

	HourlyEmployee emp1;
	emp1.set_hours(5);
	cout << "emp1's hours is " << emp1.get_hours() << " \n";
	emp1.set_rate(3);
	cout <<"emp1's rate is "<<  emp1.get_rate() << " \n";
	SalariedEmployee emp2;
	emp2.set_salary(3);
	cout << "emp2's salary is " <<emp2.get_salary() << " \n";
	cout << "emp1's weekly pay is " << emp1.weekly_pay()<< " \n"; 
	cout << "emp2's weekly pay is " << emp2.weekly_pay() << " \n";
    return 0;
}


person::person() {}
/*This constructor takes a string name and a long SIN then
1) finds out the number of characters in the name parameter
2) allocates that much space and set name memeber to point it
3) sets the "social_insurance_number" memeber to the SIN parameter*/
person::person(char * name, long social_insurance_number) {
	size_t num_of_char = strlen(name);
	this->name = new char[num_of_char + 1];
	if (!name) {
		cout << "name memory allocation failed!\n";
		exit(1);
	}
	strcpy(this->name, name);

	this->social_insurance_number = social_insurance_number;
}

/*THis is the decontructor of the Perosn class it
1) free the block of memory that the "name" memeber points
   allocated when "set_name" is called*/
person::~person() {
	delete name;
	cout << "The deconstructor is called: name has been deleted.\n";
}

/*This method
1) finds out the number of characters in the name parameter
2) allocates that much space and set name memeber to point it
3) copies the name parameter into the newly allocated space*/
void person::set_name(char * name) {
	size_t num_of_char = strlen(name);
	this->name = new char[num_of_char+1];
	if (!name) {
		cout << "name memory allocation failed!\n";
			exit(1);
	}
	strcpy(this->name, name);
}

/*This method 
1) returns the name member of the Person object*/
char * person::get_name() {
	return name;
}
/*This method
1) Prints out all instance variables of a person object*/
void person::print() {
	cout << "Name: " << name << ", SIN: " << social_insurance_number;
}

void person::set_social_insurance_number(long social_insurance_number) {
	this->social_insurance_number = social_insurance_number;
}
/*
	This method 
	1) gets the "social_insurance_number" member of a Person object
*/
long person::get_social_insurance_number() {
	return social_insurance_number;
}
//-------------------------------------------------------------------------------------
// HourlyEmlpoyee nonmember functions


/*This method 
1) set the "rate" memebr of a HourlyEmployee object to the rate parameter.*/
void HourlyEmployee::set_rate(double rate) {
	this->rate = rate;
}
/*This method 
1) returns the "rate" memeber of a HourEmployee object*/
double HourlyEmployee::get_rate() {
	return this->rate;
}
/*This method
1) Sets the "hours" memebr of a HourlEmployee object to the hours parameter*/
void HourlyEmployee::set_hours(double hours) {
	this->hours = hours;
}
/*This function
1) returns the "hours" memeber of a HourlyEmployee object*/
double HourlyEmployee::get_hours() {
	return this->hours;
}
/*This is the HourlsEmployee object's version of the "weekly_pay" function. it
1) returns the "hours" member multiplied by the "rate " member of the object*/
double HourlyEmployee::weekly_pay() {
	return hours*rate;
}
//-----------------------------------------------------------------
// SalariedEmployee memeber functions

/*this method 
1) Sets the "salary" memebr of a SalariedEmployee object to the salary parameter*/
void SalariedEmployee::set_salary(double salary) {
	this->salary = salary;
}
/*This function
1) returns the "salary" memebr of the SalariedEmployee object
*/

double SalariedEmployee::get_salary() {
	return salary;
}

/*This is the SalariedEmployee object's version of the "weekly_pay" function. it
1) returns the "salary" member divided by 52 */
double SalariedEmployee::weekly_pay() {
	return salary/52 ;
}