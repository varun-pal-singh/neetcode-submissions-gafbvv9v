class MyHashMap {
private:
    static const int cap = 10001;
    vector<pair<int, int>> table[cap];

    int hash(int key) {
        return key % cap;
    }

public:
    MyHashMap() {
        
    }
    
    void put(int key, int value) {
        int idx = hash(key);
        for (pair<int, int> &el : table[idx]) {
            if (el.first == key) {
                el.second = value;  // updating existing one
                return;
            }
        }
        table[idx].push_back({key, value}); // new one
    }
    
    int get(int key) {
        int idx = hash(key);
        for (pair<int, int> &el : table[idx]) {
            if (el.first == key) {
                return el.second;
            }
        }
        return -1;
    }
    
    void remove(int key) {
        int idx = hash(key);
        vector<pair<int, int>> &bucket = table[idx];
        bucket.erase(std::remove_if(bucket.begin(), 
                                    bucket.end(), 
                                    [key] (pair<int, int> &p) {
                                        return p.first == key;
                                    }),
                    bucket.end());
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */