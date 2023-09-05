#include<iostream>
using namespace std;
class Node
{
    public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data=data;
        this->next=NULL;
    }
};
void insertAtTail(Node *&tail,int d)
{
  Node *n1=new Node(d);
  tail->next=n1;
  tail=n1;
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
void DelLink(Node *&head,Node *&tail,int pos)
{
    int cnt = 1;
    Node *temp = head;
    if(pos==1)
    {
     head = head->next;
     delete temp;
    }
    while (cnt < pos - 1 && temp != nullptr)
    {
        temp = temp->next;
        cnt++;
    }
     
    Node *temp1;
    temp1=temp->next;
    temp->next=temp->next->next;
    temp1->next=NULL;
    delete temp1;
     if (temp->next == nullptr)
    {
        cout<<temp->data<<endl;
        tail = temp;
    }
}
int main()
{
Node *newNode=new Node(15);
Node *head=newNode;
Node *tail=newNode;
insertAtTail(tail,110);
insertAtTail(tail,30);
insertAtTail(tail,60);
print(head);
DelLink(head,tail,4);
print(head);
cout<<tail->data<<endl;
}