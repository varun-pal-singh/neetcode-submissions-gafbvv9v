class MyHashSet {
private:
    vector<list<int>> hset;
    int limit = 10001;

    int hash(int val) {
        return val % limit;
    }

public:
    
    MyHashSet() : hset(limit) {}
    
    void add(int key) {
        int idx = hash(key);
        if (!this->contains(key)) {
            hset[idx].push_back(key);
        }
    }
    
    void remove(int key) {
        int idx = hash(key);
        if (this->contains(key)) {
            for (auto itr = hset[idx].begin(); itr != hset[idx].end(); itr++) {
                if (*itr == key) {
                    hset[idx].erase(itr);
                    break;
                }
            }
        }
    }
    
    bool contains(int key) {
        int idx = hash(key);
        if (!hset[idx].empty()) {
            for (auto itr = hset[idx].begin(); itr != hset[idx].end(); itr++) {
                if (*itr == key) {
                    return true;
                }
            }
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */