#include <stdio.h>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <sstream>
#include <algorithm>

using namespace std;


int main () {
    
    int numlines;
    cin >> numlines;
    unordered_map<string,  unordered_set<string>> name_word;
    unordered_map<string, int > words;
    
    for (int i = 0; i < numlines; i++) {
        string input;
        string name;
        cin >> name;
        cin.ignore();
        getline(cin, input);
        
        istringstream iss (input);
        string token;
        
        
        while (getline(iss, token, ' '))
        {
            words[token]++;
            name_word[name].insert(token);
        }
    }
    
    vector<pair<int, string>> to_be_sorted;
    
    for (auto it = words.begin(); it != words.end(); it++) {
        int count = 0;
        for (auto it2 = name_word.begin(); it2 != name_word.end(); it2++) {
            // For each name
            auto it3 = it2->second.find(it->first); // Find the word
            if (it3 != it2->second.end()) count++;
        }
        if (count == name_word.size()) {
            // All users have spoke it
            to_be_sorted.push_back(make_pair(it->second, it->first));
        }
    }
    
    if (to_be_sorted.empty()) {
        cout << "ALL CLEAR" << endl;
        return 0;
    }
    
    sort(to_be_sorted.begin(), to_be_sorted.end());
    reverse(to_be_sorted.begin(), to_be_sorted.end());
    for (auto it  = to_be_sorted.begin(); it != to_be_sorted.end(); it++) {
        cout << it->second << endl;
    }
    
}

