// TODO: Use DFS

#include <iostream>
#include <vector>
#include <stack>
#include <tuple>

using namespace std;

char mtx[1000][1000];

int visit_check (int x, int y, vector<tuple<int, int>> visited) {
    for (auto it = visited.begin(); it != visited.end(); it++) {
        if (x == get<0>(*it) && y == get<1>(*it))
            return 1;
    }
    return 0;
}


void search_neighbours (vector<tuple<int, int>> visited, stack<tuple<int, int>> *toVist,tuple<int, int> current, int row, int col) {
    int x = get<0>(current);
    int y = get<1>(current);
    char currentChar = mtx[y][x];
    
    if (x+1 < col && mtx[y][x+1] == currentChar && !visit_check(x+1, y, visited)) {
        auto newCoords = make_tuple(x+1, y);
        toVist->push(newCoords);
    }
    if (x-1 >= 0 && mtx[y][x-1] == currentChar && !visit_check(x-1, y, visited)) {
        auto newCoords = make_tuple(x-1, y);
        toVist->push(newCoords);
        
    }
    if (y-1 >= 0 && mtx[y-1][x] == currentChar && !visit_check(x, y-1, visited)) {
        auto newCoords = make_tuple(x, y-1);
        toVist->push(newCoords);
        
    }
    if (y+1 < row && mtx[y+1][x] == currentChar && !visit_check(x, y+1, visited)) {
        auto newCoords = make_tuple(x, y+1);
        toVist->push(newCoords);
        
    }
}


int dfs (int x1, int y1, int x2, int y2, int row, int col) {
    auto current = make_tuple(x1, y1);
    vector<tuple<int, int>> visited;
    stack<tuple<int, int>> toVisit;
    toVisit.push(current);
    while (!toVisit.empty()) {
        current = toVisit.top();
        toVisit.pop();
        visited.push_back(current);
        if (get<0>(current) == x2 && get<1>(current) == y2) return 1; // found the end
        search_neighbours(visited, &toVisit ,current, row, col);
    }
    return 0;
}



int main () {
    // Flood fill and determine if it reaches the destination we want. First detect if the particular point is binary or decimal
    int x, y;
    scanf("%d %d", &y, &x);
    for (int i = 0; i < y; i++) {
        scanf("%s", &mtx[i]);
    }
    
    int queries;
    scanf("%d", &queries);
    for (int i = 0; i < queries; i++) {
        int x1, y1, x2, y2;
        scanf("%d %d %d %d", &y1, &x1, &y2, &x2);
        if (dfs(x1-1, y1-1, x2-1, y2-1, y, x)) {
            if (mtx[y1-1][x1-1] == '1') printf("decimal\n");
            else printf("binary\n");
        }else {
            printf("neither\n");
        }
    }
    
}

