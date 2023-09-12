#include <bits/stdc++.h> 
// Define the structure of a binary tree node
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};


Node* createSampleTree() {
    // Create a sample binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    return root;
}

int main() {
    // Create a sample binary tree
    Node* root = createSampleTree();

    // Perform zigzag traversal
    vector<int> result = zigZagTraversal(root);

    // Print the result
    cout << "Zigzag Traversal: ";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i];
        if (i < result.size() - 1) {
            cout << " -> ";
        }
    }

    // Clean up the allocated memory (if needed)
    // ...

    return 0;
}