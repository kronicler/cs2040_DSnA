#include <iostream>
#include <stdio.h>
#include <ctype.h>

using namespace std;
bool compare(char,string);
int main(){
    string input,lower = "abcdefghijklmnopqrstuvwxyz",upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    cin >> input;
    int i = 0;
    double length = (double)input.size();
    double w = 0,l = 0,u = 0,s = 0;
    for (i;i< input.length();i++){
        if (input[i] == '_') w++;
        else if (compare(input[i],lower)) l++;
        else if (compare(input[i],upper)) u++;
        else s++;
    }
    printf("%0.16lf\n",w/length);
    printf("%0.16lf\n",l/length);
    printf("%0.16lf\n",u/length);
    printf("%0.16lf\n",s/length);
}

bool compare(char input,string alphabet){
    int i=0;
    for (i;i < alphabet.length();i++){
        if (input == alphabet[i])
            return true;
    }
    return false;
}
