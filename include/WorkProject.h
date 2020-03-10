#ifndef WORKPROJECT_H
#define WORKPROJECT_H

#include <iostream>
using namespace std;

class WorkProject
{
private:
	string project_name;
	float project_budget;
public:
	WorkProject(string, float);
	float get_project_budget();
	string get_project_name();
};

#endif
