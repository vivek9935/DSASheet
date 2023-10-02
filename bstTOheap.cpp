#include <iostream>
#include <vector>
using namespace std;
// Define the BinaryTreeNode structure here
struct BinaryTreeNode {
    int data;
    BinaryTreeNode* left;
    BinaryTreeNode* right;
    BinaryTreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

BinaryTreeNode* heapify(BinaryTreeNode *root, vector<int>& ans, int n)
{
    if (ans.empty())
        return root;

    root->data = ans[n-1];
    root->left = heapify(root->left, ans, n-1);
    root->right = heapify(root->right, ans, n-1);

    return root;
}

void inorder(vector<int> &ans, BinaryTreeNode* root)
{
    if (root == NULL)
        return;

    inorder(ans, root->left);
    ans.push_back(root->data); // Fixed typo here
    inorder(ans, root->right);
}

BinaryTreeNode* convertBST(BinaryTreeNode* root)
{
    vector<int> ans;
    inorder(ans, root);
    int n = ans.size();
    return heapify(root, ans, n); 
}
int main() {
    // Create a sample binary search tree
    BinaryTreeNode* root = new BinaryTreeNode(4);
    root->left = new BinaryTreeNode(2);
    root->right = new BinaryTreeNode(6);
    root->left->left = new BinaryTreeNode(1);
    root->left->right = new BinaryTreeNode(3);
    root->right->left = new BinaryTreeNode(5);
    root->right->right = new BinaryTreeNode(7);

    // Convert the BST to a heap
    root = convertBST(root);

    // Print the converted heap
    std::cout << "Inorder Traversal of Converted Heap:" << std::endl;
    std::vector<int> ans;
    inorder(ans, root);
    for (int val : ans) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    // Remember to free memory allocated for the nodes in a real application

    return 0;
}