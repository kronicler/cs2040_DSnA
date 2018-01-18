#include <iostream>

using namespace std;
int result(int,int);

int main(){
    int s0,s1,r0,r1,result1,result2;
    while (true) {
        cin >> s0 >> s1 >> r0 >> r1;
        if (s0 == 0 && s1 == 0 && r0 == 0 && r1 == 0){
            return 0;
        }
        result1 = result(s0,s1);
        result2 = result(r0,r1);
        if (result1 > result2) {
            cout << "Player 1 wins." << endl;
        }
        else if (result1 < result2) {
            cout << "Player 2 wins." << endl;
        }
        else{
            cout << "Tie." << endl;
        }
    }
    return 0;
}

int result(int no1, int no2){
    if ((no1 == 1 and no2 == 2) || (no1 == 2 and no2 == 1)){
        return 1000;
    }
    else if (no1 == no2){
        return (no1 * 10 + no2) * 10;
    }
    else{
        if (no1 > no2){
            return no1 * 10 + no2;
        }
        else{
            return no2 * 10 + no1;
        }
    }
    return 0;
}

