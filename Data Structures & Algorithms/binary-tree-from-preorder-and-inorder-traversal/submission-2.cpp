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
    unordered_map<int, int> indices;
    int idx = 0;

    // root val


public:
    TreeNode* dfs(vector<int>& preorder, int left, int right) {
        if (left > right) return nullptr; // we reached the end
        int root_val = preorder[idx++]; // get the val then increment idx
        TreeNode* node = new TreeNode(root_val);
        int mid = indices[root_val];
        node->left = dfs(preorder, left, mid - 1);
        node->right = dfs(preorder, mid + 1, right);
        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); i++) {
            indices[inorder[i]] = i;
        }
        return dfs(preorder, 0, preorder.size() -1);    
    }
};
