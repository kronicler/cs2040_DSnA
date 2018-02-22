#include <bits/stdc++.h>

using namespace std;

int main(){
    char att;
    vector<char> moves;
    int i;
    char temp1,temp2,temp3;
    do{
        scanf("%c",&att);
        if (att == 'R')
            moves.push_back('S');
        else if (att == 'B')
            moves.push_back('K');
        else if (att == 'L')
            moves.push_back('H');

        if (moves.size()>=3){
            temp1 = moves.back();
            moves.pop_back();

            temp2 = moves.back();
            moves.pop_back();

            temp3 = moves.back();
            moves.pop_back();

            if ((temp1 == 'S' &&temp2 == 'K' &&temp3 == 'H')||
                (temp1 == 'S' &&temp2 == 'H' &&temp3 == 'K')||
                (temp1 == 'H' &&temp2 == 'S' &&temp3 == 'K')||
                (temp1 == 'H' &&temp2 == 'K' &&temp3 == 'S')||
                (temp1 == 'K' &&temp2 == 'S' &&temp3 == 'H')||
                (temp1 == 'K' &&temp2 == 'H' &&temp3 == 'S')
                )
                moves.push_back('C');
            else{
                moves.push_back(temp3);
                moves.push_back(temp2);
                moves.push_back(temp1);
            }
        }
    }while (att != '\n');

    for (i = 0;i<moves.size();i++){
        printf("%c",moves[i]);
    }

    return 0;
}
