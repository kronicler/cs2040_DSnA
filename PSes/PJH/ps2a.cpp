#include <bits/stdc++.h>

using namespace std;

int main () {
    int N,type,data,i,temp;
    while (cin >> N,N !=0) {
        int verifier = 0;
        stack<int>numbers;
        for (i=0;i<N;i++){
            cin >> type >> data ;
            if (type==1)
                numbers.push(data);
            else
            {
                if (numbers.size()== 0)
                    verifier =1;
                else{
                temp = numbers.top();
                numbers.pop();
                }

                if (temp != data) {
                    verifier = 1;
                }
            }
        }
        if (verifier == 1)
            cout << "impossible" <<endl;
        else
            cout << "stack" <<endl;
        }
    return 0;
}













