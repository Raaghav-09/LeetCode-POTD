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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q ; 
        q.push(root) ; 
        int mx = root->val ; 
        int ans = 1 , lv = 0 ; 
        while(!q.empty()){
            int sz = q.size() ; 
            int sum = 0 ; 
            while(sz--){
                TreeNode* node = q.front() ; q.pop() ; 
                sum += node->val ; 
                if(node->left) q.push(node->left) ; 
                if(node->right) q.push(node->right) ; 
            }
            lv++ ; 
            if(sum > mx){
                mx = sum ; 
                ans = lv ; 
            }
        }
        return ans ; 
    }
};