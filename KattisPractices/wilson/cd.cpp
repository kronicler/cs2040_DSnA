#include <iostream>
#include <stdio.h>
#include <unordered_set>

using namespace std;


int main () {
    int numJack, numJill;
    while (true) {
        unordered_set<long long> jack;
        long long count = 0;
        scanf("%d %d", &numJack, &numJill);
        if (numJack == 0 && numJill == 0) {
            break;
        }
        
        for (long long i = 0; i < numJack; i++) {
            long long num;
            scanf("%lld", &num);
            jack.insert(num);
        }
        
        for (long long i = 0; i < numJill; i++) {
            long long num;
            scanf("%lld", &num);
            if (jack.find(num) != jack.end()) {
                count++;
            }
        }
        printf("%lld\n", count);
    }
}

