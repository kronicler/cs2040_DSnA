//
//  main.cpp
//  PS2
//
//  Created by Aaryam Srivastava on 8/2/2018.
//  Copyright © 2018 Developers. All rights reserved.
//

#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

int main(void) {
    stack<int> elements;
    int testcases; 
    int operation, value;
    bool isstack = true;
    
    while (1) {
        cin >> testcases;
        if (testcases == 0) break;
        for (int i = 0; i < testcases; i++) {
            cin >> operation >> value;
            if (operation == 1) elements.push(value);
            else {
                if (elements.empty()) isstack = false;
                else if (elements.top() != value) isstack = false;
                else elements.pop();
            }
        }
        if (isstack) cout << "stack" << endl;
        else cout << "impossible" << endl;
    
        while (!elements.empty()) elements.pop();
        isstack = true;
    }
    
    return 0;
}
