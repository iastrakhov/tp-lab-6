#pragma once
//рассчет оплаты исходя из участия (бонусы от участия в проекте/делится пропорционально вкладу в данный проект)
class Project {
public:
	Project() {}
	virtual int ProjectPaymentMethod(int budget, double deposit) = 0;
	~Project() {}
};