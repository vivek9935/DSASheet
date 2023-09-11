#include <iostream>
#include <algorithm>
using namespace std;
// Define the structure of a binary tree node.
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(NULL), right(NULL) {}
};
int i=1;
int j=1;
// Function to calculate the height of a binary tree.
int height(Node *node) {
     cout<< j<<"   time the value of height is   "<<endl;
   j++;
    if (node == NULL)
      { 
       
       
         return 0;
      }
    // Recursive step:
    // Calculate the height of the left subtree.
    int left = height(node->left);
    // Calculate the height of the right subtree.
    int right = height(node->right);

    // Calculate the height of the current node.
    int ans = max(left, right) + 1;
   cout<< i<<"   time the value of height is   "<<ans<<endl;
   i++;
    return ans;

}

// Function to calculate the diameter of a binary tree.
int diameter(Node* root) {
    // Base case: If the root is NULL, the diameter is 0.
    if (root == NULL)
        return 0;

    // Recursive calls to calculate diameters of left and right subtrees.
    int op1 = diameter(root->left);
    int op2 = diameter(root->right);

    // Calculate the diameter through the current node (root).
    int op3 = height(root->left) + height(root->right) + 1;

    // Choose the maximum diameter among op1, op2, and op3.
    int ans = max(op1, max(op2, op3));

    // Return the maximum diameter.
    return ans;
}

int main() {
  /*  Create a sample binary tree:
           1
          / \
         2   3
        / \
       4   5*/
    Node* root = new Node(1);
     root->left= new Node(2);
     root->right=new Node(3);
     root->left->left=new Node(4);
     root->left->right=new Node(5);

    // Calculate the diameter of the binary tree.
    int treeDiameter = diameter(root);

    std::cout << "The diameter of the binary tree is: " << treeDiameter << std::endl;

    // Clean up memory by deleting the nodes (not necessary, but good practice).
    

    return 0;
}
