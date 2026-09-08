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
    struct State {
        TreeNode* node;
        long leftLimit;
        long rightLimit;
    };

public:
    bool isValidBST(TreeNode* root) {
        if (!root)  return true;
        deque<State> deq;
        deq.push_back({root, LONG_MIN, LONG_MAX});

        while (!deq.empty()) {
            int size = deq.size();
            while (size--) {
                auto [cur, left, right] = deq.front(); deq.pop_front();

                if (left >= cur->val || cur->val >= right) {
                    return false;
                }

                if (cur->left) {
                    deq.push_back({cur->left, left, cur->val});
                }

                if (cur->right) {
                    deq.push_back({cur->right, cur->val, right});
                }

            }
        }

        return true;
    }
};
