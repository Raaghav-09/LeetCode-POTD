class Solution {
public:
    using ll = long long ; 
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size() ; 
        /*
        xi , ri => xi+ri <= x[i+1]

        */

        // sort(bombs.begin(),bombs.end()) ; 
        // int ans = 1 ; 
        // for(int i=0 ; i<n ; i++){
        //     // int j=i+1 , k=i-1 ; 
        //     int latest = i ; 
        //     // right 
        //     int cnt = 1 ; 
        //     for(int j=i+1 ; j<n ; j++){
        //         ll x = abs(bombs[latest][0] - bombs[j][0]) ; 
        //         ll y = abs(bombs[latest][0] - bombs[j][0]) ; 
        //         ll dis = x*x + y*y ; 

        //         if(dis <= bombs[latest][2]*bombs[latest][2]){
        //             cnt++ ; 
        //         }
        //     }
        // }
        vector<vector<int>> adj(n) ; 
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<n ; j++){
                if(i == j) continue ; 
                ll x = abs(bombs[i][0] - bombs[j][0]) ; 
                ll y = abs(bombs[i][1] - bombs[j][1]) ; 
                ll dis = x*x + y*y ; 

                if(dis <= 1LL*bombs[i][2]*bombs[i][2]){
                    adj[i].push_back(j) ; 
                }
            }
        }

        

        int ans = 1 ; 
        for(int i=0 ; i<n ; i++){
            vector<int> vis(n,0) ; 
            int count = 0 ; 
            auto f = [&](auto&& f , int node) -> void{
                vis[node] = 1 ;  
                count++ ; 
                for(int adjNode : adj[node]){
                    if(vis[adjNode] == 0){
                        f(f,adjNode) ; 
                    }
                }
            };

            f(f,i) ; 

            ans = max(ans,count) ; 
        }

        
        return ans ; 
    }
};