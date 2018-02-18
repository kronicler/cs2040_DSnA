#include <stdio.h>
#include <iostream>
#include <math.h>
#define MAX 10

using namespace std;

int det (int mtx[][MAX], int size) {
    
    int total = 0;
    
    if (size == 2) {
        return mtx[0][0] * mtx[1][1] - mtx[0][1] * mtx[1][0];
    }else {
        
        for (int i = 0; i < size; i++) {
            int newMtx[MAX][MAX];
            int row = 0;
            for (int d = 1; d < size; d++) {
                int col = 0;
                for (int c = 0; c < size; c++) {
                    if (c != i) {
                        newMtx[row][col++] = mtx[d][c];
                    }
                }
                row++;
            }
            total += pow(-1, i+2) * det(newMtx, size-1) * mtx[0][i];
        }
    }
    
    return total;
}


void cofactor (int cofactor_mtx[][MAX], int input_mtx[][MAX], int size) {
    int temp_mtx[MAX][MAX];
    int row = 0, col = 0;
    
    for (int i = 0; i < size; i++) {
        for (int d = 0; d < size; d++) {
            // Outer loop: set cofactor coords, pull from input_mtx

            for (int c = 0; c < size; c++) {
                for (int k = 0; k < size; k++) {
                    if (c != i && k != d) {
                        if (col == size-1) {
                            // temp_mtx index handler
                            row++;
                            col = 0;
                        }
                        temp_mtx[row][col++] = input_mtx[c][k];
                        //printf("%d %d\n", c, k);
                    }
                }
            }
            row = 0;
            col = 0;
            cofactor_mtx[i][d] = pow(-1, i+d+2) * det(temp_mtx, size-1);
        }
    }
}

int main () {
    int cofactor_mtx[MAX][MAX], input[MAX][MAX];
    
    int size;
    
    scanf("%d", &size);
    
    for (int i = 0; i < size ; i++) {
        for (int d = 0; d < size; d++) {
            scanf("%d", &input[i][d]);
        }
    }
    
    cofactor(cofactor_mtx, input, size);
    
    for (int i = 0; i < size ; i++) {
        for (int d = 0; d < size; d++) {
            printf("%4d", cofactor_mtx[i][d]);
        }
        printf("\n");
    }
}
