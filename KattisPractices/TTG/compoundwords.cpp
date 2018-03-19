#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string val;
    vector<string> original;
    map<string,bool> compound;

    while (!cin.eof()){
        cin >> val;
        original.push_back(val);
    }
    for (auto &a : original){
        for (auto &b : original){
            if (a != b) {
                string word1,word2;
                word1 = a + b;
                word2 = b + a;
                compound[word1] = true;
                compound[word2] = true;
            }
        }
    }
    for (auto &a : compound){
        cout << a.first << endl;
    }
    return 0;
}
