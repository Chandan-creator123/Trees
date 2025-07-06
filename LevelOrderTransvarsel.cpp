#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Binary Tree Node definition
struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Function to perform level order traversal (BFS)
vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> result;  // Final result storing levels
    if (!root) return result;    // If tree is empty, return empty result

    queue<TreeNode*> q;          // Queue for BFS
    q.push(root);                // Start with the root node

    while (!q.empty()) {
        int size = q.size();     // Number of nodes in the current level
        vector<int> level;       // Store values at current level

        // Process all nodes in this level
        for (int i = 0; i < size; ++i) {
            TreeNode* node = q.front(); q.pop();  // Get front node
            level.push_back(node->val);           // Add its value to the level list

            // Add child nodes to queue for next level
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }

        result.push_back(level); // Add this level to the result
    }

    return result;
}
