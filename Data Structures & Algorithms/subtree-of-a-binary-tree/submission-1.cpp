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
        if (not root || not subRoot) {
            return false;
        }

        queue<TreeNode *> rootQ;
        rootQ.push(root);

        while (not rootQ.empty()) {
            TreeNode * rootNode = rootQ.front();
            rootQ.pop();
            
            if (rootNode->val == subRoot->val) {
                if (checkTrees(rootNode, subRoot)) {
                    return true;
                }
            }

            if (rootNode->left) {
                rootQ.push(rootNode->left);
            }
            if (rootNode->right) {
                rootQ.push(rootNode->right);
            }
        }
        return false;
    }
private:
    bool checkTrees(TreeNode* rootNode, TreeNode* subRoot) {
        queue<pair<TreeNode *, TreeNode *> > rootAndSub;
        rootAndSub.push({rootNode, subRoot});

        while (not rootAndSub.empty()) {
            auto [root, sub] = rootAndSub.front();
            rootAndSub.pop();

            if (not root && not sub) {
                continue;
            }

            if (not root || not sub) {
                // structure differs
                return false;
            }

            if (root->val != sub->val) {
                return false;
            }

            rootAndSub.push({root->left, sub->left});
            rootAndSub.push({root->right, sub->right});
        }
        return true;
    }
};
