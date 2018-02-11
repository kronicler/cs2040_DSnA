//
//  main.cpp
//  PS1
//
//  Created by Aaryam Srivastava on 27/1/2018.
//  Copyright © 2018 LearnAppMaking. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
    int test_cases, numbers;
    vector <unsigned long long> n;
    unsigned long long temp;
    unsigned long long continuous_median = 0;
    
    cin >> test_cases;
    unsigned long long answer[test_cases];
    
    for (int i = 0; i < test_cases; i++) {
        cin >> numbers;
        for (int j = 0; j < numbers; j++) {
            cin >> temp;
            n.push_back(temp);
            if (j == 0) {
                continuous_median += temp;
                continue;
            }
            
            int sorting = j;
            while (1) {
                if (n[sorting] < n[sorting-1]) {
                    swap(n[sorting], n[sorting-1]);
                    sorting--;
                    if (sorting == 0) break;
                }
                else break;
            }
            
            if ((j+1) % 2 == 0) {
                continuous_median += (n[j/2] + n[(j/2) + 1]) /2;
            }
            else {
                continuous_median += n[(j + 1) / 2];
            }
        }

        answer[i] = continuous_median;
        continuous_median = 0;
        n.erase(n.begin(), n.end());
    }
    
    for (int i = 0; i < test_cases; i++) {
        cout << answer[i] << endl;
    }
    
    return 0;
}
