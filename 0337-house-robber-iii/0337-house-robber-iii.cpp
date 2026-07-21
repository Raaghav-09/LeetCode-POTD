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
    int rob(TreeNode* root){
        map<TreeNode*,pair<int,int>> mp ; // {takke , not take}
        auto dfs = [&](auto&& dfs , TreeNode* node)->void{
            if(node == NULL) return ; 
            dfs(dfs,node->left) ; 
            dfs(dfs,node->right) ; 
            int takel = 0 , nottakel = 0 , taker = 0 , nottaker = 0 ; 
            if(node->left){
                takel = mp[node->left].first ; 
                nottakel = mp[node->left].second ; 
            }
            if(node->right){
                taker = mp[node->right].first ; 
                nottaker = mp[node->right].second ;
            }

            mp[node].first = nottakel + nottaker + node->val ; 
            mp[node].second = max(takel,nottakel) + max(taker,nottaker) ; 
        };

        dfs(dfs,root) ; 

        return max(mp[root].first ,mp[root].second) ; 
    }
};