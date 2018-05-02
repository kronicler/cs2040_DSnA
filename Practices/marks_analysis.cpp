#include <iostream>
#include <stdio.h>
#include <stdarg.h>
#include <math.h>
#include <list>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <algorithm>
#include <tuple>


using namespace std;


int main () {
    // Record number of possible paths to reach each node
    // 5 sections
    
    queue<pair<int, int> > q;
    q.push(make_pair(0, 0));
    
    // Vectors to store all the ranges
    vector<pair<int, int> > i;
    i.push_back(make_pair(8, 13));
    i.push_back(make_pair(14, 19));
    i.push_back(make_pair(1, 1));
    i.push_back(make_pair(20, 25));
    i.push_back(make_pair(15, 26));
    
    vector<int> mtx(100, 0);
    
    while (!q.empty()) {
        pair<int, int> curr = q.front();
        q.pop();
        
        
        if (curr.second > 4) {
            // We make sure the score is only recorded when it reaches the max num of sections
            mtx[curr.first]++;
            continue;
        }
        
        // Neighbours
        // In this case we are also generating the graph as we traverse
        for (int d = i[curr.second].first; d <= i[curr.second].second; d++) {
            q.push(make_pair(curr.first + d, curr.second + 1));
        }
    }
    
    cout << "Ended" << endl;
    cout << mtx[77] << endl; // This is to print out your target
    
}
