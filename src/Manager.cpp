#include "Manager.h"

Manager::Manager(int m_id, string m_name, float m_project_participation, int m_projects_budgets) :
	Employee(m_id, m_name, 0)
{
	project_participation = m_project_participation;
	project_budget = m_projects_budgets;
}

float Manager::calculate_payment_by_project()
{

	return project_budget * project_participation;
}

void Manager::calculate_payment()
{
	payment = calculate_payment_by_project();
}