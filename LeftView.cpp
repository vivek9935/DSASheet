#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;
template <typename T>
struct TreeNode {
    T data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(T val) : data(val), left(nullptr), right(nullptr) {}
};

std::vector<int> getLeftView(TreeNode<int>* root) {
    std::vector<int> ans;
    if (root == nullptr)
        return ans;

    std::map<int, int> mp;
    std::queue<std::pair<TreeNode<int>*, int>> q;
    q.push(std::make_pair(root, 0));
    
    while (!q.empty()) {
        std::pair<TreeNode<int>*, int> temp = q.front();
        q.pop();
        TreeNode<int>* frontNode = temp.first;
        int hd = temp.second;
        mp[hd] = frontNode->data;
        if (frontNode->right)
            q.push(std::make_pair(frontNode->right, hd + 1));
        if (frontNode->left)
            q.push(std::make_pair(frontNode->left, hd + 1));
        
    }
    
    for (const auto& i : mp) {
        ans.push_back(i.second);
    }
    
    return ans;
}

int main() {
    // Creating a sample binary tree
    TreeNode<int>* root = new TreeNode<int>(1);
    root->left = new TreeNode<int>(2);
    root->right = new TreeNode<int>(3);
    root->left->left = new TreeNode<int>(4);
    root->left->right = new TreeNode<int>(5);
    root->right->left = new TreeNode<int>(6);
    root->right->right = new TreeNode<int>(7);

    // Get the left view of the binary tree
    std::vector<int> leftView = getLeftView(root);

    // Print the left view elements
    std::cout << "Left View: ";
    for (int val : leftView) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    return 0;
}
