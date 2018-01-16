#include <iostream>

using namespace std;

int main(){
    int registers[8] = {0},calc = 0,value=1;
    int limits[8] = {2,3,5,7,11,13,17,19};
    int temp[8] = {0};
    for (int i = 0; i < 8; i++){
        cin >> registers[i];
    }
    for (int i = 0; i < 8; i++){
        temp[i] = limits[i] - registers[i] - 1;
    }
    for (int i = 0; i < 8; i++){
        value = 1;
        if (i == 0){
            calc += temp[i];
        }
        else{
            for (int j = 0;j<i;j++){
                value *= limits[j];
            }
            calc = calc + value * temp[i];
        }
    }
    cout << calc;
    return 0;
}
