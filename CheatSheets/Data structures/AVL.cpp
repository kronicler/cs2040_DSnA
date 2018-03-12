#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;




/*
 AVL trees:
 - Most operations run in O(log(N)) time
 - A vertex is said to be height balanced invariant if |v.left.height - v.right.height| <= 1
 - If height balancing is satisfied, total height will always be < 2*log2(N)
 - Nh > 2 ^ (h/2),  Nh = number of vertices we can fit into height h
 - Minimum number of nodes we can fit in a tree of height H: S(h) = S(h-1) + S(h-2) + 1

 Examples:

 height: 0 1 2 3 4  5  6  7  8  9   10  11  12 
 ------------------------------------------------
 number: 0 2 4 7 12 20 33 54 88 143 232 376 609


 Rotation:
 - Right rotation: can only be called if it has a left child
 - Left rotation: can only be called if it has a right child

 
*/
