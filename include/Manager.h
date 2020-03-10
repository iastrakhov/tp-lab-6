#pragma once
#include "Employee.h"
#include "Project.h"
//зп из денег проекта (которым управляет)
class Manager : public Employee, public Project {
protected:
	double deposit;
	int budget;
	string project;

public:
	Manager() {
		this->deposit = 0;
		this->budget = 0;
		this->project = "";
	}

	Manager(int id, string name, string proj, int budget, double depos) {
		this->id = id;
		this->name = name;
		this->project = proj;
		this->budget = budget;
		this->deposit = depos;

		this->worktime = 0;
		calculatePayment();
	}
	void calculatePayment() override { //метод установить зп
		this->payment = ProjectPaymentMethod(this->budget, this->deposit); //по методу участия в проекте
	}
	int ProjectPaymentMethod(int budget, double deposit) override { //метод участие в проекте
		int payment = budget * deposit;
		return payment;
	}
	void setDeposit(double depos) { //установить вклад
		this->deposit = depos;
	}
	double getDeposit() { //получить тек вклад
		return deposit;
	}

	// задать проект
	void setProject(string project_name) {
		this->project = project_name;
	}
	string getProject() { //получить проект
		return project;
	}

	~Manager() {}
};
