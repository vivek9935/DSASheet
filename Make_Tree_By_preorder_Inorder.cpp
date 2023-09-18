#include <iostream>
#include <unordered_map>
using namespace std;
// Define the Node structure
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution {
private:
    bool flag  =false;
    int a;
    int findPosition(int in[], int element, int n) {
        unordered_map<int,int>  mp;
        for (int i = 0; i < n; i++) {
            if (in[i] == element)
            {
                mp[i]=i;
                if(mp.find(i)==mp.end())
                return i;
               else 
                i++;
            }
        }
        return -1;
    }
 
    Node* solve(int in[], int pre[], int& index, int inOrderStart, int inOrderEnd, int n) {
        if (index >= n || inOrderStart > inOrderEnd)
            return nullptr;
        cout<<"indxe is "<<index<<endl;
        int element = pre[index++];
        cout<<"element is "<<element<<endl;
        Node* root = new Node(element);
        int position = findPosition(in, element,n);
        cout<<"postion   "<<position<<endl;
        cout<<"stating index for left   "<<inOrderStart<<"Ending index for left "<<position -1<<endl;
        root->left = solve(in, pre, index, inOrderStart, position - 1, n);
         cout<<"starting index for right  "<<position + 1 <<"Ending index for right "<<inOrderEnd<<endl;
        root->right = solve(in, pre, index, position + 1, inOrderEnd, n);
        cout<<"Root ka data  "<<root->data<<endl;
        if(root->left!=NULL)
        cout<<"Root ka data left side ka "<<root->left->data<<endl;
        else 
         cout<<-1<<endl;
        if(root->left!=NULL)
        cout<<"Root ka data  right side ka "<<root->right->data<<endl;
        else
        cout<<-1<<endl;
        return root;
    }

public:
    Node* buildTree(int in[], int pre[], int n) {
        int preOrderIndex = 0;
        Node* ans = solve(in, pre, preOrderIndex, 0, n - 1, n);
        return ans;
    }
};

// Function to print the inorder traversal of the tree
void printInorder(Node* root) {
    if (root == nullptr) return;
    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}

int main() {
    Solution solution;

    int inorder[] = {7 ,3, 11, 1, 17, 3, 18};
    int preorder[] = {1 ,3 ,7, 11, 3 ,17, 18};
    int n = sizeof(inorder) / sizeof(inorder[0]);

    Node* root = solution.buildTree(inorder, preorder, n);

    std::cout << "Inorder Traversal of the Constructed Tree: ";
    printInorder(root);
    std::cout << std::endl;

    // Clean up the memory allocated for the tree nodes
    // You can implement a function to delete the tree
    // or simply do it manually.
    // ...

    return 0;
}
