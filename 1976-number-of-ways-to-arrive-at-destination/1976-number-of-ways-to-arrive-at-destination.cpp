class Solution {
public:
    using ll = long long ; 
    const ll mod = 1e9 + 7 ; 
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adj(n) ; 
        for(auto& edges : roads){
            int u = edges[0] , v = edges[1] , w = edges[2] ; 
            adj[u].push_back({v,w}) ; 
            adj[v].push_back({u,w}) ; 
        }

        vector<ll> dist(n,1e18) ; 
        vector<ll> cnt(n,1) ; 

        priority_queue<pair<ll,int> , vector<pair<ll,int>> , greater<> > pq ; 
        pq.push({0,0}) ; 
        dist[0] = 0 ; 
        cnt[0] = 1 ; 

        while(pq.size()){
            auto [dis , u] = pq.top() ; pq.pop() ; 
            
            if(dist[u] < dis) continue ; 
            for(auto [v,w] : adj[u]){
                if(dis + w < dist[v]){
                    dist[v] = dis + w ;  
                    cnt[v] = cnt[u] ; 
                    pq.push({dist[v],v}) ; 
                }
                else if(dis + w == dist[v]){
                    cnt[v] += cnt[u] ;
                    cnt[v]%= mod ; 
                }
            }
        }

        return cnt[n-1] ; 
    }
};