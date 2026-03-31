class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> sMap;
        unordered_map<char, int> tMap;

        int n = s.length(), m = t.length();
        if (n != m) return false;

        for (int i = 0; i < s.length(); i++) {
            sMap[s[i]] += 1;
            tMap[t[i]] += 1;
        }

        return sMap == tMap;
    }
};
