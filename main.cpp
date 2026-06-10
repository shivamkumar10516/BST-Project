/**
 * @file main.cpp
 * @brief Menu-driven console application for Data Structures Demo
 */

#include "LinkedList.h"
#include "Stack.h"
#include "Queue.h"
#include "BST.h"
#include <iostream>
#include <string>
#include <limits>

/**
 * @brief Display the main menu and get user choice
 * @return User's menu choice
 */
int displayMainMenu() {
    std::cout << "\n=== Data Structures Implementation ===" << std::endl;
    std::cout << "1. Linked List" << std::endl;
    std::cout << "2. Stack" << std::endl;
    std::cout << "3. Queue" << std::endl;
    std::cout << "4. Binary Search Tree" << std::endl;
    std::cout << "5. Exit" << std::endl;
    std::cout << "Select data structure: ";
    
    int choice;
    std::cin >> choice;
    return choice;
}

/**
 * @brief Handle Linked List operations
 */
void handleLinkedList() {
    LinkedList<int> list;
    int choice, value;
    
    do {
        std::cout << "\n--- Linked List Operations ---" << std::endl;
        std::cout << "1. Insert at front" << std::endl;
        std::cout << "2. Insert at end" << std::endl;
        std::cout << "3. Delete value" << std::endl;
        std::cout << "4. Search value" << std::endl;
        std::cout << "5. Display list" << std::endl;
        std::cout << "6. Get size" << std::endl;
        std::cout << "7. Back to main menu" << std::endl;
        std::cout << "Choose operation: ";
        std::cin >> choice;
        
        switch (choice) {
            case 1:
                std::cout << "Enter value to insert at front: ";
                std::cin >> value;
                list.insertFront(value);
                std::cout << "Value inserted at front" << std::endl;
                break;
                
            case 2:
                std::cout << "Enter value to insert at end: ";
                std::cin >> value;
                list.insertEnd(value);
                std::cout << "Value inserted at end" << std::endl;
                break;
                
            case 3:
                std::cout << "Enter value to delete: ";
                std::cin >> value;
                if (list.deleteValue(value)) {
                    std::cout << "Value deleted successfully" << std::endl;
                } else {
                    std::cout << "Value not found" << std::endl;
                }
                break;
                
            case 4:
                std::cout << "Enter value to search: ";
                std::cin >> value;
                if (list.search(value)) {
                    std::cout << "Value found in the list" << std::endl;
                } else {
                    std::cout << "Value not found" << std::endl;
                }
                break;
                
            case 5:
                list.display();
                break;
                
            case 6:
                std::cout << "List size: " << list.getSize() << std::endl;
                break;
                
            case 7:
                std::cout << "Returning to main menu..." << std::endl;
                break;
                
            default:
                std::cout << "Invalid choice!" << std::endl;
        }
    } while (choice != 7);
}

/**
 * @brief Handle Stack operations
 */
void handleStack() {
    Stack<int> stack;
    int choice, value;
    
    do {
        std::cout << "\n--- Stack Operations ---" << std::endl;
        std::cout << "1. Push" << std::endl;
        std::cout << "2. Pop" << std::endl;
        std::cout << "3. Peek" << std::endl;
        std::cout << "4. Display stack" << std::endl;
        std::cout << "5. Get size" << std::endl;
        std::cout << "6. Back to main menu" << std::endl;
        std::cout << "Choose operation: ";
        std::cin >> choice;
        
        switch (choice) {
            case 1:
                std::cout << "Enter value to push: ";
                std::cin >> value;
                stack.push(value);
                std::cout << "Value pushed onto stack" << std::endl;
                break;
                
            case 2:
                try {
                    value = stack.pop();
                    std::cout << "Popped value: " << value << std::endl;
                } catch (const std::runtime_error& e) {
                    std::cout << "Error: " << e.what() << std::endl;
                }
                break;
                
            case 3:
                try {
                    value = stack.peek();
                    std::cout << "Top value: " << value << std::endl;
                } catch (const std::runtime_error& e) {
                    std::cout << "Error: " << e.what() << std::endl;
                }
                break;
                
            case 4:
                stack.display();
                break;
                
            case 5:
                std::cout << "Stack size: " << stack.getSize() << std::endl;
                break;
                
            case 6:
                std::cout << "Returning to main menu..." << std::endl;
                break;
                
            default:
                std::cout << "Invalid choice!" << std::endl;
        }
    } while (choice != 6);
}

