#include <iostream>
#include "staque.h"
#include "staque.cpp"
using namespace std;

int main()
{
    staque stack1, stack2;
    int num1, num2;
    cout << "Number of Vals:" << endl;
    while (!(cin >> num1)) {
        clearInput();
    }
    cin.ignore(10000, '\n');
    cout << "Enter vals: " << endl;
    for (int j = 0; j < num1; ++j) {
        while (!(cin >> num2)) {
            clearInput();
        }
        cin.ignore(10000, '\n');
        stack1.add(num2);
    }

    cout << endl;
staque stack3 = stack1;/*switch*/
staque stack4 = stack2;/*switch*/
    staque array[] = {stack1, stack2, stack3, stack4};
    cout << "Staque:" << endl;
    cout << stack1;
    cout << "Staque(copy) :" << endl;
    stack2 = stack1; /*switch*/
    cout << stack2;
    cout << "Staque from copy constructor:" << endl;
    
    cout << stack3;
    cout << "another copy of the initial staque:" << endl;
    cout << stack4<<endl;
    cout << "Inserting some number in the initial one" << endl;
    stack1.add(1);
    stack1.add(2);
    cout << "Deleting last value from Staque(copy)" << endl;
    stack3.remove(2, 1);
    stack4.remove(4);
    cout << endl;
    cout << "output:" << endl;
    cout << stack1 << stack2 << stack3 << stack4;
    for(int i = 0;i<4;i++){
        array[i].lifoRemoval();
        cout << array[i];
    }

    return 0;
}
