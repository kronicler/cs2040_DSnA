#include <iostream>
#include <vector>
using namespace std;

int main() {
    unsigned long int num = 0, sum = 0;
    vector <unsigned long int> sums {};
    int i = 0;
    
    while (1) {
        cin >> num;
        sum += num;
        i++;
        
        if (cin.get() == '\n') {
            if (i == 2 && sum == 0) {
                break;
            }
            sums.push_back(sum);
            sum = 0;
            i = 0;
        }
    }
    
    for (unsigned long int i : sums) {
        cout << i << endl;
    }
    
    return 0;
}
