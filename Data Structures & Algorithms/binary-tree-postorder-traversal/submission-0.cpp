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
    vector<int> postorderTraversal(TreeNode* root) {
        if (root == nullptr)    return vector<int>();
        vector<int> res;
        do_postorder(root, res);
        return res;
    }

private:
    void do_postorder(TreeNode *root, vector<int> &res) {
        if (root == nullptr)    return;
        do_postorder(root->left, res);
        do_postorder(root->right, res);
        res.emplace_back(root->val);
    }
};