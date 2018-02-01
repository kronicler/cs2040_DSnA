#include <iostream>
#include <queue>
#include <vector>
#include <functional>


using namespace std;

int main () {
    int num, numCases;
    cin >> numCases;
    for (int d = 0; d < numCases; d++) {
        cin >> num;
        long int median = 0;
        long int center = 0;
        priority_queue<long int> q; // Left sub tree
        priority_queue<long int, std::vector<long int>, std::greater<long int> > q2; // Right sub tree

        for (int i = 0; i < num; i++) {
            long int number;
            cin >> number;
            if (i == 0) center = number;
            
            
            else if (number < center) {
                q.push(number);
            }
            else if (number >= center) {
                q2.push(number);
                
            }
            if (q2.size() > q.size() && (i+1)%2) {
                q.push(center);
                center = q2.top();
                q2.pop();
            } else if (q2.size() < q.size()){
                q2.push(center);
                center = q.top();
                q.pop();
            }
            
            if (i%2) {
                // if odd
                median += (center + q2.top())/2;
                continue;
            }
            
            median += (center);
            //cout << center << endl;
        }
        
        cout << median << endl;
    }
    
    cout << "By submitting this C++ source code, I declare that it is MY OWN implementation work. I fully understand the underlying algorithm behind the C++ code that I wrote and can prove it to Lab TA if asked." << endl;
    return 0;
}
