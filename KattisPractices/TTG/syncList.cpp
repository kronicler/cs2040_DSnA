#include <bits/stdc++.h>

using namespace std;

int main(){
    int tc = 1,i,j,input;
    do{
        scanf("%d",&tc);
        vector<int> data;
        vector<int> q;
        vector<int> corr;
        for (i=0;i<tc;i++){
            scanf("%d",&input);
            q.push_back(input);
            data.push_back(input);
        }
        sort(q.begin(),q.end());
        for (i=0;i<tc;i++){
            scanf("%d",&input);
            corr.push_back(input);
        }
        sort(corr.begin(),corr.end());

        for (i=0;i<tc;i++){
            for (j=0;j<tc;j++){
                if (data[i] == q[j]) break;
            }
            printf("%d\n",corr[j]);
        }
        printf("\n");
    }while(tc != 0);
    return 0;
}
