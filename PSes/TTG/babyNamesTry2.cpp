#include <bits/stdc++.h>

using namespace std;

set<string> male[26];
set<string> female[26];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string babyName;
    int command,gender;
    int noNames = 0;
    while (true){
        cin >> command;
        if (command == 0) break;
        else if (command == 1){
            cin >> babyName >> gender;
            if (gender == 1)
                male[babyName[0]-'A'].insert(babyName);
            else
                female[babyName[0]-'A'].insert(babyName);
        }
        else if (command == 2){
            set<string>::iterator fit,mit;
            cin >> babyName;
            char index = babyName[0]-'A';
            fit = female[index].find(babyName);
            mit = male[index].find(babyName);
            if (fit != female[index].end()) female[index].erase(fit);
            if (mit != male[index].end()) male[index].erase(mit);
        }
        else if (command == 3){     //Returns number of names with the indicated starting letters.
            set<string>::iterator itlow,itup;
            string START,END;
            int STARTindex, ENDindex;
            noNames=0;

            cin >> START >> END >> gender;
            STARTindex = START[0]-'A';
            ENDindex = END[0]-'A';

            if (gender == 0){
                itlow = male[STARTindex].lower_bound(START);
                itup = male[ENDindex].lower_bound(END);

                if (STARTindex != ENDindex){
                    for (auto it = itlow; it != male[STARTindex].end();it++)
                        noNames++;
                    for (auto it = male[ENDindex].begin(); it != itup;it++)
                        noNames++;
                    for (auto ind = STARTindex+1; ind < ENDindex; ind++)
                        noNames = noNames + male[ind].size();
                }
                else
                    for (auto it = itlow; it != itup;it++)
                        noNames++;

                itlow = female[STARTindex].lower_bound(START);
                itup = female[ENDindex].lower_bound(END);
                if (STARTindex != ENDindex){
                    for (auto it = itlow; it != female[STARTindex].end();it++)
                        noNames++;
                    for (auto it = female[ENDindex].begin(); it != itup;it++)
                        noNames++;
                    for (auto ind = STARTindex+1; ind < ENDindex; ind++)
                        noNames = noNames + female[ind].size();
                }
                else
                    for (auto it = itlow; it != itup;it++)
                        noNames++;
            }
            else if (gender == 1){
                itlow = male[STARTindex].lower_bound(START);
                itup = male[ENDindex].lower_bound(END);
                if (STARTindex != ENDindex){
                    for (auto it = itlow; it != male[STARTindex].end();it++)
                        noNames++;
                    for (auto it = male[ENDindex].begin(); it != itup;it++)
                        noNames++;
                    for (auto ind = STARTindex+1; ind < ENDindex; ind++)
                        noNames = noNames + male[ind].size();
                }
                else
                    for (auto it = itlow; it != itup;it++)
                        noNames++;
            }
            else if (gender == 2){
                itlow = female[STARTindex].lower_bound(START);
                itup = female[ENDindex].lower_bound(END);
                if (STARTindex != ENDindex){
                    for (auto it = itlow; it != female[STARTindex].end();it++)
                        noNames++;
                    for (auto it = female[ENDindex].begin(); it != itup;it++)
                        noNames++;
                    for (auto ind = STARTindex+1; ind < ENDindex; ind++)
                        noNames = noNames + female[ind].size();
                }
                else
                    for (auto it = itlow; it != itup;it++)
                        noNames++;
            }
            cout << noNames << endl;
        }
    }
    return 0;
}
