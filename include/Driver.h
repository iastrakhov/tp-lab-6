#ifndef DRIVER_H
#define DRIVER_H

#include "Personal.h"

class Driver : public Personal
{
public:
	Driver(int, string, int, float);
	float calculate_payment_by_worktime() override;
	
};

#endif DRIVER_H
