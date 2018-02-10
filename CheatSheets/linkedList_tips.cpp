#include <iostream>
#include <stdio.h>
#include <vector>
#include <list>
#include <deque>

using namespace std;

int main () {
    list<int> myList;
    
    for (int i = 0; i < 5; i++) {
        myList.push_back(i);
    }
    
    for (auto it = myList.begin(); it != myList.end(); it++) {
        printf("%d ", *it);
    }
    printf("\n");
    
    auto rt = myList.begin();
    advance(rt, 2); // Will move the iterator forwards by 2
    printf("%d\n", *rt);
    
    auto rt2 = next(myList.begin(), 2); // Will also move the iterator forwards by 2
    printf("%d\n", *rt2);
    
    
    
    list<int> myList2({5,3,2,6,1});
    myList2.sort(); // Will sort the list
    
    
    for (auto it = myList2.begin(); it != myList2.end(); it++) {
        printf("%d ", *it);
    }
    printf("\n");
    
    while (!myList2.empty()) {
        myList2.pop_back();
    } // Popping everything from the list
    printf("%lu\n", myList2.size());
    
    deque<int> mydeque ({1,2,3,4,5}); // Double ended queue
    
    printf("Double ended queue[2]: %d\n", mydeque[2]); // This operation differentiates deque from a linked list
    // Deque might be implemented as a vector hence it can be opened just like that.
    
    
    
    return 0;
}
