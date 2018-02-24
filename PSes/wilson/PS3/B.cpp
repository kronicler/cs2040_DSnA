#include <stdio.h>
#include <iostream>
#include <tuple>
#include <map>
#include <queue>

using namespace std;


class binSomething {
private:
    tuple<int, int, string> Something[200000];
    int size = 0;
    // Recursive
    void maxSomethingify (int index, int maxSize) {
        // Compare childs
        if (2*index+1 < size && 2*index+2 < maxSize) {
            // Both child exist
            if (Something[2*index+1] > Something[2*index+2]) {
                // Left child larger than right child
                if (Something[2*index+1] > Something[index]) {
                    swap(Something[index], Something[2*index+1]);
                    maxSomethingify(2*index+1, maxSize);
                }
            }else {
                // Left child smaller or equals to right child
                if (Something[2*index+2] > Something[index]) {
                    swap(Something[index], Something[2*index+2]);
                    maxSomethingify(2*index+2, maxSize);
                }
            }
        }
        else if (2*index+1 < maxSize) {
            // Left child exist
            if (Something[2*index+1] > Something[index]) {
                swap(Something[index], Something[2*index+1]);
                maxSomethingify(2*index+1, maxSize);
            }
        }
        else if (2*index+2 < maxSize) {
            // Right child exist
            if (Something[2*index+2] > Something[index]) {
                swap(Something[index], Something[2*index+2]);
                maxSomethingify(2*index+2, maxSize);
            }
        }
        else {
            // No child left
            return;
        }
        
    }
    void shiftDown (int index) {
        // Compare parent
        if (Something[index] > Something[(index-1)/2]) {
            // more than parent
            swap(Something[index], Something[(index-1)/2]);
            shiftDown((index-1)/2);
        }else {
            return;
        }
    }
    
public:
    
    binSomething() {}
    
    void insert (tuple<int, int, string> input) {
        Something[size] = input;
        size++;
        shiftDown(size - 1);
    }
    
    string top () {
        if (!size) return "#";
        return get<2>(Something[0]);
    }
    
    
    void removeTop () {
        swap(Something[0], Something[size - 1]);
        size--;
        if (!size) return;
        maxSomethingify(0, size);
    }
    
    
    int getSize () {
        return size;
    }
    
    void update () {
        // Binary search then bubble up, bubble down
        
    }
    
};



int main () {
    int count = 0;
    int numCmds;
    //binSomething bin;
    //priority_queue<tuple<int, int, string>> bin;
    //map<int, pair<int, string>, std::greater<int>>  m2;
    queue<string> mymap[101];
    cin >> numCmds;
    
    for (int i = 0; i < numCmds; i++) {
        int type;
        string name;
        cin >> type;
        
        if (!type) {
            // Arrive at hospital
            int dilation ;
            cin >> name;
            cin >> dilation;
            //bin.insert(make_tuple(dilation, count, name));
            //bin.push(make_tuple(dilation, count, name));
            mymap[dilation].push(name);
        }
        
        else if (type == 1) {
            // update dilation
            int dilation;
            cin >> name;
            cin >> dilation;
            
        }
        
        else if (type == 2) {
            // immediately give birth
            cin >> name;
            //bin.removeTop();
            //bin.pop();
            //mymap.begin()->second.begin();
            for (int i = 100; i >= 0; i--) {
                if (!mymap[i].empty()) {
                    // first one
                    mymap[i].pop();
                    break;
                }
            }
        }
        else {
            // Query
            //string top = bin.top();
            int i;
            for (i = 100; i >= 0; i--) {
                if (!mymap[i].empty()) {
                    // first one
                    cout << mymap[i].front() << endl;
                    break;
                }
            }
            if (i == -1) {
                cout << "The delivery suite is empty\n";
            }
        }
        count++;
        
    }
}