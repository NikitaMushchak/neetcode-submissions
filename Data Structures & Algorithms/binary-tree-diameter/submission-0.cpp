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
        // may solve the problem using recursion
        // we need to compare the max sum of left and right heights
        int diameter = 0;
        height(root, diameter);
        return diameter;
    }
private:
    int height(TreeNode* node, int& diameter) {
        if (not node) {
            return 0;
        }
        int heightleft = height(node->left, diameter);
        int heigntright = height(node->right, diameter);

        diameter = max(diameter, heightleft + heigntright);
        return 1 + max(heightleft, heigntright);
    }
};
