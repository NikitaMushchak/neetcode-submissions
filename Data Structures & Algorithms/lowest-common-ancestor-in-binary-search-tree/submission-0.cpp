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
        if (!root || !p || !q) {
            return nullptr;
        }
        
        const int rootVal = root->val;

        if (max(p->val, q->val) < rootVal) {
            // move root to left
            return lowestCommonAncestor(root->left, p, q);
        } else if (min(p->val, q->val) > rootVal) {
            // move root to right
            return lowestCommonAncestor(root->right, p, q);
        }
        else {
            return root;
        }
        
    }
};
