#pragma once
#include "Programmer.h"
#include "Heading.h"

class TeamLeader : public Programmer, public Heading {
protected:
	int salary;
public:
	TeamLeader() : Programmer() { this->salary = 0; };

	TeamLeader(int id, string name, int worktime, int base, string project, int budget, double deposit, int salary) {
		this->id = id;
		this->name = name;
		this->base = base;
		this->project = project;
		this->salary = salary;
		this->worktime = worktime;
		this->budget = budget;
		this->deposit = deposit;

		calculatePayment();
	}
	//расчет зп исходя из числа подчиненнвх 
	int HeadingPaymentMethod(int salary) override {
		int pay = salary * 100;
		return pay;
	}

	void calculatePayment() {
		this->payment = (
			WorkTimePaymentMethod(this->worktime, this->base) +
			ProjectPaymentMethod(budget, deposit) +
			HeadingPaymentMethod(salary)
			);
	}
	~TeamLeader() {}
};
