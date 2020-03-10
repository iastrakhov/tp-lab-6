#pragma once
#include "Engineer.h"

class Tester : public Engineer {
public:
	Tester() : Engineer() {};

	Tester(int id, string name, int worktime, int base, string project, int budget, double deposit) {
		this->id = id;				
		this->name = name;			
		this->base = base;			
		this->project = project;	
		this->worktime = worktime;	
		this->budget = budget;		
		this->deposit = deposit;	

		calculatePayment();			
	}

	void calculatePayment() override
	{
		this->payment = (WorkTimePaymentMethod(this->worktime, this->base) + ProjectPaymentMethod(this->budget, this->deposit));
	}
	~Tester() {}
};
