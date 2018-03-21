
#include <stdio.h>
#include <iostream>
#include <set>

using namespace std;

int main () {
    
    set<string> input;
    /*
    input.insert("a");
    input.insert("bb");
    input.insert("ab");
    input.insert("b");
    */
    
    string in;
    //cin.ignore();
    while (cin >> in) {
        if (in != "") {
            input.insert(in);
        }
    }
    for (auto it = input.begin(); it != input.end(); it++) {
        for (auto it2 = input.begin(); it2 != input.end(); it2++) {
            if (it != it2) {
                if (next(it) != input.end() && (*it + *it2 >= *next(it) + *input.begin())) {
                    break;
                }
                cout << (*it + *it2) << endl;
            }
        }

    }
    
    
}

