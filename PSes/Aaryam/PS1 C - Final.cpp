//
//  main.cpp
//  PS1
//
//  Created by Aaryam Srivastava on 27/1/2018.
//  Copyright © 2018 LearnAppMaking. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;

int main () {
    int testcases, numbers;
    cin >> testcases;
    
    for (int i = 0; i < testcases; i++) {
        cin >> numbers;
        /*priority queue medians2 has a lambda comparator, and the built in 'greater' function gives
         prority to smaller elements in the pq. This is because when calculating the continuous median,
         the top of the priority queues have to be accessed, and hence one pq has to give priority to
         larger elements, while the other has to give priority to smaller elements. Pq medians1 will
         give priority to the larger elements, while medians2 will give priority to the smaller elements*/
        priority_queue<unsigned long long>medians1;
        priority_queue<unsigned long long, vector<unsigned long long>, greater<unsigned long long>>medians2;
        unsigned long long temp, cmedian = 0;
        
        for (int j = 0; j < numbers; j++) {
            cin >> temp;
            //ensures each pq has et least one element
            if (j == 0) {
                medians1.push(temp);
                cmedian += temp;
                continue;
            }
            else if (j == 1)  {
                if (temp > medians1.top()) medians2.push(temp);
                else {
                    medians1.push(temp);
                    medians2.push(medians1.top());
                    medians1.pop();
                }
                cmedian += (medians1.top() + medians2.top())/2;
                continue;
            }
            
            //places next element
            if (temp < medians1.top()) medians1.push(temp);
            else if (temp > medians2.top()) medians2.push(temp);
            else medians1.push(temp);
            
            /*resizes pq if needed, won't run when no. of elements is odd as there obviously will be a difference then */
            if ((int)medians1.size() > (int)medians2.size() + 1) {
                medians2.push(medians1.top());
                medians1.pop();
            }
            else if ((int)medians2.size() > (int)medians1.size() + 1) {
                medians1.push(medians2.top());
                medians2.pop();
            }
            
            //calculates median based on no. of elements
            if (((int)medians1.size() + (int)medians2.size()) % 2 == 0) {
                cmedian += (medians1.top() + medians2.top())/2;
            }
            else {
                if ((int)medians1.size() > (int)medians2.size()) cmedian += medians1.top();
                else cmedian += medians2.top();
            }
        }
        cout << cmedian << endl;
    }
    
    cout << "By submitting this C++ source code, I declare that it is MY OWN implementation work. I fully understand the underlying algorithm behind the C++ code that I wrote and can prove it to Lab TA if asked." << endl;
    
    return 0;
}

