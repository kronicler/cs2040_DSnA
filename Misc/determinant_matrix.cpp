#include <stdio.h>
#include <iostream>
#include <math.h>
#define MAX 10

using namespace std;

// Recursive
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


int main () {
    int size;
    
    scanf("%d", &size);
    
    int arr[MAX][MAX] = {{0}};
    
    for (int i = 0; i < size ; i++) {
        for (int d = 0; d < size; d++) {
            scanf("%d", &arr[i][d]);
        }
    }
    printf("%d\n", det(arr, size));
}
