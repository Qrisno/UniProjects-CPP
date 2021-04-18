#include <iostream>
#include "Base.h"
#include "workers.cpp"

using namespace std;

int main() {
    
    Employee* Emps[6] = {
        new Owner("Nini"), new Chef("SIZIFE", "DUSHETI"), new Chef("NINO", "KARTLI"),
        new Waiter("Gocha", 5), new Waiter("Daro", 1), new Waiter("SOMEONE", 6)
    };
    cout << "Personnel:" << endl;
    int i = 0;
    while(i<=5){
        cout << "(" << i + 1 << ") ";
        Emps[i]->dispEmp();
        i++;
    }
    i=0;

    double totalprofit;
    double totalSurplus;
    while(i<3){
      cout << "\n Monthly Rep" << "N " << i + 1 <<":" << endl;
        cout << "--------------------------------" << endl;
        totalprofit = rand() & 9000 + 100000;
        int j = 0;
        while(j<6){
           cout << j + 1 << ") " << Emps[j]->getEmpName() << " - " << Emps[j]->getPosition()  << " ID: " << Emps[j]->getEmpID() << endl;
            cout << "\tBase:" << Emps[j]->getWage() <<endl;            
            if (Emps[j]->getPosition() != 'W') {
                cout << "\tBonus Amount - " << totalprofit * Emps[j]->getProfShare() / 100.0 <<endl;
                cout << "\tTotal - " << Emps[j]->calculate_salary(totalprofit) << endl;
            }
            else {
                totalSurplus = (double)(rand() % 20) * 100.0;
                cout << "\tBonus Amount -" << totalSurplus << endl;
                cout << "\tTotal -" << Emps[j]->calculate_salary(totalSurplus) << endl;
            }
            j++;
        }
        i++;
    }
    i=0;
   
    //test case for negative profit
    cout << "\nMonthly Negative Profit" << endl;
    cout << "--------------------------------" << endl;
    totalprofit = -10000.0;
    while(i<6){
      cout << i + 1 << ") " << Emps[i]->getEmpName() << " - " << Emps[i]->getPosition() << "  ID:  " << Emps[i]->getEmpID() <<  endl;
        cout << "\tBase:" << Emps[i]->getWage() << endl;
        if (Emps[i]->getPosition() != 'W') {
            cout << "\tBonus Amount -" << totalprofit * Emps[i]->getProfShare() / 100.0 << endl;
            cout << "\tTotal -" << Emps[i]->calculate_salary(totalprofit) << endl;
        }
        else {
            totalSurplus = (double)(rand() % 20) * 100.0;
            cout << "\tBonus Amount -" << totalSurplus << endl;
            cout << "\tTotal -" << Emps[i]->calculate_salary(totalSurplus) << endl;
        }
        i++;
    }
    i=0;
    while(i<6){
      delete Emps[i];
      i++;
    }

}
