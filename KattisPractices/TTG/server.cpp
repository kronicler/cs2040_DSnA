#include <bits/stdc++.h>

using namespace std;

int main(){
    int tc,timeLimit,noTasks=0,input,i,time=0,accept=1;
    scanf("%d",&tc);
    scanf("%d",&timeLimit);

    for (i=0;i<tc;i++){
        scanf("%d",&input);
        if (((time + input) <= timeLimit)&&accept){
            time+=input;
            noTasks++;
        }
        else accept = 0;
    }
    printf("%d",noTasks);
}
