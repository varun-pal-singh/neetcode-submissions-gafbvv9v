class Solution {
public:

    std::unordered_map<char, int> hmap {
        {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}
    };

    int romanToInt(string s) {
        int size = s.length();
        int sum = 0;
        for (int i = 0; i < size; i++) {
            char cur_ch = s[i];
            int val = hmap[cur_ch];
            if (i > 0 && hmap[s[i - 1]] < hmap[cur_ch]) {
                char prev_ch = s[i - 1];
                int prev_val = hmap[prev_ch];
                val -= (2 * prev_val);
            }
            sum += val;
        }
        return sum;
    }
};