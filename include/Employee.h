#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>

using namespace std;

class Employee
{
protected:
	int id;
	string name;
	int worktime;
	float payment;

public:
	Employee(int, string, int);
	virtual void calculate_payment() = 0;
	float get_payment();
	string get_name();
};

#endif