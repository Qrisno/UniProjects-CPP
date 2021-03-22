#include <iostream>
#include <new>
#include "staque.h"
using namespace std;

staque::staque() 
	: start(0), end(0), length(0)
{}

staque::~staque() {
	node* pointer1 = start;
	node* pointer2;
	while (true) {
        if(pointer1 == 0) break;
        /*In order to store the address before removal*/
		pointer2 = pointer1->following; 
		delete pointer1;
		pointer1 = pointer2;
	}
   end = start = 0, length = 0;
}

staque::staque(const staque& origin) {
	if (origin.emptyCheck()== false) {
		start = new (nothrow) node(origin.start->data, origin.start->order);
		if (start == 0) {
			cerr << "Storage Allocation Failed";
			exit(1);
		}
		length = origin.length;
		node* copPointer = start;
		node* originPointer = origin.start->following;
		while (true) {
            if(originPointer==0) break;
			copPointer->following = new (nothrow) node(originPointer->data,originPointer->order);
            outputText(copPointer->following);
			(copPointer->following)->previous = copPointer;
			copPointer = copPointer->following;
			originPointer = originPointer->following;
		}
		end = copPointer;
	} else end = start = 0, length = 0;
}

const staque & staque::operator=(const staque& righty) {
	if (this == &righty) return *this;
	else {
		this->~staque();
		if (righty.emptyCheck()==false) {
			start = new (nothrow) node(righty.start->data, righty.start->order);
			outputText(start);
			length = righty.length;
			node* copPointer = start;
			node* originPointer = righty.start->following;
			while (true) {
                if(originPointer==0) break;
				copPointer->following = new (nothrow) node(originPointer->data, originPointer->order);
                outputText(copPointer->following);
				(copPointer->following)->previous = copPointer; 
				copPointer = copPointer->following;
				originPointer = originPointer->following;
			}
			end = copPointer;
			return *this;
		}
		else return *this;
		
	}
}

bool staque::emptyCheck() const {
    if(length==0) return true;
    return false;
}

void staque::output(ostream& o) const {
	node* ptr;
	cout << "In the front ";
	for (ptr = start; ptr != 0; ptr = ptr->following) {
		o << ptr->data << " ";
	}
	cout << " in the back\n";
}
/*Case when start=0 is for generating the first node, which both start/end will point*/
void staque::pushFront(const int val) {
	++length;
	int index = 0;

	if (start == 0) { 
		start = new (nothrow) node(val, index, start);
		outputText(start);
		end = start;
	}
	else {
		start->order >= end->order? index = start->order + 1:index= end->order + 1;
		start = new (nothrow) node(val, index, start);
		outputText(start);
		(start->following)->previous = start;
	}
}

void staque::pushBack(const int val) { 
	length++;
	int index = 0;
	if (end == 0) {
		end = new (nothrow) node(val, index, 0, end);
		outputText(end);
		start = end;
	}
	else {
        start->order >= end->order ? index = start->order + 1: index = end->order + 1;
		end = new (nothrow) node(val, index, 0, end);
		outputText(end);
		(end->previous)->following = end;
	}
}

void staque::add(const int val) {
	if (val % 2 != 0) pushBack(val);
	else pushFront(val);
}

void staque::removeBack() {
	if (emptyCheck()==false)
	{
		if (length == 1) {
			node* ptr = end;
			end = end->previous;
			start = start->following;
			delete ptr;
			length--;
		}
		else {
			node* ptr = end;
			end = end->previous;
			(ptr->previous)->following = 0; 
			delete ptr;
			length--;
		}
	}
	else
		cerr << "Empty" << endl;
}
/*removes from the front*/
void staque::removeFront() {
	if (!emptyCheck())
	{
		if (length == 1) {
			node* ptr = start;
			start = start->following;
			end = end->previous;
			delete ptr;
			length--;
		}
		else {
			node* ptr = start;
			start = start->following;
			(ptr->following)->previous = 0;
			delete ptr;
			length--;
		}
	}
	else cerr << "Empty" << endl;
}

void staque::remove() {
	if (!emptyCheck()) {
		if (this->start->order > this->end->order) removeFront();
		else removeBack();
	}
	else cerr << "Empty" << endl;

}
void staque::remove(int num) {
	if (!emptyCheck()) {
		if (num <= length) {
            int j =0;
            while(j!=num){
                j++;
                if (this->start->order > this->end->order) removeFront();
				else removeBack();
            }
		}
		else {
			cerr << "Total Elements: " << length << " . You can't delete " << num << endl;
		}
	}
	else {
		cerr << "emty" << endl;
	}
}
/*
I am removing nums according to ther status. LIFO
*/
void staque::remove(int numEven, int numOdd) { 
    int i= 0;
    int j = 0;
    while(true){
        if(i==numEven) break;
        if (start->data % 2 != 1) removeFront();
		else {
			cerr << "No more even nums found" << endl;
			break;
		}
        i++;
    }
    while(true){
        if(j==numOdd) break;
        if (end->data % 2 != 0) removeBack();
		else {
			cerr << "No more odd nums found"<< endl;
			break;
		}
        j++;
    }
}
void staque::outputText(staque::node * val){
    if (val == 0) {
        cerr << "Storage Allocation Failed" << endl;
        exit(1);
	}
}
void staque::lifoRemoval() {
	remove(length);
}
void clearInput(){
    cin.clear();
    cin.ignore(1000,'\n');
    cerr << "Integers Only" << endl;
}
ostream& operator<<(ostream& val1, const staque& val2) {
	val2.output(val1);
	return val1;
}