#include<iostream>
using namespace std;
class Node
{
public:
int data;
Node *next;
Node(int d)
{
    this->data=d;
    this->next=NULL;
}
};
void insertAtTail(Node *&tail,Node*&curr)
{
    tail->next=curr;
    tail=curr;
}

Node* sortList(Node *head)
{    
    Node *zeroHead=new Node(-1);
    Node *zeroTail=zeroHead;
    Node *oneHead=new Node(-1);
    Node *oneTail=oneHead;
    Node *twoHead=new Node(-1);
    Node *twoTail=twoHead;
    Node *curr=head;
    while(curr!=NULL)
    {
        int value=curr->data;
        if(value==0)
        {
            insertAtTail(zeroTail,curr);
        } else if (value == 1) {
          insertAtTail(oneTail, curr);
        } 
        else if(value==2)
        {
            insertAtTail(twoTail, curr);
        }
        curr=curr->next;
    }
    //merge the 3 linked list together 
    if(oneHead->next!=NULL)//there are element in 1 list
    {
        zeroTail->next=oneHead->next;
         
    }
    else{
        zeroTail->next=twoHead->next;
    }
   oneTail->next=twoHead->next;
    twoTail->next=NULL;
    //putting the head in first position
    head=zeroHead->next;
    //delete the dummy linked list
    delete zeroHead;
    delete oneHead;
    delete twoHead;
    return head;
}
int main()
{
    
}