class Solution {
public:
    int maxArea(vector<int>& heights) {
        int i = 0, j = heights.size() - 1;
        int maxWater = 0;
        while (i < j) {
            if (heights[i] < heights[j]) {
                int water = (j - i) * heights[i];
                maxWater = std::max(maxWater, water);
                i++;
            }
            else {
                int water = (j - i) * heights[j];
                maxWater = std::max(maxWater, water);
                j--;
            }
            // std::cout << maxWater << "\n";
        }
        return maxWater;
    }
};
