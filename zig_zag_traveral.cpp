#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Define the structure of a binary tree node
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

// Function to perform zigzag traversal and return the result
vector<int> zigZagTraversal(Node* root) {
    vector<int> result;
    if (root == NULL)
        return result;

    queue<Node *> q;
    q.push(root);
    bool leftToRight = true;
    int j=0;
    while (!q.empty()) {
        int size = q.size();
        vector<int> ans(size); // Initialize ans for each level

        for (int i = 0; i < size; i++) {
            Node *frontNode = q.front();
            cout<<" yo "<<q.front()->data<<"   ";
            cout<<endl;
            q.pop();
            int index = leftToRight ? i : size - i - 1;
            ans[index] = frontNode->data;
            // cout<<j<<"   times the value is "<<ans[index]<<endl;
            // j++;
            if (frontNode->left)
                q.push(frontNode->left);
            if (frontNode->right)
                q.push(frontNode->right);
          cout<<"gfg"<<endl;
            
        }

        leftToRight = !leftToRight;

        for (int i = 0; i < ans.size(); i++) {
            //cout<<i<<"  yo time i do this "<<ans[i]<<"  ";
    result.push_back(ans[i]);
}cout<<endl;
    }

    return result;
}

// Function to create a sample binary tree
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
