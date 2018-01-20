#include <bits/stdc++.h>
#define MAX_NAME_LENGTH 20

using namespace std;

class alphabet_t{
private:
    char alpha;
    int length;
    vector<string> names;
public:
    alphabet_t(){}
    alphabet_t(char a){
        alpha = a;
        length = 0;
    }
    void display(){
        int i;
        for (i=0;i<length;i++){
            cout << names[i] << endl;
        }
    }
    void ownSort(){
        int i,j;
        string temp;
        for (i=0;i<length;i++){
            for (j=0;j<(length-i-1);j++){
                if ((names[j][0]+names[j][1]) > (names[j+1][0] + names[j][1])) {
                    temp = names[j];
                    names[j] = names[j+1];
                    names[j+1] = temp;
                }
            }
        }
    }
    void add(string s){
        names[length++] = s;
    }
};

int main(){
    string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    int noNames,i;
    vector<alphabet_t> everything;
    for (i = 0;i< alphabet.length();i++){
        everything[i] = alphabet_t(alphabet[i]);
    }
    cout << alphabet;
    for (i = 0;i< alphabet.length();i++){
        everything[i].display();
    }
//    while (cin >> noNames){
//        for (i=0;i<noNames;i++){
//
//        }
//
//    }
    return 0;
}
