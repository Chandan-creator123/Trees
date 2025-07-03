#include <bits/stdc++.h> // Corrected the header
using namespace std;
#define ll long long

// Class definition for each node in the binary tree
class Node {
public:
    int data;      // The value stored in this node
    Node* left;    // Pointer to the left child
    Node* right;   // Pointer to the right child

    // Constructor: called when creating a new node
    Node(int val) {
        data = val;           // Assign the given value to this node
        left = right = NULL;  // Initialize left and right children as NULL
    }
};

// Global index to track position in preorder array while building the tree
static int idx = -1;

// Function to build binary tree from preorder traversal with -1 as NULL
Node* buildTree(vector<ll>& preorder) {
    idx++;  // Move to the next index

    // If the current value is -1, it represents a NULL (no node)
    if (preorder[idx] == -1) {
        return NULL;
    }

    // Create a new node with the current value
    Node* root = new Node(preorder[idx]);

    // Recursively build the left subtree
    root->left = buildTree(preorder);

    // Recursively build the right subtree
    root->right = buildTree(preorder);

    return root; // Return the root of this (sub)tree
}

// Preorder traversal (Root → Left → Right)
void preOrder(Node* root) {
    if (root == NULL) {
        return; // Base case: if node is NULL, return
    }
    cout << root->data << " ";    // Visit root
    preOrder(root->left);         // Visit left subtree
    preOrder(root->right);        // Visit right subtree
}

// Inorder traversal (Left → Root → Right)
void inOrder(Node* root) {
    if (root == NULL) {
        return;
    }
    inOrder(root->left);          // Visit left subtree
    cout << root->data << " ";    // Visit root
    inOrder(root->right);         // Visit right subtree
}

// Postorder traversal (Left → Right → Root)
void postOrder(Node* root) {
    if (root == NULL) {
        return;
    }
    postOrder(root->left);        // Visit left subtree
    postOrder(root->right);       // Visit right subtree
    cout << root->data << " ";    // Visit root
}

// Level order traversal using queue (BFS)
void levelOrder(Node* root) {
    if (root == NULL) {
        return; // If tree is empty, do nothing
    }

    queue<Node*> q;       // Create a queue to hold nodes
    q.push(root);         // Start with the root

    while (!q.empty()) {  // While queue is not empty
        Node* current = q.front(); // Get the front node
        q.pop();                   // Remove it from queue

        cout << current->data << " "; // Visit current node

        if (current->left != NULL) {
            q.push(current->left);    // Add left child to queue
        }

        if (current->right != NULL) {
            q.push(current->right);   // Add right child to queue
        }
    }
}

int main() {
    // Preorder array to build the tree, with -1 representing NULL
    vector<ll> preorder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};

    // Build the binary tree
    Node* root = buildTree(preorder);

    // Preorder Traversal
    cout << "Preorder: ";
    preOrder(root);
    cout << endl;

    // Inorder Traversal
    cout << "Inorder: ";
    inOrder(root);
    cout << endl;

    // Postorder Traversal
    cout << "Postorder: ";
    postOrder(root);
    cout << endl;

    // Level Order Traversal
    cout << "Level Order: ";
    levelOrder(root);
    cout << endl;

    return 0;
}
