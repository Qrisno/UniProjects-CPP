#pragma once
#include <iostream>

using namespace std;

class Employee {
protected:
	int employee_id;
	char employee_position;
	int employee_salary;
	int emp_profit_share;
	string employee_name;
public:
	int getEmpID();
	char getPosition();
	int getWage();
	int getProfShare();
	string getEmpName();
	void dispEmp();
	virtual double calculate_salary(double bonusAmount) = 0;
};

class Owner : public Employee {
public:
	Owner(string name);
	double calculate_salary(double bonusAmount);
	void dispEmp();
};

class Chef : public Employee {
private:
	string cuisineType;
public:
	Chef(string name, string cuisine);
	double calculate_salary(double bonusAmount);
	string getCuisineType();
	void dispEmp();
};

class Waiter : public Employee {
private:
	int expYears;
public:
	Waiter(string name, int years);
	double calculate_salary(double bonusAmount);
	int getExpYears();
	void dispEmp();
};