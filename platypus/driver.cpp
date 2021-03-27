#include "./header.h"
#include "./main.cpp"
#include <iostream>

//Driver function
int main ()
{
  platypus platy;			// created new instance platypus;
  platy.print ();

  platypus platy1 ('m', 7, 13, 'p');
  platy1.print ();
  platy1.age_me ();
  platy1.print ();

  platypus platy2 ('f', 4, 2, 'c');
  platy2.print ();

  platy1.fight (platy2);
  platy2.print ();
  

  platy1.hatch ();
  platy1.print ();
  cout<<platy1.getWeight()<<"\n";
  cout<<platy1.getAge();

  return 0;
}