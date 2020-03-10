#include "Creator.h"

int id = 0,
worktime = 100;

EmployeeFactory::EmployeeFactory(vector<WorkProject*> proj)
{
	projects = proj;
}

Employee* EmployeeFactory::create(vector<string> data)
{
	id += 1;
	string employee_position = data[1];
	if (employee_position == "Cleaner")
		return new Cleaner(id, data[0], worktime, stoi(data[2]));

	else if (employee_position == "Driver")
		return new Driver(id, data[0], worktime, stoi(data[2]));

	else if (employee_position == "Programmer")
	{
		int sum_budget = 0;
		for (auto proj : projects)
		{
			if (proj->get_project_name() == data[5])
				sum_budget = proj->get_project_budget();
		}
		return new Programmer(id, data[0], worktime, stoi(data[3]), stoi(data[4]), stof(data[2]), sum_budget);
	}

	else if (employee_position == "Tester")
	{
		int sum_budget = 0;
		for (auto proj : projects)
		{
			if (proj->get_project_name() == data[5])
				sum_budget = proj->get_project_budget();
		}
		return new Tester(id, data[0], worktime, stoi(data[3]), stoi(data[4]), stof(data[2]), sum_budget);
	}

	else if (employee_position == "TeamLeader")
	{
		int sum_budget = 0;
		for (auto proj : projects)
		{
			if (proj->get_project_name() == data[5])
				sum_budget = proj->get_project_budget();
		}
		return new TeamLeader(id, data[0], worktime, stoi(data[3]), stoi(data[4]), stof(data[2]), sum_budget, stoi(data[6]));
	}

	else if (employee_position == "Manager")
	{
		int sum_budget = 0;
		for (auto proj : projects)
		{
			if (proj->get_project_name() == data[3])
				sum_budget = proj->get_project_budget();
		}
		return new Manager(id, data[0], stof(data[2]), sum_budget);
	}

	else if (employee_position == "ProjectManager")
	{
		int sum_budget = 0;
		for (auto proj : projects)
		{
			if (proj->get_project_name() == data[3])
				sum_budget = proj->get_project_budget();
		}
		return new ProjectManager(id, data[0], stof(data[2]), sum_budget, stoi(data[4]));
	}

	else if (employee_position == "SeniorManager")
	{
		int sum_budget = 0;
		for (auto proj : projects)
		{
			sum_budget += proj->get_project_budget();
		}
		return new SeniorManager(id, data[0], stof(data[2]), stoi(data[3]), sum_budget);
	}
}