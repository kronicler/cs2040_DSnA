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
        root = insert(root, v);
    }
    
    void remove(string v) {
        root = remove(root, v);
    }
    
    string successor(string v) {
        BSTVertex* vPos = search(root, v);
        return vPos == NULL ? "" : successor(vPos)->key;
    }
    
    BSTVertex * lower_bound ( string v) {
        prev = root;
        search_lower_bound(root, v);
        return prev;
    }
    
    BSTVertex * moveNext (BSTVertex * curr) {
        return successor(curr);
    }
    
    void inorder () {
        inorder_recur(root);
        cout << endl;
    }
    
private:
    
    BSTVertex * prev;
    
    BSTVertex* search(BSTVertex* T, string v) {
        if (T == NULL)   return T;                                // not found
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
    
    
    BSTVertex* search_lower_bound (BSTVertex* T, string v) {
        if (T == NULL)   return T;
        
        if (T->key == v) {
            prev = T;
            return T;
        }
        else if (T->key < v) {
            // If key is smaller than V
            prev = T;
            return search_lower_bound(T->right, v);
        }else {
            prev = T;
            return T;
        }
    }
    
    
    void inorder_recur (BSTVertex * curr) {
        if (curr == NULL) return;
        inorder_recur(curr->left);
        cout << curr->key << " ";
        inorder_recur(curr->right);
    }
    
    
    BSTVertex *root;
    
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
    
    string findMax(BSTVertex* T) {
        if (T == NULL)        return "";            // BST is empty, no maximum
        else if (T->right == NULL) return T->key;                 // this is the max
        else                       return findMax(T->right);      // go to the right
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
    
    string predecessor(BSTVertex* T) {
        if (T->left != NULL)                        // this subtree has left subtree
            return findMax(T->left); // the predecessor is the maximum of left subtree
        else {
            BSTVertex* par = T->parent;
            BSTVertex* cur = T;
            // if par(ent) is not root and cur(rent) is its left children
            while ((par != NULL) && (cur == par->left)) {
                cur = par;                                         // continue moving up
                par = cur->parent;
            }
            return par == NULL ? "" : par->key;          // this is the successor of T
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
                T = NULL;                                      // simply erase this node
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
    

};


BST male_;
BST female_;



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
                male_.insert(name);
            }
            else {
                female_.insert(name);
            }
        }
        
        else if (command == 2) {
            string name;
            cin >> name;
            
            male_.remove(name);
            female_.remove(name);
        }
        
        else if (command == 3) {
            // Search
            string start, end;
            int gender;
            cin >> start >> end >> gender;
            int count = 0;
            if (gender == 0) {
                
                BSTVertex * it_ = male_.lower_bound(start);
                BSTVertex  * it2_ = male_.lower_bound(end);
                
                cout << it2_->key << " " << end <<endl;
                
                while (it_ != NULL) {
                    if (it_ == it2_) break;
                    count++;
                    it_ = male_.moveNext(it_);
                }
                it_ = female_.lower_bound(start);
                it2_ = female_.lower_bound(end);

                while (it_ != NULL) {
                    if (it_ == it2_) break;
                    count++;
                    it_ = female_.moveNext(it_);
                }
            }
            else if (gender == 1) {
                BSTVertex * it_ = male_.lower_bound(start);
                BSTVertex  * it2_ = male_.lower_bound(end);
                cout << it2_->key << " " << end <<endl;

                // Will take O(N)
                while (it_ != NULL) {
                    if (it_ == it2_) break;
                    count++;
                    it_ = male_.moveNext(it_);
                }
            }
            else {
                BSTVertex * it_ = female_.lower_bound(start);
                BSTVertex  * it2_ = female_.lower_bound(end);
                cout << it2_->key << " " << end <<endl;
                // Will take O(N)
                while (it_ != NULL) {
                    if (it_ == it2_) break;
                    count++;
                    it_ = female_.moveNext(it_);
                }
            }
            cout << count << endl;
        }
        
    }
    
    
}
