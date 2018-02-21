#include <bits/stdc++.h>
#include <string.h>

using namespace std;

int main() {

    string moves,output;
    cin >> moves;

   for (int i = 0;i<=moves.size();i++){
    if ((moves[i] != moves[i+1]) && (moves [i+1]!= moves [i+2]) && (moves[i] != moves[i+2])&& (i+2)<moves.size()){
        output.push_back('C');
        i=i+2;
    }
    else if (moves[i]=='R')
        output.push_back('S');
    else if (moves[i]=='B')
        output.push_back('K');
    else if (moves[i]=='L')
        output.push_back('H');
   }
   cout << output <<endl;

    return 0;
}
