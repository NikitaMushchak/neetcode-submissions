class Solution {
public:
    int maxArea(vector<int>& heights) {
        // 1, 7, 2, 5, 4, 7, 3, 6
        //   1  7  7  7  7  6  6 =  41
        // brute force O[N^2]
        int maxVolume = 0;
        int volume = 0;
        for (int i = 0; i < heights.size(); i++) {
            for (int j = i + 1; j < heights.size(); j++) {
                volume = min(heights[i], heights[j]) * (j - i); 
                maxVolume = max(volume, maxVolume);
            }
        }
        return maxVolume;
    }
};
