#include <bits/stdc++.h>

using namespace std;

set<string> male;
set<string> female;
string START,END;
int gender;
bool commandLoop = true;
int command;
string babyName;
set<string>::iterator itlow,itup,it,fit,mit;
int noNames;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while (true){
        cin >> command;
        if (command == 0) break;
        else if (command == 1){     //add a suggestion to the list.
            cin >> babyName >> gender;
            if (gender == 1){   //Good for males
                male.insert(babyName);
            }
            else{ // females
                female.insert(babyName);
            }
        }
        else if (command == 2){     //Remove a suggestion from the list.
            cin >> babyName;
            auto fit = female.find(babyName);
            auto mit = male.find(babyName);
            if (fit != female.end()) female.erase(fit);
            if (mit != male.end()) male.erase(mit);
        }
        else if (command == 3){     //Returns number of names with the indicated starting letters.
            cin >> START >> END >> gender;
            noNames=0;
            if (gender == 0){
                itlow = male.lower_bound(START);
                itup = male.lower_bound(END);
                for(it = itlow;it != itup;it++)
                    noNames++;
                itlow = female.lower_bound(START);
                itup = female.lower_bound(END);
            }
            else if (gender == 1){
                itlow = male.lower_bound(START);
                itup = male.lower_bound(END);
            }
            else if (gender == 2){
                itlow = female.lower_bound(START);
                itup = female.lower_bound(END);
            }
            for(it = itlow;it != itup;it++)
                noNames++;
            cout << noNames << endl;
        }
    }
    return 0;
}
