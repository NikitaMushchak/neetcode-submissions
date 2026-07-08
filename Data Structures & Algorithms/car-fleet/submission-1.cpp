class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        if (position.size() != speed.size()) {
            return 0;
        }

        vector<pair<int, int>> posAndSpeed(position.size());
        for (int i = 0; i < position.size(); ++i) {
            posAndSpeed[i] = {position[i], speed[i]};
        }
        // n log(n)
        sort(posAndSpeed.begin(), posAndSpeed.end(), 
             [](const pair<int, int>& lhv, const pair<int, int> & rhv) 
              { return lhv.first > rhv.first; });
            //   [[4, 2], [1, 3]]
            //    [[6, 2] [4, 3]]
            //    [[8, 2]  [7, 3]]
            //    [[10, 2],[10, 2]]
        
        // for (auto [dist, time]: posAndSpeed) {
        //     cout << "[" << dist << ", " << time << "]" << endl;
        // }
//         [4, 1] 10 - 4 / 1 = 6
// [2, 3] 8 / 3 = 2.66
// [0, 2] 5
        int fleets = 1;
        double prevTime = (double)(target - posAndSpeed[0].first) / posAndSpeed[0].second;
        for (int i = 1; i < posAndSpeed.size(); ++i) {
            double curTime = (double)(target - posAndSpeed[i].first) / posAndSpeed[i].second;
            if (curTime > prevTime) {
                fleets++;
                prevTime = curTime;
            }
        }

        return fleets;
    }
};
