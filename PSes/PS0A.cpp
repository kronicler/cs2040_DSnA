#include <iostream>
#include <vector>
using namespace std;

int main() {
    int num1 = 0, num2 = 0, sum = 0;
    vector <int> sums {};
    
    while (1) {
        cin >> num1 >> num2;
        sum = num1 + num2;
        
        if (sum == 0) {
            break;
        }
        
        sums.push_back(sum);
    }
    
    for (int i : sums) {
        cout << i << endl;
    }
    
    return 0;
}
