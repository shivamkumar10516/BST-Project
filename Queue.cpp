/**
 * @file Queue.cpp
 * @brief Implementation of Queue using Linked List
 */

#include "Queue.h"
#include <stdexcept>

template<typename T>
Queue<T>::Queue() : front(nullptr), rear(nullptr), size(0) {}

template<typename T>
Queue<T>::~Queue() {
    // Smart pointers automatically handle cleanup
    while (front) {
        front = std::move(front->next);
    }
    rear = nullptr;
}

template<typename T>
void Queue<T>::enqueue(T value) {
    auto newNode = std::make_unique<QueueNode<T>>(value);
    
    if (isEmpty()) {
        front = std::move(newNode);
        rear = front.get();
    } else {
        rear->next = std::move(newNode);
        rear = rear->next.get();
    }
    size++;
}

template<typename T>
T Queue<T>::dequeue() {
    if (isEmpty()) {
        throw std::runtime_error("Queue is empty");
    }
    
    T value = front->data;
    front = std::move(front->next);
    
    if (!front) {
        rear = nullptr;
    }
    size--;
    return value;
}

template<typename T>
T Queue<T>::getFront() const {
    if (isEmpty()) {
        throw std::runtime_error("Queue is empty");
    }
    return front->data;
}

template<typename T>
void Queue<T>::display() const {
    if (isEmpty()) {
        std::cout << "Queue is empty" << std::endl;
        return;
    }
    
    QueueNode<T>* current = front.get();
    std::cout << "Queue (front to rear): ";
    while (current) {
        std::cout << current->data;
        if (current->next) std::cout << " -> ";
        current = current->next.get();
    }
    std::cout << std::endl;
}

// Explicit template instantiation for common types
template class Queue<int>;
template class Queue<double>;
template class Queue<std::string>;
