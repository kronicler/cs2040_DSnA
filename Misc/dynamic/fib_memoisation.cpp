#include <iostream>
#include <stdio.h>
#include <time.h>

using namespace std;

int fib (int n, int memo[]) {
    if (n == 1 || n == 2) {
        return 1;
    }
    
    if (memo[n] != 0) {
        return memo[n];
    } else {
        memo[n] = fib(n-1, memo) + fib(n-2, memo);
        
        return memo[n];
    }
}

int fib_wo_memo (int n) {
    if (n == 1 || n == 2)
        return 1;
    
    return fib_wo_memo(n - 1) + fib_wo_memo(n - 2);
}


int main () {
    int n, memo[1000] = {0};
    printf("Try n = 30, at least it's able to show the time. Max is 30 for int\n");
    do {
        printf("n = ");
        scanf("%d", &n);
        if (n) {
            clock_t startTime = clock();

            printf("%d ", fib(n, memo));
            clock_t endTime = clock();
            clock_t duration = double(endTime - startTime)/CLOCKS_PER_SEC*1000;
            cout << "time: " << duration << "ms" << endl;
            startTime = clock();
            
            printf("%d ", fib_wo_memo(n));
            endTime = clock();
            duration = double(endTime - startTime)/CLOCKS_PER_SEC*1000;
            cout << "time_w/o_memo: " << duration << "ms" << endl;
        }
    }while (n > 0);
}
