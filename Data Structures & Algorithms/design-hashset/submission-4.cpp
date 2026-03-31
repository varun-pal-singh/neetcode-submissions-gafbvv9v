class MyHashSet {
private:
    static const int limit = 1000001;
    bool hashArr[limit] = {false};

    int getHash(int val) {
        return val % limit;
    }

public:
    MyHashSet() {
        // bool hashArr[limit] = {false};
    }
    
    void add(int key) {
        hashArr[getHash(key)] = true;
    }
    
    void remove(int key) {
        int hash = getHash(key);
        if (hashArr[hash]) {
            hashArr[hash] = false;
        }
    }
    
    bool contains(int key) {
        int hash = getHash(key);
        return hashArr[hash];
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */