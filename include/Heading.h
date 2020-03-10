#pragma once
class Heading //расчет оплаты по руководству(кол-ву подчиненных)
{
public:
	Heading() {}
	virtual int HeadingPaymentMethod(int salary) = 0;
	~Heading() {}
};
