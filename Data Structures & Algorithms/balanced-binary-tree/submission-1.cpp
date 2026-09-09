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
    bool isBalanced(TreeNode* root) {
        if (not root) {
            return true;
        }
        return abs(dfs(root->left) - dfs(root->right)) <= 1 &&
               isBalanced(root->left) &&
               isBalanced(root->right);
    }
private:
    int dfs(TreeNode* node) {
        if (not node) {
            return 0;
        }

        int leftHeight = dfs(node->left);
        int rightHeight = dfs(node->right);

        return 1 + max(leftHeight, rightHeight);
    }
};
