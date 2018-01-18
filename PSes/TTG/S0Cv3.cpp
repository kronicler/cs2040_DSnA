#include <iostream>

using namespace std;

int main(){
    unsigned long long int a,sum=0,counter = 0;
    int i;

    while (true){
        cin >> a;
        sum += a;
        counter++;
        if ((cin.peek() == '\n')){
            if (counter == 2 && sum == 0){
                return 0;
            }
            cout << sum << endl;
            sum = 0;
            counter = 0;
        }
    }
    return 0;
}
