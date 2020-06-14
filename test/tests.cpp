#include "gtest/gtest.h"
#include "Creator.h"


TEST(Driver, calculate_payment)
{
	WorkProject* project1 = new WorkProject("project_1", 100000);
	WorkProject* project2 = new WorkProject("project_2", 200000);
	WorkProject* project3 = new WorkProject("project_3", 300000);
	vector<WorkProject*> projects = { project1, project2, project3 };
	EmployeeFactory EF = EmployeeFactory(projects);
	vector<string> data = { "A B C", "Driver", "150" };
	Employee* employee = EF.create(data);
	employee->calculate_payment();
	int emp_payment = employee->get_payment();
	EXPECT_EQ(emp_payment, 24000);
}



TEST(Tester, calculate_payment)
{
	WorkProject* project1 = new WorkProject("project_1", 100000);
	WorkProject* project2 = new WorkProject("project_2", 200000);
	WorkProject* project3 = new WorkProject("project_3", 300000);
	vector<WorkProject*> projects = { project1, project2, project3 };
	EmployeeFactory EF = EmployeeFactory(projects);
	vector<string> data = { "A B C", "Tester", "0.1", "15000", "150", "project_1" };
	Employee* employee = EF.create(data);
	employee->calculate_payment();
	int emp_payment = employee->get_payment();
	EXPECT_EQ(emp_payment, 49000);
}



TEST(ProjectManager, calculate_payment)
{
	WorkProject* project1 = new WorkProject("project_1", 100000);
	WorkProject* project2 = new WorkProject("project_2", 200000);
	WorkProject* project3 = new WorkProject("project_3", 300000);
	vector<WorkProject*> projects = { project1, project2, project3 };
	EmployeeFactory EF = EmployeeFactory(projects);
	vector<string> data = { "A B C", "ProjectManager", "0.1", "project_1", "5" };
	Employee* employee = EF.create(data);
	employee->calculate_payment();
	int emp_payment = employee->get_payment();
	EXPECT_EQ(emp_payment, 15000);
}

TEST(SeniorManager, calculate_payment)
{
	WorkProject* project1 = new WorkProject("project_1", 100000);
	WorkProject* project2 = new WorkProject("project_2", 200000);
	WorkProject* project3 = new WorkProject("project_3", 300000);
	vector<WorkProject*> projects = { project1, project2, project3 };
	EmployeeFactory EF = EmployeeFactory(projects);
	vector<string> data = { "A B C", "SeniorManager", "0.1", "17" };
	Employee* employee = EF.create(data);
	employee->calculate_payment();
	int emp_payment = employee->get_payment();
	EXPECT_EQ(emp_payment, 85500);
}
