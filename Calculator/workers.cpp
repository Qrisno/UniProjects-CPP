#include <iostream>
#include "Base.h"
using namespace std;

int Employee::getEmpID() {
	return employee_id;
}
char Employee::getPosition() {
	return employee_position;
}
int Employee::getWage() {
	return employee_salary;
}
int Employee::getProfShare() {
	return emp_profit_share;
}
string Employee::getEmpName() {
	return employee_name;
}

void Employee::dispEmp() {
    cout << "Name: " << employee_name << endl;
    cout << "\t ID: " << employee_id << endl;
    cout << "\t Base Salary: " << employee_salary << endl;
    cout << "\t Share %: " << emp_profit_share << endl;
}
void Owner::dispEmp() {
    Employee::dispEmp();
}
void Chef::dispEmp() {
    Employee::dispEmp();
    cout << "\t Mastery: " << cuisineType << endl;
}
void Waiter::dispEmp() {
    Employee::dispEmp();
    cout << "\t Service: " << expYears <<endl;
}

Owner::Owner(string inputName) {

    employee_position = 'O';
    employee_salary = 15000;
    emp_profit_share = 60;
    employee_id = rand() % 8999 + 1000;
    employee_name = inputName;

}

double Owner::calculate_salary(double bonus) {
    return employee_salary + bonus * emp_profit_share / 100.0;
}

Chef::Chef(string inputName, string inputcuisineType) {

    employee_position = 'C';
    employee_salary = 10000;
    emp_profit_share = 20;
    employee_id = rand() % 8999 + 1000;
    employee_name = inputName;
    cuisineType = inputcuisineType;

}
double Chef::calculate_salary(double bonus) {
    return employee_salary + bonus * emp_profit_share / 100.0;
}

string Chef::getCuisineType() {
    return cuisineType;
}

Waiter::Waiter(string inputName, int inputYears) {

    employee_position = 'W';
    employee_salary = 3000;
    emp_profit_share = 0;
    employee_id = rand() % 8999 + 1000;
    employee_name = inputName;
    expYears = inputYears;

}

double Waiter::calculate_salary(double bonus) {
    if (bonus > 0)
        return employee_salary + bonus;
    else
        return employee_salary;
}

int Waiter::getExpYears() {
    return expYears;
}


