#include "TeamLeader.h"

TeamLeader::TeamLeader(int t_id, string t_name, int t_worktime, float t_rate, float t_pay_in_hour, float t_progect_participation,
	int t_project_budget, int t_subordinates) :
	Programmer(t_id, t_name, t_worktime, t_rate, t_pay_in_hour, t_progect_participation, t_project_budget)
{
	subordinates = t_subordinates;
}

float TeamLeader::calculate_payment_by_heading()
{
	return subordinates * 1000;
}

void TeamLeader::calculate_payment()
{
	payment = calculate_payment_by_project() + calculate_payment_by_worktime() + calculate_payment_by_heading() + rate;
}