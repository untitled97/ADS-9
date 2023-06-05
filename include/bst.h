// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_
#include <iostream>
#include <fstream>

template<typename T>
class BST {
 private:
    struct Node {
        T value;
        uint64_t count;
        Node* left, *right;
    };
    Node* root = nullptr;
    Node* addNode(Node*, const T&);
    int searchTree(Node*, const T&);
    int getDepthTree(Node*);
 public:
    void add(const T&);
    int search(const T&);
    int depth();
};

template<typename T>
typename BST<T>::Node* BST<T>::addNode(Node* root, const T& value) {
    if (root == nullptr) {
        root = new Node;
        root->value = value;
        root->count = 1;
        root->left = root->right = nullptr;
    } else if (root->value > value) {
        root->left = addNode(root->left, value);
    } else if (root->value < value) {
        root->right = addNode(root->right, value);
    } else {
        root->count+=1;
    }
    return root;
}

template<typename T>
int BST<T>::searchTree(Node* root, const T& value) {
    if (root == nullptr)
        return 0;
    else if (root->value > value)
        return searchTree(root->left, value);
    else if (root->value < value)
        return searchTree(root->right, value);
    else
        return root->count;
    return 0;
}

template<typename T>
int BST<T>::getDepthTree(Node* root) {
    if (root == nullptr)
        return 0;
    int leftDepth = getDepthTree(root->left);
    int rightDepth = getDepthTree(root->right);
    if (leftDepth > rightDepth) {
        return leftDepth + 1;
    } else {
        return rightDepth + 1;
    }
}

template<typename T>
void BST<T>::add(const T& value) {
    root = addNode(root, value);
}

template<typename T>
int BST<T>::search(const T& value) {
    return searchTree(root, value);
}

template<typename T>
int BST<T>::depth() {
    return getDepthTree(root) - 1;
}

#endif  // INCLUDE_BST_H_
