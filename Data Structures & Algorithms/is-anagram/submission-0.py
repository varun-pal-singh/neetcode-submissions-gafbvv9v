class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t):  return False
        smap = defaultdict(int)
        tmap = defaultdict(int)

        for i in range(len(s)):
            smap[s[i]] += 1
            tmap[t[i]] += 1
        
        for key, val in smap.items():
            if key not in tmap or tmap[key] != val:
                return False
        
        return True