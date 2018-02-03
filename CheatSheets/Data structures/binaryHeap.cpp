// Key theory
/*
Indexing from 1
 i left = 2i
 i right = 2i + 1
 i parent = floored i/2 (rely on integer)

Indexing from 0
 i left = 2i + 1
 i right = 2i + 2
 i parent = floored (i-1)/2
 */


class binHeap {
private:
    vector<int> heap;
    
    
    // Recursive
    void maxHeapify (int index) {
        // Compare childs
        if (2*index+1 < heap.size() && heap[2*index+1] > heap[index] && heap[2*index+1] > heap[2*index+2]) {
            swap(heap[index], heap[2*index+1]);
            maxHeapify(2*index+1);
        }else if (2*index+2 < heap.size() && heap[2*index+2] > heap[index] && heap[2*index+1] <= heap[2*index+2]) {
            swap(heap[index], heap[2*index+2]);
            maxHeapify(2*index+2);
        }else {
            return;
        }
    }
    void fixTree (int index) {
        // Compare parent
        if (heap[index] > heap[(index-1)/2]) {
            // more than parent
            swap(heap[index], heap[(index-1)/2]);
            fixTree((index-1)/2);
        }else {
            return;
        }
    }
    
public:
    binHeap(vector<int> myVector) {
        buildHeap(myVector);
    }
    
    void insert (int value) {
        heap.push_back(value);
        fixTree(heap.size() - 1);
    }
    
    int top () {
        if (heap.empty()) return -1;
        return heap[0];
    }
    
    void removeTop () {
        swap(heap[0], heap[heap.size() - 1]);
        heap.erase(--heap.end());
        if (heap.empty()) return;
        maxHeapify(0);
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
            maxHeapify(i); // uses maxHeapify, basically start from the first half of the array and heapify from there
            // O(N)
        }
    }
};