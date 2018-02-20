#include <stdio.h>
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;


int main () {
    vector<pair<int, int>> period_id;
    queue<int> id_queue;
    int smallest_period = 3000;
    int num_queries;
    string placeholder;

    do {
        int id, period;
        cin >> placeholder;
        if (placeholder[0] != '#') {
            cin >> id >> period;
            if (period < smallest_period) smallest_period = period;
            
            period_id.push_back(make_pair(id, period));
        }
        
    }while (placeholder[0] != '#');
    
    cin >> num_queries;
    
    sort(period_id.begin(), period_id.end());
    
    for (int i = smallest_period; i <= smallest_period*num_queries; i++) {
        for (auto it = period_id.begin(); it != period_id.end(); it++) {
            if (i % it->second == 0) {
                id_queue.push(it->first);
            }
        }
    }
    
    for (int i = 0; i < num_queries; i++) {
        cout << id_queue.front() << endl;
        if (i != num_queries-1) {
            id_queue.pop();
        }
    }
}
