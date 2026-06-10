/**
 * @file BST.h
 * @brief Header file for Binary Search Tree implementation
 */

#ifndef BST_H
#define BST_H

#include <iostream>
#include <memory>
#include <vector>

/**
 * @class BSTNode
 * @brief Represents a node in the Binary Search Tree
 */
template<typename T>
class BSTNode {
public:
    T data;                     ///< Data stored in the node
    std::unique_ptr<BSTNode<T>> left;  ///< Pointer to left child
    std::unique_ptr<BSTNode<T>> right; ///< Pointer to right child
    
    /**
     * @brief Constructor to initialize node with data
     * @param value The data to store in the node
     */
    explicit BSTNode(T value) : data(value), left(nullptr), right(nullptr) {}
};

/**
 * @class BST
 * @brief Binary Search Tree implementation
 */
template<typename T>
class BST {
private:
    std::unique_ptr<BSTNode<T>> root; ///< Pointer to the root node
    
    // Private helper methods
    std::unique_ptr<BSTNode<T>> insertHelper(std::unique_ptr<BSTNode<T>> node, T value);
    std::unique_ptr<BSTNode<T>> deleteHelper(std::unique_ptr<BSTNode<T>> node, T value);
    BSTNode<T>* searchHelper(BSTNode<T>* node, T value) const;
    void displayHelper(BSTNode<T>* node, int space = 0) const;
    BSTNode<T>* findMin(BSTNode<T>* node) const;

public:
    /**
     * @brief Default constructor
     * Time Complexity: O(1)
     * Space Complexity: O(1)
     */
    BST();
    
    /**
     * @brief Insert a value into the BST
     * @param value The value to insert
     * Time Complexity: O(h) where h is height of tree, O(log n) average, O(n) worst
     * Space Complexity: O(h) for recursion stack
     */
    void insert(T value);
    
    /**
     * @brief Delete a value from the BST
     * @param value The value to delete
     * Time Complexity: O(h) where h is height of tree, O(log n) average, O(n) worst
     * Space Complexity: O(h) for recursion stack
     */
    void deleteValue(T value);
    
    /**
     * @brief Search for a value in the BST
     * @param value The value to search for
     * @return true if found, false otherwise
     * Time Complexity: O(h) where h is height of tree, O(log n) average, O(n) worst
     * Space Complexity: O(h) for recursion stack
     */
    bool search(T value) const;
    
    /**
     * @brief Display the BST in a tree format
     * Time Complexity: O(n)
     * Space Complexity: O(n) for recursion stack
     */
    void display() const;
    
    /**
     * @brief Check if the BST is empty
     * @return true if empty, false otherwise
     * Time Complexity: O(1)
     * Space Complexity: O(1)
     */
    bool isEmpty() const { return !root; }
};

#endif
