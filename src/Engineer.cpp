#include "Engineer.h"

Engineer::Engineer(int eng_id, string eng_name, int eng_worktime, float eng_rate, float eng_pay_in_hour, float eng_project_participation,
	int eng_project_budget) :
	Employee(eng_id, eng_name, eng_worktime)
{
	rate = eng_rate;
	pay_in_hour = eng_pay_in_hour;
	project_participation = eng_project_participation;
	project_budget = eng_project_budget;
}

float Engineer::calculate_payment_by_worktime()
{
	return worktime * pay_in_hour;
}

float Engineer::calculate_payment_by_project()
{
	return project_budget * project_participation;
}

void Engineer::calculate_payment()
{
	payment = calculate_payment_by_project() + calculate_payment_by_worktime() + rate;
}