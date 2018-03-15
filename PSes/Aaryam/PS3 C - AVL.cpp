#include <unordered_map>
#include <iostream>
#include <string>
using namespace std;

//tuple to hold all of the information for each woman
typedef tuple<int, int, string> iii;
//standard reply if the BST is empty
iii EMPTY = make_tuple(0, 0, "The delivery suite is empty");
//keeps count of how many woman have entered the hospital
int woman = 0;

//unordered map to return corresponding dilations and positions to women names in constant time
unordered_map<string, int> finding;
unordered_map<string, int> position;

//boolean to determine whether a new node is being inserted, or an updated one
bool updating = false;

//implementing a BST to make all four operations O(log N) or faster
struct AVLNode {
    AVLNode* parent;
    AVLNode* left;
    AVLNode* right;
    iii womaninfo;
    int height;
};

class AVL {
private:
    AVLNode *root;
    
    //checks for successor of node to be deleted in case that node has 2 children
    iii successor(AVLNode* newNode) {
        if (newNode->right != NULL) return QueryMin(newNode->right);
        else {
            AVLNode* par = newNode->parent;
            AVLNode* cur = newNode;
            
            while ((par != NULL) && (cur == par->right)) {
                cur = par;
                par = cur->parent;
            }
            return par == NULL ? EMPTY : par->womaninfo;
        }
    }
    
    //returns the woman with the minimum dilation
    iii QueryMin(AVLNode* newNode) {
        if (newNode == NULL) return EMPTY;
        else if (newNode->left == NULL) return newNode->womaninfo;
        else return QueryMin(newNode->left);
    }
    
    //returns the info of the woman with the maximum dilation
    iii QueryMax(AVLNode* newNode) {
        if (newNode == NULL) return EMPTY;
        else if (newNode->right == NULL) return newNode->womaninfo;
        else return QueryMax(newNode->right);
    }
    
    AVLNode* rotateLeft(AVLNode* newNode) {
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
        // newNode must have a left child
        
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
    
    //inserts a new node each time a woman checks into the hospital
    AVLNode* ArriveatHospital(AVLNode* newNode, iii info) {
        if (newNode == NULL) {
            newNode = new AVLNode;
            newNode->womaninfo = info;
            newNode->parent = newNode->left = newNode->right = NULL;
            newNode->height = 0;
        }
        else if (newNode->womaninfo < info) {
            newNode->right = ArriveatHospital(newNode->right, info);
            newNode->right->parent = newNode;
        }
        else {
            newNode->left = ArriveatHospital(newNode->left, info);
            newNode->left->parent = newNode;
        }
        
        int balance = h(newNode->left) - h(newNode->right);
        if (balance == 2) { // left heavy
            int balance2 = h(newNode->left->left) - h(newNode->left->right);
            if (balance2 == 1) {
                newNode = rotateRight(newNode);
            }
            else { // -1
                newNode->left = rotateLeft(newNode->left);
                newNode = rotateRight(newNode);
            }
        }
        else if (balance == -2) { // right heavy
            int balance2 = h(newNode->right->left) - h(newNode->right->right);
            if (balance2 == -1)
                newNode = rotateLeft(newNode);
            else { // 1
                newNode->right = rotateRight(newNode->right);
                newNode = rotateLeft(newNode);
            }
        }
        
        newNode->height = max(h(newNode->left), h(newNode->right)) + 1;   // return the updated AVL
        return newNode;
    }
    
    //removes a node from the BST when a woman gives birth
    AVLNode* GiveBirth(AVLNode* newNode, iii info) {
        if (newNode == NULL) return newNode;
        
        if (newNode->womaninfo == info) {
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
                iii successorINFO = successor(newNode);
                newNode->womaninfo = successorINFO;
                newNode->right = GiveBirth(newNode->right, successorINFO);
            }
        }
        else if (newNode->womaninfo < info) newNode->right = GiveBirth(newNode->right, info);
        else newNode->left = GiveBirth(newNode->left, info);
        
        if (newNode != NULL) {               // similar as insertion code except this line
            int balance = h(newNode->left) - h(newNode->right);
            if (balance == 2) { // left heavy
                int balance2 = h(newNode->left->left) - h(newNode->left->right);
                if (balance2 == 1) {
                    newNode = rotateRight(newNode);
                }
                else { // -1
                    newNode->left = rotateLeft(newNode->left);
                    newNode = rotateRight(newNode);
                }
            }
            else if (balance == -2) { // right heavy
                int balance2 = h(newNode->right->left) - h(newNode->right->right);
                if (balance2 == -1)
                    newNode = rotateLeft(newNode);
                else { // 1
                    newNode->right = rotateRight(newNode->right);
                    newNode = rotateLeft(newNode);
                }
            }
            
            newNode->height = max(h(newNode->left), h(newNode->right)) + 1;
        }
        return newNode;
    }
public:
    AVL() {root = NULL;}
    
    //returns the height of a node
    int h(AVLNode* Node) { return Node == NULL ? -1 : Node->height;}
    
    //inserts an element in the BST
    void ArriveatHospital(string name, int dilation) {
        if (updating == true) {
            auto pos = position.find(name);
            root = ArriveatHospital(root, make_tuple(dilation, pos->second, name));
            updating = false;
        }
        else {
            finding.insert({name, dilation});
            position.insert({name, -woman});
            root = ArriveatHospital(root, make_tuple(dilation, -woman, name)); woman++;
        }
    }
    
    //removes the information of the woman who gave birth
    void GiveBirth(string womanName) {
        auto search = finding.find(womanName);
        auto pos = position.find(womanName);
        root = GiveBirth(root, make_tuple(search->second, pos->second, womanName));
        finding.erase(womanName); position.erase(womanName);
    }
    
    //updates dilation of a woman in the BST
    void UpdateDilation(string womanName, int increasedilation) {
        auto search = finding.find(womanName);
        auto pos = position.find(womanName);
        
        iii newdilation = make_tuple(search->second, pos->second, womanName);
        get<0>(newdilation) = get<0>(newdilation) + increasedilation;
        
        GiveBirth(womanName);
        
        updating = true;
        finding.insert({womanName, get<0>(newdilation)});
        position.insert({womanName, get<1>(newdilation)});
        ArriveatHospital(womanName, get<0>(newdilation));
    }
    //returns the name of the woman with the maximum dilation
    iii Query() { return QueryMax(root); }
};

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    AVL* A = new AVL();
    
    long long commands; cin >> commands;
    int oper, dilation, increase; string name;
    for (int i = 0; i < commands; i++) {
        cin >> oper;
        switch (oper) {
            case 0:
                cin >> name >> dilation;
                A->ArriveatHospital(name, dilation);
                break;
            case 1:
                cin >> name >> increase;
                A->UpdateDilation(name, increase);
                break;
            case 2:
                cin >> name;
                A->GiveBirth(name);
                break;
            default:
                iii tmp = A->Query();
                cout << get<2>(tmp) << endl;
                break;
        }
    }
    return 0;
}

