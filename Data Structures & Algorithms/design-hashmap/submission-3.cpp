class MyHashMap {
private:
    int n;
    vector<list<pair<int, int>>> mp;

    int hash(int key) {
        return key % n;
    }

public:
    MyHashMap() : n(1e4 + 1), mp(n, list<pair<int, int>> {}) {}
    
    void put(int key, int value) {
        int idx = hash(key);
        for (auto it = mp[idx].begin(); it != mp[idx].end(); it++) {
            if (it->first == key) {
                it->second = value;  // update
                return;
            }
        }
        mp[idx].push_back({key, value}); // insert new entry
    }
    
    int get(int key) {
        int idx = hash(key);
        for (auto it = mp[idx].begin(); it != mp[idx].end(); it++) {
            if (it->first == key) {
                return it->second;
            }
        }
        return -1;
    }
    
    void remove(int key) {
        int idx = hash(key);
        for (auto it = mp[idx].begin(); it != mp[idx].end(); it++) {
            if (it->first == key) {
                mp[idx].erase(it);
                return;
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */