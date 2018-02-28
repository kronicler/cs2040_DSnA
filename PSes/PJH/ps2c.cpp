#include <bits/stdc++.h>

using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N,type,data,i,temp;
    while (cin >> N,N !=0) {
        int verifier = 0 , verifier2 =0, verifier3=0 ,verifiersum;
        stack<int>numbers;
        queue<int>numbers2;
        priority_queue<int>numbers3;
        for (i=0;i<N;i++){
            cin >> type >> data ;
            if (type==1)
                numbers.push(data);
            else
            {
                if (numbers.size()==  0)
                    verifier =1;
                else{
                temp = numbers.top();
                numbers.pop();
                }

                if (temp != data) {
                    verifier = 1;
                }
            }
            if (type==1)
                numbers2.push(data);
            else {
                if(numbers2.empty())
                    verifier2=1;
                else {
                    temp = numbers2.front();
                    numbers2.pop();
                }
                if (temp!= data)
                    verifier2 = 1;
            }
            if(type == 1)
                numbers3.push(data);
            else {
                if(numbers3.empty())
                    verifier3 = 1;
                else{
                    temp = numbers3.top();
                    numbers3.pop();
                }
                if (temp != data)
                    verifier3 = 1;
            }
        }
        verifiersum = verifier + verifier2 + verifier3;

        if (verifiersum < 2)
            cout << "not sure"<<endl;
        else if (verifier == 0)
            cout << "stack" <<endl;
        else if (verifier2 == 0)
            cout <<"queue"<<endl;
        else if (verifier3 == 0)
            cout <<"priority queue"<<endl;
        else
            cout << "impossible" <<endl;
    }
    return 0;
}

