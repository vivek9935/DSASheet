#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *prev;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};
void insertAt(Node *&head, int d)
{
    Node *n1 = new Node(d);
    n1->next = head;
    head->prev = n1;
    head = n1;
}
void insertAtTail(Node *&tail, int d)
{
    Node *temp = new Node(d);
    tail->next = temp;
    temp->prev = tail;
    tail = temp;
}
void insertAtMiddle(Node *&head, Node *&tail, int pos, int d)
{
    if (pos == 1)
    {
        insertAt(head, d);
        return;
    }
    int cnt = 1;
    Node *temp = head;
    while (cnt < pos - 1 && temp->next != NULL)
    {
        temp = temp->next;
        cnt++;
    }
    if (temp->next == NULL)
    {
        insertAtTail(tail, d);
        return;
    }
    Node *newNode = new Node(d);
    newNode->prev = temp;
    newNode->next = temp->next;
    if (temp->next != NULL)
    {
        temp->next->prev = newNode;
    }
    temp->next = newNode;
}
void del(Node *&head, int pos)
{
    Node *temp = head;
    if (pos == 1)
    {
        if (temp->next != NULL)
        {
            temp->next->prev = NULL;
            head = temp->next;
        }
        delete temp;
        return;
    }
    int cnt = 1;
    while (cnt < pos - 1 && temp != NULL)
    {
        cnt++;
        temp = temp->next;
    }
    
    if (temp == NULL || temp->next == NULL)
    {
        // Invalid position or end of the list reached
        return;
    }
    
    Node *nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;
    
    if (nodeToDelete->next != NULL)
    {
        nodeToDelete->next->prev = temp;
    }

    delete nodeToDelete;
}
void reverse1(Node *&head)
{
    Node *current = head;
    Node *prev = NULL;
    Node *nextNode = NULL;

    while (current != NULL)
    {
        nextNode = current->next;
        current->next = prev;
        current->prev = nextNode;
        prev = current;
        current = nextNode;
    }

    head = prev; 
}
Node* reverse(Node*& head) {
    // Base case: If the list is empty or has only one node, it's already reversed.
    if (head == NULL || head->next == NULL) {
        head->prev=NULL;
        return head;
    }

    // Recursively reverse the rest of the list
    Node* restReversed = reverse(head->next);

    // Update the next and prev pointers
    head->next->next = head;
    head->prev = head->next;
    head->next = NULL;

    // Return the new head of the reversed list
    return restReversed;
}
void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }cout<<endl;
}
int main()
{
    Node *first = new Node(10);
    Node *head = first;
    Node *tail = first;
    insertAt(head, 20);
    insertAt(head, 5);
    insertAt(head, 16);
    insertAt(head, 85);
    insertAt(head, 45);
    // insertAtTail(tail, 45);
    cout << head->data << endl;
    insertAtMiddle(head, tail, 2, 2);

    print(head);
   del(head,7);
    print(head);
    Node *temp;
    temp=reverse(head);
    print(temp);
}