#pragma once
#include "Personal.h"

class Driver : public Personal
{
public:
	Driver(int id, string name, int worktime, int base) { //конструктор с параметрами (id, фио, ставка, отработанное время, зп)
		this->id = id;
		this->name = name;
		this->base = base;
		this->worktime = worktime;
		calculatePayment();
	}
	void calculatePayment() override //метод назначения зп
	{
		this->payment = WorkTimePaymentMethod(this->worktime, this->base);
	}
	int WorkTimePaymentMethod(int worktime, int base) override //метод расчета зп
	{
		this->payment = worktime * base;
		return payment;
	}
	~Driver() {}
};
