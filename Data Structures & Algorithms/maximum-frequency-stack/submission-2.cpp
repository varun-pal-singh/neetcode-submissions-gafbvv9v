class FreqStack {
   private:
    unordered_map<int, int> numToFreqMap;
    map<int, deque<int>> freqToNumMap;
    // priority_queue<pair<int, int>> maxHeap

   public:
    FreqStack() {}

    void push(int val) {
        if (numToFreqMap.find(val) != numToFreqMap.end()) {
            numToFreqMap[val]++;
            int freq = numToFreqMap[val];
            freqToNumMap[freq].push_front(val);
        } else {
            numToFreqMap[val] = 1;
            freqToNumMap[1].push_front(val);
        }
    }

    int pop() {
        // map<int, deque<int>>::iterator it = freqToNumMap.rbegin();
        auto it = freqToNumMap.rbegin();
        int maxFreq = it->first;
        int maxFreqVal = it->second.front();
        // cout << "maxFreq: " << maxFreq << " maxFreqVal: " << maxFreqVal << "\n";
        it->second.pop_front();
        numToFreqMap[maxFreqVal]--;
        if (it->second.empty()) {
            freqToNumMap.erase(maxFreq);
        }
        return maxFreqVal;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */