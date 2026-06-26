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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (root && !subRoot) return true; // empty subtree is subtree of nonempty tree
        if (!root && subRoot) return false; // nonempty subtree is not subtree of empty tree
        if (sameTree(root, subRoot)) return true; // if trees are same then subtree
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
        // continue trying to find a subtree
    }

    bool sameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q) return true;
        if (p && q && p->val == q->val) {
            return sameTree(p->left, q->left) && sameTree(p->right, q->right);
        } else {
            return false;
        }
    }
};
