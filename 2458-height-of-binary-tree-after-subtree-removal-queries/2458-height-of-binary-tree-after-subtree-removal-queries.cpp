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
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        
        map<TreeNode*,int> levels , height ; 
        map<int,TreeNode*> value_map ; 

        auto dfs = [&](auto&& dfs , TreeNode* node , int lvl) -> void{
            if(node == NULL) return ; 
            levels[node] = lvl ; 
            value_map[node->val] = node ; 
            dfs(dfs,node->left,lvl+1) ; 
            dfs(dfs,node->right,lvl+1) ;

            int h = 0 ; 
            if(node->left){
                h = max(h,height[node->left]) ; 
            }
            if(node->right){
                h = max(h,height[node->right]) ; 
            }
            h++ ; 
            height[node] = h ; 
        };

        dfs(dfs,root,0) ; 
        vector<vector<pair<int,TreeNode*>>> level(height[root]) ; 

        for(auto [node,lvl] : levels){
            level[lvl].push_back(make_pair(height[node],node)) ; 
        }

        for(auto& v : level){
            sort(v.begin(),v.end()) ; 
            reverse(v.begin(),v.end()) ; 
        }
        vector<int> res ; 
        for(auto query : queries){
            TreeNode* node = value_map[query] ; 
            int lvl = levels[node] ; 

            if(level[lvl][0].second == node){
                if(level[lvl].size() == 1){
                    res.push_back(lvl-1) ; 
                }
                else res.push_back(level[lvl][1].first+lvl-1) ; 
            }
            else{
                res.push_back(level[lvl][0].first+lvl-1) ; 
            }
        }

        return res ; 
    }
};