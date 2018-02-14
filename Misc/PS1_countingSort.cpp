#include <stdio.h>
#include <iostream>


using namespace std;

// Adjust the pivot
// Best case O(N) complexity

void adjust (int *center, int *left, int *right, int arr[]) {
    if (*left > *right) {
        *right += 1;
        *left -= 1;
        
        for (int i = *center-1; i >= 0 ; i--) {
            if (arr[i]) {
                *center = i;
                break;
            }
        }
    }else if (*left < *right - 1) {
        *right -= 1;
        *left += 1;
        
        for (int i = *center+1; i < 100000 ; i++) {
            if (arr[i]) {
                *center = i;
                break;
            }
        }
        
    }else {
        return;
    }
}

int main () {
    // Use an array to store the occurences of the digits then traverse the central pointer
    int center, left = 0, right = 0;
    int arr[100000] = {0};
    int size;
    scanf("%d", &size);
    for (int i = 0; i < size; i++) {
        int number;
        scanf("%d", &number);
        arr[number]++;
        
        if (!i) {
            center = number;
        }else {
            if (number > center) {
                right++;
                adjust(&center, &left, &right, arr);
            }else {
                left++;
                adjust(&center, &left, &right, arr);
            }
        }
        printf("Pivot: %d\n", center);
        
        if (!(i+1)%2) {
            // Even number
            int d;
            for (d = center+1; d < 100000; d++) {
                if (arr[d]) {
                    break;
                }
            }
            printf("Median: %d\n", (center+d)/2);
        }else {
            printf("Median: %d\n", center);
        }
        
    }
    
    
    
}

