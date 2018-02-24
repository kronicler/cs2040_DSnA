//
//  main.cpp
//  PS2
//
//  Created by Aaryam Srivastava on 8/2/2018.
//  Copyright © 2018 Developers. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;

// This is my implementation of a priority queue, arguably the trickiest to implement.
// The implementation uses a max He*p in order to model the priority queue
class PQ {
private:
    //need to use an array to store my elements, as a vector is not permitted
    int elements[100000] = {0}, size = 0;
public:
    //priority queue constructor
    PQ() {}
    
    //returns the size of the PQ
    int sizePQ () {return size;}
    
    //inserts an element into the priority queue, calls the function movedown
    //to shift that number to its correct position
    void push (int value) {
        elements[size] = value;
        size++;
        moveUp(size - 1);
    }
    
    //function to move up an element in the array by comparing it to its parent
    void moveUp (int position) {
        if (elements[position] > elements[(position - 1)/2]) {
            int temp = elements[position];
            elements[position] = elements[(position - 1)/2];
            elements[(position - 1)/2] = temp;
            //function called recursively until the element has reached its correct node
            moveUp((position - 1)/2);
        }else return;
    }
    
    /*removes an element from the priority queue, by first swapping the maximum
     element with the 'root' of this max he*p, and then recreating the max he*p
     after the removal of the maximum element */
    void pop () {
        int temp = elements[0];
        elements[0] = elements[size - 1];
        elements[size - 1] = temp;
        size--;
        maxHify(0, size);
    }
    
    //returns the maximum element in the priority queue
    int top () {return elements[0];}
    
    /*this is arguably the most important function for the priority queue, the
     max hea*ify function. After the removal on an element, the root will need to
     be placed in the correct position in the max he*p, and this recursive function
     achieves that, by comparing the value of the root with its children, and then
     swapping the two elements accordingly
     */
    void maxHify (int position, int size) {
        //compares if element has 2 children
        if (((2 * position + 2) < size) && ((2 * position + 1) < size)) {
            if (elements[(2 * position + 2)] < elements[(2 * position + 1)]) {
                // if the left child is greater than the right child
                if (elements[(2 * position + 1)] > elements[position]) {
                    int temp = elements[position];
                    elements[position] = elements[(2 * position + 1)];
                    elements[(2 * position + 1)] = temp;
                    maxHify((2 * position + 1), size);
                }
            }else {
                // if the right child is equal to or larger than the left child
                if (elements[(2 * position + 2)] > elements[position]) {
                    int temp = elements[position];
                    elements[position] = elements[(2 * position + 2)];
                    elements[(2 * position + 2)] = temp;
                    maxHify((2 * position + 2), size);
                }
            }
        }
        //compares the element with the left child
        else if ((2 * position + 1) < size) {
            if (elements[(2 * position + 1)] > elements[position]) {
                int temp = elements[position];
                elements[position] = elements[(2 * position + 1)];
                elements[(2 * position + 1)] = temp;
                maxHify((2 * position + 1), size);
            }
        }
        else return;
    }
};

// The following class is my implementation of a queue, based on a Linked List
struct nodeQ {
    int data;
    nodeQ *next;
};

class Q {
private:
    //initialise the front and back nodes, as well as a variable to keep track of the queue size
    int size = 0;
    nodeQ *front, *back;
public:
    //constructor for the queue
    Q () {front = NULL; back = NULL;}
    
    //enqueue operation inserts an element into the back of the queue
    void enqueue(int value) {
        nodeQ *temp = new nodeQ;
        if (temp == NULL) return;
        
        temp->data = value;
        temp->next = NULL;
        
        if (front == NULL) {front = temp; back = temp;}
        else { back->next = temp; back = temp;}
        size++;
    }
    
    //dequeue operation that removes an element from the front of the queue
    void dequeue() {
        if (front == back) {
            front = NULL;
            back = NULL;
        }
        else {
            front = front->next;
        }
        size--;
    }
    
