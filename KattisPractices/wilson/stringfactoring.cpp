#include <stdio.h>
#include <iostream>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

string shortener (string input) {
    map<string, int> freq;
    int flag = 0;
    for (int i = (input.length())/2; i >= 1 && !flag; i--) {
        for (int d = 0; d + i + i <= input.length(); d++) {
            if (input.substr(d, i) == input.substr(d + i, i)) {
                
                freq[input.substr(d,i)]++;
                flag = 1; // stop at this size
            }
        }
    }
    
    int largest = 0;
    if (freq.empty()) return input;
    
    //string largest;
    auto x = max_element(freq.begin(), freq.end(),
                              [](const pair<string, int>& p1, const pair<string, int>& p2) {
                                  return p1.second < p2.second; });
    if (x->first == input) return input;
    
    int a = input.find(x->first);
    
    for (int i = 0; i < x->second ; i++) {
        input.replace(a, x->first.length(), "");
        a = input.find(x->first);
    }
    if (a != -1) {
        if (!input.substr(0, a).empty())
            input.replace(0, a, shortener(input.substr(0, a)));
        if (!input.substr(a + x->first.length()-1, input.length()-1).empty())
            input.replace(a + x->first.length()-1, input.length()-1, shortener(input.substr(a + x->first.length()-1, input.length()-1)));
        //cout << input.substr(a + x->first.length()-1, input.length()-1) << endl;
        input.replace(a, x->first.length(), shortener(x->first));
    }
    
    return input;
}

int main () {
    string input;
    cin >> input;
    
    cout << shortener(input) << endl;
}