#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int entries;
    cin >> entries;
    while (entries > 0){
        int i=0;
        map<string,vector<string>> breakfast;
        while (i<=entries){
            string stream,name,food;
            getline(cin,stream);
            istringstream iss(stream);
            iss >> name;
            while (!iss.eof()){
                iss >> food;
                breakfast[food].push_back(name);
            }
            i++;
        }
        for (auto &x : breakfast){
            cout << x.first << " ";
            sort(x.second.begin(),x.second.end());
            for (auto &y : x.second)
                cout << y << " ";
            cout << endl;
        }
        cin >> entries;
    }
    return 0;
}
