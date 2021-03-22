#include <iostream>
using namespace std;

#ifndef STAQUE
#define STAQUE
class staque{
    public:
    void output(ostream & val) const;
    bool emptyCheck() const; 
    void remove(); /*high order val removal*/
    void remove(int val); /*removal in order*/
    void remove(int even, int odd); /*removal of even and odd values*/
    void add(const int val); /*evens to front odds in the back*/
    void lifoRemoval(); /*LIFO removal*/
   
    
    const staque & operator=(const staque & onTheRight);
    staque(); /*constructor*/
    staque(const staque & orig); /*constructor(copy)*/
    ~staque(); /*destructor*/
    public:
    class node {
        public:
        int data;
        int order;
        node* following;
        node* previous;
        node(int val = 0, int ord = 0, node* num = 0, node* pointer = 0)
        : data(val), following(num), order(ord), previous(pointer)
        {}
    };
    int length;
    node * start;
    node * end;
    
    

    /*Private Functions, their names are descriptive*/
    void pushFront(const int val);
    void pushBack(const int val);
    void removeBack();
    void removeFront();
    void outputText(staque::node * val);
    
    
};

/*For overloading purposes*/
    ostream& operator<<(ostream& val1, const staque& val2);
void clearInput();
#endif