/**
 * @brief Handle Queue operations
 */
void handleQueue() {
    Queue<int> queue;
    int choice, value;
    
    do {
        std::cout << "\n--- Queue Operations ---" << std::endl;
        std::cout << "1. Enqueue" << std::endl;
        std::cout << "2. Dequeue" << std::endl;
        std::cout << "3. Get front" << std::endl;
        std::cout << "4. Display queue" << std::endl;
        std::cout << "5. Get size" << std::endl;
        std::cout << "6. Back to main menu" << std::endl;
        std::cout << "Choose operation: ";
        std::cin >> choice;
        
        switch (choice) {
            case 1:
                std::cout << "Enter value to enqueue: ";
                std::cin >> value;
                queue.enqueue(value);
                std::cout << "Value added to queue" << std::endl;
                break;
                
            case 2:
                try {
                    value = queue.dequeue();
                    std::cout << "Dequeued value: " << value << std::endl;
                } catch (const std::runtime_error& e) {
                    std::cout << "Error: " << e.what() << std::endl;
                }
                break;
                
            case 3:
                try {
                    value = queue.getFront();
                    std::cout << "Front value: " << value << std::endl;
                } catch (const std::runtime_error& e) {
                    std::cout << "Error: " << e.what() << std::endl;
                }
                break;
                
            case 4:
                queue.display();
                break;
                
            case 5:
                std::cout << "Queue size: " << queue.getSize() << std::endl;
                break;
                
            case 6:
                std::cout << "Returning to main menu..." << std::endl;
                break;
                
            default:
                std::cout << "Invalid choice!" << std::endl;
        }
    } while (choice != 6);
}

/**
 * @brief Handle Binary Search Tree operations
 */
void handleBST() {
    BST<int> bst;
    int choice, value;
    
    do {
        std::cout << "\n--- Binary Search Tree Operations ---" << std::endl;
        std::cout << "1. Insert" << std::endl;
        std::cout << "2. Delete" << std::endl;
        std::cout << "3. Search" << std::endl;
        std::cout << "4. Display tree" << std::endl;
        std::cout << "5. Back to main menu" << std::endl;
        std::cout << "Choose operation: ";
        std::cin >> choice;
        
        switch (choice) {
            case 1:
                std::cout << "Enter value to insert: ";
                std::cin >> value;
                bst.insert(value);
                std::cout << "Value inserted into BST" << std::endl;
                break;
                
            case 2:
                std::cout << "Enter value to delete: ";
                std::cin >> value;
                bst.deleteValue(value);
                std::cout << "Value deleted from BST" << std::endl;
                break;
                
            case 3:
                std::cout << "Enter value to search: ";
                std::cin >> value;
                if (bst.search(value)) {
                    std::cout << "Value found in BST" << std::endl;
                } else {
                    std::cout << "Value not found" << std::endl;
                }
                break;
                
            case 4:
                bst.display();
                break;
                
            case 5:
                std::cout << "Returning to main menu..." << std::endl;
                break;
                
            default:
                std::cout << "Invalid choice!" << std::endl;
        }
    } while (choice != 5);
}

/**
 * @brief Main function - entry point of the application
 */
int main() {
    std::cout << "Welcome to Data Structures Implementation Demo!" << std::endl;
    std::cout << "This application demonstrates four fundamental data structures." << std::endl;
    
    int choice;
    
    do {
        choice = displayMainMenu();
        
        switch (choice) {
            case 1:
                handleLinkedList();
                break;
                
            case 2:
                handleStack();
                break;
                
            case 3:
                handleQueue();
                break;
                
            case 4:
                handleBST();
                break;
                
            case 5:
                std::cout << "Thank you for using Data Structures Implementation!" << std::endl;
                break;
                
            default:
                std::cout << "Invalid choice! Please try again." << std::endl;
                // Clear input buffer
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    } while (choice != 5);
    
    return 0;
}
