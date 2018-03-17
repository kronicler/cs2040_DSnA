#include <iostream>
#include <tuple>
#include <queue>
#include <unordered_map>
using namespace std;
//tuple to store information for each woman
typedef tuple<int, int, string> womaninfo;
//keeps track of the position of each woman
int woman = 0;

int main () {
    //a priority queue to sort the woman based on their dilations
    priority_queue<womaninfo> info;
    //hash table to quickly find the dilation and position based on the woman name
    unordered_map<string, womaninfo> hash;
    int commands; cin >> commands;
    int oper, dilation, increase; string name;
    
    for (int i = 0; i < commands; i++) {
        cin >> oper;
        switch (oper) {
            case 0: {
                cin >> name >> dilation;
                // -woman is used as the later women arrive at the hospital,
                //the lower priority they're given
                hash[name] = make_tuple(dilation, -woman, name);
                info.push(make_tuple(dilation, -woman, name));
                woman++;
                break;
            }
            case 1: {
                cin >> name >> increase;
                womaninfo tmp = hash[name];
                //updates the dilation in the hash table
                get<0>(hash[name]) = get<0>(hash[name]) + increase;
                //then inserts this 'updated' node into the priority queue
                //this will work as dilations are always strictly increasing
                info.push(make_tuple(get<0>(hash[name]), get<1>(hash[name]), name));
                break;
            }
            case 2: {
                cin >> name;
                //removes woman information and name from the hash table
                hash.erase(hash.find(name));
                
                //if hash table is empty, the delivery suite is empty, so assign the
                //priority queue to an empty priority queue (same as clearing it but in O(1))
                if (hash.empty()) info = priority_queue<womaninfo>();
                //if the top of the PQ exists in the hash table, contineu
                else if (hash.find(get<2>(info.top())) != hash.end()) continue;
                //if the top of the PQ doesn't exist in the hash table, keep popping until it does
                else {
                    while (!(hash.find(get<2>(info.top())) != hash.end())) {
                        info.pop();
                    }
                }
                break;
            }
            default: {
                //if PQ is empty
                if (info.empty()) cout << "The delivery suite is empty" << endl;
                //output name of the top of the PQ
                else {
                    womaninfo tmp2 = info.top();
                    cout << get<2>(tmp2) << endl;
                }
                break;
            }
        }
    }
    return 0;
}
