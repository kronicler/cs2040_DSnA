#include <stdio.h>
#include <iostream>

using namespace std;


struct BSTVertex {
    BSTVertex* parent;
    BSTVertex* left;
    BSTVertex* right;
    string key;
    int height;
};


class BST {
public:
    void insert(string v) {
        size++;
        root = insert(root, v);
    }
    
    void remove(string v) {
        if (search(root, v) != NULL) size--;
        root = remove(root, v);
    }
    
    string successor(string v) {
        BSTVertex* vPos = search(root, v);
        return vPos == NULL ? "" : successor(vPos)->key;
    }
    
    BSTVertex * lower_bound ( string v) {
        return search_lower_bound(root, v);
    }
    
    BSTVertex * moveNext (BSTVertex * curr) {
        return successor(curr);
    }
    
    int getSize () {
        return size;
    }
    
    BST () {
        size = 0;
    }
    
    void inorder() {
        inorder(root);
        printf("\n");
    }

    
    
private:
    BSTVertex *root = NULL;
    
    int size = 0;
    
    BSTVertex* search(BSTVertex* T, string v) {
        if (T == NULL)   return T;
        else if (T->key == v) {
            return T;
        }
        else if (T->key < v) {
            return search(T->right, v);
        }
        else {
            return search(T->left, v);
        }
    }
    
    BSTVertex* search_lower_bound (BSTVertex* temp, string key) {
        BSTVertex * prev = NULL;
        while (temp != NULL) {
            if (key < temp->key) {
                prev = temp;
                temp = temp->left;
            }
            else if (key == temp->key) return temp;
            else {
                temp = temp->right;
            }
        }
        return prev;
    }

    // will be used in AVL lecture
    int getHeight(BSTVertex* T) {
        if (T == NULL) return -1;
        else return max(getHeight(T->left), getHeight(T->right)) + 1;
    }
    
    
    BSTVertex * findMin(BSTVertex* T) {
        if (T == NULL)       return NULL;             // BST is empty, no minimum
        else if (T->left == NULL) return T;                  // this is the min
        else                      return findMin(T->left);         // go to the left
    }
    
    
    // Used for traversal
    BSTVertex * successor(BSTVertex* T) {
        if (T->right != NULL)                      // this subtree has right subtree
            return findMin(T->right); // the successor is the minimum of right subtree
        else {
            BSTVertex* par = T->parent;
            BSTVertex* cur = T;
            // if par(ent) is not root and cur(rent) is its right children
            while ((par != NULL) && (cur == par->right)) {
                cur = par;                                         // continue moving up
                par = cur->parent;
            }
            return par;         // this is the successor of T
        }
    }
    
    
    
    int h(BSTVertex* T) { return T == NULL ? -1 : T->height; }
    
    BSTVertex* rotateLeft(BSTVertex* T) {
        // T must have a right child
        
        BSTVertex* w = T->right;
        w->parent = T->parent;
        T->parent = w;
        T->right = w->left;
        if (w->left != NULL) w->left->parent = T;
        w->left = T;
        
        T->height = max(h(T->left), h(T->right)) + 1;
        w->height = max(h(w->left), h(w->right)) + 1;
        
        return w;
    }
    
    BSTVertex* rotateRight(BSTVertex* T) {
        // T must have a left child
        
        BSTVertex* w = T->left;
        w->parent = T->parent;
        T->parent = w;
        T->left = w->right;
        if (w->right != NULL) w->right->parent = T;
        w->right = T;
        
        T->height = max(h(T->left), h(T->right)) + 1;
        w->height = max(h(w->left), h(w->right)) + 1;
        
        return w;
    }
    
