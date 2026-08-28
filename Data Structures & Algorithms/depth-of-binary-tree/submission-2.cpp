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

        queue<TreeNode*> q;
        q.push(root);

        unordered_map<TreeNode*, int> NodeAndDepth;
        NodeAndDepth[root] = 1;
        while(!q.empty()) {
            int size = q.size();

            for (int i = 0; i < size; i++) {
                TreeNode * node = q.front();
                q.pop();

                if (!NodeAndDepth.count(node)) {
                    continue;
                }
                
                int rootDepth = NodeAndDepth[node];
                if (node->left) {
                    NodeAndDepth.emplace(node->left,rootDepth + 1);
                    q.push(node->left);
                }
                if (node->right) {
                    NodeAndDepth.emplace(node->right, rootDepth + 1);
                    q.push(node->right);
                }
            }
        }
        int maxDepth = 1;
        for (const auto & [_, depth] : NodeAndDepth) {
            maxDepth = max(depth, maxDepth);
        }
        return maxDepth;
    }
};
