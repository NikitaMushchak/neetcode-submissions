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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // what if p = nullptr and q = nullptr? it's the same trees!
        // we going to match trees by its values if p->val == q->val => same leaf!
         if (not p && not q) {
            return true;
        }

        if (not p || not q) {
            return false;
        }
       
        queue<pair<TreeNode*, TreeNode*> > pToQNodes;
        pToQNodes.push({p, q});

        while(not pToQNodes.empty()) {
            auto [pNode, qNode] = pToQNodes.front();
            pToQNodes.pop();

            if (pNode->val != qNode->val) {
                return false;
            }

            if (pNode->left && qNode->left) {
                pToQNodes.push({pNode->left, qNode->left});
            } else if (pNode->left || qNode->left) {
                return false;
            }

            if (pNode->right && qNode->right) {
                pToQNodes.push({pNode->right, qNode->right});
            } else if (pNode->right || qNode->right) {
                return false;
            }
        }
        return true;
    }
};
