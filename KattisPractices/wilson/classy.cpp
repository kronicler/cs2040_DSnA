#include <iostream>
#include <stdio.h>
#include <map>
#include <sstream>
#include <vector>
#include <algorithm>


using namespace std;

int main () {
    
    int TC, pax;
    cin >> TC >> pax;
    while (TC--) {
        vector<pair<unsigned long, string> > my_names;
        
        while (pax--) {
            string name;
            string classes;
            string dump;
            cin >> name >> classes >> dump;
            name[name.size()-1] = '\0';
            
            istringstream iss (classes);
            string token;
            string number;
            while (getline(iss, token, '-')) {
                if (token == "upper") {
                    number += "3";
                }else if (token == "middle") {
                    number += "2";
                }else {
                    number += "1";
                }
            }
            
            //reverse(number.begin(), number.end());
            while (number.size() != 10) {
                number += "2";
            }
            unsigned long converted_number = stoul(number);
            my_names.push_back(make_pair(converted_number, name));
        }
        
        sort(my_names.rbegin(), my_names.rend());
        for (auto it : my_names) {
            cout << it.second << endl;
        }
        cout << "==============================" << endl;

    }
}
