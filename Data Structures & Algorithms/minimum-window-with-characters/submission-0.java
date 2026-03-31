class Solution {
    public String minWindow(String s, String t) {
        int n1 = t.length(), n2 = s.length();
        if (n1 > n2)    return "";

        // max size of the hashmap will be 52, so O(1) space
        Map<Character, Integer> hmap = new HashMap<>();     
        for (char ch : t.toCharArray()){
            hmap.put(ch, hmap.getOrDefault(ch, 0) + 1);
        }

        int req = hmap.size(), l = 0;
        int[] res = {-1, -1};
        int minWindow = Integer.MAX_VALUE;

        for (int r = 0; r < n2; r++){
            char rch = s.charAt(r);
            if (hmap.containsKey(rch)){
                hmap.put(rch, hmap.get(rch) - 1);
                if (hmap.get(rch) == 0) req -= 1;
            }

            while (l <= r && (!hmap.containsKey(s.charAt(l)) || hmap.get(s.charAt(l)) < 0 )){
                char lch = s.charAt(l);
                if (hmap.containsKey(lch)){
                    hmap.put(lch, hmap.get(lch) + 1);
                    if (hmap.get(lch) == 1) req += 1;
                }
                l += 1;
            }

            if (req == 0 && (r - l + 1) < minWindow){
                minWindow = r - l + 1;
                res[0] = l; res[1] = r;
            }
        }

        if (minWindow == Integer.MAX_VALUE)   return "";
        return s.substring(res[0], res[1] + 1);
    }
}
