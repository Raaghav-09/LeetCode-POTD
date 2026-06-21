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
// class Solution {
// public:
//     int minCameraCover(TreeNode* root){
//         auto dfs = [&](auto&& dfs , TreeNode* node) -> pair<int,int>{
//             if(node->left == NULL && node->right == NULL){
//                 return {1e9,1} ; 
//             }

//             pair<int,int> p1 = {1e9 , 1e9} ;
//             pair<int,int> p2 = {1e9 , 1e9} ;
//             pair<int,int> ans ; 
//             ans.second = 1 ; 

//             if(node->left != NULL){
//                 p1 = dfs(dfs,node->left) ; 
//                 ans.second += p1.first ; 
//             }
            
//             if(node->right != NULL){
//                 p2 = dfs(dfs,node->right) ; 
//                 ans.second += p2.first ; 
//             }        
//             if(node->left && node->right){
//                 ans.first = min({p1.second + p2.first , p1.second + p2.second , p1.first + p2.second}) ;  
//             }
//             else if(node->left){
//                 ans.first = p1.second ; 
//             }
//             else if(node->right){
//                 ans.first = p2.second ; 
//             }

//             return ans ; 
//         };
//         pair<int,int> ans = dfs(dfs,root) ; 
//         return min(ans.first , ans.second) ; 
//     }
// };
class Solution {
public:
    int minCameraCover(TreeNode* root){
        auto dfs = [&](auto&& dfs, TreeNode* node) -> vector<int> {
            if(node == NULL){
                return {99999, 0, 0}; 
            }

            vector<int> p1 = dfs(dfs, node->left);
            vector<int> p2 = dfs(dfs, node->right);

            int s0 = 1 + min({p1[0], p1[1], p1[2]}) + min({p2[0], p2[1], p2[2]});
            int s1 = min(p1[0] + min(p2[0], p2[1]), p2[0] + min(p1[0], p1[1]));
            int s2 = p1[1] + p2[1];

            return {s0, s1, s2}; 
        };
        
        vector<int> ans = dfs(dfs, root);
        return min(ans[0], ans[1]); 
    }
};