class Solution {
public:
    // pair<string,string> parseIt()
    void dfs(string node , string& target , auto& mp, set<string>& visited, double val , double& res){
        if(node == target){
            res = val ; 
            return ;
        }
        visited.insert(node);
        cout << val << endl ; 
        for(auto adjNode : mp[node]){
            if(visited.count(adjNode.first)) continue ; 
            dfs(adjNode.first,target,mp,visited,val*adjNode.second,res) ; 
        }
        visited.erase(node);
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int n = values.size() ; 
        unordered_map<string,vector<pair<string,double>>> mp ; 

        for(int i=0 ; i<n ; i++){
            string u = equations[i][0] , v = equations[i][1] ; 
            double val = values[i] ; 
            double invval = 1.0/val ; 
            cout << val << " " << invval ;
            mp[v].push_back(make_pair(u,val)) ; 
            mp[u].push_back(make_pair(v,invval)) ; 
        }

        vector<double> ans ; 
        for(auto query : queries){
            string u = query[0] , v = query[1] ; 

            if(!(mp.count(u) && mp.count(v))){
                ans.push_back(-1.0) ; 
                continue ; 
            }
            if(u == v){
                ans.push_back(1.0) ; 
                continue ; 
            }
            set<string> visited ; 
            double val = 1.0 ; 
            double res = -1.0 ;
            bool found = false ;
            dfs(v,u,mp,visited,val,res) ; 
       
            ans.push_back(res) ; 
        
        }
        return ans ;
    }
};