#include <iostream>

// Define a Node structure for the linked list
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Function to add a new node at the end of the linked list
void append(Node*& head, int val) {
    Node* newNode = new Node(val);
    if (head == nullptr) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to print the linked list
void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        std::cout << temp->data << " -> ";
        temp = temp->next;
    }
    std::cout << "nullptr" << std::endl;
}

int main() {
    // Create a sample linked list with a cycle
    Node* head = nullptr;
    append(head, 1);
    append(head, 2);
    append(head, 3);
    append(head, 4);
    append(head, 5);

    // Create a cycle by connecting the last node to the second node
    head->next->next->next->next->next = head->next;

    bool hasCycle = detectAndRemoveCycle(head);

    if (hasCycle) {
        std::cout << "Cycle detected and removed." << std::endl;
    } else {
        std::cout << "No cycle detected." << std::endl;
    }

    // Print the modified linked list (cycle removed)
    std::cout << "Linked List after cycle removal: ";
    printList(head);

    return 0;
}
