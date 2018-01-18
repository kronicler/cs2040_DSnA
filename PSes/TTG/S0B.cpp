#include <iostream>

using namespace std;

int main(){
    unsigned long long a,sum,previous = -1;
    int first = 1;
    while (true){
        if (first){
            cin >> a;
        }
        else{
            previous = a;
            cin >> a;
        }
        if (previous == 0 && a == 0) break;

        sum += a;
    }
    return 0;
}
