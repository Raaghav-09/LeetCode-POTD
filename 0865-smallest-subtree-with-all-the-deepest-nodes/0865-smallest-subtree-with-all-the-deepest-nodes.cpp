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
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        if(!root) return nullptr ; 
        map<int, vector<TreeNode*> > mp ; 
        map<TreeNode*,TreeNode*> parent ;

        function<void(TreeNode*, int)> dfs = [&](TreeNode* node, int level) {

            mp[level].push_back(node) ;

            if(node->left){
                parent[node->left] = node ; 
                dfs(node->left , level+1) ; 
            }
            if(node->right){
                parent[node->right] = node  ; 
                dfs(node->right,level+1) ; 
            }
        }; 

        parent[root] = nullptr ;
        dfs(root,0) ; 

        auto it = mp.rbegin() ; 

        int depth = it->first ; 
        set<TreeNode*> s(it->second.begin(),it->second.end()) ; 

        while(s.size()!=1){
            set<TreeNode*> newS ; 
            for(auto node : s){

                TreeNode* p = parent[node] ; 
                newS.insert(p) ; 
            }
            s = newS ; 
        }

        return *s.begin() ; 

    }
};