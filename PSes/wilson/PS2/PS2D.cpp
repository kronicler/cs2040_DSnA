#include <iostream>
#include <stdio.h>
#include <functional>

using namespace std;

struct stack_node {
    int data;
    struct stack_node *next;
};

class Stack {
    struct stack_node *top;
private:
    int size;
public:
    Stack() { //constructor
        top = NULL;
        size = 0;
    }
    void push(int value) {
        struct stack_node *ptr;
        
        ptr = new stack_node;
        ptr->data = value;
        ptr->next = NULL;
        
        if (top!= NULL) {
            ptr->next=top;
        }
        top = ptr;
        size++;
    }
    
    //pop operation
    void pop() {
        struct stack_node *temp;
        if (top == NULL) {
            
        }
        temp = top;
        top = top->next;
        delete temp;
    }
    
    int getSize () {
        return size;
    }
    
    int getTop () {
        return top->data;
    }
};


struct queue_node {
    int data;
    queue_node *next;
};

//creating a queue class
class Queue {
private:
    int size;
public:
    queue_node *front, *rear; //to store the front and rear positions
    Queue () {front = rear = NULL; size = 0;}
    //enqueue operation
    void push(int value) {
        queue_node *ptr = new queue_node;
        if (ptr == NULL) {
            return;
        }
        ptr->data = value;
        ptr->next = NULL;
        
        //for the first node
        if (front == NULL) front = rear = ptr;
        else {
            rear->next=ptr;
            rear=ptr;
        }
        size++;
    }
    
    //dequeue operation
    void dequeue() {
        if (front == NULL) {
        }
        if (front == rear) { //if only one node exists
            front = rear = NULL;
        }
        else {
            front = front->next;
        }
    }
    
    int getSize () {
        return size;
    }
    
    int getTop () {
        return front->data;
    }
};


class binSomething {
private:
    int Something[100000] = {0};
    int size = 0;
    // Recursive
    void maxSomethingify (int index, int maxSize) {
        // Compare childs
        if (2*index+1 < size && 2*index+2 < maxSize) {
            // Both child exist
            if (Something[2*index+1] > Something[2*index+2]) {
                // Left child larger than right child
                if (Something[2*index+1] > Something[index]) {
                    swap(Something[index], Something[2*index+1]);
                    maxSomethingify(2*index+1, maxSize);
                }
            }else {
                // Left child smaller or equals to right child
                if (Something[2*index+2] > Something[index]) {
                    swap(Something[index], Something[2*index+2]);
                    maxSomethingify(2*index+2, maxSize);
                }
            }
        }
        else if (2*index+1 < maxSize) {
            // Left child exist
            if (Something[2*index+1] > Something[index]) {
                swap(Something[index], Something[2*index+1]);
                maxSomethingify(2*index+1, maxSize);
            }
        }
        else if (2*index+2 < maxSize) {
            // Right child exist
            if (Something[2*index+2] > Something[index]) {
                swap(Something[index], Something[2*index+2]);
                maxSomethingify(2*index+2, maxSize);
            }
        }
        else {
            // No child left
            return;
        }
        
    }
    void shiftDown (int index) {
        // Compare parent
        if (Something[index] > Something[(index-1)/2]) {
            // more than parent
            swap(Something[index], Something[(index-1)/2]);
            shiftDown((index-1)/2);
        }else {
            return;
        }
    }
    
public:
    
    binSomething() {}
    
    void insert (int value) {
        Something[size] = value;
        size++;
        shiftDown(size - 1);
    }
    
    int top () {
        if (!size) return -1;
        return Something[0];
    }
    
    void removeTop () {
        swap(Something[0], Something[size - 1]);
        size--;
        if (!size) return;
        maxSomethingify(0, size);
    }
    
    
    int getSize () {
        return size;
    }
    
};


int main () {
    // We need a list and a priority queue
    // priority queue - will always return the largest element inserted
    // stack - insert will be to the back, remove will be Last item
    // Queue - insert will be to the back, remove will be to the front
    int num;
    
    do {
        binSomething myPQ;
        Stack myStack;
        Queue myQueue;
        scanf("%d", &num);
        int conditions[3] = {0};
        
        conditions[0] = 1;
        conditions[1] = 1;
        conditions[2] = 1;
        
        for (int i = 0; i < num; i++) {
            int ops, number;
            
            scanf("%d %d", &ops, &number);
            
            switch (ops) {
                case 1:
                    myStack.push(number);
                    myQueue.push(number);
                    myPQ.insert(number);
                    break;
                    
                case 2:
                    // Need to inspect and check here
                    int tops[3] = {0};
                    if (myQueue.getSize() > 0) {
                        tops[1] = myQueue.getTop();
                    }else {
                        conditions[1] = 0;
                    }
                    
                    if (myStack.getSize() > 0) {
                        tops[0] = myStack.getTop();
                    } else {
                        conditions[0] = 0;
                    }
                    
                    if (myPQ.getSize() > 0) {
                        tops[2] = myPQ.top();
                    }else {
                        conditions[2] = 0;
                    }
                    
                    if (conditions[0] && myStack.getTop() != number) {
                        conditions[0] = 0;
                    }else if (conditions[0]){
                        myStack.pop();
                    }
                    
                    if (conditions[1] && myQueue.getTop() != number) {
                        conditions[1] = 0;
                    }else if (conditions[1]){
                        myQueue.dequeue();
                    }
                    
                    if (conditions[2] && myPQ.top() != number) {
                        conditions[2] = 0;
                    }else if (conditions[2]){
                        myPQ.removeTop();
                    }
                    
                    break;
            }
        }
        
        int total = 0, latestIndex = 0;
        if (num != 0) {
            for (int it = 0; it < 3; it++) {
                total += conditions[it];
                if (conditions[it] == 1) latestIndex = it;
            }
            if (total > 1) {
                printf("not sure\n");
                continue;
            }
            if (total == 0) {
                printf("impossible\n");
                continue;
            }
            
            switch (latestIndex) {
                case 0:
                    printf("stack\n");
                    break;
                case 1:
                    printf("queue\n");
                    break;
                case 2:
                    printf("priority queue\n");
                    break;
            }
        }
        
    }while (num > 0);
    
    
    printf("By submitting this C++ source code, I declare that it is MY OWN implementation work. I fully understand the underlying algorithm behind the C++ code that I wrote and can prove it to Lab TA if asked.\n");
}

