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
    const int inf = 1e5 ; 
    int minCameraCover(TreeNode* root) {
        map<TreeNode*,pair<int,int>> mp ; 
        
        auto dfs = [&](auto&& dfs , TreeNode* node) -> vector<int>{ // {take , no camera but covered by child , no camera and uncovered}
            if(node == NULL){
                return {inf,0,0} ; 
            }

            vector<int> p1 = dfs(dfs,node->left) ; 
            vector<int> p2 = dfs(dfs,node->right) ;

            vector<int> res(3,inf) ; 
            res[0] = 1 + min({p1[0],p1[1],p1[2]}) + min({p2[0],p2[1],p2[2]}) ; 
            res[1] = min(p1[0]+min({p2[0],p2[1]}) , p2[0] + min({p1[0],p1[1]})) ; 
            res[2] = p1[1] + p2[1] ; 

            return res ; 
        };

        vector<int> ans = dfs(dfs,root) ; 

        return min(ans[0],ans[1]) ; 
    }
};