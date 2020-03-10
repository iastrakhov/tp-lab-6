#include "Personal.h"

Personal::Personal(int pers_id, string pers_name, int pers_worktime, float pers_rate) : Employee(pers_id, pers_name, pers_worktime)
{
	rate_in_hour = pers_rate;
}

float Personal::calculate_payment_by_worktime()
{
	return rate_in_hour * worktime;
}

void Personal::calculate_payment()
{
	payment = calculate_payment_by_worktime();
}