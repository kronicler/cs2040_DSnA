#include <iostream>

using namespace std;

int main(){
    int registers[8] = {0},calc = 0;
    int limits[8] = {2,3,5,7,11,13,17,19};
    for (int i = 0; i < 8; i++){
        cin >> registers[i];
    }
    while (registers[7] < 19){
        registers[0]++;
        calc++;
        for (int i = 0; i < 7; i++){
            if (registers[i] >= limits[i]){
                registers[i+1]++;
                registers[i] = 0;
            }
        }
    }
    calc--;
    cout << calc;
    return 0;
}
