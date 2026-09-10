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
    int averageOfSubtree(TreeNode* root) {
        unordered_map<TreeNode*,int> sum , count ; 
        auto dfs = [&](auto&& dfs , TreeNode* node) -> void{

            if(node == NULL) return ; 
            dfs(dfs,node->left) ; 
            dfs(dfs,node->right) ; 

            sum[node] = 0 , count[node] = 0 ; 
            if(node->left){
                sum[node] = sum[node->left] ; 
                count[node] = count[node->left] ; 
            }

            if(node->right){
                sum[node] += sum[node->right] ; 
                count[node] += count[node->right] ; 
            }

            sum[node] += node->val ; 
            count[node]++ ; 

        };

        dfs(dfs,root) ;
        int ans = 0 ; 
        for(auto [node,s] : sum){
            int val = node->val ; 
            int avg = s/count[node] ; 

            if(val == avg) ans++ ; 
        }

        return ans ; 
    }
};