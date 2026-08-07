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
        // DFS search
        if (!root) {
            return 0;
        }
        int depth = 0;
        queue<TreeNode*> st;
        st.push(root);
        while (!st.empty()) {
            int size = st.size();
            for (int i = 0; i < size; ++i) {
                TreeNode * node = st.front();
                st.pop();
                if (node->left) {
                    st.push(node->left);
                }
                if (node->right) {
                    st.push(node->right);
                }
            }
            depth++;
        }

        return depth;
    }
};
