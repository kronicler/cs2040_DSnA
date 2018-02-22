#include <bits/stdc++.h>

using namespace std;

int main() {
    int i,tc,length=0,input;
    stack<int> great;
    stack<int> order;
    scanf("%d",&tc);

    for(i=0;i<tc;i++){
        scanf("%d",&input);
        if (length == 0){
            great.push(input);
            length++;
        }
        else{
            if (input > great.top()){
                great.push(input);
                length++;
            }
        }

    }
    printf("%d\n",length);
    for(i=0;i<length;i++){
        order.push(great.top());
        great.pop();
    }
    for(i=0;i<length;i++){
        printf("%d ",order.top());
        order.pop();
    }
}
