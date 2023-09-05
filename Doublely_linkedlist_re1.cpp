#include<iostream>
using namespace std;
class Node
{
    public:
    int data;
    Node *prev;
    Node *next;
    Node(int data)
    {
        this->data=data;
        this->next=NULL;
        this->prev=NULL;
    }
};
void insertAt(Node *&head,int d)
{
    Node *n1=new Node(d);
    n1->next=head;
    head->prev=n1;
    head=n1;
}
void print(Node *head)
{
    Node *temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }cout<<endl;
}
int main()
{
    Node *first=new Node(10);
    Node *head=first;
    insertAt(head,20);
    insertAt(head,5);
    insertAt(head,16);
    insertAt(head,85);
    insertAt(head,45);
    print(head);


}