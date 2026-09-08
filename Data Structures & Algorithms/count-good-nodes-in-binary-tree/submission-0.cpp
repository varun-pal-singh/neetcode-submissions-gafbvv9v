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
    int cntGoodNodes(TreeNode *root, int maxVal) {
        if (root == nullptr)    return 0;
        int sum = 0;
        if (root->val >= maxVal) {
            maxVal = root->val;
            sum++;
        }
        sum += cntGoodNodes(root->left, maxVal);
        sum += cntGoodNodes(root->right, maxVal);
        return sum;
    }

public:
    int goodNodes(TreeNode* root) {
        if (root == nullptr)    return 0;
        return cntGoodNodes(root, root->val);
    }
};
