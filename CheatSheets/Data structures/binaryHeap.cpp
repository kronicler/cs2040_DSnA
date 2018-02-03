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
            // NLog(N)
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
        //printVector();
        for (int i = 0; i < myVector->size() ; i++) {
            swap(heap[0], heap[heap.size()-1 - i]);
            maxHeapify(0, heap.size()-1 - i);
            //cout << heap[0] << endl;
        }
        
        *myVector = heap;
    }
    
    // TODO: Finish my heap_Sort algo
};