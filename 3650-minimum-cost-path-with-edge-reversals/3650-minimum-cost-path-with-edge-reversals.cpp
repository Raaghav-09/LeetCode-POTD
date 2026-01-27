class Solution {
public:
    using pii = pair<int,int> ;
    int minCost(int n, vector<vector<int>>& edges) {
        int m = edges.size() ; 
        vector<vector<pii>> adj(n) ; 
        for(int i=0 ; i<m ; i++){
            int u = edges[i][0] , v = edges[i][1] , w = edges[i][2] ; 
            adj[u].push_back({v,w}) ; 
            adj[v].push_back({u,2*w}) ; 
        }

        priority_queue<pii , vector<pii> , greater<pii>> pq ; // min heap
        pq.push({0,0}) ; 

        vector<int> dist(n,INT_MAX) ; 
        dist[0] = 0 ; 

        while(pq.size()){
            auto [dis , node] = pq.top() ; 
            pq.pop() ; 
            if (dis != dist[node]) continue;

            for(auto [adjNode , weight] : adj[node]){
                if(dist[adjNode] > dis + weight){
                    dist[adjNode] = dis + weight ; 
                    pq.push({dis + weight , adjNode}) ; 
                }
            }
        }

        int ans = dist[n-1] ; 
        return ans == INT_MAX ? -1 : ans ; 
    }
};