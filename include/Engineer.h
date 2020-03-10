#ifndef ENGINEER_H
#define ENGINEER_H

#include "Employee.h"
#include "WorkTime.h"
#include "Project.h"
#include "WorkProject.h"


class Engineer : public Employee, public WorkTime, public Project
{
protected:
	float rate;
	float pay_in_hour;
	float project_participation;
	int project_budget;
public:
	Engineer(int, string, int, float, float, float, int);
	float calculate_payment_by_worktime() override;
	float calculate_payment_by_project() override;
	void  calculate_payment() override;
	
};

#endif ENGINEER_H