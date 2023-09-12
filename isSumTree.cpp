#include <iostream>
#include <utility>
using namespace std;
// Define a Node struct with data, left, and right pointers
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

std::pair<bool, int> isSumTreeFast(Node* root) {
    if (root == nullptr) {
        std::pair<bool, int> p = std::make_pair(true, 0);
        return p;
    }
    if (root->left == nullptr && root->right == nullptr) {
        std::pair<bool, int> p = std::make_pair(true, root->data);
        return p;
    }
    std::pair<bool, int> leftAns = isSumTreeFast(root->left);
    std::pair<bool, int> rightAns = isSumTreeFast(root->right);
    bool left = leftAns.first;
    bool right = rightAns.first;
    bool condn = root->data == leftAns.second + rightAns.second;
    std::pair<bool, int> ans;
    if (left && right && condn) {
        ans.first = true;
        ans.second =  2*root->data;
    } else {
        ans.first = false;
        ans.second = 0; // You should set ans.second to some value when the conditions are not met.
    }
    return ans;
}

bool isSumTree(Node* root) {
    return isSumTreeFast(root).first;
}

// Function to create a sample binary tree
int main()
{
    Node* root = new Node(24);
    root->left = new Node(8);
    root->right = new Node(8);
    root->left->right = new Node(3);
    root->left->left = new Node(5);
    if( isSumTree(root))
     cout<<"bT is sum tree "<<endl;
    else 
     cout<<"you get bambooselled "<<endl;
    return 0;
}

