class Solution {
    public int trap(int[] height) {
        int maxWater = 0, water = 0;
        int l = 0, r = height.length - 1;
        int leftMax = height[l], rightMax = height[r];

        while (l < r){
            if (leftMax < rightMax){
                leftMax = Math.max(leftMax, height[l + 1]);
                water = leftMax - height[l + 1];
                l += 1;
            } else {
                rightMax = Math.max(rightMax, height[r - 1]);
                water = rightMax - height[r - 1];
                r -= 1;
            }
            maxWater += water;
        }
        return maxWater;
    }
}