    BSTVertex* insert(BSTVertex* T, string v) {       // override insert in BST class
        if (T == NULL) {                                 // insertion point is found
            T = new BSTVertex;
            T->key = v;
            T->parent = T->left = T->right = NULL;
            T->height = 0; // will be used in AVL lecture
        }
        else if (T->key < v) {                                // search to the right
            T->right = insert(T->right, v);
            T->right->parent = T;
        }
        else {                                                 // search to the left
            T->left = insert(T->left, v);
            T->left->parent = T;
        }
        
        int balance = h(T->left) - h(T->right);
        if (balance == 2) { // left heavy
            int balance2 = h(T->left->left) - h(T->left->right);
            if (balance2 == 1) {
                T = rotateRight(T);
            }
            else { // -1
                T->left = rotateLeft(T->left);
                T = rotateRight(T);
            }
        }
        else if (balance == -2) { // right heavy
            int balance2 = h(T->right->left) - h(T->right->right);
            if (balance2 == -1)
                T = rotateLeft(T);
            else { // 1
                T->right = rotateRight(T->right);
                T = rotateLeft(T);
            }
        }
        
        T->height = max(h(T->left), h(T->right)) + 1;
        return T;                                          // return the updated AVL
    }
    
    
    BSTVertex* remove(BSTVertex* T, string v) {
        if (T == NULL)  return T;              // cannot find the item to be deleted
        
        if (T->key == v) {                         // this is the node to be deleted
            if (T->left == NULL && T->right == NULL)                 // this is a leaf
            {
                T = NULL;                                      // simply erase this node
            }
            else if (T->left == NULL && T->right != NULL) { // only one child at right
                BSTVertex* temp = T;
                T->right->parent = T->parent;
                T = T->right;                                                // bypass T
                temp = NULL;
            }
            else if (T->left != NULL && T->right == NULL) {  // only one child at left
                BSTVertex* temp = T;
                T->left->parent = T->parent;
                T = T->left;                                                 // bypass T
                temp = NULL;
            }
            else {                                 // has two children, find successor
                string successorV = successor(v);
                T->key = successorV;        // replace this key with the successor's key
                T->right = remove(T->right, successorV);    // delete the old successorV
            }
        }
        else if (T->key < v)                                  // search to the right
            T->right = remove(T->right, v);
        else                                                   // search to the left
            T->left = remove(T->left, v);
        
        if (T != NULL) {               // similar as insertion code except this line
            int balance = h(T->left) - h(T->right);
            if (balance == 2) { // left heavy
                int balance2 = h(T->left->left) - h(T->left->right);
                if (balance2 == 1) {
                    T = rotateRight(T);
                }
                else { // -1
                    T->left = rotateLeft(T->left);
                    T = rotateRight(T);
                }
            }
            else if (balance == -2) { // right heavy
                int balance2 = h(T->right->left) - h(T->right->right);
                if (balance2 == -1)
                    T = rotateLeft(T);
                else { // 1
                    T->right = rotateRight(T->right);
                    T = rotateLeft(T);
                }
            }
            
            T->height = max(h(T->left), h(T->right)) + 1;
        }
        
        return T;                                          // return the updated BST
    }
    
    void inorder(BSTVertex* T) {
        if (T == NULL) return;
        inorder(T->left);                              // recursively go to the left
        cout << T->key << " ";
        inorder(T->right);                            // recursively go to the right
    }

    
};


BST male_ [127] ;
BST female_ [127];


int count_males (string start, string end) {
    int count = 0;
    
    for (int i = start[0]; i <= end[0]; i++) {
        if (i == start[0] || i == end[0]) {
            auto it_start = male_[i].lower_bound(start);
            auto it_end = male_[i].lower_bound(end);
            while (it_start != NULL && it_start != it_end) {
                count++;
                it_start = male_[i].moveNext(it_start);
            }
        }else {
            count += male_[i].getSize();
        }
    }
    
    return count;
}

int count_females (string start, string end) {
    int count = 0;
    
    for (int i = start[0]; i <= end[0]; i++) {
        if (i == start[0] || i == end[0]) {
            auto it_start = female_[i].lower_bound(start);
            auto it_end = female_[i].lower_bound(end);
            while (it_start != NULL && it_start != it_end) {
                count++;
                it_start = female_[i].moveNext(it_start);
            }
        }else {
            count += female_[i].getSize();
        }
    }
    return count;
}




int main () {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int command;
    while (true) {
        cin >> command;
        if (!command) break;
        
        else if (command == 1) {
            string name;
            int gender;
            cin >> name >> gender;
            if (gender == 1) {
                male_[name[0]].insert(name);
            }
            else {
                female_[name[0]].insert(name);
            }
        }
        
        else if (command == 2) {
            string name;
            cin >> name;
            
            male_[name[0]].remove(name);
            female_[name[0]].remove(name);
        }
        
        else if (command == 3) {
            // Search
            string start, end;
            int gender;
            cin >> start >> end >> gender;
            int count = 0;
            if (gender == 0) {
                count += count_males(start, end);
                count += count_females(start, end);
            }
            else if (gender == 1) {
                count += count_males(start, end);
            }
            else {
                count  += count_females(start, end);
            }
            cout << count << endl;
        }
        
    }
    
    
}

