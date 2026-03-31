class Solution {
    public int longestConsecutive(int[] nums) {
        Set<Integer> seen = new HashSet<>();
        int longest = 0, cnt = 0;
        for (int n : nums){
            seen.add(n);
        }
        for (int n : seen){
            if (!seen.contains(n - 1)){
                cnt = 0;
                while (seen.contains(n)){
                    cnt += 1;
                    n += 1;
                }
                longest = Math.max(longest, cnt);
            }
        }
        return longest;
    }
}
