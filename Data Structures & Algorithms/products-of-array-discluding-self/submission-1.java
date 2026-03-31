class Solution {
    public int[] productExceptSelf(int[] nums) {
        int n = nums.length;
        int[] prefix = new int[n];
        int[] postfix = new int[n];
        prefix[0] = 1;
        postfix[n - 1] = 1;
        int pro = 1;
        for (int i = 1; i < n; i++){
            prefix[i] = nums[i - 1] * pro;
            pro = prefix[i];
        }
        pro = 1;
        for (int i = n - 2; i >= 0; i --){
            postfix[i] = nums[i + 1] * pro;
            pro = postfix[i];
        }

        for (int i = 0; i < n; i++){
            prefix[i] *= postfix[i];
        }
        return prefix;
    }
}  