    //returns the value of the node at the front of the queue
    int front_of_Q() {return front->data;}
    
    //returns the size of the queue, which will be useful to check whether the queue is empty
    int getSizeQ() {return size;}
    
    //destructor for the queue
    ~Q() {
        while (front != NULL) {
            nodeQ *temp=front;
            front=front->next;
            delete temp;
        }
        back = NULL;
    }
};

// The following class is my implementation of a stack, also based on a Linked List
struct nodeS {
    int data;
    struct nodeS *next;
};

class S {
private:
    //initialise a top node, as well as a variable to keep track of the stack size
    struct nodeS *top;
    int size = 0;
public:
    //constructor for the stack
    S() {top = NULL;}
    
    //function to push an element in the stack, and fix the top node
    void push(int value) {
        struct nodeS *temp;
        temp = new nodeS;
        
        temp->data = value;
        temp->next = NULL;
        
        if (top!= NULL) {
            temp->next=top;
        }
        top = temp;
        size++;
    }
    
    //accesses the top of the stack, and returns the value of the top node
    int top_of_S() {return top->data;}
    
    //removes the top of the stack, and replaces the top node with the next element in the stack
    void pop() {
        struct nodeS *temp;
        
        temp = top;
        top = top->next;
        delete temp;
        size--;
    }
    
    //returns the size of the stack, which will be used to check whether the stack is empty
    int getSizeS() {return size;}
    
    //destructor for the stack
    ~S() {
        while (top != NULL) {
            nodeS *temp = top;
            top = top->next;
            delete temp;
        }
    }
};

int main(void) {
    int testcases;
    int operation, value;
    //3 boolean variables check whether the data can represent a stack, queue, or priority queue
    bool isS = true, isQ = true, isPQ = true;
    
    while (1) {
        cin >> testcases;
        if (testcases == 0) break;
        
        //create a new stack, queue, and priority queue for each test case
        S S_implementation;
        Q Q_implementation;
        PQ PQ_implementation;
        
        for (int i = 0; i < testcases; i++) {
            cin >> operation >> value;
            
            //pushes the new element if the operation is 1
            if (operation == 1) {
                S_implementation.push(value);
                Q_implementation.enqueue(value);
                PQ_implementation.push(value);
            }
            //conditional statements check whether the element can be removed from each data structure
            else {
                if (S_implementation.getSizeS() == 0) isS = false;
                else if (S_implementation.top_of_S() != value) isS = false;
                else S_implementation.pop();
                
                if (Q_implementation.getSizeQ() == 0) isQ = false;
                else if (Q_implementation.front_of_Q() != value) isQ = false;
                else Q_implementation.dequeue();
                
                if (PQ_implementation.sizePQ() == 0) isPQ = false;
                else if (PQ_implementation.top() != value) isPQ = false;
                else PQ_implementation.pop();
            }
        }
        
        // 4 conditions to check whether the data fits more than one data structure
        if ((isS == true && isQ == true && isPQ == false) || (isS == false && isQ == true && isPQ == true) || (isS == true && isQ == false && isPQ == true) || (isS == true && isQ == true && isPQ == true)) {
            cout << "not sure" << endl;
        }
        else if (isS == true && isQ == false && isPQ == false) cout << "stack" << endl;
        else if (isS == false && isQ == true && isPQ == false) cout << "queue" << endl;
        else if (isS == false && isQ == false && isPQ == true) cout << "priority queue" << endl;
        else cout << "impossible" << endl;
        
        //reset the boolean variables to true before the next iteration
        isS = true; isQ = true; isPQ = true;
    }
    
    cout << "By submitting this C++ source code, I declare that it is MY OWN implementation work. I fully understand the underlying algorithm behind the C++ code that I wrote and can prove it to Lab TA if asked." << endl;
    
    return 0;
}


