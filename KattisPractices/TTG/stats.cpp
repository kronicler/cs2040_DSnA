#include <iostream>

using namespace std;

int main() {
    int num,i,counter = 1;
    while (cin >> num){
        int low,high,range,first = 1,temp;
        for (i=0;i<num;i++){
            cin >> temp;
            if (first){
                low = temp;
                high = temp;
                range = 0;
                first = 0;
            }
            else{
                if (temp < low) low = temp;
                else if (temp > high) high = temp;
                range = high - low;
            }

        }
        cout << "Case " << counter << ": " << low << " " << high << " " << range << endl;
        counter++;
    }
}
