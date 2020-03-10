#ifndef PERSONAL_H
#define PERSONAL_H

#include "Employee.h"
#include "WorkTime.h"

class Personal : public Employee, public WorkTime
{
protected:
	float rate_in_hour;
public:
	Personal(int, string, int, float);
	float calculate_payment_by_worktime() override;
	void  calculate_payment() override;
};

#endif PERSONAL_H
