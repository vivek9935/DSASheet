#include<iostream>
using namespace std;
class Node
{
    public:
    int data;
    Node *left;
    Node *right;
    Node(int d)
    {
        this->data =d;
        this ->left=NULL;
        this->right =NULL;
    }
};
Node *insertInBST(Node *root,int d)
{
    if(root==NULL)
    {
        root = new Node(d);
        return root;

    }
    if(d>root->data)
     root->right= insertInBST(root->right,d);
    else
     root->left = insertInBST(root->left,d);
    return root;
}
void inorder(Node *root)
{
    if(root == NULL)
      return ;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
void preorder(Node *root)
{
    if(root == NULL)
      return ;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
void postorder(Node *root)
{
    if(root == NULL)
      return ;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}
void insertdata(Node *root)
{
  int data;
  cin>>data;
  while(data!=-1)
  {
    root = insertInBST(root,data);
    cin>>data;
  }
inorder(root);
cout<<endl;
preorder(root);
cout<<endl;
postorder(root);
}

    
int main()
{
    Node *root =NULL;
    cout<<"Enter the data in BST "<<endl;
    insertdata(root);
    return 0;
}