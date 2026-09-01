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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<TreeNode*,pair<int,int>> mp ; 
        mp[root] = make_pair(0,0) ;
        int lvl = 0 ; 
        auto dfs = [&](auto&& dfs , TreeNode* node) -> void{
            if(node == NULL) return ; 
            int nr = mp[node].first+1 , nc = mp[node].second ; 
            if(node->left){
                lvl = max(lvl,nr) ; 
                mp[node->left] = make_pair(nr,nc-1) ; 
                dfs(dfs,node->left) ; 
            }
            if(node->right){
                lvl = max(lvl,nr) ; 
                mp[node->right] = make_pair(nr,nc+1) ; 
                dfs(dfs,node->right) ; 
            }
        };

        dfs(dfs,root) ; 
        map<int,vector<pair<int,int>>> res ; 
        for(auto& [node,p] : mp){
            int val = node->val ; 
            int r = p.first , c = p.second ; 
            res[c].push_back({r,val}) ; 
        }

        vector<vector<int>> ans ; 
        for(auto& [c,v] : res){
            sort(v.begin(),v.end()) ; 
            vector<int> temp ; 
            for(auto [r,val] : v) temp.push_back(val) ; 
            ans.push_back(temp) ; 
        }

        return ans ; 
    }
};