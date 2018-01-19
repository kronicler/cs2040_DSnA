#include <iostream>

using namespace std;

int main(){
    unsigned long long int a,sum=0,arr[10] = {0},counter = 0,limit=1;
    int i;
    for (i=0;i<60;i++){
        limit *= 2;
    }

    while (true){
        cin >> a;
        if (counter < 10 && a >=0 && a < limit){
            arr[counter++] = a;
        }
        if ((cin.peek() == '\n')){
            if (counter = 2 && sum = 0){
                return 0;
            }
            for (i=0;i<10;i++){
                sum += arr[i];
            }
            for (i=0;i<10;i++){
                arr[i] = 0;
            }
            cout << sum << endl;
            sum = 0;
            counter = 0;
        }
    }
    return 0;
}
