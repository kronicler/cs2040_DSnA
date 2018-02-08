#include <iostream>
#include <vector>
#include <stack>
#include <tuple>

using namespace std;


void searchNeighbours (stack<tuple<int, int>> *mystack, char mtx[][1000], tuple<int, int> currentCoords, int bin, char paint, int row, int col) {
    int x = get<0>(currentCoords);
    int y = get<1>(currentCoords);
    
    if (x+1 < col && mtx[y][x+1] != paint && mtx[y][x+1] == bin){
        auto newCoords = make_tuple(x+1, y);
        mystack->push(newCoords);
    }
    if (x-1 >= 0 && mtx[y][x-1] != paint && mtx[y][x-1] == bin) {
        auto newCoords = make_tuple(x-1, y);
        mystack->push(newCoords);
    }
    if (y-1 >= 0 && mtx[y-1][x] != paint && mtx[y-1][x] == bin) {
        auto newCoords = make_tuple(x, y-1);
        mystack->push(newCoords);
    }
    if (y+1 < row && mtx[y+1][x] != paint && mtx[y+1][x] == bin) {
        auto newCoords = make_tuple(x, y+1);
        mystack->push(newCoords);
    }
}

void floodFill_stacks(char mtx[][1000], tuple<int, int> firstCoords, int row, int col) {
    stack<tuple<int, int>> myStack;
    myStack.push(firstCoords);
    
    while (!myStack.empty()) {
        int bin = mtx[get<1>(myStack.top())][get<0>(myStack.top())];
        auto current = myStack.top();
        myStack.pop();
        if (bin == '1') {
            mtx[get<1>(current)][get<0>(current)] = 'x';
            char paint = 'x';
            searchNeighbours(&myStack, mtx, current, bin, paint, row, col);
        }else if (bin == '0'){
            mtx[get<1>(current)][get<0>(current)] = 'y';
            char paint = 'y';
            searchNeighbours(&myStack, mtx, current, bin, paint, row, col);
        }
        
        // TODO: Complete flood fill. If the character is not 1 or 0, that means it has been filled before
        // TODO: If it is, fill it with something different and unique
    }
}




int main () {
    // Flood fill and determine if it reaches the destination we want. First detect if the particular point is binary or decimal
    int x, y;
    scanf("%d %d", &y, &x);
    char mtx[1000][1000];
    for (int i = 0; i < y; i++) {
        for (int d = 0; d < x; d++) {
            scanf("%s", &mtx[i]);
        }
    }
    
    
    int queries;
    cin >> queries;
    for (int i = 0; i < queries; i++) {
        int x1, y1, x2, y2;
        cin >> y1 >> x1 >> y2 >> x2;
        //auto firstCoords = make_tuple(x1-1, y1-1);
        //auto endCoords = make_tuple(x2-1, y2-1);
        int code = mtx.at(y1-1).at(x1-1);
        int endcode = mtx.at(y2-1).at(x2-1);
        
        if (code == endcode) {
            if (code > 0) cout << "binary" << endl;
            else if (code < 0) cout << "decimal" << endl;
        }else {
            cout << "neither" << endl;
        }
    }
}

