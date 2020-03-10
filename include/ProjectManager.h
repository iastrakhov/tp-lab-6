#pragma once
#include "Manager.h"
#include "Heading.h"

class ProjectManager : public Manager, public Heading {
protected:
	int salary;
public:
	ProjectManager() : Manager() { this->salary = 0; };

	ProjectManager(int id, string name, string project, int budget, double deposit, int salary) {
		this->id = id;
		this->name = name;
		this->project = project;
		this->salary = salary;
		this->budget = budget;
		this->deposit = deposit;
		this->worktime = 0;
		calculatePayment();
	}

	void calculatePayment() override {
		this->payment = (
			ProjectPaymentMethod(this->budget, this->deposit) +
			HeadingPaymentMethod(this->salary)
			);
	}
	//метод рассчитать зп исходя из кол-ва подчиненных
	int HeadingPaymentMethod(int sal) override {
		int salary = sal * 1000;
		return salary;
	}
	~ProjectManager() {}
};
