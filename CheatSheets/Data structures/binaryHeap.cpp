// Impt notes: 
/*
1. i left = 2i+1
2. i right = 2i+2
3. i parent = (i-1)/2 (floored)
*/


class binHeap {
private:
    vector<int> heap;
    
    
    // Recursive
    void maxHeapify (int index, int maxSize) {
        // Compare childs
        if (2*index+1 < heap.size() && 2*index+2 < maxSize) {
            // Both child exist
            if (heap[2*index+1] > heap[2*index+2]) {
                // Left child larger than right child
                if (heap[2*index+1] > heap[index]) {
                    swap(heap[index], heap[2*index+1]);
                    maxHeapify(2*index+1, maxSize);
                }
            }else {
                // Left child smaller or equals to right child
                if (heap[2*index+2] > heap[index]) {
                    swap(heap[index], heap[2*index+2]);
                    maxHeapify(2*index+2, maxSize);
                }
            }
        }
        else if (2*index+1 < maxSize) {
            // Left child exist
            if (heap[2*index+1] > heap[index]) {
                swap(heap[index], heap[2*index+1]);
                maxHeapify(2*index+1, maxSize);
            }
        }
        else if (2*index+2 < maxSize) {
            // Right child exist
            if (heap[2*index+2] > heap[index]) {
                swap(heap[index], heap[2*index+2]);
                maxHeapify(2*index+2, maxSize);
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
            shiftDown((index-1)/2);
        }else {
            return;
        }
    }
    
public:
    binHeap(vector<int> myVector) {
        buildHeap(myVector);
    }
    
    binHeap() {}
    
    
    
    void insert (int value) {
        heap.push_back(value);
        shiftDown(heap.size() - 1);
    }
    
    int top () {
        if (heap.empty()) return -1;
        return heap[0];
    }
    
    void removeTop () {
        swap(heap[0], heap[heap.size() - 1]);
        heap.erase(--heap.end());
        if (heap.empty()) return;
        maxHeapify(0, heap.size());
    }
    
    void printVector () {
        for (int i = 0; i < heap.size(); i++) {
            cout << heap[i] << " ";
        }
        cout << endl;
    }
    
    void buildHeap_slow (vector<int> myVector) {
        for (auto i = myVector.begin(); i != myVector.end(); i++) {
            insert(*i); // Insert and fixTree
            // O(NLogN)
        }
    }
    
    void buildHeap (vector<int> myVector) {
        heap = myVector;
        for (int i = heap.size()/2; i >= 0; i--) {
            maxHeapify(i, heap.size()); // uses maxHeapify, basically start from the first half of the array and heapify from there
            // O(N)
        }
    }
    
    void heap_sort (vector<int> *myVector) {
        heap = *myVector;
        buildHeap(heap);
        for (int i = 0; i < myVector->size() ; i++) {
            swap(heap[0], heap[heap.size()-1 - i]);
            maxHeapify(0, heap.size()-1 - i);
        }
        
        *myVector = heap;
    }    
};

// Some notes on binary heap
/*
    1. Vertices less than a given vertice basically just means all smaller nodes in the whole tree. 
    2. Min num comparisons made in buidHeap O(n) is just N elements - 1
    3. Worst case insertion: Log(N), N = height of tree
    4. Best case insertion: O(1)
    5. HeapSort speed is O(NlogN)
    6. Max number of comparisons in a binHeap = num of (parent-child) * 2 for a 2 child subtree. 
*/










