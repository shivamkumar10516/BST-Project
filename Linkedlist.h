/**
 * @file LinkedList.h
 * @brief Header file for Singly Linked List implementation
 */

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <memory>

/**
 * @class Node
 * @brief Represents a node in the singly linked list
 */
template<typename T>
class Node {
public:
    T data;                    ///< Data stored in the node
    std::unique_ptr<Node<T>> next; ///< Unique pointer to the next node
    
    /**
     * @brief Constructor to initialize node with data
     * @param value The data to store in the node
     */
    explicit Node(T value) : data(value), next(nullptr) {}
};

/**
 * @class LinkedList
 * @brief Singly Linked List implementation
 */
template<typename T>
class LinkedList {
private:
    std::unique_ptr<Node<T>> head; ///< Pointer to the first node in the list
    int size;                     ///< Number of elements in the list

public:
    /**
     * @brief Default constructor
     * Time Complexity: O(1)
     * Space Complexity: O(1)
     */
    LinkedList();
    
    /**
     * @brief Insert an element at the beginning of the list
     * @param value The value to insert
     * Time Complexity: O(1)
     * Space Complexity: O(1)
     */
    void insertFront(T value);
    
    /**
     * @brief Insert an element at the end of the list
     * @param value The value to insert
     * Time Complexity: O(n)
     * Space Complexity: O(1)
     */
    void insertEnd(T value);
    
    /**
     * @brief Delete the first occurrence of a value
     * @param value The value to delete
     * @return true if deletion successful, false otherwise
     * Time Complexity: O(n)
     * Space Complexity: O(1)
     */
    bool deleteValue(T value);
    
    /**
     * @brief Search for a value in the list
     * @param value The value to search for
     * @return true if found, false otherwise
     * Time Complexity: O(n)
     * Space Complexity: O(1)
     */
    bool search(T value) const;
    
    /**
     * @brief Display all elements in the list
     * Time Complexity: O(n)
     * Space Complexity: O(1)
     */
    void display() const;
    
    /**
     * @brief Get the current size of the list
     * @return Number of elements
     * Time Complexity: O(1)
     * Space Complexity: O(1)
     */
    int getSize() const { return size; }
    
    /**
     * @brief Check if the list is empty
     * @return true if empty, false otherwise
     * Time Complexity: O(1)
     * Space Complexity: O(1)
     */
    bool isEmpty() const { return size == 0; }
};

#endif
