#include <stdio.h>
#include <iostream>
#include <tuple>

using namespace std;

class l_linked {
private:
    
    struct node {
        pair<string, int> data;
        node *next;
    };
    

    node *head, *tail;
    int size = 0;
    
    
public:
    l_linked () {
        head = NULL;
        tail = NULL;
    }
    
    int getSize () {return size;}
    
    void create_node (pair<string, int> value) {
        node *temp = new node;
        temp->data = value;
        temp->next = NULL;
        if (head == NULL) {
            // If list is empty, use temp as the head and tail.
            head = temp;
            tail = temp;
            temp = NULL; // set temp to reference NULL
            size++;
        }else {
            tail->next = temp; // else create the node at the end
            tail = temp; // temp becomes the tail.
            size++;
        }
    }

    
    int search (string val) {
        node *temp = head; // Start from the head first
        while (temp != NULL) {
            // If list is not empty
            if (temp->data.first == val) return temp->data.second;
            temp = temp->next;
        }
        return NULL;
    }
};


int size = 0;
int id_index[200001];
tuple<int, int, string> something[200001];
l_linked hash_table[2000001]; // TODO: Try to implement buckets in the hash table, use a linked list, then traverse thru the linked list.

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
        hash<string> myHash;

        if (!type) {
            // Arrive at hospital
            int dilation ;
            cin >> name;
            cin >> dilation;
            insert(make_tuple(dilation, id, name));
            //nameMap[name] = id;
            
            hash_table[myHash(name)%(2000001)].create_node(make_pair(name, id));
            //cout << myHash(name) << endl;
            id--;
        }
        
        else if (type == 1) {
            // update dilation
            int dilation;
            cin >> name;
            cin >> dilation;
            //int index = id_index[nameMap[name]]; // might take the longest
            int index = id_index[hash_table[myHash(name)%(2000001)].search(name)];
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
            int index = id_index[hash_table[myHash(name)%(2000001)].search(name)];
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
    cout << "By submitting this C++ source code, I declare that it is MY OWN implementation work. I fully understand the underlying algorithm behind the C++ code that I wrote and can prove it to Lab TA if asked.\n";
}

