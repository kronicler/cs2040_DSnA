#include <stdio.h>
#include <iostream>
#include <tuple>
#include <map>
#include <deque>
#include <vector>

using namespace std;

int size = 0;
map<string, int> name_index;


void maxHeapify (tuple<int, int, string> *heap ,int index, int maxSize) {
    // Compare childs
    if (2*index+2 < maxSize) {
        // Both child exist
        if (heap[2*index+1] > heap[2*index+2]) {
            // Left child larger than right child
            if (heap[2*index+1] > heap[index]) {
                swap(heap[index], heap[2*index+1]);
                
                name_index[get<2>(heap[index])] = index;
                name_index[get<2>(heap[2*index+1])] = 2*index+1;

                maxHeapify( heap ,2*index+1, maxSize);
            }
        }else {
            // Left child smaller or equals to right child
            if (heap[2*index+2] > heap[index]) {
                swap(heap[index], heap[2*index+2]);
                
                name_index[get<2>(heap[index])] = index;
                name_index[get<2>(heap[2*index+2])] = 2*index+2;

                maxHeapify(heap ,2*index+2, maxSize);
            }
        }
    }
    else if (2*index+1 < maxSize) {
        // Left child exist
        if (heap[2*index+1] > heap[index]) {
            swap(heap[index], heap[2*index+1]);
            
            name_index[get<2>(heap[index])] = index;
            name_index[get<2>(heap[2*index+1])] = 2*index+1;

            
            maxHeapify(heap, 2*index+1, maxSize);
        }
    }
    else {
        // No child left
        return;
    }
    
}
void shiftDown (tuple<int, int, string> *heap ,int index) {
    // Compare parent
    if (heap[index] > heap[(index-1)/2]) {
        // more than parent
        swap(heap[index], heap[(index-1)/2]);
        
        name_index[get<2>(heap[index])] = index;
        name_index[get<2>(heap[(index-1)/2])] = (index-1)/2;

        
        shiftDown(heap ,(index-1)/2);
    }else {
        return;
    }
}


void insert (tuple<int, int, string> *arr, tuple<int, int, string> input) {
    name_index[get<2>(input)] = size;
    arr[size++] = input;
    shiftDown(arr, size - 1);
}

string top (tuple<int, int, string> *arr) {
    if (!size) return "#";
    return get<2>(arr[0]);
}

void removeTop (tuple<int, int, string> *heap) {
    swap(heap[0], heap[size - 1]);
    
    name_index[get<2>(heap[0])] = 0;
    name_index[get<2>(heap[size-1])] = size-1;
    size--;
    if (!size) return;
    maxHeapify(heap ,0, size);
}



int main () {
    int count = 200000;
    int numCmds;
    tuple<int, int, string> mymap[200000];
    
    
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
            insert(mymap, make_tuple(dilation, count, name));
            count--;
        }
        
        else if (type == 1) {
            // update dilation
            int dilation;
            cin >> name;
            cin >> dilation;
            int index = name_index[name];
            get<0>(mymap[index]) += dilation;
            maxHeapify(mymap, index, size);
        }
        
        else if (type == 2) {
            // immediately give birth
            cin >> name;
            int index = name_index[name];
            get<0>(mymap[index]) = 100;
            //cout << "----- " << get<2>(mymap[name_index[name]]) << " " << get<0>(mymap[name_index[name]]) << endl;
            //swap(mymap[0], mymap[name_index[name]]);
            shiftDown(mymap, index);
            //maxHeapify(mymap, 0, size);
            //cout<< "TOP "<< get<2>(mymap[0]) << endl;
            removeTop(mymap);
        }
        else {
            // Query
            //string top = bin.top();
            if (top(mymap) == "#") {
                cout << "The delivery suite is empty\n";
            }else {
                cout << top(mymap) << endl;

            }
        }
        //cout << "-----------MARIA " << get<0>(mymap[name_index["MARIA"]]) << " " << top(mymap) <<endl;
        count++;
    }
}
