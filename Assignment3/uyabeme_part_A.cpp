// Assignment3.cpp : Defines the entry point for the console application.
/*Program description: */

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
	person(char * name, long social_insurance_number);
	void set_name(char * name);
	char * get_name();
	void set_social_insurance_number(long social_insurance_number);
	long get_social_insurance_number();
};




int main()
{
	person person1("Ted", 5);

    return 0;
}

person::person(char * name, long social_insurance_number) {
	this->name = name;
	this->social_insurance_number = social_insurance_number;
}