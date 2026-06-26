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
    int kthSmallest(TreeNode* root, int k) {
        //return inOrder(0, root, k);
        int n = 0;
        stack<TreeNode*> inOrder;
        TreeNode* curr = root;
        while (curr || !inOrder.empty()) {
            while (curr) {
                inOrder.push(curr);
                curr = curr->left;
            }
            curr = inOrder.top();
            inOrder.pop();
            n++;
            if (n == k) return curr->val;
            curr = curr->right;
        }
        return -1;
    }
};
