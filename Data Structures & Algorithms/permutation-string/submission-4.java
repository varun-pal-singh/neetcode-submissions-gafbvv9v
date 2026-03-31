class Solution {
    public boolean checkInclusion(String s1, String s2) {
        int n1 = s1.length(), n2 = s2.length();
        Map<Character, Integer> hmap = new HashMap<>();
        for (char ch : s1.toCharArray()){
            hmap.put(ch, hmap.getOrDefault(ch, 0) + 1);
        }
        int req = hmap.size();
        int l = 0;
        for (int r = 0; r < n2; r++){
            while (l <= r && (r - l + 1) > n1){
                char ch = s2.charAt(l);
                if (hmap.containsKey(ch)){
                    hmap.put(ch, hmap.get(ch) + 1);
                    if (hmap.get(ch) == 1)  req += 1;
                }
                l += 1;
            }

            char ch = s2.charAt(r);
            if (hmap.containsKey(ch)){
                hmap.put(ch, hmap.get(ch) - 1);
                if (hmap.get(ch) == 0)  req -= 1;
            }

            if (req == 0)   return true;
        }
        return false;
    }
}
