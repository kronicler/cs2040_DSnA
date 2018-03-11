class BST {
    // Precond: this BST does not store duplicates
    // 0 is used to signify a non-existent value return
    
private:
    struct vertex {
        vertex * parent;
        vertex * left;
        vertex * right;
        int key;
    };
    
    vertex * root;
    int size;
    vertex * search_recur(int key, vertex * curr) {
        if (curr == NULL) return curr;
        
        else if (curr->key == key) return curr;

        else if (curr->key < key) return search_recur(key, curr->right);
        else return search_recur(key, curr->left);
    }

    vertex * findMax_recur (vertex * curr) {
        if (curr == NULL) return curr; // Empty
        if (curr->right != NULL) return findMax_recur(curr->right); // go right
        else return curr;
    }
    
    vertex * findMin_recur (vertex * curr) {
        if (curr == NULL) return curr; // Empty
        if (curr->left != NULL) return findMin_recur(curr->left); // go left
        else return curr;
    }
    
    
    void inorder_recur (vertex * curr) {
        if (curr == NULL) return;
        inorder_recur(curr->left);
        cout << curr->key << " ";
        inorder_recur(curr->right);
    }
    
    
    /*
        If vertex has two children, we will find successor and replace current key with the successor's key.
        We then call delete on the successor and it will happen recursively until it can no longer find a successor/ the other 2 cases happen.
    */
    vertex * remove_recur (vertex * curr, int key) {
        if (curr == NULL)  return curr; // cannot find the item to be deleted
        if (curr->key == key) {
            // 3 cases
            if (curr->right == NULL && curr->left == NULL) {
                // Leaf
                delete curr;
            }
            else if ((curr->left != NULL && curr->right == NULL) || (curr->left == NULL && curr->right != NULL)) {
                // Only one child
                vertex * temp = curr;
                if (curr->left != NULL) {
                    // Left contains a child
                    curr->left->parent = curr->parent;
                    curr = curr->left;
                    delete temp;
                }else {
                    // Right contains a child
                    curr->right->parent = curr->parent;
                    curr = curr->right;
                    delete temp;
                }
            }
            else {
                // Find successor or predecessor also can
                int successorV = successor(key);
                curr->key = successorV; // Let current vertex key be the successor
                curr->right = remove_recur(curr->right, successorV);
            }

        }
        // Find left and right if current vertex key is not the one we want. - search
        else if (curr->key < key) curr->right = remove_recur(curr->right, key);
        else curr->left = remove_recur(curr->left, key);
        
        return curr;
    }
    
public:
    
    BST () {
        // constructor
        size = 0;
        root = NULL;
    }
    
    bool search (int key) {
        if (search_recur(key, root) != NULL) return true;
        return false;
    }
    
    // Find Min/ Max will take O(h), h = height of tree. h can be as big as N if all vertices are connected to the right
    
    int findMax () {
        vertex * temp = findMax_recur(root);
        if (temp == NULL) return 0;
        
        return temp->key;
    }
    
    int findMin () {
        vertex * temp = findMin_recur(root);
        if (temp == NULL) return 0;
        return temp->key;
    }
    
    // Predecessor and successor will also run in O(h)
    
    int successor (int key) {
        vertex * curr = search_recur(key, root);
        if (curr == NULL) return 0;
        if (curr->right != NULL) return findMin_recur(curr->right)->key;
        
        else {
            vertex * p = curr->parent, * T = curr;
            
            while (p != NULL && T == p->right) {
                T = p;
                p = T->parent;
            }
            if (p == NULL) return -1;
                else return p->key;
        }
        return -1;
    }
    
    int predecessor (int key) {
        vertex * curr = search_recur(key, root);
        if (curr == NULL) return 0;
        if (curr->left != NULL) return findMax_recur(curr->left)->key;
        else {
            vertex * p = curr->parent, * T = curr;
            
            while (p != NULL && T == p->left) {
                T = p;
                p = T->parent;
            }
            if (p == NULL) return -1;
            else return p->key;
        }
        return -1;
    }
    
    // Commonly used for DFS
    // inorder traversal will give a sorted sequence O(n)
    void inorder () {
        inorder_recur(root);
        cout << endl;
    }
    
    // O(h) as we have to search first then insert if not found
    
    void insert (int key) {
        if (root == NULL) {
            vertex * temp = new vertex;
            temp->key = key;
            temp->parent = NULL;
            temp->left = NULL;
            temp->right = NULL;
            root = temp;
            size++;
            return;
        }
        vertex * temp = root;
        while (true) {
            if (key > temp->key) {
                // traverse right
                if (temp->right == NULL) {
                    // found insertion pt
                    vertex * insert = new vertex;
                    insert->key = key;
                    insert->parent = temp;
                    insert->left = NULL;
                    insert->right = NULL;
                    temp->right = insert;
                    size++;
                    return;
                }
                temp = temp->right;
            }
            else if (key < temp->key) {
                // traverse left
                if (temp->left == NULL) {
                    // found insertion pt
                    vertex * insert = new vertex;
                    insert->key = key;
                    insert->parent = temp;
                    insert->left = NULL;
                    insert->right = NULL;
                    temp->left = insert;
                    size++;
                    return;
                }
                temp = temp->left;
            }
            else{
                return;
            }
        }
    }
    
    /*
     Removal:
     - O(h) as we depend on search too
     Cases:
     - Vertex is a leaf = just search and remove by deleting
     - Vertex is internal + only 1 child = We just connect this vertex's parent with its only child
     - Vertex is internal + 2 children = We set itself to same value as its successor (successor means we have to keep travelling down the right subtree then leftwards),
     then delete duplicate in right subtree (whilst moving its child along to the current vertex too)
    */
    
    void remove (int key) {
        root = remove_recur(root, key);
    }
};


/*
 BST properties:
 - Root vertex does not have parent
 - Leaf vertex does not have any child
 - Internal vertices are vertices which are not leaves
 - We can store satellite data with the key being used to sort the BST
 - Vertices which are greater fall on the right of parent
 - Vertices which are smaller fall on the left of parent
 - We have to decide if we wish to store duplicate on the left or right (optional)
 
 - Dynamic data structure which is efficient even when updating vertices inside

 - Lower bound: h > log2(N)
 - Upper bound: h < N
 */