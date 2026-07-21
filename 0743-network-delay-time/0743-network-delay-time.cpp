class Solution {
public:
    using pii = pair<int,int> ;
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        int m = times.size() ; 
        k-- ; 
        vector<vector<pair<int,int>>> adj(n) ; 
        for(int i=0 ; i<m ; i++){
            int u = times[i][0] , v = times[i][1] , w = times[i][2] ; 
            u-- , v-- ; 
            adj[u].push_back(make_pair(v,w)) ; 
        }

        vector<int> dist(n,INT_MAX) ; 
        dist[k] = 0 ; 
        priority_queue<pii,vector<pii>,greater<pii>> pq ; 
        pq.push({0,k}) ; 
        while(pq.size()){
            auto [dis , node] = pq.top() ; pq.pop() ; 

            if(dis > dist[node]) continue ; 
            for(auto& [adjNode,w] : adj[node]){
                if(dist[adjNode] > dis + w){
                    dist[adjNode] = dist[node] + w ; 
                    pq.push({dist[adjNode],adjNode}) ; 
                }
            }
        }

        int mx = *max_element(dist.begin(),dist.end()) ; 
        if(mx == INT_MAX) return -1 ; 
        return mx ; 
    }
};