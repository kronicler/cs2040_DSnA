#include <unordered_map>
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
unordered_map<string, int> genders;

struct AVLNode {
    AVLNode* parent;
    AVLNode* left;
    AVLNode* right;
    string babyname;
    int height;
};

class AVL {
private:
    AVLNode *root;
    
    string successor(AVLNode* newNode) {
        if (newNode->right != NULL) return QueryMin(newNode->right);
        else {
            AVLNode* par = newNode->parent;
            AVLNode* cur = newNode;
            
            while ((par != NULL) && (cur == par->right)) {
                cur = par;
                par = cur->parent;
            }
            return par == NULL ? "EMPTY" : par->babyname;
        }
    }
    
    string QueryMin(AVLNode* newNode) {
        if (newNode == NULL) return "EMPTY";
        else if (newNode->left == NULL) return newNode->babyname;
        else return QueryMin(newNode->left);
    }
    
    AVLNode* rotateLeft(AVLNode* newNode) {
        if (newNode->right == NULL) return NULL;
        
        AVLNode* temp = newNode->right;
        temp->parent = newNode->parent;
        newNode->parent = temp;
        newNode->right = temp->left;
        if (temp->left != NULL) temp->left->parent = newNode;
        temp->left = newNode;
        
        newNode->height = max(h(newNode->left), h(newNode->right)) + 1;
        temp->height = max(h(temp->left), h(temp->right)) + 1;
        
        return temp;
    }
    
    AVLNode* rotateRight(AVLNode* newNode) {
        if (newNode->left == NULL) return NULL;
        
        AVLNode* temp = newNode->left;
        temp->parent = newNode->parent;
        newNode->parent = temp;
        newNode->left = temp->right;
        if (temp->right != NULL) temp->right->parent = newNode;
        temp->right = newNode;
        
        newNode->height = max(h(newNode->left), h(newNode->right)) + 1;
        temp->height = max(h(temp->left), h(temp->right)) + 1;
        
        return temp;
    }
    
    AVLNode* AddSuggestion(AVLNode* newNode, string name) {
        if (newNode == NULL) {
            newNode = new AVLNode;
            newNode->babyname = name;
            newNode->parent = newNode->left = newNode->right = NULL;
            newNode->height = 0;
        }
        else if (newNode->babyname < name) {
            newNode->right = AddSuggestion(newNode->right, name);
            newNode->right->parent = newNode;
        }
        else {
            newNode->left = AddSuggestion(newNode->left, name);
            newNode->left->parent = newNode;
        }
        
        int balance = h(newNode->left) - h(newNode->right);
        if (balance == 2) {
            int balance2 = h(newNode->left->left) - h(newNode->left->right);
            if (balance2 == 1) {
                newNode = rotateRight(newNode);
            }
            else {
                newNode->left = rotateLeft(newNode->left);
                newNode = rotateRight(newNode);
            }
        }
        else if (balance == -2) {
            int balance2 = h(newNode->right->left) - h(newNode->right->right);
            if (balance2 == -1) {
                newNode = rotateLeft(newNode);
            }
            else {
                newNode->right = rotateRight(newNode->right);
                newNode = rotateLeft(newNode);
            }
        }
        
        newNode->height = max(h(newNode->left), h(newNode->right)) + 1;
        return newNode;
    }
    
    AVLNode* RemoveSuggestion(AVLNode* newNode, string name) {
        if (newNode == NULL) return newNode;
        
        if (newNode->babyname == name) {
            if (newNode->left == NULL && newNode->right == NULL) newNode = NULL;
            else if (newNode->left == NULL && newNode->right != NULL) {
                AVLNode* temp = newNode;
                newNode->right->parent = newNode->parent;
                newNode = newNode->right;
                temp = NULL;
            }
            else if (newNode->left != NULL && newNode->right == NULL) {
                AVLNode* temp = newNode;
                newNode->left->parent = newNode->parent;
                newNode = newNode->left;
                temp = NULL;
            }
            else {
                string successorINFO = successor(newNode);
                newNode->babyname = successorINFO;
                newNode->right = RemoveSuggestion(newNode->right, successorINFO);
            }
        }
        else if (newNode->babyname < name) newNode->right = RemoveSuggestion(newNode->right, name);
        else newNode->left = RemoveSuggestion(newNode->left, name);
        
        if (newNode != NULL) {
            int balance = h(newNode->left) - h(newNode->right);
            if (balance == 2) {
                int balance2 = h(newNode->left->left) - h(newNode->left->right);
                if (balance2 == 1) {
                    newNode = rotateRight(newNode);
                }
                else {
                    newNode->left = rotateLeft(newNode->left);
                    newNode = rotateRight(newNode);
                }
            }
            else if (balance == -2) {
                int balance2 = h(newNode->right->left) - h(newNode->right->right);
                if (balance2 == -1)
                    newNode = rotateLeft(newNode);
                else {
                    newNode->right = rotateRight(newNode->right);
                    newNode = rotateLeft(newNode);
                }
            }
            
            newNode->height = max(h(newNode->left), h(newNode->right)) + 1;
        }
        return newNode;
    }
    
    int Count(AVLNode* newNode, string start, string end, int gender) {
        if (!newNode) return 0;
        
        if (newNode->babyname < end && newNode->babyname == start) {
            return 1;
        }
        
        if (newNode->babyname < end && newNode->babyname >= start) {
            if (gender == 0) {
                return 1 + Count(newNode->left, start, end, gender) + Count(newNode->right, start, end, gender);
            }
            else if (genders[newNode->babyname] != gender) {
                return 0 + Count(newNode->left, start, end, gender) + Count(newNode->right, start, end, gender);
            }
            else {
                return 1 + Count(newNode->left, start, end, gender) + Count(newNode->right, start, end, gender);
            }
        }
        else if (newNode->babyname >= end) {
            return Count(newNode->left, start, end, gender);
        }
        else return Count(newNode->right, start, end, gender);
    }
    
public:
    AVL() {root = NULL;}
    
    int h(AVLNode* Node) { return Node == NULL ? -1 : Node->height;}
    
    void AddSuggestion(string name, int gender) {
        root = AddSuggestion(root, name);
    }
    
    void RemoveSuggestion(string name) {
        root = RemoveSuggestion(root, name);
    }
    
    int Query(string start, string end, int gender) {
        return Count(root, start, end, gender);
    }
};

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    AVL* A = new AVL();
    
    int oper, gender; string name, start, end;
    while (1) {
        cin >> oper; if (oper == 0) break;
        switch (oper) {
            case 1:
                cin >> name >> gender;
                genders[name] = gender;
                A->AddSuggestion(name, gender);
                break;
            case 2:
                cin >> name;
                genders.erase(name);
                A->RemoveSuggestion(name);
                break;
            default:
                cin >> start >> end >> gender;
                cout << A->Query(start, end, gender) << endl;
                break;
        }
    }
    return 0;
}
