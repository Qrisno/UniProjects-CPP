#include <iostream>
using namespace std;
//Declared main functions
  void sum(float &x, float &y); 
  void substract(float &x, float &y);
  void divide(float &x, float &y);
  void multiply(float &x, float &y);


int main() {
  //input pointer for controling while loop
  
  int *input=new int;
  //float type pointers with anonymous values
   float *num1 = new float ;
   float *num2 = new float ;
   while(true){
    
    cout << "1 enter for Addition (x+y)" << endl;
    cout << "2 for Subtraction (x-y)" << endl;
    cout << "3 for Multiplication (x*y)" << endl;
    cout << "4 for Division (x/y)" << endl;
    cout << "5 for the Exit" << endl;
      /* cin returns false if an input operation fails, that is, if
        something other than an int (the type of input) is entered.
        If the input is not an integer then I cin.clear() in order to clear the error flag,
        for input output operations to run smoothly. Cin.ignore skips to the next line so that the 
        program won't be able to read anything that user entered on that line. This way I avoided parsing failures.
        */
    if (!(cin >> *input)) {
      cout << "Please enter numbers only." << endl;
      cin.clear();
      cin.ignore(10000,'\n');
      continue;
    }
   
    if(*input<1 || *input>5){
      cout << "Please enter a number in a range from (1 including 5)"<<endl;
      continue;
    }
    if(*input==5){
      cout<<"You have successfully quited, have a nice day!";
     
      break;
    }
    cout<<"Enter number 1: ";
    
    if (!(cin>>*num1)) {
      cout << "Please enter numbers only." << endl;
      cin.clear();
      cin.ignore(10000,'\n');
      continue;
    }
    cout<<"Enter number 2: ";
    
    if (!(cin>>*num2)) {
      cout << "Please enter numbers only." << endl;
      cin.clear();
      cin.ignore(10000,'\n');
      continue;
    }
  /*Switch that controls stream of inputs*/
    switch (*input){
      case 1:
        sum(*num1, *num2);
        break;
      case 2:
        substract(*num1, *num2);
        break;
      case 3:
        multiply(*num1, *num2);
        break;
      case 4:
        divide(*num1, *num2);
        break;
    }
   }
   

  delete num1, num2, input;

  return 0;
}
/*actual functions that return void as we only need to see the output 
and not using this functions as some kind of values later*/

  void sum(float &x, float &y){
    cout <<x+y<<endl;
  }
  void substract(float &x, float &y){
    cout <<x-y<<endl;
  }
  void divide(float &x, float &y){
    cout <<x/y<<endl;
  }
  void multiply(float &x, float &y){
    cout <<x*y<<endl;
  }


  /**/