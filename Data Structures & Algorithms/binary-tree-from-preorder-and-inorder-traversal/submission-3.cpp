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
    int idx = 0;
    unordered_map<int, int> indices;

public:

    TreeNode* dfs(vector<int>& preorder, int l, int r) {
        if (l > r) return nullptr;
        int root_val = preorder[idx++];
        TreeNode* node = new TreeNode(root_val);
        int mid = indices[root_val];
        node->left = dfs(preorder, l, mid - 1);
        node->right = dfs(preorder, mid + 1, r);
        return node;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); i++) {
            indices[inorder[i]] = i;
        }
        return dfs(preorder, 0, preorder.size() -1);
    }
};
