#include <iostream>

// Define a TreeNode class
template <typename T>
class TreeNode {
public:
    T data;
    TreeNode<T>* left;
    TreeNode<T>* right;
    TreeNode(T val) : data(val), left(nullptr), right(nullptr) {}
};

// Function to insert a new node into the BST
template <typename T>
TreeNode<T>* insert(TreeNode<T>* root, T val) {
    if (root == nullptr) {
        return new TreeNode<T>(val);
    }
    if (val < root->data) {
        root->left = insert(root->left, val);
    } else {
        root->right = insert(root->right, val);
    }
    return root;
}
int solve(TreeNode<int> *root,int &i,int k)
{
    if(root==NULL)
    {
        return -1;
    }
    int right=solve(root->right,i,k);
    if(right!=-1)
      return right;
    i++;
    if(i==k)
    return root->data;
    return solve(root->left,i,k);
}
int kthSmallest(TreeNode<int> *root, int k)
{
    int i = 0;
    int ans = solve(root,i,k);
    return ans;
}
// Helper function to print the inorder traversal of the BST
template <typename T>
void inorder(TreeNode<T>* root) {
    if (root == nullptr) {
        return;
    }
    inorder(root->left);
    std::cout << root->data << " ";
    inorder(root->right);
}

int main() {
    // Create a simple binary search tree
    TreeNode<int>* root = nullptr;
    root = insert(root, 5);
    root = insert(root, 3);
    root = insert(root, 7);
    root = insert(root, 2);
    root = insert(root, 4);
    root = insert(root, 6);
    root = insert(root, 8);

    // Print the inorder traversal of the BST (should be sorted)
    std::cout << "Inorder traversal: ";
    inorder(root);
    std::cout << std::endl;

    // Find the kth smallest element (k=3 in this example)
    int k = 3;
    int result = kthSmallest(root, k);
    std::cout << "The " << k << "th smallest element is: " << result << std::endl;

    // Clean up memory (if needed) by deleting the tree nodes
    // DeleteTree(root); // Implement this function if necessary

    return 0;
}
