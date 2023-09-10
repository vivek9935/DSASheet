#include <iostream>
using namespace std;
// Define the Node structure
struct Node {
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};
void printList(Node *head) {
    Node *curr = head;
    while (curr != nullptr) {
        cout << curr->data;
        if (curr->next != nullptr) {
            cout << " -> ";
        }
        curr = curr->next;
    }
    cout << std::endl;
}
// Function to reverse a linked list in-place
Node *reverse(Node *&head) {
    Node *curr = head;
    Node *prev = nullptr;
    while (curr != nullptr) {
        Node *next_next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next_next;
    }
    return prev;
}

// Function to insert a new node at the tail of a linked list
void insertAtTail(Node *&head, Node *&tail, int value) {
    Node *temp = new Node(value);
    if (head == nullptr) {
        head = temp;
        tail = temp;
        return;
    } else {
        tail->next = temp;
        tail = temp;
    }
}

// Function tNodeo add two numbers represented as linked lists
// Function to add two numbers represented as linked lists
Node *add(Node *first, Node *second) {
    int carry = 0;
    Node *ansHead = nullptr;
    Node *ansTail = nullptr;
    while (first != nullptr || second != nullptr) {
        int sum = carry;
        if (first != nullptr) {
            sum += first->data;
            first = first->next;
        }
        if (second != nullptr) {
            sum += second->data;
            second = second->next;
        }
        
        int digit = sum % 10;
        carry = sum / 10;
        
        insertAtTail(ansHead, ansTail, digit);
    }
    
    if (carry != 0) {
        insertAtTail(ansHead, ansTail, carry);
    }
    
    return ansHead;
}

// Function to add two numbers represented as linked lists
Node *addTwoNumbers(Node *num1, Node *num2) {
    Node *ans = add(num1, num2);
    return ans;
}
// Function to add two numbers represented as linked lists
Node *addTwoNumbers(Node *num1, Node *num2) {
    // Reverse the input linked lists
    num1 = reverse(num1);
    num2 = reverse(num2);
    // Add the reversed number
    cout<<"after the reverse the num1 is"<<endl;
    printList(num1);
     cout<<"after the reverse the num1 is"<<endl;
    printList(num2);
    Node *ans = add(num1, num2);
    // Reverse the result
    ans = reverse(ans);
    return ans;
}

// Function to print a linked list


int main() {
    // Create two linked lists representing two numbers
    Node *num1 = new Node(2);
    num1->next = new Node(4);
    num1->next->next = new Node(3);

    Node *num2 = new Node(5);
    num2->next = new Node(6);


    cout << "Number 1: ";
    printList(num1);

    cout << "Number 2: ";
    printList(num2);

    // Add the two numbers
    Node *result = addTwoNumbers(num1, num2);

    // Print the result
    cout << "Sum: ";
    printList(result);

    return 0;
}