class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res(temperatures.size(), 0);
        stack<pair<int, int>> st; // stack of temp, ind

        for (int i = 0; i < temperatures.size(); ++i) {
            int temp = temperatures[i];
            while (!st.empty() && temp > st.top().first) {
                auto tempInd = st.top();
                st.pop();
                res[tempInd.second] = i - tempInd.second;
            }
            st.push({temp, i});
        }
        return res;
    }
};
