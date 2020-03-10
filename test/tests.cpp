#include "gtest/gtest.h"
#include "Creator.h"

TEST(Driver, calculate_payment)
{
	WorkProject* project1 = new WorkProject("project_1", 100000);
	WorkProject* project2 = new WorkProject("project_2", 200000);
	WorkProject* project3 = new WorkProject("project_3", 300000);
	vector<WorkProject*> projects = { project1, project2, project3 };
	EmployeeFactory EF = EmployeeFactory(projects);
	vector<string> data = {"Surname_2 First_name_2 Second_name_2", "Driver", "150"};
	Employee* employee = EF.create(data);
	employee->calculate_payment();
	int emp_payment = employee->get_payment();
	EXPECT_EQ(emp_payment, 24000);
}