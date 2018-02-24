#include <stdio.h>
#include <iostream>
#include <tuple>
#include <unordered_map>
#include <vector>

using namespace std;

int size = 0;
unordered_map<string, int> name_index;
tuple<int, int, string> heap[200000];

void maxHeapify (int index, int maxSize) {
    // Compare childs
    if (2*index+2 < maxSize) {
        // Both child exist
        if (heap[2*index+1] > heap[2*index+2]) {
            // Left child larger than right child
            if (heap[2*index+1] > heap[index]) {
                swap(heap[index], heap[2*index+1]);
                
                name_index[get<2>(heap[index])] = index;
                name_index[get<2>(heap[2*index+1])] = 2*index+1;

                maxHeapify(2*index+1, maxSize);
            }
        }else {
            // Left child smaller or equals to right child
            if (heap[2*index+2] > heap[index]) {
                swap(heap[index], heap[2*index+2]);
                
                name_index[get<2>(heap[index])] = index;
                name_index[get<2>(heap[2*index+2])] = 2*index+2;

                maxHeapify(2*index+2, maxSize);
            }
        }
    }
    else if (2*index+1 < maxSize) {
        // Left child exist
        if (heap[2*index+1] > heap[index]) {
            swap(heap[index], heap[2*index+1]);
            
            name_index[get<2>(heap[index])] = index;
            name_index[get<2>(heap[2*index+1])] = 2*index+1;

            
            maxHeapify(2*index+1, maxSize);
        }
    }
    else {
        // No child left
        return;
    }
    
}
void shiftDown (int index) {
    // Compare parent
    if (heap[index] > heap[(index-1)/2]) {
        // more than parent
        swap(heap[index], heap[(index-1)/2]);
        
        name_index[get<2>(heap[index])] = index;
        name_index[get<2>(heap[(index-1)/2])] = (index-1)/2;

        
        shiftDown((index-1)/2);
    }else {
        return;
    }
}


void insert (tuple<int, int, string> input) {
    name_index[get<2>(input)] = size;
    heap[size++] = input;
    shiftDown(size - 1);
}

string top () {
    if (!size) return "#";
    return get<2>(heap[0]);
}

void removeTop () {
    swap(heap[0], heap[size - 1]);
    
    name_index[get<2>(heap[0])] = 0;
    name_index[get<2>(heap[size-1])] = size-1;
    size--;
    if (!size) return;
    maxHeapify(0, size);
}



int main () {
    int count = 200000;
    int numCmds;
    
    
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
            insert(make_tuple(dilation, count, name));
            count--;
        }
        
        else if (type == 1) {
            // update dilation
            int dilation;
            cin >> name;
            cin >> dilation;
            int index = name_index[name];
            get<0>(heap[index]) += dilation;
            maxHeapify(index, size);
        }
        
        else if (type == 2) {
            // immediately give birth
            cin >> name;
            int index = name_index[name];
            get<0>(heap[index]) = 100;
            //cout << "----- " << get<2>(mymap[name_index[name]]) << " " << get<0>(mymap[name_index[name]]) << endl;
            //swap(mymap[0], mymap[name_index[name]]);
            shiftDown(index);
            //maxHeapify(mymap, 0, size);
            //cout<< "TOP "<< get<2>(mymap[0]) << endl;
            removeTop();
        }
        else {
            // Query
            //string top = bin.top();
            if (top() == "#") {
                cout << "The delivery suite is empty\n";
            }else {
                cout << top() << endl;

            }
        }
        //cout << "-----------MARIA " << get<0>(mymap[name_index["MARIA"]]) << " " << top(mymap) <<endl;
        count++;
    }
}