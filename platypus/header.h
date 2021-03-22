#pragma once
using namespace std;

class Platypus{
    private:

        float weight; //pounds
        short age; //months
        char nameInitial;
        char gender;
        bool alive;
        bool mutant;
    public:
        //constructors: default/custom
        Platypus();//default
        Platypus(char defaultGender, float defaultWeight, short defaultAge, char defaultNameInitial);

        void print() const;
        void age_me();
        void fight(Platypus&otherPlatypus);
        void eat();
        void hatch();

        //getters
        float getWeight();
        float getAge();


};
