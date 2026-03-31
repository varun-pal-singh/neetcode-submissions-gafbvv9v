#include <algorithm>

class MyHashSet {
private:
    static const int cap = 1000;
    vector<int> hashArr[cap];

    int hash(int key) {
        return key % cap;
    }

public:
    MyHashSet() {
        
    }
    
    void add(int key) {
        int idx = hash(key);
        for (int &el : hashArr[idx]) {
            if (el == key) {
                return;
            }
        }
        hashArr[idx].push_back(key);
    }
    
    void remove(int key) {
        int idx = hash(key);
        vector<int> &bucket = hashArr[idx];
        bucket.erase(std::remove(bucket.begin(), bucket.end(), key), bucket.end());
    }
    
    bool contains(int key) {
        int idx = hash(key);
        for (int &el : hashArr[idx]) {
            if (el == key) {
                return true;
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