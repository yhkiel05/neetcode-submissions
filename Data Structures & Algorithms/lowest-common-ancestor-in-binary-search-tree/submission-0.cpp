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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // wherever a split occurs that is the lca
        TreeNode* curr = root;
        while (curr) {
            if (p->val > curr->val && q->val > curr->val) curr = curr->right;
            else if (p->val < curr->val && q->val < curr->val) curr = curr->left;
            else return curr;
        }
    }
};
