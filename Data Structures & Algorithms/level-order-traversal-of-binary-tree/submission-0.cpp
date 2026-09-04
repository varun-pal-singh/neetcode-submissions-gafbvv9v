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
    vector<vector<int>> levelOrder(TreeNode* root) {
        deque<TreeNode*> deq;
        vector<vector<int>> res;
        if (root == nullptr)    return res;

        deq.push_back(root);

        while (!deq.empty()) {
            int size = deq.size();
            vector<int> sub;
            while (size--) {
                TreeNode* cur = deq.front();
                deq.pop_front();
                sub.push_back(cur->val);
                if (cur->left) {
                    deq.push_back(cur->left);
                }
                if (cur->right) {
                    deq.push_back(cur->right);
                }
            }
            res.push_back(sub);
        }

        return res;
    }
};
