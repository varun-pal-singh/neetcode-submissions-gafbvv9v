class MyHashSet {
private:
    int n;
    vector<list<int>> st;

    int hash(int key) {
        return key % n;
    }

public:
    MyHashSet() {
        n = 1e4 + 1;
        st.resize(n, list<int>{});
    }
    
    void add(int key) {
        int idx = hash(key);
    
        if (!this->contains(key)) {
            st[idx].push_back(key);
        }
    }
    
    void remove(int key) {
        int idx = hash(key);
        if (!this->contains(key)) return;

        st[idx].remove(key);
    }
    
    bool contains(int key) {
        int idx = hash(key);
        return std::find(st[idx].begin(), st[idx].end(), key) != st[idx].end();
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */