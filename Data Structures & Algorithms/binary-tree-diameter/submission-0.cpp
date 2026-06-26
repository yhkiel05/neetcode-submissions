/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
int diameterOfBinaryTree(TreeNode* root) {
    // Declare a variable to keep track of the maximum diameter found
    int diameter = 0;
    
    // Define a helper function to compute the depth of each subtree
    function<int(TreeNode*)> depth = [&](TreeNode* node) -> int {
        // If the node is null, its depth is 0
        if (!node) return 0;
        // Recursively find the depth of the left subtree
        int left = depth(node->left);
        // Recursively find the depth of the right subtree
        int right = depth(node->right);
        // Update the diameter if the path through this node is larger
        diameter = max(diameter, left + right);
        // Return the depth of the current node
        return 1 + max(left, right);
    };
    
    // Start the depth-first search from the root
    depth(root);
    // Return the maximum diameter found
    return diameter;
}
};
