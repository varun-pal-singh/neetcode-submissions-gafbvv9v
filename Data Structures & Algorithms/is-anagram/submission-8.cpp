class Solution {
public:
    bool isAnagram(string s, string t) {
        int32_t sizeS = s.size(), sizeT = t.size();
        if (sizeS != sizeT)  return false;
        vector<int> map(26, 0);
        for (size_t i = 0; i < sizeS; i++) {
            map[s[i] - 'a'] += 1;
            map[t[i] - 'a'] -= 1;
        }

        for (size_t i = 0; i < 26; i++) {
            if (map[i] != 0) {
                return false;
            }
        }
        return  true;
    }
};
