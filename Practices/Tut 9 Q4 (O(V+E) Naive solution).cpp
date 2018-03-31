#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;
vector<vector<int>> friends; int degree = 0;
vector<int> visited;

bool CanAccess(int i, int j) {
    visited[i] = 1;
    for (auto k : friends[i]) {
        if (k == j) {
            if (degree < 2) return true;
        }
        else if (!visited[k]) {
            degree++;
            CanAccess(k, j);
        }
    }
    return false;
}

int main () {
    friends.emplace_back(1, 2);
    friends.emplace_back(1, 3);
    friends.emplace_back(1, 4);
    friends.emplace_back(2, 11);
    friends.emplace_back(3, 5);
    friends.emplace_back(3, 6);
    friends.emplace_back(3, 7);
    friends.emplace_back(3, 8);
    friends.emplace_back(4, 9);
    friends.emplace_back(4, 10);
    friends.emplace_back(7, 12);
    friends.emplace_back(7, 13);
    friends.emplace_back(7, 14);
    
    visited.assign(13, 0);
    cout << CanAccess(1, 14) << endl;
    visited.clear();
    visited.assign(13, 0);
    degree = 0;
    cout << CanAccess(1, 3) << endl;
    visited.clear();
    visited.assign(13, 0);
    degree = 0;
    cout << CanAccess(1, 7) << endl;
    
    
    return 0;
}
