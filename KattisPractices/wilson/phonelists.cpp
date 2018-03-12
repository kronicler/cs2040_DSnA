#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;


void calculate () {
    priority_queue<string, vector<string>, greater<string>> pq;
    
    string input;
    int num;
    cin >> num;
    while (num--) {
        cin >> input;
        pq.push(input);
    }
    
    string curr = pq.top();
    pq.pop();
    while (pq.size() > 0) {
        string curr_ = pq.top();
        pq.pop();
        if (!strncmp(curr_.c_str(), curr.c_str(), strlen(curr.c_str()))) {
            cout << "NO" << endl;
            return;
        }
        else curr = curr_;
    }
    
    cout << "YES" << endl;
}


int main () {
    int TC;
    cin >> TC;
    
    while (TC--) {
        calculate();
    }
}

