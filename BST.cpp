/**
 * @file BST.cpp
 * @brief Implementation of Binary Search Tree
 */

#include "BST.h"

template<typename T>
BST<T>::BST() : root(nullptr) {}

template<typename T>
std::unique_ptr<BSTNode<T>> BST<T>::insertHelper(std::unique_ptr<BSTNode<T>> node, T value) {
    if (!node) {
        return std::make_unique<BSTNode<T>>(value);
    }
    
    if (value < node->data) {
        node->left = insertHelper(std::move(node->left), value);
    } else if (value > node->data) {
        node->right = insertHelper(std::move(node->right), value);
    }
    // If value == node->data, do nothing (duplicates not allowed)
    
    return node;
}

template<typename T>
void BST<T>::insert(T value) {
    root = insertHelper(std::move(root), value);
}

template<typename T>
BSTNode<T>* BST<T>::findMin(BSTNode<T>* node) const {
    while (node && node->left) {
        node = node->left.get();
    }
    return node;
}

template<typename T>
std::unique_ptr<BSTNode<T>> BST<T>::deleteHelper(std::unique_ptr<BSTNode<T>> node, T value) {
    if (!node) return nullptr;
    
    if (value < node->data) {
        node->left = deleteHelper(std::move(node->left), value);
    } else if (value > node->data) {
        node->right = deleteHelper(std::move(node->right), value);
    } else {
        // Node to be deleted found
        
        // Case 1: No child or one child
        if (!node->left) {
            return std::move(node->right);
        } else if (!node->right) {
            return std::move(node->left);
        }
        
        // Case 2: Two children
        BSTNode<T>* minNode = findMin(node->right.get());
        node->data = minNode->data;
        node->right = deleteHelper(std::move(node->right), minNode->data);
    }
    
    return node;
}

template<typename T>
void BST<T>::deleteValue(T value) {
    root = deleteHelper(std::move(root), value);
}

template<typename T>
BSTNode<T>* BST<T>::searchHelper(BSTNode<T>* node, T value) const {
    if (!node || node->data == value) {
        return node;
    }
    
    if (value < node->data) {
        return searchHelper(node->left.get(), value);
    } else {
        return searchHelper(node->right.get(), value);
    }
}

template<typename T>
bool BST<T>::search(T value) const {
    return searchHelper(root.get(), value) != nullptr;
}

template<typename T>
void BST<T>::displayHelper(BSTNode<T>* node, int space) const {
    const int COUNT = 5; // Space between levels
    
    if (!node) return;
    
    space += COUNT;
    
    // Process right child first
    displayHelper(node->right.get(), space);
    
    // Print current node
    std::cout << std::endl;
    for (int i = COUNT; i < space; i++) {
        std::cout << " ";
    }
    std::cout << node->data << "\n";
    
    // Process left child
    displayHelper(node->left.get(), space);
}

template<typename T>
void BST<T>::display() const {
    if (!root) {
        std::cout << "BST is empty" << std::endl;
        return;
    }
    std::cout << "Binary Search Tree (rotated 90° clockwise):" << std::endl;
    displayHelper(root.get(), 0);
}

// Explicit template instantiation for common types
template class BST<int>;
template class BST<double>;
