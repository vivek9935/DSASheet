/* C++ Program to find distance between n1 and n2
using one traversal */
#include <iostream>
using namespace std;

// A Binary Tree Node
struct Node {
	struct Node *left, *right;
	int key;
};

// Utility function to create a new tree Node
Node* newNode(int key)
{
	Node* temp = new Node;
	temp->key = key;
	temp->left = temp->right = NULL;
	return temp;
}
//Global variable to store distance
//between n1 and n2.
int ans;
//Function that finds distance between two node.
int _findDistance(Node* root, int n1, int n2)
{
	if (root==NULL) 
       return 0;
	int left = _findDistance(root->left, n1, n2);
	int right = _findDistance(root->right, n1, n2);
	//if any node(n1 or n2) is found
	if (root->key == n1 || root->key == n2)
	{
		//check if there is any descendant(n1 or n2)
		//if descendant exist then distance between descendant
		//and current root will be our answer.
		if (left || right)
		{
			ans = max(left, right);
			return 0;
		}
		else
			return 1;
	}
	//if current root is LCA of n1 and n2.
	else if (left && right)
	{
		ans = left + right;
		return 0;
	}
	//if there is a descendant(n1 or n2).
	else if (left || right)
		//increment its distance
		return max(left, right) + 1;
	//if neither n1 nor n2 exist as descendant.
	return 0;
}
// The main function that returns distance between n1
// and n2.
int findDistance(Node* root, int n1, int n2)
{
	ans = 0;
	_findDistance(root, n1, n2);
	return ans;
}

// Driver program to test above functions
int main()
{
	// Let us create binary tree given in
	// the above example
	Node* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->right->left = newNode(6);
	root->right->right = newNode(7);
	root->right->left->right = newNode(8);
	cout << "Dist(4, 5) = " << findDistance(root, 4, 5);
	cout << "\nDist(4, 6) = " << findDistance(root, 4, 6);
	cout << "\nDist(3, 4) = " << findDistance(root, 3, 4);
	cout << "\nDist(2, 4) = " << findDistance(root, 2, 4);
	cout << "\nDist(8, 5) = " << findDistance(root, 8, 5);
	return 0;
}
