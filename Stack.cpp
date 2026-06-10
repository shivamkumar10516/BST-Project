/**
 * @file Stack.cpp
 * @brief Implementation of Stack using Linked List
 */

#include "Stack.h"
#include <stdexcept>

template<typename T>
Stack<T>::Stack() : top(nullptr), size(0) {}

template<typename T>
void Stack<T>::push(T value) {
    auto newNode = std::make_unique<StackNode<T>>(value);
    newNode->next = std::move(top);
    top = std::move(newNode);
    size++;
}

template<typename T>
T Stack<T>::pop() {
    if (isEmpty()) {
        throw std::runtime_error("Stack is empty");
    }
    
    T value = top->data;
    top = std::move(top->next);
    size--;
    return value;
}

template<typename T>
T Stack<T>::peek() const {
    if (isEmpty()) {
        throw std::runtime_error("Stack is empty");
    }
    return top->data;
}

template<typename T>
void Stack<T>::display() const {
    if (isEmpty()) {
        std::cout << "Stack is empty" << std::endl;
        return;
    }
    
    StackNode<T>* current = top.get();
    std::cout << "Stack (top to bottom): ";
    while (current) {
        std::cout << current->data;
        if (current->next) std::cout << " | ";
        current = current->next.get();
    }
    std::cout << std::endl;
}

// Explicit template instantiation for common types
template class Stack<int>;
template class Stack<double>;
template class Stack<std::string>;
