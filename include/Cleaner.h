#pragma once
#include "Personal.h"

class Cleaner : public Personal {
public:
	Cleaner(int id, string name, int worktime, int base) { //конструктор с параметрами (id,фио, ставка, отработанное время)
		this->id = id;
		this->name = name;
		this->base = base;
		this->worktime = worktime;
		calculatePayment(); //расчет заработной платы			
	}
	// метод определения зп 
	void calculatePayment() {
		this->payment = WorkTimePaymentMethod(this->worktime, this->base); //по средствам отработанного времени по ставке
	}
	// метод рассчета зп
	int WorkTimePaymentMethod(int work_time, int base) override {
		int payment = work_time * base;
		return payment;
	}
	~Cleaner() {}
};