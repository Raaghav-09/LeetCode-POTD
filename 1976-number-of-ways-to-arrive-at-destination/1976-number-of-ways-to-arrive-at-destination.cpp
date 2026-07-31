class Solution {
public:
    using ll = long long; 
    const ll mod = 1e9 + 7 ; 
    int countPaths(int n, vector<vector<int>>& roads) {
        // no multiple edges
        // undirected
        // connected
        // no of ways to arrive at shortest amount of time 
        vector<vector<pair<int,int>>> adj(n) ; 
        for(auto road : roads){
            int u = road[0] , v = road[1] , w = road[2] ; 
            adj[u].push_back(make_pair(v,w)) ; 
            adj[v].push_back(make_pair(u,w)) ; 
        }
        vector<ll> cnt(n,0) ; 
        cnt[0] = 1 ; 
        vector<ll> distance(n,1e18) ; 
        distance[0] = 0 ;
        priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> pq; 
        pq.push({0,0}) ; // dist , node
        while(pq.size()){
            auto [dist,node] = pq.top() ; pq.pop() ; 

            if(distance[node] < dist) continue ; 
            for(auto& [adjNode,weight] : adj[node]){
                if(distance[adjNode] > dist + weight){
                    distance[adjNode] = dist + weight ; 
                    pq.push({distance[adjNode],adjNode}) ; 
                    cnt[adjNode] = cnt[node] ; 
                }
                else if(distance[adjNode] == dist + weight){
                    cnt[adjNode] += cnt[node] ; 
                }
                cnt[adjNode] %= mod ; 
            }
        }

        return cnt[n-1] ; 
    }
};