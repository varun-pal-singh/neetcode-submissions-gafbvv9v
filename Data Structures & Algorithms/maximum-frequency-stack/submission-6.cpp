class FreqStack {
   private:
    unordered_map<int, int> numToFreqMap;
    unordered_map<int, stack<int>> freqToNumMap;
    int maxFreq;
    // priority_queue<pair<int, int>> maxHeap

   public:
    FreqStack() : maxFreq(0) {}

    void push(int val) {
        if (numToFreqMap.find(val) != numToFreqMap.end()) {
            numToFreqMap[val]++;
            int freq = numToFreqMap[val];
            if (maxFreq < freq) {
                maxFreq = freq;
                freqToNumMap[freq] = stack<int>();
            }
            freqToNumMap[freq].push(val);
        } else {
            numToFreqMap[val] = 1;
            if (freqToNumMap.find(1) == freqToNumMap.end()) {
                maxFreq = 1;
                freqToNumMap[1] = stack<int>();
            }
            freqToNumMap[1].push(val);
        }
    }

    int pop() {
        unordered_map<int, stack<int>>::iterator it = freqToNumMap.find(maxFreq);
        // cout << "maxFreq: " << maxFreq << " it->first: " << it->first << " , it->second: " << it->second.front() << "\n";

        int val = it->second.top();
        it->second.pop();
        numToFreqMap[val]--;
        if (it->second.empty()) {
            freqToNumMap.erase(maxFreq);
            maxFreq--;
        }
        return val;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */