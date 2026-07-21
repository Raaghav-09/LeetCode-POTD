class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        int m = flights.size() ; 

        vector<vector<pair<int,int>>> adj(n) ; 
        for(int i=0 ; i<m ; i++){
            int u = flights[i][0] , v = flights[i][1] , w = flights[i][2] ; 
            adj[u].push_back({v,w}) ; 
        }

        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq ; 
        pq.push({0,0,src}) ; 
        vector<vector<int>> dist(n,vector<int>(k+5,INT_MAX)) ; 
        for(int i=0 ; i<k ; i++){
            dist[src][i] = 0 ; 
        }

        while(pq.size()){
            auto v = pq.top() ; pq.pop() ; 
            int dis = v[0] , stops = v[1] , node = v[2] ; 
            if(node == dst) return dis ; 
            if(stops > k) continue ; 
            if(dis > dist[node][stops]) continue ; 
            for(auto& [adjNode,w] : adj[node]){
                if(dist[adjNode][stops+1] > dis + w){
                    dist[adjNode][stops+1] = dis + w ; 
                    pq.push({dis+w,stops+1,adjNode}) ; 
                }
            }
        }

        return -1 ; 
    }
};