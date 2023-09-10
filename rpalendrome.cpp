#include<iostream>
#include<vector>
using namespace std;
struct Node {
    int data;
    Node* next;
};

    Node *middle(Node* head) {
    if (head == nullptr || head->next == nullptr) {
        return head; // Handle empty list or list with one node.
    }

    Node* slow = head;
    Node* fast = head->next;

    while (fast != nullptr) {
        fast = fast->next;
        if (fast != nullptr) {
            fast = fast->next;
        }
        slow = slow->next;
    }

    return slow;
}

Node* reverse(Node* head) {
    Node* prev = nullptr;
    Node* current = head;

    while (current != nullptr) {
        Node* next_node = current->next;
        current->next = prev;
        prev = current;
        current = next_node;
    }

    return prev;
}

bool isPalindrome(Node* head) {
    if (head == nullptr || head->next == nullptr) {
        return true; // An empty list or a list with one node is always a palindrome.
    }
     
    Node* mid = middle(head);
    Node* temp = mid->next;
    mid->next = reverse(temp);
    
    Node* temp1 = head;
    Node* temp2 = mid->next;
    
    while (temp2 != nullptr) {
        cout<<"temp 1 data is  = "<<temp1->data<<"   temp 2 data = "<<temp2->data<<endl;
        if (temp1->data != temp2->data) {
            return false;
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
    }

    //mid->next = reverse(mid->next); // Restore the original linked list.
    
    return true;
}
int main() {
    // Example usage:
    Node* head = new Node{1, new Node{2, new Node{1, new Node{1, nullptr}}}};
    bool result = isPalindrome(head);
    std::cout << "Is Palindrome: " << result << std::endl;

    return 0;
}