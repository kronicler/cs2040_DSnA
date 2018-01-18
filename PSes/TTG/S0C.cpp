#include <iostream>

using namespace std;

int main(){
    unsigned long long int a,sum=0,previous = -1,counter = 0;
    int first = 1;
    while (true){
        if (first){
            cin >> a;
            first = 0;
        }
        else{
            previous = a;
            cin >> a;
        }
        counter++;
        sum += a;
        if (previous == 0 && a == 0) return 0;
        if ((cin.peek() == '\n') ||(counter == 10)){
            cout << sum << endl;
            sum = 0;
            counter = 0;
        }
    }
    return 0;
}
