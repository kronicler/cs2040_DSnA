#include <bits/stdc++.h>

using namespace std;

int main(){
    unsigned long long int TC,counter1 = 0;
    cin >> TC;

    while (counter1 < TC) {
        unsigned long long int N,med,sum = 0,temp,i,input;
        priority_queue <unsigned long long int> q1;
        priority_queue <unsigned long long int,vector<unsigned long long int>,greater <unsigned long long int> > q2;
        cin >> N;
        for (i=0;i<N;i++) {
            cin >> input;
            //arrange the input into two priority queue heap
            if(q1.empty())
                q1.push(input);
            else if (input >= q1.top())
                    q2.push(input);
            else
                q1.push(input);

        //sort the input accordingly so that the q1 and q2 would have the same size and if size differs ,the extra element always go to q1
            if (q1.size() > q2.size()){
                q2.push(q1.top());
                q1.pop();
            }
            if(q1.size()< q2.size()){
                q1.push(q2.top());
                q2.pop();
            }

        //calculate the median
            if (q1.size()== q2.size())
                med = (q1.top()+q2.top())/2;
            else
                med = q1.top();

            sum += med;

        }
        cout << sum <<endl;
        counter1++;

    }

    cout << "By submitting this C++ source code, I declare that it is MY OWN implementation work. I fully understand the underlying algorithm behind the C++ code that I wrote and can prove it to Lab TA if asked."<<endl;



    return 0;
}
