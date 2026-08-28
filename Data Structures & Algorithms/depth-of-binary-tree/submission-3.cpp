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
    int maxDepth(TreeNode* root) {
        if (!root) {
            return 0;
        }

        queue<pair<TreeNode*, int>> q;
        q.push({root, 1});

        int maxDepth = 1;

        while(!q.empty()) {
            int size = q.size();

            for (int i = 0; i < size; i++) {
                auto [node, count] = q.front();
                q.pop();
                
                if (node->left) {
                    q.push({node->left, count + 1});
                    maxDepth = max(maxDepth, count + 1);
                }
                if (node->right) {
                    q.push({node->right, count + 1});
                    maxDepth = max(maxDepth, count + 1);
                }
            }
        }
       
        return maxDepth;
    }
};
