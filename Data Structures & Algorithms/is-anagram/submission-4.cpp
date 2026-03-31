class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.length(), m = t.length();
        if (n != m) {
            return false;
        }
        unordered_map<char, int> hmap;
        for (char ch: s) {
            hmap[ch] += 1;
        }

        for (unordered_map<char, int>::iterator it = hmap.begin(); it != hmap.end(); it++) {
            std::cout << it->first << ": " << it->second << ", ";
        }
        std::cout << "\n";

        for (char ch: t) {
            if (hmap.find(ch) != hmap.end()) {
                hmap[ch] -= 1;
                if (hmap[ch] == 0) {
                    hmap.erase(ch);
                }
            } else {
                return false;
            }
        }

        for (unordered_map<char, int>::iterator it = hmap.begin(); it != hmap.end(); it++) {
            std::cout << it->first << ": " << it->second << ", ";
        }
        std::cout << "\n";

        return hmap.size() == 0;
    }
};
