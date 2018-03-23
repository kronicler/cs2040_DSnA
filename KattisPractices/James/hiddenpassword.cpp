#include <iostream>
#include <string>
using namespace std;

int main() {
    string password, message;
    int pIndex = 0;
    int mIndex = 0;

    cin >> password >> message;
    int pLength = password.length();
    int mLength = message.length();

    while (pIndex <= pLength && mIndex <= mLength) {
        if (password[pIndex] == message[mIndex]) {
            pIndex++;
            mIndex++;
        } else if (password.substr(pIndex, password.length()).find(message[mIndex]) != string::npos) {
            cout << "FAIL" << " " << pIndex << mIndex << endl;
            cout << password.substr(pIndex, password.length()) << endl;
            cout << message[mIndex] << endl;
            return 0;
        } else {
            mIndex++;
        }
    }
    if (pLength != pIndex-1) {
            cout << "FAIL" << endl;
    } else cout << "PASS" << endl;
    return 0;
}