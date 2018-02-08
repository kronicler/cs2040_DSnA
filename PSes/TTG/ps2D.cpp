#include <bits/stdc++.h>

using namespace std;

class binH{
private:
    int arr[100000] = {0};
    int S = 0;

    void maxH(int i, int maxSize) {
        if (2*i+1 < get_size() && 2*i+2 < maxSize) {
            if (arr[2*i+1] > arr[2*i+2]) {
                if (arr[2*i+1] > arr[i]) {
                    swap(arr[i], arr[2*i+1]);
                    maxH(2*i+1, maxSize);
                }
            }else {
                if (arr[2*i+2] > arr[i]) {
                    swap(arr[i], arr[2*i+2]);
                    maxH(2*i+2, maxSize);
                }
            }
        }
        else if (2*i+1 < maxSize) {
            if (arr[2*i+1] > arr[i]) {
                swap(arr[i], arr[2*i+1]);
                maxH(2*i+1, maxSize);
            }
        }
        else if (2*i+2 < maxSize) {
            if (arr[2*i+2] > arr[i]) {
                swap(arr[i], arr[2*i+2]);
                maxH(2*i+2, maxSize);
            }
        }
        else {
            return;
        }
    }
    void shiftDown (int i) {
        if (arr[i] > arr[(i-1)/2]) {
            swap(arr[i], arr[(i-1)/2]);
            shiftDown((i-1)/2);
        }else {
            return;
        }
    }
public:
    binH(){
        S=0;
    }
    void insert (int value) {
        arr[S++]=value;
        shiftDown(get_size() - 1);
    }
    int get_size(){
        return S;
    }
    int top(){
        if (S == 0) return -1;
        return arr[0];
    }
    void removeTop () {
        swap(arr[0], arr[get_size() - 1]);
        S--;
        if (S==0) return;
            maxH(0, get_size());
    }
};

int main(){
    int numInputs=1,i,k,type,value,s_flag = 1,q_flag=1,p_flag=1;
    do{
        s_flag = 1;
        q_flag = 1;
        p_flag = 1;
        int storage_s[100000] = {0},storage_q[100000] = {0};
        binH storage_p;

        int s_back = 0;
        int q_front = 0,q_back=0;
        int p_back=0;

        scanf("%d",&numInputs);
        if (numInputs==0) {
            printf("By submitting this C++ source code, I declare that it is MY OWN implementation work. I fully understand the underlying algorithm behind the C++ code that I wrote and can prove it to Lab TA if asked.\n");
            return 0;
        }
        for (i=0;i<numInputs;i++){
            scanf("%d",&type);
            scanf("%d",&value);
            if (type==1){
                storage_s[s_back++] = value;
                storage_q[q_back++] = value;
                storage_p.insert(value);
            }
            else{
                if (s_back != 0){
                    if (storage_s[s_back-1] != value && s_flag){
                        s_flag = 0;
                    }
                    s_back--;
                }
                else if (s_back == 0)
                    s_flag = 0;

                if (q_front!=q_back){
                    if (storage_q[q_front] != value && q_flag){
                        q_flag = 0;
                    }
                    q_front++;
                }
                else if (q_back == 0)
                    q_flag = 0;

                if (storage_p.get_size() != 0){
                    if (storage_p.top() != value && p_flag){
                        p_flag = 0;
                    }
                    storage_p.removeTop();
                }
                else if (storage_p.get_size()==0)
                    p_flag = 0;
            }
            //printf("stack=%d,queue=%d,priority=%d ",s_flag,q_flag,p_flag);
        }

        if ((s_flag+q_flag+p_flag)>= 2)
            printf("not sure\n");
        else if (s_flag)
            printf("stack\n");
        else if (q_flag)
            printf("queue\n");
        else if (p_flag)
            printf("priority queue\n");
        else
            printf("impossible\n");
    } while(numInputs!=0);

}
