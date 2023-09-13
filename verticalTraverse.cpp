#include <iostream>
#include <map>
#include <queue>
#include <vector>
using namespace std;

// Definition of a binary tree node
struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> verticalOrder(Node* root) {
    map<int, map<int, vector<int>>> node;
    queue<pair<Node*, pair<int, int>>> q;
    vector<int> ans;
    if (root == NULL)
        return ans;
    q.push(make_pair(root, make_pair(0, 0)));
    while (!q.empty()) {
        pair<Node*, pair<int, int>> temp = q.front();
        q.pop();
        Node* frontNode = temp.first;
        int hd = temp.second.first;
        int lvl = temp.second.second;
        node[hd][lvl].push_back(frontNode->val);
        if (frontNode->left) {
            cout<<"  hd  "<<hd<<"  lvl   "<<lvl<<"  front end data "<<frontNode->left->val<<endl;
            q.push(make_pair(frontNode->left, make_pair(hd - 1, lvl + 1)));
            cout<<"  hd  "<<hd<<"  lvl   "<<lvl<<endl;

        }
        cout<<endl;
        if (frontNode->right) {
            cout<<"  hd  "<<hd<<"  lvl   "<<lvl<<"  front end data "<<frontNode->right->val<<endl;
            q.push(make_pair(frontNode->right, make_pair(hd + 1, lvl + 1)));
            cout<<"  hd1  "<<hd<<"  lvl1   "<<lvl<<endl;
        }
    }
    for (auto i = node.begin(); i != node.end(); ++i) {
    for (auto j = i->second.begin(); j != i->second.end(); ++j) {
        for (auto k = j->second.begin(); k != j->second.end(); ++k) {
            ans.push_back(*k);
        }
    }
}
    return ans;
}

// Utility function to create a binary tree from an array
Node* createSampleTree() {
    // Create a sample binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    // root->left->left = new Node(4);
    // root->left->right = new Node(5);
    // root->right->left = new Node(6);
    // root->right->right = new Node(7);

    return root;
}

int main() {
    // Create a sample binary tree
    Node* root = createSampleTree();

    // Perform zigzag traversal
    vector<int> result = verticalOrder(root);

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
