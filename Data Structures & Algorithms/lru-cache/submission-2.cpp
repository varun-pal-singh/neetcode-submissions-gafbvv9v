class LRUCache {
private:
    int n;
    list<pair<int, int>> cache;
    unordered_map<int, pair<int, list<pair<int, int>>::iterator>> mp; 
    // mp[key] = [val, itr];

    void makeLatest(int key, int val) {
        cache.push_front({key, val});
        mp[key] = {val, cache.begin()};
    }

    void print(list<pair<int, int>> &cache) {
        cout << "n : " << n << "\n";
        cout << "[ ";
        for (auto &p : cache) {
            cout << "{" << p.first << ": " << p.second << "}, "; 
        }
        cout << " ]\n";
    }

public:
    LRUCache(int capacity) : n(capacity){
        
    }
    
    int get(int key) {
        auto it = mp.find(key);
        if (it != mp.end()) {
            int val = it->second.first;
            cache.erase(it->second.second);  // remove from cache list
            makeLatest(key, val);
            return val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        auto it = mp.find(key);
        if (mp.find(key) != mp.end()) {
            auto pr = mp[key];
            cache.erase(pr.second);
            mp.erase(key);
            makeLatest(key, value);
            return;
        } else if (n <= 0) {
            // size exceeds remove least recently used from cache list
            auto pr = cache.back();
            cache.pop_back();
            cout << "key to remove: " << pr.first;
            mp.erase(pr.first);
            n++;
        }
        makeLatest(key, value);
        n--;
        // print(cache);
    }
};
