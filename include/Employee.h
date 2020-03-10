#pragma once
#include <string>

using namespace std;
//основной родительский класс для всех методов
class Employee
{
protected:

	int id;
	string name;
	int worktime;
	int payment;

public: //описываем методы

	Employee() {}	//конструктор по умолчанию

	Employee(int id, string name, int worktime, int payment) { //конструктор с параметрами (id, фио, отработанное время)
		this->id = id;
		this->name = name;
		this->worktime = worktime;
	}
	virtual void calculatePayment() = 0; //унив метод установки зп

	void setID(int id) { //присвоить  id
		this->id = id;
	}

	int getID() const { //получить  id
		return id;
	}

	void setFIO(string name) { //назначить фио
		this->name = name;
	}

	string getFIO() const { //получить фио
		return name;
	}

	void setWorkTime(int worktime) { //присвоить отработанное время
		this->worktime = worktime;
	}

	int getWorkTime() const { //получить отработанное время
		return worktime;
	}

	int getPaymentTime() const { //получить рабочее время работника
		return payment;
	}

	~Employee() {}
};