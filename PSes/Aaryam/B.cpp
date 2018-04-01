#include <iostream>
#include <stdio.h>
#include <string>
#include <set>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    //two sets to keep track of male and female baby names
    set<string>male; set<string> female;
    int oper;
    
    while (1) {
        cin >> oper; if (oper == 0) break;
        //insert a new baby name depending on its gender
        if (oper == 1) {
            int gender; string name;
            cin >> name >> gender;
            if (gender == 1) male.insert(name);
            else female.insert(name);
        }
        //delete a baby name depending on its gender
        else if (oper == 2) {
            string name; cin >> name;
            auto mexist = male.find(name);
            auto fexist = female.find(name);
            
            if (mexist != male.end()) male.erase(mexist);
            if (fexist != female.end()) female.erase(fexist);
        }
        //counts the number of babies that satisfy [start, end)
        //lower_bound used as upper_bound will give the next element from the element that's desired
        //i.e. lower_bound is [ whereas upper_bound is )
        else {
            string start, end; int gender;
            cin >> start >> end >> gender;
            //keeps track of how many baby names satisfy the condition
            int babies = 0;
            
            //gender neutral, we need to count from both sets
            if (gender == 0) {
                //find no. of babies from male set
                auto m1 = male.lower_bound(start); auto m2 = male.lower_bound(end);
                for (auto i = m1; i != m2; i++) babies++;
                
                //find no. of babies from female set
                auto f1 = female.lower_bound(start); auto f2 = female.lower_bound(end);
                for (auto i = f1; i != f2; i++) babies++;
            }
            //only need to look at the male set
            else if (gender == 1) {
                auto m1 = male.lower_bound(start); auto m2 = male.lower_bound(end);
                for (auto i = m1; i != m2; i++) babies++;
            }
            //only need to look at the female set
            else {
                auto f1 = female.lower_bound(start); auto f2 = female.lower_bound(end);
                for (auto i = f1; i != f2; i++) babies++;
            }
            cout << babies << endl;
        }
    }
    return 0;
}
