class TimeMap {
private:
    unordered_map<string, vector<int>> keyToTimeMap;
    unordered_map<int, string>         timeToValMap;

public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        keyToTimeMap[key].push_back(timestamp);
        timeToValMap[timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        if (keyToTimeMap.find(key) == keyToTimeMap.end())   return "";
        vector<int> &arr = keyToTimeMap[key];
        int l = 0, r = arr.size() - 1;
        int idx = -1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (arr[mid] <= timestamp) {
                idx = mid;
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }
        // for (const int &time: arr) {
        //     std::cout << time << ", ";
        // }
        // std::cout << "\nidx: " << idx << "\n";
        return idx == -1 ? "" : timeToValMap[arr[idx]];
    }
};
