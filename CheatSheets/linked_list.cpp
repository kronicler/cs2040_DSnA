//
//  main.cpp
//  ADTs_linkedList
//
//  Created by Ler Wilson on 31/12/17.
//  Copyright © 2017 Ler Wilson. All rights reserved.
//

#include <iostream>
using namespace std;



class LinkedList{
    // Struct inside the class LinkedList
    // This is one node which is not needed by the caller. It is just
    // for internal work.
    struct Node {
        int x;
        Node *next;
    };
    
    // private member
private:
    
    
    // public member
public:
    
    Node *head; // this is the private member variable. It is just a pointer to the first Node
    Node *tail;
    
    // constructor - its called when a new list is being created
    LinkedList(){
        head = NULL; // set head to NULL
        tail = NULL; // Assign and allocate memory to this pointer variable 
    }
    
    // This prepends a new value at the beginning of the list
    void addValue(int val){
        Node *n = new Node();   // create new Node
        n->x = val;             // set value
        n->next = head;         // make the node point to the next node.
        //  If the list is empty, this is NULL, so the end of the list --> OK
        
        // Init node handlin
        if (tail == NULL) {
            tail = n;
        }
        head = n;               // last but not least, make the head point at the new node.
    }
    
    // Incomplete: Tail must be declared when elements are added to the list from the above function 
    void addValueTail(int val) {
        Node *n = new Node();
        n->x = val;
        if (head == NULL) {
            addValue(val);
        }else {
            tail->next = n;
            tail = n;
        }
    }
    
    // returns the first element in the list and deletes the Node.
    // caution, no error-checking here!
    int popValue(){
        Node *n = head;
        int ret = n->x;
        
        head = head->next;
        delete n;
        return ret;
    }
    
    // Prints all the elemtns in the linked list
    void printAll () {
        Node *n = head;
        while (n != NULL) {
            cout << n->x << " ";
            n = n->next;
        }
        cout << endl;
    }
    
    int searchVal (int val) {
        Node *n = head;
        while (n != NULL) {
            if (n->x == val) return n->x;
            n = n->next;
        }
        return NULL;
    }
    
};

int main() {
    LinkedList list;
    
    list.addValue(1);
    list.addValue(2);
    list.addValue(3);
    
    list.addValueTail(5);
    list.addValueTail(10);
    list.addValueTail(20);
    
    
    cout << "Printing added data" << endl;
    list.printAll();
    
    cout << "Search: " << list.searchVal(5) << endl;
    
    cout << "Popping added data" << endl;
    while (list.head != NULL) {
        cout << list.popValue() << " ";
    }
    cout << endl;
   
    // because there is no error checking in popValue(), the following
    // is undefined behavior. Probably the program will crash, because
    // there are no more values in the list.
    // cout << list.popValue() << endl;
    return 0;
}
