//
//  main.cpp
//  PS2
//
//  Created by Aaryam Srivastava on 8/2/2018.
//  Copyright © 2018 Developers. All rights reserved.
//

#include <iostream>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

int main(void) {
    stack<int> stack;
    queue<int> queue;
    priority_queue<int> pq;
    int testcases; 
    int operation, value;
    bool isstack = true, isqueue = true, ispq = true;
    
    while (1) {
        cin >> testcases;
        if (testcases == 0) break;
        for (int i = 0; i < testcases; i++) {
            cin >> operation >> value;
            if (operation == 1) {
                stack.push(value);
                queue.push(value);
                pq.push(value);
            }
            else {
                if (stack.empty()) isstack = false;
                else if (stack.top() != value) isstack = false;
                else stack.pop();
                
                if (queue.empty()) isqueue = false;
                else if (queue.front() != value) isqueue = false;
                else queue.pop();
                
                if (pq.empty()) ispq = false;
                else if (pq.top() != value) ispq = false;
                else pq.pop();
            }
        }
        if ((isstack == true && isqueue == true && ispq == false) || (isstack == false && isqueue == true && ispq == true) || (isstack == true && isqueue == false && ispq == true) || (isstack == true && isqueue == true && ispq == true)) {
            cout << "not sure" << endl;
        }
        else if (isstack == true && isqueue == false && ispq == false) cout << "stack" << endl;
        else if (isstack == false && isqueue == true && ispq == false) cout << "queue" << endl;
        else if (isstack == false && isqueue == false && ispq == true) cout << "priority queue" << endl;
        else cout << "impossible" << endl;
    
        while (!stack.empty()) stack.pop();
        while (!queue.empty()) queue.pop();
        while (!pq.empty()) pq.pop();
        isstack = true; isqueue = true; ispq = true;
    }
    
    return 0;
}
