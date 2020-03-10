#ifndef TEAMLEADER_H
#define TEAMLEADER_H

#include "Programmer.h"
#include "Heading.h"

class TeamLeader : public Programmer, public Heading
{
protected:
	int subordinates;
public:
	TeamLeader(int, string, int, float, float, float, int, int);
	float calculate_payment_by_heading() override;
	void  calculate_payment() override;
};

#endif
