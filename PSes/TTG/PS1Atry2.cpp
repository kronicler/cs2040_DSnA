#define MAX 100000
#include <bits/stdc++.h>

using namespace std;

int main(){
    long int arr[MAX] = {0},input,sum=0;
    int testcases,i,j,k,num;
    clock_t start,stop;
    //scanf("%d",&testcases);

    start = clock();
    testcases = 3;
    for (i=0;i<testcases;i++){
        int counter=0;
        sum=0;
        //scanf("%d",&num);
        num = 100000;
        for (j=0;j<num;j++){
            //scanf("%ld",&input);
            input = rand();
            if (counter==0 || arr[counter-1]<=input){
                arr[counter++] = input;
            }
            else{
                for (k = counter-1; (k >= 0) && (arr[k] > input); k--)
                    arr[k+1] = arr[k];
                arr[k+1] = input;
                counter++;
            }
            int total = counter-1;
            if ((counter % 2) == 1)
                sum +=  arr[(total)/2];
            else
                sum += floor((arr[total/2]+arr[total/2+1])/2);
        }
        printf("%ld\n",sum);
    }
    stop = clock();
    cout << (((double)stop - start) / CLOCKS_PER_SEC) << endl;
    //printf("By submitting this C++ source code, I declare that it is MY OWN implementation work. I fully understand the underlying algorithm behind the C++ code that I wrote and can prove it to Lab TA if asked.");
    return 0;
}
