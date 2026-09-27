/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    int solve(TreeNode* root, std::unordered_map<TreeNode*, std::array<int, 2>> &memo, bool canSteal) {
        if (!root) 
            return 0;
        
        int state = canSteal ? 1 : 0;

        if (memo.find(root) != memo.end()) {
            std::array<int, 2> &boolarr = memo[root];
            return boolarr[state];
        }

        int steal = 0, skip = 0;
        // option1: steal the root and skip its childern
        // if (canSteal)
            steal = root->val + solve(root->left, memo, false) + solve(root->right, memo, false);

        // option2: skip the root, to steal its childern
        // if (!canSteal)
            skip = solve(root->left, memo, true) + solve(root->right, memo, true);

        memo[root][0] = skip;
        memo[root][1] = std::max(steal, skip);

        return memo[root][state];
    }

public:
    int rob(TreeNode* root) {
        if (!root) 
            return 0;

        std::unordered_map<TreeNode*, std::array<int, 2>> memo;
        
        return solve(root, memo, true);
    }
};