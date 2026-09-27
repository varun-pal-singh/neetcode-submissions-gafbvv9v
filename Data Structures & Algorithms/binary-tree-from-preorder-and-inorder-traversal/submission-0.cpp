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
    TreeNode* build(
        std::vector<int> &preorder, std::unordered_map<int32_t, int32_t> &umap, 
        int32_t i, int32_t start_idx, int32_t end_idx) 
        {
            if (start_idx > end_idx) 
                return nullptr;
            
            int32_t val = preorder[i];
            TreeNode *root = new TreeNode(val);
            int32_t idx_inorder = umap[val];
            int32_t left_side = idx_inorder - start_idx;
                     
            root->left  = build(preorder, umap, i + 1, start_idx, idx_inorder - 1);
            root->right = build(preorder, umap, i + left_side + 1, idx_inorder + 1, end_idx);

            return root;
        }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int32_t n = preorder.size(), n2 = inorder.size();
        if (n != n2)    
            return nullptr;

        std::unordered_map<int32_t, int32_t> umap;
        for (int32_t i = 0; i < n; i++) {
            umap[inorder[i]] = i;   // umap[val] = idx
        }
        int32_t i = 0;
        return build(preorder, umap, i, 0, n - 1);
    }
};
