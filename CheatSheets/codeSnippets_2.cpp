

// How do we use custom data structs and still have comparison abilities in sorting/ priority queue

// 1st method
struct special_int {
    int x;
    special_int(int _x) {
        x = _x;
    }
    // Create an operator overload
    bool operator < (const special_int& b) const {
        return x > b.x;
    }
};

// 2nd method - use pairs
auto i = make_pair(0, make_pair(1, 1)); // 0 will be used as the comparison integer

