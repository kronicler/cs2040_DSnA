#include <iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{
    unsigned long long int a,sum;
    int i;
    string numbers;
    while (true){
        sum = 0;
        getline(cin,numbers);
        istringstream iss(numbers);

        if (numbers == "0 0")
            return 0;

        while (!iss.eof()) {
            iss >> a;
            sum += a;
    }
    cout << sum <<endl;
}

    return 0;
}
