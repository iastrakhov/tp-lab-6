#pragma once
#include"ProjectManager.h"
//руководитель направления
class SeniorManager : public ProjectManager {
private:
	int pjcts_amount;

public:
	SeniorManager() : ProjectManager() { this->pjcts_amount = 0; };

	SeniorManager(int id, string name, int pjcts_amount, double deposit, int salary) {
		this->id = id;
		this->name = name;
		this->pjcts_amount = pjcts_amount;
		this->salary = salary;
		this->deposit = deposit;

		this->worktime = 0;
		calculatePayment();
	}
	//рассчитать зп исходя из участия в проекте
	int ProjectPaymentMethod(int whole_budget, double deposit) override
	{
		int payment = whole_budget * this->deposit * this->pjcts_amount;
		return payment;
	}
	//установить зп
	void calculatePayment() override
	{
		this->payment = (
			ProjectPaymentMethod(1000, this->deposit) +
			HeadingPaymentMethod(this->salary)
			);
	}
	~SeniorManager() {}
};
