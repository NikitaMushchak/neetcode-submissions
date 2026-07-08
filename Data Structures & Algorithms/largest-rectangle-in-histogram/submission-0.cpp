class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        // return the bigger volume of the rectangle
        // brute force: N^2 
        // start from left and every step shift the right border
        // store the minimum heigh and maximum volume
        // 

        int vol = 0;
        for (int i = 0; i < heights.size(); i++) {
            int minHeigh = heights[i];
            for (int j = i; j < heights.size(); j++) {
                minHeigh = min(minHeigh, heights[j]);
                vol = max(vol, minHeigh * (j - i + 1));
            }
        }
        return vol;
    }
};
