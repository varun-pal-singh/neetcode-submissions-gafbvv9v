class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        hmap = {}
        l, longest = 0, 0
        for r in range(len(s)):
            ch = s[r]
            if l < r and ch in hmap:
                l = max(l, hmap[ch] + 1)
            hmap[ch] = r
            longest = max(longest, r - l + 1)
        
        return longest