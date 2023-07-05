//
// Created by Manajit Halder
// For Project BinarySearchTree on 13/10/22
// Using Swift 5.0 on MacOS 12.4
// 

#include <iostream>
#include <memory>
using namespace std;

struct Node {
    int data;
    Node *parent;
    Node *left;
    Node *right;
};

// Recursive implementation
class BinarySearchTree {
    Node *node;
    
public:
    BinarySearchTree(): node(nullptr) {}
    ~BinarySearchTree() {}
    
    void insert(Node* &root, int value);
    void iterativeInsert(Node* &root, int value);
    void printPreOrder(Node* root);
    Node* search(Node* root, int searchValue);

};

void BinarySearchTree::insert(Node* &node, int value) {
    if (node == nullptr) {
        node = new Node;
        node->data = value;
        node->parent = nullptr;
        node->left = nullptr;
        node->right = nullptr;
    } else if (value < node->data) {
        insert(node->left, value);
        node->left->parent = node;
    } else {
        insert(node->right, value);
        node->right->parent = node;
    }
    
//    return node;
}

void BinarySearchTree::iterativeInsert(Node* &node, int value) {
    if (node == nullptr) {
        node = new Node;
        node->data = value;
        node->left = nullptr;
        node->right = nullptr;
        node->parent = nullptr;
        
        return;
    }
    
    Node* curr = node;
    Node* prev = nullptr;
    while (curr != nullptr) {
        prev = curr;
        if (value < curr->data) {
            curr = curr->left;
        } else {
            curr = curr->right;
        }
    }
    
    if (value < prev->data) {
        prev->left = new Node;
        prev->data = value;
    } else {
        prev->right = new Node;
        prev->data = value;
    }
//    prev->left = nullptr;
//    prev->right = nullptr;
}

void BinarySearchTree::printPreOrder(Node* root) {
    if (root == nullptr) {
        return;
    } else {
        cout << root->data << endl;
        printPreOrder(root->left);
        printPreOrder(root->right);
    }
}

Node* BinarySearchTree::search(Node* root, int searchValue) {
    if (root == nullptr) {
        return nullptr;
    } else if (searchValue == root->data) {
        return root;
    } else if (searchValue < root->data) {
        return search(root->left, searchValue);
    } else {
        return search(root->right, searchValue);
    }
}

int main(int argc, const char * argv[]) {
    Node* root = nullptr;
    BinarySearchTree* bst = new BinarySearchTree;
    
//    bst->insert(root, 400);
//    bst->insert(root, 200);
//    root = bst->insert(root, 300);
//    root = bst->insert(root, 150);
//    root = bst->insert(root, 500);
//    root = bst->insert(root, 550);
//    root = bst->insert(root, 700);
    
    bst->iterativeInsert(root, 89);
    bst->iterativeInsert(root, 78);
    bst->iterativeInsert(root, 98);
    
    bst->printPreOrder(root);
    
    int searchdata = 700;
    Node* search = bst->search(root, searchdata);
    if (search == nullptr) {
        cout << searchdata << " is not found in the tree" << endl;
    } else {
        int parentData = 0;
        if (search->parent != nullptr) {
            parentData = search->parent->data;
        }
        cout << search->data << " found in the tree and its parent is " << parentData << endl;
    }
    
    return 0;
}
