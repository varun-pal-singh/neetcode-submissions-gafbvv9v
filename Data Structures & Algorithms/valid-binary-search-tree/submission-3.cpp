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
    bool testBST(TreeNode *root, long left, long right) {
        if (!root) {
            return true;
        }

        if (left >= root->val || right <= root->val) {
            return false;
        }

        return testBST(root->left, left, root->val)
                && testBST(root->right, root->val, right);
    }

public:
    bool isValidBST(TreeNode* root) {
        return testBST(root, LONG_MIN, LONG_MAX);
    }
};
