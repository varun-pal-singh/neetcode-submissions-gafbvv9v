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
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if (root == nullptr)    return vector<int>();
        vector<int> res;
        do_in_order(root, res);
        return res;
    }

private:
    void do_in_order(TreeNode *root, vector<int> &res) {
        if (root == nullptr)    return;
        do_in_order(root->left, res);
        res.emplace_back(root->val);
        do_in_order(root->right, res);
    }

};