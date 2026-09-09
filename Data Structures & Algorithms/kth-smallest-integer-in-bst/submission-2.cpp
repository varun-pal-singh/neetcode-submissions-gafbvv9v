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
    void dfs(TreeNode *root, pair<int, int> &pr) {
        if (!root)
            return;
        
        dfs(root->left, pr);
        // if (pr.first == 0)
        //     return;
        
        pr.first --;
        if (pr.first == 0) {
            pr.second = root->val;
            return;
        }

        dfs(root->right, pr);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        pair<int, int> pr = {k, -1};
        dfs(root, pr);
        
        return pr.second;
    }
};
