//
//  main.cpp
//  Treasure Hunt
//
//  Created by Aaryam Srivastava on 9/1/2018.
//  Copyright © 2018 LearnAppMaking. All rights reserved.
//

#include <iostream>
using namespace std;

int direction(int *pos_x, int *pos_y, int columns, int rows, char direct);
int main(void) {
    int rows, columns, i, j;
    int position_x = 0, position_y = 0;
    char direct;
    int moves = 0;
    int change = 0;

    cin >> rows >> columns;

    for (i = 0; i < rows; i++) {
        for (j = 0; j < columns; j++) {
            cin >> direct;
            direction(&position_x, &position_y, columns, rows, direct);
            moves++;

            if (change == 99) {
                cout << moves << endl;
                return 0;
            }
            else if (change == 10) {
                cout << "Out" << endl;
                return 0;
            }
        }
    }

    cout << "Lost" << endl;

    return 0;
}

int direction(int *pos_x, int *pos_y, int columns, int rows, char direct) {
    if (direct == 'N') {
        (*pos_y)--;
    }
    else if (direct == 'S') {
        (*pos_y)++;
    }
    else if (direct == 'W'){
        (*pos_x)--;
    }
    else if (direct == 'E') {
        (*pos_x)++;
    }
    else if (direct == 'T') {
        return 99;
    }

    if ((*pos_y) < 0 || (*pos_y) >= rows || (*pos_x) < 0 || (*pos_x) >= columns) {
        return 10;
    }

    return 0;
}
