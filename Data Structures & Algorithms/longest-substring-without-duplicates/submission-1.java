class Solution {
    public int lengthOfLongestSubstring(String s) {
        Set<Character> seen = new HashSet<>();
        int longest = 0, l = 0;
        for (int i = 0; i < s.length(); i += 1){
            char ch = s.charAt(i);
            while (l < i && seen.contains(ch)){
                char firstChar = s.charAt(l);
                seen.remove(firstChar);
                l += 1;
            }
            seen.add(ch);
            longest = Math.max(longest, i - l + 1);
        }
        return longest;
    }
}