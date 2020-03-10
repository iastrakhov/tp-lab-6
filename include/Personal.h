#pragma once
#include "Employee.h"
#include "WorkTime.h"
//СТАВКА ЗА ЧАС
class Personal : public Employee, public WorkTime {
protected:
	int base; //ставка

public:

	Personal() {} //констр по умолчанию

	void setBase(int base) { //установить ставку
		this->base = base;
	}

	int getBase() const { //получить  ставку
		return base;
	}

	~Personal() {}
};