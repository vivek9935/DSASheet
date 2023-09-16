#include <iostream>
#include <vector>

using namespace std;

// Definition of a binary tree node
template <typename T>
struct TreeNode {
    T data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(T val) : data(val), left(NULL), right(NULL) {}
};

void solve(TreeNode<int> *root, int k, int &count, vector<int> &path) {
    if (root == NULL)
        return;

    path.push_back(root->data);
     cout<<"before calling the funtion"<<endl;
    for(int i=0;i<path.size();i++)
    {
        cout<<path[i]<<"  ";
    }cout<<endl;
    

    // Recursively traverse the left and right subtrees
    solve(root->left, k, count, path);
    cout<<"inbetween the calling the funtion"<<endl;
    for(int i=0;i<path.size();i++)
    {
        cout<<path[i]<<"  ";
    }cout<<endl;
    solve(root->right, k, count, path);
    cout<<"after calling the funtion"<<endl;
    for(int i=0;i<path.size();i++)
    {
        cout<<path[i]<<"  ";
    }cout<<endl;
    // Calculate the sum of the path so far
    int sum = 0;
    for (int i = path.size() - 1; i >= 0; i--) {
        sum += path[i];
        if (sum == k) {
            count++;
        }
    }
    cout<<"before pop back and after sum"<<endl;
    for(int i=0;i<path.size();i++)
    {
        cout<<path[i]<<"  ";
    }cout<<endl;
    // Remove the current node from the path before backtracking
    path.pop_back();
    cout<<"After pop back "<<endl;
    for(int i=0;i<path.size();i++)
    {
        cout<<path[i]<<"  ";
    }cout<<endl;
    return;
}

int noWays(TreeNode<int> *root, int k) {
    vector<int> path;
    int count = 0;
    solve(root, k, count, path);
    return count;
}

int main() {
    // Create a binary tree
    TreeNode<int> *root = new TreeNode<int>(10);
    root->left = new TreeNode<int>(5);
    root->right = new TreeNode<int>(15);
    root->left->left = new TreeNode<int>(3);
    root->left->right = new TreeNode<int>(7);
    root->right->right = new TreeNode<int>(18);

    // Define the target sum
    int k = 18;

    // Call the noWays function to count paths with sum equal to k
    int count = noWays(root, k);

    // Output the result
    cout << "Number of paths with sum " << k << ": " << count << endl;

    // Remember to free the memory used by the tree nodes (not shown in this example)

    return 0;
}
