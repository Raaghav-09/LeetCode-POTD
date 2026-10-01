/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool has(TreeNode* root , TreeNode* p){
        if(root==NULL) return false ; 
        if(root==p) return true ; 
        return has(root->left,p) || has(root->right,p) ; 
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==p || root==q) return root ; 
        else if(has(root->left,p) && has(root->right,q)) return root ; 
        else if(has(root->left,q) && has(root->right,p)) return root ; 
        else if(has(root->left,p) && has(root->left,q))return lowestCommonAncestor(root->left,p,q) ;
        else return lowestCommonAncestor(root->right,p,q) ; 
    }
};