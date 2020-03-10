#include "Creator.h"

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

vector<string> split(const string& s, char delimiter)
{
	vector<string> Tokens;
	string Token;
	istringstream TokenStream(s);
	while (getline(TokenStream, Token, delimiter))
		Tokens.push_back(Token);
	return Tokens;
}

int main()
{

	system("chcp 1251");

	WorkProject* project1 = new WorkProject("project_1", 100000);
	WorkProject* project2 = new WorkProject("project_2", 200000);
	WorkProject* project3 = new WorkProject("project_3", 300000);

	vector<WorkProject *> projects = { project1, project2, project3 };

	EmployeeFactory EF = EmployeeFactory(projects);

	ifstream file("staff.txt");
	vector<Employee*> staff;
	while (!file.eof())
	{
		string buf;
		getline(file, buf, '\n');
		vector<string> data = split(buf, ':');
		staff.push_back(EF.create(data));
	}

	for (auto employee : staff)
	{
		employee->calculate_payment();
		cout << "FIO: " << employee->get_name() << "   PAYMENT: " << employee->get_payment() << endl;
	}
	return 0;
}