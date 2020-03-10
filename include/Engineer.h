#pragma once
#include "Employee.h"
#include "WorkTime.h"
#include "Project.h" 
//ставка с почасовой оплатой и бонусы за участие в проектах
class Engineer : public Employee, public WorkTime, public Project {
protected:
	int base;	//ставка	
	double deposit;	//вклад
	string project;	//проект
	int budget;	//бюджет	

public:
	Engineer() : Employee() {}; //конструктор по умолчанию наследуемый у Employee
	int WorkTimePaymentMethod(int work_time, int base) override { //рассчитать зп по ставке
		int payment = work_time * base;
		return payment;
	}


	int ProjectPaymentMethod(int budget, double deposit) override { //зп от учетом бонуса от выполняемого проекта
		int bonus = budget * deposit;
		return bonus;
	}

	void setBase(int base) { //установить ставку
		this->base = base;
	}

	int getBase() const { //получить тек ставку
		return base;
	}

	void setDeposit(double depos) { //установить депозит
		this->deposit = depos;
	}

	double getDeposit() { //получить тек депозит
		return deposit;
	}

	void setProject(string project_name) { //задать проект
		this->project = project_name;
	}

	string getProject() { //получить проект
		return project;
	}

	~Engineer() {}
};