#ifndef TESTER_H
#define TESTER_H

#include "Engineer.h"

class Tester : public Engineer
{
public:
	Tester(int, string, int, float, float, float, int);
	void  calculate_payment() override;
};

#endif
