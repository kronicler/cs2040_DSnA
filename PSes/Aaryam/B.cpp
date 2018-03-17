//
//  main.cpp
//  PS3A
//
//  Created by Aaryam Srivastava on 24/2/2018.
//  Copyright © 2018 Developers. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
typedef tuple<int, int, string> iii;
priority_queue<iii> womaninfo; stack<iii> temp_stack;
int woman = 0; string empty = "The delivery suite is empty";

void ArriveatHospital(string name, int dilation) {
    woman++;
    womaninfo.push(make_tuple(dilation, -woman, name));
}

void GiveBirth(string womanName) {
    womaninfo.pop();
}

string Query() {
    if ((int)womaninfo.size() == 0) return empty;
    iii tmp = womaninfo.top();
    return get<2>(tmp);
}

int main(void) {
    int commands; cin >> commands;
    int oper, dilation; string name;
    for (int i = 0; i < commands; i++) {
        cin >> oper;
        switch (oper) {
            case 0:
                cin >> name >> dilation;
                ArriveatHospital(name, dilation);
                break;
            case 2:
                cin >> name;
                GiveBirth(name);
                break;
            default:
                cout << Query() << endl;
                break;
        }
    }
    return 0;
}
