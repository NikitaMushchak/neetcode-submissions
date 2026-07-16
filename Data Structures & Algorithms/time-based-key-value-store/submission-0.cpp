class TimeMap {
public:
    TimeMap() {
        
    }
    
    // O(1)
    void set(string key, string value, int timestamp) {
        m[key].emplace_back(timestamp, value);
    }
    
    // O(log(N))
    string get(string key, int timestamp) {
        if (m.count(key)) {
            auto & vec = m[key];
            // sort & binary search
            sort(vec.rbegin(), vec.rend());
          
            int l = 0;
            int r = vec.size() - 1;
            int idx = -1;
            while (l <= r) {
                int mid = l + (r - l) / 2;
                //[4,3, 2, 1]
                if (vec[mid].first <= timestamp) {
                    idx = mid;
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }
            if (idx != -1) {
                return vec[idx].second;
            }
           
            // it returns largest timestamp_prev
        }
        // not found
        return "";
    }
private:
    unordered_map<string, vector<pair<int, string>>> m;
};
// multiple values for the same key at diff timestamp
// 