#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long int TC,N,med,sum = 0,temp,counter1=0,counter2,j;

    cin >> TC;

    while (counter1 < TC) {
        vector<long int> numbers;
        cin >> N;
        counter2 = 0;
        sum = 0;
        while (counter2 < N) {
            cin >> temp;
            numbers.push_back(temp);
            counter2++;
            sort (numbers.begin(),numbers.begin()+counter2);
            j = (counter2-1)/2;
            if ((counter2%2)==0)
                med = ((numbers[j] + numbers[j+1])/2);
            else
                med = numbers[j];
            sum += med;

        }
        cout << sum << endl;
        counter1++;
    }
    return 0;
}
