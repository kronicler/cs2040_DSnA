#include <iostream>

int getvalue(char[8],int[8],char);
using namespace std;

int main(){
    char number[8] = {'A','K','Q','J','T','9','8','7'};
    int value[8] = {11,4,3,2,10,0,0,0};
    int value_d[8] = {11,4,3,20,10,14,0,0};

    int noCards = 0,i,sum=0;
    string dominant,temp;
    cin >> noCards;
    noCards *= 4;
    cin >> dominant;

    for (i=0;i<noCards;i++){
        cin >> temp;
        if (temp[1] == dominant[0]){
            sum += getvalue(number,value_d,temp[0]);
        }
        else{
            sum += getvalue(number,value,temp[0]);
        }
    }
    cout << sum;
    return 0;
}

int getvalue(char number[8],int value[8],char num){
    int i;
    for (i=0;i<8;i++){
        if (number[i] == num)
            break;
    }
    return value[i];
}
