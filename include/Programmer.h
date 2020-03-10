#pragma once
#include "Engineer.h"
class Programmer : public Engineer {
public:
	Programmer() : Engineer() {};
	Programmer(int id, string name, int worktime, int base, string project, int budget, double deposit) {
		this->id = id;
		this->name = name;
		this->base = base;
		this->project = project;
		this->worktime = worktime;
		this->budget = budget;
		this->deposit = deposit;
		calculatePayment();
	}

	void calculatePayment() override //зп ставка + бонусы от проекта
	{
		this->payment = (
			WorkTimePaymentMethod(this->worktime, this->base) +
			ProjectPaymentMethod(budget, deposit)
			);
	}
	~Programmer() {}
};