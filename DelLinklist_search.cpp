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
void inseratHead(Node *&head,int d)
{
    Node *newNode=new Node(d);
    newNode->next=head;
    head=newNode;
}
void delBySearch(Node *&head,int d)
{
    Node *temp=head;
    if(temp!=NULL&&temp->data==d)
    {
        head=temp->next;
        delete temp;
        return ;
    }
    while(temp!=NULL&&temp->next!=NULL)
    {
        if(temp->next->data==d)
        {
            Node *pos=temp->next;
            temp->next=pos->next;
            delete pos;
            return ;
        }
        temp=temp->next;
    }
}
void print_linkList(Node *head)
{
    Node *temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<"  ";
        temp=temp->next;
    }
    cout<<endl;
    return ;
}
int main()
{
Node *n1 = new Node(10);
Node *head=n1;
head->next=new Node(20); 
head ->next->next=new Node(50);
head->next->next->next=new Node(66);
inseratHead(head,1);
print_linkList(head);
delBySearch(head,20);
print_linkList(head);
return 0;
}