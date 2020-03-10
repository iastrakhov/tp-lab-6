#ifndef MANAGER_H
#define MANAGER_H

#include "Employee.h"
#include "Project.h"
#include "WorkProject.h"

#include <vector>

class Manager : public Employee, public Project
{
protected:
	float project_participation;
	int project_budget;
public:
	Manager(int, string, float, int);
	float calculate_payment_by_project() override;
	void  calculate_payment() override;
};

#endif MANAGER_H
