// intlist.cpp
// Implements class IntList
// Dani  Arellano; 1/15/2026

#include "intlist.h"

#include <iostream>
using std::cout;

// copy constructor
IntList::IntList(const IntList& source) {
   
    this-> head = nullptr;
    this-> tail = nullptr;
    Node* temp = source.head;
    
    while(temp != nullptr ){
        Node* curr = new Node;

        curr-> info = temp-> info;
        curr-> next = nullptr;

        if (head == nullptr){
            head =  curr;
            tail = curr;
        }
        else{
            tail->next = curr;
            tail = curr;
        }

        temp = temp->next;
    }
}

// destructor deletes all nodes
IntList::~IntList() {
   
    Node* curr = head;
  
    while (curr != nullptr){
        Node* temp = curr ->next;
        delete curr;
        curr = temp;
    }

}


// return sum of values in list
int IntList::sum() const {
    int total = 0;
    Node* curr = head;

    while (curr != nullptr){
        total += curr->info;
        curr = curr->next;
    }

    return total; 
}

// returns true if value is in the list; false if not
bool IntList::contains(int value) const {
    Node* curr = head;

     while (curr != nullptr){
        if(curr->info == value){
            return true;
        }
        curr = curr->next;
    }

    return false; 
}

// returns maximum value in list, or 0 if empty list
int IntList::max() const {
    if (head == nullptr){
        return 0;
    }

    Node* curr = head;
    int max_value = curr->info;

    while(curr != nullptr){
        if (max_value < curr->info){
            max_value = curr->info;
        }
        curr = curr->next;
    }
    return max_value;
}

// returns average (arithmetic mean) of all values, or
// 0 if list is empty
double IntList::average() const {
    if (head == nullptr){
        return 0.0;
    }

    int n = 0;
    int total = 0;
    Node* curr = head;

    while (curr != nullptr){
        total += curr->info;
        n ++;
        curr = curr->next;
    }
    double average_val = static_cast<double>(total) / n;

    return average_val; 
}

// inserts value as new node at beginning of list
void IntList::push_front(int value) {
    Node* temp = new Node;
    temp->info = value;
    temp -> next = head;

    if (tail == nullptr){
        tail = temp;
    }
    head = temp;
}

// append value at end of list
void IntList::push_back(int value) {
    Node* temp = new Node;
    temp->info = value;
    temp->next = nullptr;

    if (head == nullptr){
        head = temp;
        tail = temp;
    }
    else{
        tail -> next = temp;
        tail = temp;
    }
    
}

// return count of values
int IntList::count() const {
   Node* temp = head;
   int n = 0;

   while(temp != nullptr){
    n ++;
    temp = temp->next;
   }

   return n;
}


//Assignment operator should copy the list from the source
//to this list, deleting/replacing any existing nodes
IntList& IntList::operator=(const IntList& source){
    if (this == &source){
        return *this;
    }

    Node* del = head;
    while(del != nullptr){
        Node* next = del->next;
        delete del;
        del = next;
    }
    head = nullptr;
    tail = nullptr;

    Node* temp = source.head;
    while(temp != nullptr ){
        Node* curr = new Node;
        curr-> info = temp-> info;
        curr-> next = nullptr;

        if (head == nullptr){
            head =  curr;
            tail = curr;
        }
        else{
            tail->next = curr;
            tail = curr;
        }

        temp = temp->next;
    }

    return *this;
}

// constructor sets up empty list
IntList::IntList(){ 
    head = nullptr;
    tail = nullptr;
}


// DO NOT CHANGE ANYTHING BELOW (READ IT THOUGH)

// print values enclose in [], separated by spaces
void IntList::print() const {
    Node *n = head;
    cout << '[';
    while (n) {
        cout << n->info;
        if (n->next)
            cout << " ";
        n = n->next;
    }
    cout << ']';
}

