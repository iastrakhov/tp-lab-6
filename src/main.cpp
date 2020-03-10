#include <iostream>
#include <fstream>
#include <vector>
#include "Employee.h"
#include "Manager.h"
#include "Cleaner.h"
#include "Driver.h"
#include "Programmer.h"
#include "TeamLeader.h"
#include "Tester.h"
#include "ProjectManager.h"
#include "SeniorManager.h"

using namespace std;

int main() {
	
	vector <Employee*> workers; //создадим работника

	ifstream FileWorkers("C:\Users\Кирилл\source\repos\lab6\lab6\workers");  //загрузка данных из файла

	if (!FileWorkers.is_open()) {
		cout << "Failed to open" << endl;
		return false;
	}
	else
	{
		enum PROFFESIONS { TRAINEE, MANAGER, CLEANER, DRIVER, PROGRAMMER, TEAM_LEADER, TESTER, PROJECT_MANAGER, SENIOR_MANAGER };
		PROFFESIONS pos_ID = TRAINEE; // стажер по умолчанию 
		int id;

		while (FileWorkers >> id) {
			string name, surname, second_name, fio, position; //считаем 
			FileWorkers >> name >> surname >> second_name >> position; //запишем в перемен
			fio = name + " " + surname + " " + second_name;
			//присвоение должности
			if (position == "Cleaner")				    pos_ID = CLEANER;
			else if (position == "Driver")				pos_ID = DRIVER;
			else if (position == "ProjectManager")		pos_ID = PROJECT_MANAGER;
			else if (position == "Tester")				pos_ID = TESTER;
			else if (position == "Manager")				pos_ID = MANAGER;
			else if (position == "TeamLeader")			pos_ID = TEAM_LEADER;
			else if (position == "SeniorManager")		pos_ID = SENIOR_MANAGER;
			else if (position == "Programmer")			pos_ID = PROGRAMMER;


			int worktime = 0,
				base = 0,
				budget = 0,
				salary = 0,
				pjcts_amount = 0;

			double deposit = 0.0;
			string project = "";

			switch (pos_ID) { //оюраюотаем данные кождой должности
			case CLEANER:
			{
				FileWorkers >> worktime;
				FileWorkers >> base;
				workers.push_back(new Cleaner(id, fio, worktime, base));
				break;
			}
			case DRIVER:
			{
				FileWorkers >> worktime;
				FileWorkers >> base;
				workers.push_back(new Driver(id, fio, worktime, base));
				break;
			}
			case TESTER:
			{
				FileWorkers >> worktime;
				FileWorkers >> base;
				FileWorkers >> project;
				FileWorkers >> budget;
				FileWorkers >> deposit;
				workers.push_back(new Tester(id, fio, worktime, base, project, budget, deposit));
				break;
			}
			case PROGRAMMER:
			{
				FileWorkers >> worktime;
				FileWorkers >> base;
				FileWorkers >> project;
				FileWorkers >> budget;
				FileWorkers >> deposit;
				workers.push_back(new Programmer(id, fio, worktime, base, project, budget, deposit));
				break;
			}
			case TEAM_LEADER:
			{
				FileWorkers >> worktime;
				FileWorkers >> base;
				FileWorkers >> project;
				FileWorkers >> budget;
				FileWorkers >> deposit;
				FileWorkers >> salary;
				workers.push_back(new TeamLeader(id, fio, worktime, base, project, budget, deposit, salary));
				break;
			}
			case MANAGER:
			{
				FileWorkers >> project;
				FileWorkers >> budget;
				FileWorkers >> deposit;
				workers.push_back(new Manager(id, fio, project, budget, deposit));
				break;
			}
			case PROJECT_MANAGER:
			{
				FileWorkers >> project;
				FileWorkers >> budget;
				FileWorkers >> deposit;
				FileWorkers >> salary;
				workers.push_back(new ProjectManager(id, fio, project, budget, deposit, salary));
				break;
			}
			case SENIOR_MANAGER:
			{
				FileWorkers >> pjcts_amount;
				FileWorkers >> deposit;
				FileWorkers >> salary;
				workers.push_back(new SeniorManager(id, fio, pjcts_amount, deposit, salary));
				break;
			}
			}
		}

		FileWorkers.close(); //закрытие файла
		for (int i = 0; i < workers.size(); ++i) { //вывод информ о работнике на экран
			workers[i]->calculatePayment();
			cout <<
				workers[i]->getID() << "\t" <<
				workers[i]->getFIO() << "\t" <<
				workers[i]->getPaymentTime() << "\t" <<
				workers[i]->getWorkTime()
				<< endl;
		}
	}
	system("pause");
	return 0;
}