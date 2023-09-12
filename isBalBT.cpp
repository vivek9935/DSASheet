#include <iostream>
#include <utility>
#include <cmath>

using namespace std;

template <typename T>
class TreeNode {
public:
    T data;
    TreeNode<T>* left;
    TreeNode<T>* right;

    TreeNode(T value) : data(value), left(nullptr), right(nullptr) {}
};

pair<bool, int> bal(TreeNode<int>* root) {
    if (root == NULL) {
        pair<bool, int> p = make_pair(true, 0);
        return p;
    }
    pair<bool, int> left = bal(root->left);
    pair<bool, int> right = bal(root->right);
    bool leftAns = left.first;
    bool rightAns = right.first;
    bool diff = abs(left.second - right.second) <= 1;
    pair<bool, int> ans;
    ans.second = max(left.second, right.second) + 1;
    if (leftAns && rightAns && diff)
        ans.first = true;
    else
        ans.first = false;
    return ans;
}

bool isBalancedBT(TreeNode<int>* root) {
    return bal(root).first;
}

int main() {
    // Create a sample binary tree
    TreeNode<int>* root = new TreeNode<int>(1);
    root->left = new TreeNode<int>(2);
    //root->right = new TreeNode<int>(3);
    root->left->left = new TreeNode<int>(4);
    root->left->right = new TreeNode<int>(5);
   

    bool balanced = isBalancedBT(root);

    if (balanced) {
        cout << "The binary tree is balanced." << endl;
    } else {
        cout << "The binary tree is not balanced." << endl;
    }

    // Don't forget to free the dynamically allocated memory
    delete root->left->left;
    delete root->left->right;
    delete root->right->left;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
