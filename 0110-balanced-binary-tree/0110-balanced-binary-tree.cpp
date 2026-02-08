class Solution {
public:
    int level(TreeNode* root){
        if(root==NULL) return 0 ; 
        return 1+max(level(root->left),level(root->right)) ; 
    }
    bool isBalanced(TreeNode* root) {
        bool flag = false ; 
        if(root==NULL) return true ;
        if(abs(level(root->left)-level(root->right))<=1) flag = true ; 
        return isBalanced(root->left) && isBalanced(root->right) && flag ; 
    }
};