#include <bits/stdc++.h>

using namespace std;

int main(){
    int numInputs=1,i,type,value,stack_flag = 1,queue_flag=1,priority_flag=1;
    do{
        stack_flag = 1;
        queue_flag = 1;
        priority_flag = 1;
        vector<int> storage_s;
        vector<int> storage_q;
        priority_queue<int> storage_p;

        scanf("%d",&numInputs);
        if (numInputs==0) return 0;
        for (i=0;i<numInputs;i++){
            scanf("%d",&type);
            scanf("%d",&value);
            if (type==1){
                storage_s.push_back(value);
                storage_q.push_back(value);
                storage_p.push(value);
            }
            else{
                if (storage_s.size() != 0){
                    if (storage_s.back() != value && stack_flag){
                        stack_flag = 0;
                    }
                    storage_s.pop_back();
                }
                else if (storage_s.size() == 0)
                    stack_flag = 0;

                if (storage_q.size() != 0){
                    if (storage_q.front() != value && queue_flag){
                        queue_flag = 0;
                    }
                    storage_q.erase(storage_q.begin());
                }
                else if (storage_q.size() == 0)
                    queue_flag = 0;

                if (storage_p.size() != 0){
                    if (storage_p.top() != value && priority_flag){
                        priority_flag = 0;
                    }
                    storage_p.pop();
                }
                else if (storage_p.size() == 0)
                    priority_flag = 0;
            }
            //printf("stack=%d,queue=%d,priority=%d ",stack_flag,queue_flag,priority_flag);
        }

        if ((stack_flag+queue_flag+priority_flag)>= 2)
            printf("not sure\n");
        else if (stack_flag)
            printf("stack\n");
        else if (queue_flag)
            printf("queue\n");
        else if (priority_flag)
            printf("priority queue\n");
        else
            printf("impossible\n");
    } while(numInputs!=0);
}
