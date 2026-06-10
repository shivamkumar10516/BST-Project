/**
 * @file LinkedList.cpp
 * @brief Implementation of Singly Linked List
 */

#include "LinkedList.h"

template<typename T>
LinkedList<T>::LinkedList() : head(nullptr), size(0) {}

template<typename T>
void LinkedList<T>::insertFront(T value) {
    auto newNode = std::make_unique<Node<T>>(value);
    newNode->next = std::move(head);
    head = std::move(newNode);
    size++;
}

template<typename T>
void LinkedList<T>::insertEnd(T value) {
    auto newNode = std::make_unique<Node<T>>(value);
    
    if (!head) {
        head = std::move(newNode);
    } else {
        Node<T>* current = head.get();
        while (current->next) {
            current = current->next.get();
        }
        current->next = std::move(newNode);
    }
    size++;
}

template<typename T>
bool LinkedList<T>::deleteValue(T value) {
    if (!head) return false;
    
    // Check if head needs to be deleted
    if (head->data == value) {
        head = std::move(head->next);
        size--;
        return true;
    }
    
    Node<T>* current = head.get();
    while (current->next && current->next->data != value) {
        current = current->next.get();
    }
    
    if (current->next) {
        current->next = std::move(current->next->next);
        size--;
        return true;
    }
    
    return false;
}

template<typename T>
bool LinkedList<T>::search(T value) const {
    Node<T>* current = head.get();
    while (current) {
        if (current->data == value) {
            return true;
        }
        current = current->next.get();
    }
    return false;
}

template<typename T>
void LinkedList<T>::display() const {
    if (!head) {
        std::cout << "List is empty" << std::endl;
        return;
    }
    
    Node<T>* current = head.get();
    std::cout << "Linked List: ";
    while (current) {
        std::cout << current->data;
        if (current->next) std::cout << " -> ";
        current = current->next.get();
    }
    std::cout << std::endl;
}

// Explicit template instantiation for common types
template class LinkedList<int>;
template class LinkedList<double>;
template class LinkedList<std::string>;
