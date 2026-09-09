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
    void inOrder(TreeNode* root, vector<int> &arr) {
        if (root == nullptr)    
            return;

        inOrder(root->left, arr);
        arr.push_back(root->val);
        inOrder(root->right, arr);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        if (root == nullptr || k <= 0)   
            return 0;
        
        vector<int> in_order;
        inOrder(root, in_order);

        int size = in_order.size();
        // std::cout << "size: " << size << "\n";

        // for (auto el : in_order) {
        //     std::cout << el << " ";
        // }

        k = k % (size + 1);

        // return -1;
        return in_order[k - 1];
    }
};
