#ifndef CREATOR_H
#define CREATOR_H

#include "Cleaner.h"
#include "Driver.h"
#include "Manager.h"
#include "Programmer.h"
#include "ProjectManager.h"
#include "SeniorManager.h"
#include "TeamLeader.h"
#include "Tester.h"
#include "WorkProject.h"
#include <vector>
#include <string>

class EmployeeFactory
{
private:
	vector<WorkProject*> projects;
public:
	EmployeeFactory(vector<WorkProject*>);
	Employee* create(vector<string>);
};

#endif
