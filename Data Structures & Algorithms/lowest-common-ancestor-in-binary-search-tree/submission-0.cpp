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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr || p == nullptr || q == nullptr)    
            return nullptr;
        
        if (root->val == p->val || root->val == q->val) {
            return root;
        }

        TreeNode* left  = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        // std::cout << "left->val: " << (left ? left->val : -1) 
        //           << ", right->val: " << (right ? right->val : -1) << "\n";

        if (left && right) {
            return root;
        }
        else if (!left && right) {
            return right;
        }
        else if (left && !right) {
            return left;
        }
        return nullptr;
    }
};
