//
//  main.cpp
//  Country A and B
//
//  Created by Aaryam Srivastava on 21/1/2018.
//  Copyright © 2018 LearnAppMaking. All rights reserved.
//

#include <iostream>
#include <list>
using namespace std;

int main(void) {
    int soldiers, cases;
    cin >> soldiers >> cases;
    
    list <int> survivors;
    list <int> temp;
    
    int deceased_left, deceased_right;
    
    for (int i = 0; i < soldiers; i++) {
        survivors.push_back(i);
    }
    
    for (int i = 0; i < cases; i++) {
        cin >> deceased_left >> deceased_right;
        if (survivors.front() == deceased_left) {
            cout << "-1" << " ";
            
            survivors.pop_front();
            
            while (survivors.front() != deceased_right) {
                survivors.pop_front();
            }
            
            survivors.pop_front();
            cout << survivors.front() << endl;
            
        }
        else if (survivors.back() == deceased_right){
            cout << "-1" << " ";
            
            while (survivors.back() != deceased_left) {
                temp.push_back(survivors.back());
                survivors.pop_back();
            }
            
            survivors.pop_back();
            cout << survivors.back() << endl;
            
        }
        else {
            while (survivors.front() != deceased_left) {
                temp.push_back(survivors.front());
                survivors.pop_front();
            }
        
            while (survivors.front() != deceased_right) {
                survivors.pop_front();
            }
            
            survivors.pop_front();
            cout << temp.back() << " ";
            cout << survivors.front() << endl;
            
            while (!temp.empty()) {
                survivors.push_front(temp.back());
                temp.pop_back();
            }
        }
    }
    
    return 0;
}
