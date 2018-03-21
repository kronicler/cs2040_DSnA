#include <iostream>
#include <stdio.h>
#include <unordered_map>


using namespace std;

unordered_map<int, int> myMap;
unordered_map<int, int> myHeight;


int insert (int key) {
    if (myMap.empty()) {
        myMap[0] = key;
        myHeight[0] = 0;
        return 0 ;
    }
    
    int index = 0;
    while (true) {
        if (key > myMap[index]) {
            // traverse right
            if (myMap[2*index + 2] == 0) {
                // found insertion pt
                myMap[2*index + 2] = key;
                myHeight[2*index + 2] = myHeight[index] + 1;
                return myHeight[2*index + 2];
            }
            index = 2*index+2;
        }
        else if (key < myMap[index]) {
            // traverse left
            if (myMap[2*index + 1] == 0) {
                // found insertion pt
                myMap[2*index + 1] = key;
                myHeight[2*index + 1] = myHeight[index] + 1;
                return myHeight[2*index + 1];
            }
            index = 2*index+1;
        }
        else{
            return 0;
        }
    }
}



int main () {
    
    int count = 0;
    int num; cin >> num;
    for (int i = 1; i <= num; i++) {
        //int key; cin >> key;
        count += insert(i);
        cout << count << endl;
    }
    // TODO: Find out how to minimise the index size as it overflows too easily 
    
}
