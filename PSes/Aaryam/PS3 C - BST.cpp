//
//  main.cpp
//  PS3C
//
//  Created by Aaryam Srivastava on 24/2/2018.
//  Copyright © 2018 Developers. All rights reserved.
//

#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>
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
struct BSTNode {
    BSTNode* parent;
    BSTNode* left;
    BSTNode* right;
    iii womaninfo;
};

class BST {
protected:
    //initialising the root of the BST and the functions required
    BSTNode *root;
    
    //removes a node from the BST when a woman gives birth
    BSTNode* GiveBirth(BSTNode* newNode, iii info) {
        if (newNode == NULL) return newNode;
        
        if (newNode->womaninfo == info) {
            if (newNode->left == NULL && newNode->right == NULL) newNode = NULL;
            else if (newNode->left == NULL && newNode->right != NULL) {
                newNode->right->parent = newNode->parent;
                newNode = newNode->right;
            }
            else if (newNode->left != NULL && newNode->right == NULL) {
                newNode->left->parent = newNode->parent;
                newNode = newNode->left;
            }
            else {
                iii successorINFO = successor(newNode);
                newNode->womaninfo = successorINFO;
                newNode->right = GiveBirth(newNode->right, successorINFO);
            }
        }
        else if (newNode->womaninfo < info) newNode->right = GiveBirth(newNode->right, info);
        else newNode->left = GiveBirth(newNode->left, info);
        return newNode;
    }
    
    //checks for successor of node to be deleted in case that node has 2 children
    iii successor(BSTNode* newNode) {
        if (newNode->right != NULL) return QueryMin(newNode->right);
        else {
            BSTNode* par = newNode->parent;
            BSTNode* cur = newNode;
            
            while ((par != NULL) && (cur == par->right)) {
                cur = par;
                par = cur->parent;
            }
            return par == NULL ? EMPTY : par->womaninfo;
        }
    }
    
    //returns the woman with the minimum dilation
    iii QueryMin(BSTNode* newNode) {
        if (newNode == NULL) return EMPTY;
        else if (newNode->left == NULL) return newNode->womaninfo;
        else return QueryMin(newNode->left);
    }
    
    //returns the info of the woman with the maximum dilation
    iii QueryMax(BSTNode* newNode) {
        if (newNode == NULL) return EMPTY;
        else if (newNode->right == NULL) return newNode->womaninfo;
        else return QueryMax(newNode->right);
    }
    
    //inserts a new node each time a woman checks into the hospital
    BSTNode* ArriveatHospital(BSTNode* newNode, iii info) {
        if (newNode == NULL) {
            newNode = new BSTNode;
            newNode->womaninfo = info;
            newNode->parent = newNode->left = newNode->right = NULL;
        }
        else if (newNode->womaninfo < info) {
            newNode->right = ArriveatHospital(newNode->right, info);
            newNode->right->parent = newNode;
        }
        else {
            newNode->left = ArriveatHospital(newNode->left, info);
            newNode->left->parent = newNode;
        }
        return newNode;
    }
public:
    BST() {root = NULL;}
    
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
    
    //removes the information of the woman who gave birth
    void GiveBirth(string womanName) {
        auto search = finding.find(womanName);
        auto pos = position.find(womanName);
        root = GiveBirth(root, make_tuple(search->second, pos->second, womanName));
        finding.erase(finding.find(womanName)); position.erase(position.find(womanName));
    }
    
    //returns the name of the woman with the maximum dilation
    iii Query() { return QueryMax(root); }
};

int main(void) {
    BST* Tree = new BST();
    
    long long commands; cin >> commands;
    int oper, dilation, increase; string name;
    for (int i = 0; i < commands; i++) {
        cin >> oper;
        switch (oper) {
            case 0:
                cin >> name >> dilation;
                Tree->ArriveatHospital(name, dilation);
                break;
            case 1:
                cin >> name >> increase;
                Tree->UpdateDilation(name, increase);
                break;
            case 2:
                cin >> name;
                Tree->GiveBirth(name);
                break;
            default:
                iii tmp = Tree->Query();
                cout << get<2>(tmp) << endl;
                break;
        }
    }
    return 0;
}
