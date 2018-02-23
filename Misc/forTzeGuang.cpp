#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main () {
    string arr[] = {
        "       *",
        " *     *",
        "   *   *",
        "     * *",
        "        ",
        "       x",
        "     x  ",
        "     x  ",
        "     x  ",
        "     x  ",
        "     x  ",
        "     x  ",
        "    x   ",
        "  x     ",
        "  x     "
    };
    
    string arr2[15];
    for (int i = 0; i < 15; i++) {
        //arr2[i] = arr[i];
        reverse(arr[i].begin(), arr[i].end());

        for (int d = 0; d < 20; d++) {
            reverse(arr[i].begin(), arr[i].end());
            arr2[i] += arr[i];
        }
        cout << arr2[i] << endl;
    }
}
