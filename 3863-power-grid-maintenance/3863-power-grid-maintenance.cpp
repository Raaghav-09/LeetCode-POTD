class Solution {
public:
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        int n = connections.size() ; 
        int m = queries.size() ; 
        // union find i guess --> nope
        vector<vector<int>> adj(c+1) ; 
        for(int i=0 ; i<n ; i++){
            int u = connections[i][0] , v = connections[i][1] ; 
            adj[u].push_back(v) ; 
            adj[v].push_back(u) ; 
        }

        vector<int> visited(c+1,0) ;
        int cnt = 1 ; 
        for(int i=1 ; i<=c ; i++){
            if(visited[i]!=0) continue ; 
            queue<int> q ; 
            q.push(i) ; 
            visited[i] = cnt ; 
            while(q.size()){
                int node = q.front() ; 
                q.pop() ; 
                for(int nei : adj[node]){
                    if(visited[nei]==0){
                        visited[nei] = cnt ; 
                        q.push(nei) ; 
                    }
                }
            }
            cnt++ ; 
        }
        vector<set<int>> setss(cnt+1) ; 
        for(int i=1 ; i<=c ; i++){
            setss[visited[i]].insert(i) ; 
        }
        vector<int> isOnline(c+1,1) ; 
        vector<int> ans ;
        for(int i=0 ; i<m ; i++){
            int type = queries[i][0] ,node = queries[i][1] ; 
            if(type==1){
                if(isOnline[node]){
                    ans.push_back(node) ; 
                }
                else{
                    int setType = visited[node] ; 
                    if(setss[setType].size()==0) ans.push_back(-1) ; 
                    else ans.push_back(*setss[setType].begin()) ; 
                }
            }
            else{
                int node = queries[i][1] ; 
                isOnline[node] = 0 ; 
                int setType = visited[node] ; 
                setss[setType].erase(node) ; 
            }
        }
        return ans ; 
        
    }
};