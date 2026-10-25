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
    bool hasPathSum(TreeNode* root, int targetSum) {
        bool res = false ; 
        auto dfs = [&](auto&& dfs , TreeNode* node, int sum) -> void{
            if(res) return ; 
            if(node == nullptr) return ; 
            if(node->left == nullptr && node->right == nullptr && sum + node->val == targetSum){
                res = true ; 
                return ; 
            } 

            dfs(dfs,node->left,sum + node->val) ; 
            dfs(dfs,node->right,sum += node->val) ; 
        };

        dfs(dfs,root,0) ; 

        return res ; 
    }
};