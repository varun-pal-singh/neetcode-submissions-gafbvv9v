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
    vector<int> rightSideView(TreeNode* root) {
        if (root == nullptr)   
            return vector<int>();
        
        vector<int> res;
        queue<TreeNode*> que;
        que.push(root);
        while (!que.empty()) {
            int size = que.size();
            bool flag = false;
            while (size--) {
                TreeNode* cur = que.front();
                que.pop();

                if (!flag) {
                    res.push_back(cur->val);
                    flag = true;
                }

                if (cur->right) {
                    que.push(cur->right);
                }

                if (cur->left) {
                    que.push(cur->left);
                }
            }
        }

        return res;
    }
};
