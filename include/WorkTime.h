#pragma once
//расчет зп исходя из отработанного времени(часы*ставку)

class WorkTime {
public:
	WorkTime() {}

	virtual int WorkTimePaymentMethod(int worktime, int base) = 0;
	~WorkTime() {}
};