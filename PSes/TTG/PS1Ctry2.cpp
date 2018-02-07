#include <bits/stdc++.h>
using namespace std;

int main(){
    long int i,j,test,number,first = 1,temp,input;
    long long int sum;

    scanf("%d",&test);
    for (i = 0;i< test;i++){
        priority_queue<long int> maximum;
        priority_queue<long int,vector<long int>,greater<long int> > minimum;
        sum = 0;
        first = 1;
        scanf("%ld",&number);
        for (j=0;j<number;j++){
            scanf("%ld",&input);
            // inserts the input based on whether the input is greater than the middle value, where middle is referenced by maximum.top()
            if (first){
                maximum.push(input);
                first = 0;
            }
            else{
                if (input >= maximum.top())
                    minimum.push(input);
                else
                    maximum.push(input);
                //check re-balance if needed
                if (maximum.size() > minimum.size()){
                    temp = maximum.top();
                    maximum.pop();
                    minimum.push(temp);
                }
                else if (maximum.size() < minimum.size()){
                    temp = minimum.top();
                    minimum.pop();
                    maximum.push(temp);
                }
            }
            // calculates the median of the current entries by finding the top of the minimum priority queue(larger half) and the maximum priority queue(smaller half).
            if ((maximum.size()+minimum.size())%2==0){
                sum = sum + (maximum.top() + minimum.top())/2;
            }
            else{
                if (maximum.size()>minimum.size())
                    sum+=maximum.top();
                else
                    sum+=minimum.top();
            }
        }
        printf("%ld\n",sum);
    }
    printf("By submitting this C++ source code, I declare that it is MY OWN implementation work. I fully understand the underlying algorithm behind the C++ code that I wrote and can prove it to Lab TA if asked.\n");
    return 0;
}
