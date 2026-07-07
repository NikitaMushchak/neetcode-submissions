class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> warmerDays(temperatures.size());
        for (int i = 0; i < temperatures.size(); ++i) {
            int temp = temperatures[i];
            for (int j = i + 1; j < temperatures.size(); j++) {
                if (temp < temperatures[j]) {
                    warmerDays[i] = j - i;
                    break;
                }
            }
        }
        return warmerDays;
    }
};
