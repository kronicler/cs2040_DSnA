//
//  main.cpp
//  Stack Construction
//
//  Created by Aaryam Srivastava on 13/2/2018.
//  Copyright © 2018 Developers. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

int operations(string display, int size) {
    int oper = 0, remaining = size;
    size_t found;
    
    for (int i = 0; i < size; i++) {
        found = display.find_first_of(display[i]);
        
        if (i == 0) {
            oper += 2;
        }
        else if (display[i] == display[i+1] && (i < size - 1)) {
            oper += 3;
            remaining -= 1;
            i++;
        }
        else if (found != string::npos && ((int)found < i)) {
            oper += (i - (int)found - (size - remaining));
            remaining -= ((i - (int)found - 1) - (size - remaining));
        }
        else {
            oper += 2;
        }
        cout << oper << "\n";
    }
    
    oper += remaining;
    
    return oper;
}

int main(void) {
    int testcases; cin >> testcases;
    
    for (int i = 0; i < testcases; i++) {
        string display; getline(cin, display);
        
        cout << operations(display, (int)display.size());
    }
    return 0;
}
