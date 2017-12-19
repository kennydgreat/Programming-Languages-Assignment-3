// Assignment3.cpp : Defines the entry point for the console application.
/*Program description: */

#define _CRT_SECURE_NO_WARNINGS
#include "stdafx.h"
#include <iostream>
#define NUM_OF_WEEKS_IN_YEAR 52
#define ONE 1
#define NUMBER_OF_WORK_HOURS_IN_WEEK 40
#define ZERO 0
using namespace std;
//----------------------------------------------------------------------------------
//Classes 


/*person is the base class with the private members
	1) name: name of the person(a pointer to a char)
	2) social_insurance_number: the person's sin number
*/
class person {
	char * name;
	long social_insurance_number;
	//constructors and non member functions
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
class HourlyEmployee : virtual public person {
	double rate;
public:
	void set_rate(double rate);
	double get_rate();
	virtual void set_hours(double hours);
	double get_hours();
	virtual double weekly_pay();
protected:
	double hours;
};

/*This class is derived from Person
it has a double "salary" memeber*/
class SalariedEmployee : virtual public person {
	double salary;
public:
	void set_salary(double salary);
	double get_salary();
	double weekly_pay();
};
/*This class inherts from the "HourlyEmployee" and "SalariedEmployee" class
	It has it's very own "set_hours" also has a weeklyPay() method that calls the weeklyPay() 
	methods from each Base class and adds the results*/

class HybridEmployee : public HourlyEmployee, public SalariedEmployee {
public : 
	void set_hours(double hours);
	double weekly_pay();
};


//--------------------------------------------------------------------------------------
// Main Function

int main()
{
	person person1("Ted", ZERO);
	char * name = "Kolo";
	person1.set_name(name);
	person1.print();

	HourlyEmployee emp1;
	SalariedEmployee emp2;
	HybridEmployee emp3;
	HourlyEmployee * emp4 = &emp3;
	emp1.print();
	emp2.print();
	emp3.print();
	emp4->print();
	emp3.set_hours(9);
	cout << "emp3's hours before changed by pointer is " << emp3.get_hours() << " \n";
	emp1.set_hours(5);
	emp4 = &emp3;
	emp4->set_hours(45);
	// emp3 hours is now 5
	cout << "emp1's hours is " << emp1.get_hours() << " \n";
	cout << "emp3's hours is " << emp3.get_hours() << " \n";
	cout << "emp4's hours is " << emp4->get_hours() << " \n";
	emp1.set_rate(3);
	cout <<"emp1's rate is "<<  emp1.get_rate() << " \n";
	emp2.set_salary(3);
	emp3.set_rate(2);
	emp3.set_salary(52);
	//rate is 2
	cout << "emp2's salary is " <<emp2.get_salary() << " \n";
	cout << "emp1's weekly pay is " << emp1.weekly_pay()<< " \n"; 
	cout << "emp2's weekly pay is " << emp2.weekly_pay() << " \n";
	cout << "emp3's weekly pay is " << emp3.weekly_pay() << " \n";
	//weekly_pay should be 52/52 + 5*2
    return 0;
}

//-------------------------------------------------------------------------------
//Person nonmember functions
/*This default constructor of the Person class
1) sets the "name" memeber to "NOT GIVEN" using the set_name method
2) sets the SIN number to 0*/
person::person() {
	this->set_name("NOT GIVEN");
	this->set_social_insurance_number(ZERO); 
}
/*This constructor takes a string name and a long SIN then
1)Sets the "name" memeber to the name parameter using the set_name() method
3) sets the "social_insurance_number" memeber to the SIN parameter*/
person::person(char * name, long social_insurance_number) {
	this->set_name(name);
	this->social_insurance_number = social_insurance_number;
}

/*THis is the decontructor of the Perosn class it
1) frees the block of memory that the "name" memeber points to  which was
   allocated when "set_name" is called*/
person::~person() {
	delete name;
	cout << "The deconstructor is called: name has been deleted.\n";
}

/*This method
1) finds out the number of characters in the name parameter
2) allocates that much space and set the name memeber to point it
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
	cout << "Name: " << name << ", SIN: " << social_insurance_number << " \n";
}
/*This method 
1) sets the"social_insurance_number" member to a person object to the SIN parameter */
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
	return salary/NUM_OF_WEEKS_IN_YEAR ;
}
//----------------------------------------------------------------------------------
// HybridEmployee member functions

/*This method
1) Sets the "hours" memeber from the HybridEmployee's base class (HourlyEmployee) to 
	the number of hours passed 40 from the hours parameter and 0 if the paramter is less 
	than 40*/
void HybridEmployee::set_hours(double hours) {
	if (hours > NUMBER_OF_WORK_HOURS_IN_WEEK) this->hours = hours - NUMBER_OF_WORK_HOURS_IN_WEEK;
	else this->hours = ZERO;
}
/*This method 
1)calculates the weekly_pay of a HybridEmployee by calling weekly_pay() methods 
both base classes (HourlyEmployee and SalariedEmployee) and adds the results
*/
double HybridEmployee::weekly_pay() {
	return this->HourlyEmployee::weekly_pay() + this->SalariedEmployee::weekly_pay();
}