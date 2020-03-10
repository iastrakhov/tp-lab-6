#include "Employee.h"

Employee::Employee(int emp_id, string emp_name, int emp_worktime)
{
	id = emp_id;
	name = emp_name;
	worktime = emp_worktime;
}

float Employee::get_payment()
{
	return payment;
}

string Employee::get_name()
{
	return name;
}