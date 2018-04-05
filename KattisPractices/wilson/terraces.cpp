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
#include <stack>


using namespace std;

int mtx[600][600], mtx_prime[600][600];
int col, row;


bool join (int x, int y) {
    mtx_prime[y][x] = 0; // temp marking
    bool move = false;
    int dx [4] = {0, 1, 0, -1};
    int dy [4] = {1, 0, -1, 0};
    for (int i = 0; i < 4; i++) {
        if (x + dx[i] < col && y + dy[i] < row && x + dx[i] >= 0 && y + dy[i] >= 0) {
            if (mtx[y][x] == mtx[y + dy[i]][x + dx[i]] && mtx_prime[y + dy[i]][x + dx[i]] == -1) {
                if (join(x + dx[i], y + dy[i])) {
                    move = true;
                }else if (mtx[y][x] > mtx[y + dy[i]][x + dx[i]]) {
                    move = true;
                }
            }else if (mtx[y][x] == mtx[y + dy[i]][x + dx[i]] && mtx_prime[y + dy[i]][x + dx[i]] == 0) {
                move = true;
            }
        }
    }
    if (!move) {
        mtx_prime[x][y] = 1;
    }
    
    return move;
}


bool dfs_recur (int x, int y) {
    mtx_prime[y][x] = 0; // 0 means visited but not collection point
    int dx [4] = {0, 1, 0, -1};
    int dy [4] = {1, 0, -1, 0};
    bool moves = false;
    for (int i = 0; i < 4; i++) {
        if (x + dx[i] < col && y + dy[i] < row && x + dx[i] >= 0 && y + dy[i] >= 0) {
            if (mtx[y][x] > mtx[y+dy[i]][x+dx[i]]) {
                moves = true;
                if (mtx_prime[y + dy[i]][x + dx[i]] == -1) {
                    dfs_recur(x + dx[i], y + dy[i]);
                }
            }else if (mtx[y][x] == mtx[y + dy[i]][x + dx[i]] && mtx_prime[y + dy[i]][x + dx[i]] == -1) {
                // need to have proper condition here
                // TODO: Add a flood fill which floods all elements of the same while checking if it can flow anywhere else. 
            }
        }
    }
    
    if (!moves) {
        mtx_prime[y][x] = 1;
    }
    return moves;
}


void dfs (int x, int y) {
    dfs_recur(x, y);
}



int main() {
    // Flood fill at unvisited nodes/ nodes that are not marked using DFS until it reaches a node with nowhere to flow to (ie bottom-most)
    // Mark that node as a collection point
    // Move on with the rest
    cin >> col >> row;
    for (int i = 0; i < row; i++) {
        for (int d = 0; d < col; d++) {
            cin >> mtx[i][d];
            mtx_prime[i][d] = -1; // -1 means unvisited
        }
    }
    
    for (int i = 0; i < row; i++) {
        for (int d = 0; d < col; d++) {
            if (mtx_prime[i][d] == -1) {
                dfs(d, i);
            }
        }
    }
    cout << endl;
    for (int i = 0; i < row; i++) {
        for (int d = 0; d < col; d++) {
            if (mtx_prime[i][d] == 1) {
                cout << "x ";
            }else {
                cout << mtx[i][d] << " ";
            }
        }
        cout << endl;
    }
    cout << endl;
    for (int i = 0; i < row; i++) {
        for (int d = 0; d < col; d++) {
            cout << mtx_prime[i][d] << " ";
        }
        cout << endl;
    }

    
    
}

