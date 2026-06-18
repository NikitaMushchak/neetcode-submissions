class Solution {
public:
    int trap(vector<int>& height) {
        // height: 0, 2, 0, 3, 1, 0, 1, 3, 2, 1
        // prefix: 0  0  2  0  3  1  0  1  3  1
        //postfix: 2  0  3  1  0  1  3  2  1  0
        // ab initio result: (2 - 0) + (3-1) + (3- 0) + (3-1) = 9
        // volume[i] = min(prefix[i] - postfix[i]) - height[i]
        int maxArea = 0;
        vector<int> prefix(height.size());
        vector<int> postfix(height.size());

        prefix[0] = height[0];
        for (int i = 1; i < height.size(); ++i) {
            prefix[i] = max(prefix[i - 1], height[i]);
        }
        postfix[height.size() - 1] = height[height.size() - 1];
        for (int i = height.size() - 2; i >= 0; --i) {
            postfix[i] = max(postfix[i + 1], height[i]);
        }

        for (int i = 0; i < height.size(); ++i) {
            maxArea += min(prefix[i], postfix[i]) - height[i];
        }
        return maxArea;
    }
};
