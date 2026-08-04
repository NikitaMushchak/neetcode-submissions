class LRUCache {
public:
    LRUCache(int capacity) : m_capacity(capacity) {}
    
    int get(int key) {
        auto it = m.find(key);
        if (it != m.end()) {
            // we find the key
            // we need to put lru in the begining
            int val = it->second->second; // [key, value]
            lruPair.erase(it->second);
            auto itLru = lruPair.insert(lruPair.begin(), {key, val});
            it->second = itLru;
            return val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        
        auto it = m.find(key);
        if (it != m.end()) {
            // update val
            auto listIt = it->second;
            listIt->second = value;
            lruPair.splice(lruPair.begin(), lruPair, listIt);

            return;
        } 

        if (lruPair.size() == m_capacity) {
            // we need to delete the last elem in the lru and corresponding in the map
            auto last = lruPair.back();
            int lastKey = last.first;
            lruPair.pop_back();
            m.erase(lastKey);
        }
        lruPair.push_front({key, value});
        m[key] = lruPair.begin();
    }
private:
    int m_capacity; 
    list<pair<int, int>> lruPair; // key - value
    using listIt = list<pair<int, int>>::iterator;
    unordered_map<int, listIt> m; // key and iter to value
};
