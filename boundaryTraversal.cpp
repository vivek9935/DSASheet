#include <bits/stdc++.h>
// Define the structure of a binary tree node
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};
void traverseLeft(Node *root, vector<int> &ans)
{
    if (root == NULL || (root->left == NULL && root->right == NULL))
        return;
    ans.push_back(root->data);
    if (root->left)
        traverseLeft(root->left, ans);
    else
        traverseLeft(root->right, ans);
}

void traverseLeaf(Node *root, vector<int> &ans) // Fixed the function name
{
    if (root == NULL)
        return;
    if (root->left == NULL && root->right == NULL)
    {
        ans.push_back(root->data);
        return;
    }
    traverseLeaf(root->left, ans);  // Fixed the function name
    traverseLeaf(root->right, ans); // Fixed the function name
}

void traverseRight(Node *root, vector<int> &ans)
{
    if (root == NULL || (root->left == NULL && root->right == NULL))
        return;
    if (root->right) // Fixed the condition
        traverseRight(root->right, ans);
    else
        traverseRight(root->left, ans); // Fixed the traversal direction
    ans.push_back(root->data);
}

vector<int> boundary(Node *root)
{
    vector<int> ans;
    if (root == NULL)
        return ans;
    ans.push_back(root->data);
    traverseLeft(root->left, ans);
    traverseLeaf(root->left, ans);  // Fixed the function name
    traverseLeaf(root->right, ans); // Fixed the function name
    traverseRight(root->right, ans);
    return ans;
}

Node *createSampleTree()
{
    // Create a sample binary tree
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->left->left = new Node(6);
    root->left->left->right = new Node(7);

    return root;
}

int main()
{
    // Create a sample binary tree
    Node *root = createSampleTree();

    // Perform zigzag traversal
    vector<int> result = boundary(root);

    // Print the result
    cout << "boundary: ";
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i];
        if (i < result.size() - 1)
        {
            cout << " -> ";
        }
    }

    // Clean up the allocated memory (if needed)
    // ...

    return 0;
}