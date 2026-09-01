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
    TreeNode* pruneTree(TreeNode* root) {
        auto f = [&](auto&& f , TreeNode* node) -> bool{
            if(node == NULL) return false ; 
            // if(node->val == 1) return true; 

            bool lp = f(f,node->left) ; 
            bool rp = f(f,node->right) ; 

            if(lp == false) node->left = NULL ; 
            if(rp == false) node->right = NULL ; 

            // if(lp == false && rp == false) return false ;
            // else return true ; 
            return node->val == 1 || lp || rp;
        };

        bool flag = f(f,root) ; 
        if(flag) return root ; 
        return NULL ; 
    }
};