#include <stdio.h>
#include <iostream>
#include <set>
#include <unordered_map>
#include <vector>

using namespace std;

set<string> male;
set<string> female;


int count_male_babies (string start, string end) {
    auto it = male.lower_bound(start);
    auto it2 = male.lower_bound(end);
    // Will take O(N)
    int count = 0;
    for (auto i = it; i != it2 && i != male.end(); i++) {
        count++;
    }
    return count;
}

int count_female_babies (string start, string end) {
    auto it = female.lower_bound(start);
    auto it2 = female.lower_bound(end);
    int count = 0;
    for (auto i = it; i != it2 && i != female.end(); i++) {
        count++;
    }
    return count;
}


int main () {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int command;
    while (true) {
        cin >> command;
        if (!command) break;
        
        else if (command == 1) {
            string name;
            int gender;
            cin >> name >> gender;
            if (gender == 1) {
                male.insert(name);
            }
            else {
                female.insert(name);
            }
        }
        
        else if (command == 2) {
            string name;
            cin >> name;
            auto it = female.find(name);
            auto it2 = male.find(name);
            if (it != female.end()) female.erase(it);
            if (it2 != male.end()) male.erase(it2);
        }
        
        else if (command == 3) {
            // Search
            string start, end;
            int gender;
            cin >> start >> end >> gender;
            int count = 0;
            if (gender == 0) {
                // gender fluid
                auto it = male.lower_bound(start);
                auto it2 = male.lower_bound(end);
                // Will take O(N)
                for (auto i = it; i != it2 && i != male.end(); i++) {
                    count++;
                }
                it = female.lower_bound(start);
                it2 = female.lower_bound(end);
                for (auto i = it; i != it2 && i != female.end(); i++) {
                    count++;
                }

            }
            else if (gender == 1) {
                auto it = male.lower_bound(start);
                auto it2 = male.lower_bound(end);
                // Will take O(N)
                for (auto i = it; i != it2 && i != male.end(); i++) {
                    count++;
                }
            }
            else {
                auto it = female.lower_bound(start);
                auto it2 = female.lower_bound(end);
                for (auto i = it; i != it2 && i != female.end(); i++) {
                    count++;
                }
            }
            cout << count << endl;
        }
        
    }
    
    
}