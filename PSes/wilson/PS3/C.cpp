#include <stdio.h>
#include <iostream>
#include <tuple>
#include <unordered_map>

using namespace std;

int size = 0;
int id_index[200001];
tuple<int, int, string> something[200001];

unordered_map<string, int> nameMap;

void maxsomethingify (int index, int maxSize) {
    // Compare childs
    if (2*index+2 < maxSize) {
        // Both child exist
        if (something[2*index+1] > something[2*index+2]) {
            // Left child larger than right child
            if (something[2*index+1] > something[index]) {
                swap(something[index], something[2*index+1]);
                
                id_index[get<1>(something[index])] = index;
                id_index[get<1>(something[2*index+1])] = 2*index+1;
                
                maxsomethingify(2*index+1, maxSize);
            }
        }else {
            // Left child smaller or equals to right child
            if (something[2*index+2] > something[index]) {
                swap(something[index], something[2*index+2]);
                
                id_index[get<1>(something[index])] = index;
                id_index[get<1>(something[2*index+2])] = 2*index+2;
                
                maxsomethingify(2*index+2, maxSize);
            }
        }
    }
    else if (2*index+1 < maxSize) {
        // Left child exist
        if (something[2*index+1] > something[index]) {
            swap(something[index], something[2*index+1]);
            
            id_index[get<1>(something[index])] = index;
            id_index[get<1>(something[2*index+1])] = 2*index+1;
            
            
            maxsomethingify(2*index+1, maxSize);
        }
    }
    else {
        // No child left
        return;
    }
    
}
void shiftDown (int index) {
    // Compare parent
    if (something[index] > something[(index-1)/2]) {
        // more than parent
        swap(something[index], something[(index-1)/2]);
        
        id_index[get<1>(something[index])] = index;
        id_index[get<1>(something[(index-1)/2])] = (index-1)/2;
        
        
        shiftDown((index-1)/2);
    }else {
        return;
    }
}


void insert (tuple<int, int, string> input) {
    id_index[get<1>(input)] = size;
    something[size++] = input;
    shiftDown(size - 1);
}

string top () {
    if (!size) return "#";
    return get<2>(something[0]);
}

void removeTop () {
    swap(something[0], something[size - 1]);
    
    id_index[get<1>(something[0])] = 0;
    id_index[get<1>(something[size-1])] = size-1;
    size--;
    if (!size) return;
    maxsomethingify(0, size);
}



int main () {
    int id = 200000;
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
            insert(make_tuple(dilation, id, name));
            nameMap[name] = id;
            id--;
        }
        
        else if (type == 1) {
            // update dilation
            int dilation;
            cin >> name;
            cin >> dilation;
            int index = id_index[nameMap[name]]; // might take the longest
            get<0>(something[index]) += dilation;
            if (something[index] > something[(index-1)/2]) {
                shiftDown(index);
            }else {
                maxsomethingify(index, size);
            }
        }
        
        else if (type == 2) {
            // immediately give birth
            cin >> name;
            int index = id_index[nameMap[name]]; // might take the longest
            get<0>(something[index]) = 100;
            
            if (something[index] > something[(index-1)/2]) {
                shiftDown(index);
            }else {
                maxsomethingify(index, size);
            }
            
            //cout << "----- " << get<2>(something[index]) << " " << get<0>(something[index]) << endl;
            
            //shiftDown(index);
            //maxsomethingify (index, size);
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
    }
}

