/**
 * @file Stack.h
 * @brief Header file for Stack implementation using Linked List
 */

#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <memory>

/**
 * @class StackNode
 * @brief Represents a node in the stack
 */
template<typename T>
class StackNode {
public:
    T data;                          ///< Data stored in the node
    std::unique_ptr<StackNode<T>> next; ///< Pointer to the next node
    
    /**
     * @brief Constructor to initialize node with data
     * @param value The data to store in the node
     */
    explicit StackNode(T value) : data(value), next(nullptr) {}
};

/**
 * @class Stack
 * @brief Stack implementation using Linked List (LIFO)
 */
template<typename T>
class Stack {
private:
    std::unique_ptr<StackNode<T>> top; ///< Pointer to the top of the stack
    int size;                         ///< Number of elements in the stack

public:
    /**
     * @brief Default constructor
     * Time Complexity: O(1)
     * Space Complexity: O(1)
     */
    Stack();
    
    /**
     * @brief Push an element onto the stack
     * @param value The value to push
     * Time Complexity: O(1)
     * Space Complexity: O(1)
     */
    void push(T value);
    
    /**
     * @brief Pop the top element from the stack
     * @return The popped value
     * @throws std::runtime_error if stack is empty
     * Time Complexity: O(1)
     * Space Complexity: O(1)
     */
    T pop();
    
    /**
     * @brief Get the top element without removing it
     * @return The top element
     * @throws std::runtime_error if stack is empty
     * Time Complexity: O(1)
     * Space Complexity: O(1)
     */
    T peek() const;
    
    /**
     * @brief Check if the stack is empty
     * @return true if empty, false otherwise
     * Time Complexity: O(1)
     * Space Complexity: O(1)
     */
    bool isEmpty() const { return size == 0; }
    
    /**
     * @brief Get the current size of the stack
     * @return Number of elements
     * Time Complexity: O(1)
     * Space Complexity: O(1)
     */
    int getSize() const { return size; }
    
    /**
     * @brief Display all elements in the stack
     * Time Complexity: O(n)
     * Space Complexity: O(1)
     */
    void display() const;
};

#endif
