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
        vector<int> res;
        if (root == nullptr) {
            return res;
        }
        stack<TreeNode*> stk;
        TreeNode* cur = root;
        
        while (!stk.empty() || cur != nullptr) {
            if (cur == nullptr) {
                cur = stk.top();
                stk.pop();
                res.push_back(cur->val);
                cur = cur->right;
            } else {
                stk.push(cur);
                cur = cur->left;
            }
        }

        return res;
    }
};