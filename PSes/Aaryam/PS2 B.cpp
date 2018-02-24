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
    int testcases; 
    int operation, value;
    bool isstack = true, isqueue = true;
    
    while (1) {
        cin >> testcases;
        if (testcases == 0) break;
        for (int i = 0; i < testcases; i++) {
            cin >> operation >> value;
            if (operation == 1) {
                stack.push(value);
                queue.push(value);
            }
            else {
                if (stack.empty()) isstack = false;
                else if (stack.top() != value) isstack = false;
                else stack.pop();
                
                if (queue.empty()) isqueue = false;
                else if (queue.front() != value) isqueue = false;
                else queue.pop();
            }
        }
        if (isstack && isqueue) cout << "not sure" << endl;
        else if (isstack == true && isqueue == false) cout << "stack" << endl;
        else if (isstack == false && isqueue == true) cout << "queue" << endl;
        else cout << "impossible" << endl;
    
        while (!stack.empty()) stack.pop();
        while (!queue.empty()) queue.pop();
        isstack = true; isqueue = true;
    }
    
    return 0;
}
