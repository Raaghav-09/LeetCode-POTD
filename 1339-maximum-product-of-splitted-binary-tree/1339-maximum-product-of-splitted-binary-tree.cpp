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
    const int mod = 1e9 + 7 ; 
    void inorder(TreeNode* root , long long& sum){
        if(root==NULL) return ;
        if(root->left) inorder(root->left , sum) ;  
        sum += root->val ; 
        if(root->right) inorder(root->right,sum) ; 
    }

    void dfs(TreeNode* root , long long& ans , long long& sum){
        if(!root->left && !root->right){
            ans = max(ans,( ((sum-root->val)*(root->val))) ) ; 
            return ; 
        }
        if(root->left){
            dfs(root->left,ans , sum) ; 
            root->val += root->left->val ; 
        }
        if(root->right){
            dfs(root->right,ans,sum) ; 
            root->val += root->right->val ; 
        }
        ans = max(ans,( ((sum-root->val)*(root->val))) ) ; 
    }

    int maxProduct(TreeNode* root) {
        long long sum = 0 ; 
        inorder(root,sum) ; 

        long long ans = 0 ; 
        dfs(root,ans,sum) ; 
        return ans%mod ; 
    }
};