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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!subRoot)   return true;
        if (!root)      return false;
        if (isSameTree(root, subRoot)) {
            return true;
        }
        return isSubtree(root->left, subRoot) ||
               isSubtree(root->right, subRoot);
    }

private:
    bool isSameTree(TreeNode *root0, TreeNode *root1) {
        if (root0 == nullptr && root1 == nullptr)   return true;
        if (root0 == nullptr || 
            root1 == nullptr || 
            root0->val != root1->val)   return false;
        return isSameTree(root0->left, root1->left) &&
               isSameTree(root0->right, root1->right);
    }
};
