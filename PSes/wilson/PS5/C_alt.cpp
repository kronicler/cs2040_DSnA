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

list<pair<int, int> > AL[500];
list<pair<int, int> > AL_backup[500];
list<pair<int, int> > AL_dag[500];

// O (V+E)
void dag_maker (int v, int dest) {
    unordered_set<int> visited;
    stack<int> s;
    s.push(v);

    while (!s.empty()) {
        int curr = s.top();
        //cout << (char)curr << endl;
        s.pop();
        visited.insert(curr);
        
        if (!AL[curr].empty()) {
            auto it = AL[curr].front();
            if (visited.find(it.second) == visited.end()) {
                s.push(it.second);
                //cout << (char)it.second << endl;
                AL_dag[curr].push_back(make_pair(it.first, it.second));
                AL[curr].erase(AL[curr].begin());
                if (it.second == dest) return;
            }
        }
    }
}


void dfs_topo (int vertex, unordered_set<int> *visited, list<int> * topo_list) {
    // Mark visited
    visited->insert(vertex);
    // Show its visits
    for (auto it : AL_dag[vertex]) {
        if (visited->find(it.second) == visited->end()) {
            dfs_topo(it.second, visited, topo_list);
        }
    }
    // Finish DFS, add to back of list
    topo_list->push_back(vertex);
}

void one_pass (int source, int dest, int k) {
    unordered_set<int> visited;
    list<int> topo_list;
    vector<int> added_weight (500, 1000000);
    
    dfs_topo(source, &visited, &topo_list);
    topo_list.reverse();
    
    added_weight[source] = 0;
    
    for (int i = 0; i < k; i++) {
        
        int curr = topo_list.front();
        topo_list.pop_front();
        for (auto it : AL[curr]) {
            // Relax
            if (added_weight[it.second] > added_weight[curr] + it.first) {
                added_weight[it.second] = added_weight[curr] + it.first;
            }
        }
    }
    cout << added_weight[dest] << endl;
}


int main () {
    AL['A'].push_back(make_pair(2, 'C'));
    AL['C'].push_back(make_pair(3, 'D'));
    AL['D'].push_back(make_pair(7, 'E'));
    AL['A'].push_back(make_pair(15, 'E'));
    AL['A'].push_back(make_pair(9, 'D'));
    AL['D'].push_back(make_pair(1, 'A'));

    // copy operation
    for (int i = 0; i < 500; i++) {
        AL_backup[i] = AL[i];
    }
    
    // Must specify source and destination
    while (!AL['A'].empty())
        dag_maker('A', 'E');
    
    // copy operation
    for (int i = 0; i < 500; i++) {
        AL[i] = AL_backup[i];
    }

    
    one_pass('A', 'E', 3);
    
    cout << "Ended" << endl;
}
