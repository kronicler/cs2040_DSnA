#include <bits/stdc++.h>

using namespace std;

int main () {

deque<char>output;
string original;

cin >> original;

for (int i=0;original[i];i++) {
    if (original[i] != '<')
        output.push_back(original[i]);
    else
        output.pop_back();

    }

    for(auto &v: output) {
        cout << v ;
    }
    return 0;
}

