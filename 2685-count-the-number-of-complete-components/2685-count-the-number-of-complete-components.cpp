class Solution {
public:
    bool helper(vector<vector<int>>& adj, vector<int>& visited , int node){
        queue<int> q ; 
        q.push(node) ; 
        visited[node] = 1 ; 
        vector<int> bfs ; 
        while(!q.empty()){
            int nodee = q.front() ; 
            bfs.push_back(nodee) ; 
            q.pop() ;
            for(int adjnode : adj[nodee]){
                if(!visited[adjnode]){
                    visited[adjnode] = 1 ; 
                    q.push(adjnode) ; 
                }
            }
        }
        int sz = bfs.size() ; 
        for(int i=0 ; i<sz ; i++){
            if(adj[bfs[i]].size()!=sz-1) return false ; 
        }
        return true ; 
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n) ; 
        for(vector<int> vec : edges){
            int u = vec[0] , v = vec[1] ; 
            adj[u].push_back(v) ; 
            adj[v].push_back(u) ; 
        }
        vector<int> visited(n,0) ; 
        int cnt = 0 ; 
        for(int i=0 ; i<n ; i++){
            if(!visited[i]){
                cnt += helper(adj,visited,i) ; 
            }
        }
        return cnt ; 
    }
};