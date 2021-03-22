#include <iostream>

using namespace std;

class platypus
{
  float weight = 0.0;
  short age = 0.0;		//months
  char nameInitial = 'a';
  char gender = 'm';
  bool alive = true;
  bool mutant = true;

public:

    platypus ()
  {
    alive = false; //Created Dead Platypus
  }
  //a constructor that establishes its gender, weight, age, and name
  platypus (char defaultGender, float defaultWeight, short defaultAge, char defaultNameInitial)
  {
    gender = defaultGender;
    weight = defaultWeight;
    age = defaultAge;
    nameInitial =defaultNameInitial;
    // it will default to alive and not mutant.
    alive = true; 
    mutant = false;
  }
  //a print function that will output to the screen the attributes of that platypus 
  void print ()
  {
    cout << "Name ---> " << nameInitial << "\n";
    cout << "Age ---> " << age << "\n";
    cout << "Gender ---> " << gender << "\n";
    cout << "Weight ---> " << weight << "\n";
    
    alive ? cout << "Platypus is alive!\n":cout << "Oops... Platypus is dead!\n";
    mutant ?  cout << "Oops... Platypus is mutant\n":cout << "Platypus is not mutant\n";

    cout << "\n\n";
  }
  float getWeight(){
    return weight;
  }
  float getAge(){
    return age;
  }
  //an age_me function that returns nothing but increments the object's age, it includes the percentages of chances.
  void age_me ()
  {
    age++;
    int chance = weight * 10;
    cout << "There is a " << chance << "chance of death\n";
    cout << "It has 2 % chance of becoming mutant\n";
  }
  //a fight function that accepts another platypus object as a parameter. It will have the calling platypus attack the other platypus.
  void fight (platypus otherPlatypus)
  {
    int fightRatio = (weight / otherPlatypus.weight) * 50;
    int randomValue = rand() % 100;
    if (randomValue < fightRatio) 
      {
        alive = true;
        otherPlatypus.alive = false;
      }
    else
      {
        otherPlatypus.alive = true;
        alive = false;
      }
  }
  //eat func increases the weight of the platypus by a random amount 
  void eat ()
  {
      alive ? weight = weight + (rand () % 50) / 10 : weight;
  }
  // hatch function randomly sets up a newborn platypus
  void hatch ()
  {
    alive = true;
    mutant = false;
    age = 0;
    int randomGenderVal = rand () % 2;
    int randomNamingVal = rand () % 2;
    switch (randomGenderVal){
      case 1:{
        gender = 'm';
        cout << "It is a male!\n";
        break;
      }
      default:{
        gender = 'f';
        cout << "It is a female!\n";
        break;
      }
    }
    switch (randomNamingVal){
      case 1:{
        gender = 'm';
        cout << "Enter a name: ";
        cin>>nameInitial;
        break;
      }
      default:{
      // generate a random number
        nameInitial = 'a' + rand()%26; // Convert to a character from a-z
        break;
      }
    }
    weight = ((double)rand()/RAND_MAX)*0.9+0.1;
  }


};



