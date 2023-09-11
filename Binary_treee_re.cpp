#include<iostream>
#include<queue>
#include<stack>
using namespace std;
class node
{
public:
int data;
node *left;
node *right;
node(int d)
{
    this->data = d;
    this->left=NULL;
    this->right=NULL;
} 
};
node *buildTree(node *&root)
{
    cout<<"Enter the data for  node  "<<endl;
    int data;
    cin>>data;
    root = new node(data);
    if(data == -1)
    {
        return NULL;
    }
    cout<<"Enter to the left  "<<data<<endl;
    root->left = buildTree(root->left);
    cout<<"Enter data to the right "<<data<<endl;
    root->right=buildTree(root->right);
    return root;
}
void levelOrderTraversal(node* root) {
    if (root == NULL) {
        return; // Handle the case of an empty tree.
    }

    queue<node*> q;
    q.push(root);
    while (!q.empty()) {
        node* temp = q.front();
        cout << temp->data << "  ";
        q.pop();
        if (temp->left)
            q.push(temp->left);
        if (temp->right)
            q.push(temp->right);
    }
}
void reverseOrderTraverse(node *root)
{
    cout<<endl;
queue<node *> q;
stack<node *> s;
q.push(root);
while(!q.empty())
{
 node *temp=q.front();
 q.pop();
 s.push(temp); 
 if(temp->left)
   q.push(temp->left);
 if(temp->right)
    q.push(temp->right);  
}
while(!s.empty())
{
    node *temp=s.top();
    cout<<temp->data<<"   ";
    s.pop();
    
}  
}
void inorder(node *root)
{
    if(root == NULL)
      return ;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
void preorder(node *root)
{
    if(root == NULL)
      return ;
    
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
void postorder(node *root)
{
    if(root == NULL)
      return ;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
    
}
int height(node *root)
{
    if(root==NULL)
     return 0;
    int left=height(root->left);
    int right=height(root->right);
    int ans=max(left,right)+1;
    return ans;
}
int main()
{
    //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    node *root=NULL;
    buildTree(root);
    levelOrderTraversal(root);
    reverseOrderTraverse(root);
    cout<<endl;
    inorder(root);
    cout<<endl;
    preorder(root);
    cout<<endl;
    postorder(root);
   cout<<endl;
   cout<<height(root)<<endl;
}