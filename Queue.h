/**
 * @file Queue.h
 * @brief Header file for Queue implementation using Linked List
 */

#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <memory>

/**
 * @class QueueNode
 * @brief Represents a node in the queue
 */
template<typename T>
class QueueNode {
public:
    T data;                          ///< Data stored in the node
    std::unique_ptr<QueueNode<T>> next; ///< Pointer to the next node
    
    /**
     * @brief Constructor to initialize node with data
     * @param value The data to store in the node
     */
    explicit QueueNode(T value) : data(value), next(nullptr) {}
};

/**
 * @class Queue
 * @brief Queue implementation using Linked List (FIFO)
 */
template<typename T>
class Queue {
private:
    std::unique_ptr<QueueNode<T>> front; ///< Pointer to the front of the queue
    QueueNode<T>* rear;                 ///< Pointer to the rear of the queue
    int size;                          ///< Number of elements in the queue

public:
    /**
     * @brief Default constructor
     * Time Complexity: O(1)
     * Space Complexity: O(1)
     */
    Queue();
    
    /**
     * @brief Destructor to clean up resources
     */
    ~Queue();
    
    /**
     * @brief Add an element to the rear of the queue (enqueue)
     * @param value The value to add
     * Time Complexity: O(1)
     * Space Complexity: O(1)
     */
    void enqueue(T value);
    
    /**
     * @brief Remove an element from the front of the queue (dequeue)
     * @return The removed value
     * @throws std::runtime_error if queue is empty
     * Time Complexity: O(1)
     * Space Complexity: O(1)
     */
    T dequeue();
    
    /**
     * @brief Get the front element without removing it
     * @return The front element
     * @throws std::runtime_error if queue is empty
     * Time Complexity: O(1)
     * Space Complexity: O(1)
     */
    T getFront() const;
    
    /**
     * @brief Check if the queue is empty
     * @return true if empty, false otherwise
     * Time Complexity: O(1)
     * Space Complexity: O(1)
     */
    bool isEmpty() const { return size == 0; }
    
    /**
     * @brief Get the current size of the queue
     * @return Number of elements
     * Time Complexity: O(1)
     * Space Complexity: O(1)
     */
    int getSize() const { return size; }
    
    /**
     * @brief Display all elements in the queue
     * Time Complexity: O(n)
     * Space Complexity: O(1)
     */
    void display() const;
};

#endif
