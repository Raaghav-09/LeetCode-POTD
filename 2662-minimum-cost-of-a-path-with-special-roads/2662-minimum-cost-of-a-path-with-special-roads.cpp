class Solution {
public:
    int minimumCost(vector<int>& start, vector<int>& target, vector<vector<int>>& specialRoads) {
        int sx = start[0], sy = start[1], tx = target[0], ty = target[1];
        map<pair<int, int>, int> dist; 
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq; 
        
        pq.push({0, sx, sy});
        dist[{sx, sy}] = 0;
        
        int ans = abs(sx - tx) + abs(sy - ty); 
        
        while (!pq.empty()) {
            auto t = pq.top(); 
            pq.pop();
            
            int d = t[0], x = t[1], y = t[2];
            
            if(d > dist[{x, y}]) continue;
            
            ans = min(ans, d + abs(tx - x) + abs(ty - y));
            
            for (auto& road : specialRoads) {
                int x1 = road[0], y1 = road[1], x2 = road[2], y2 = road[3], cost = road[4];
                
                int walkToStart = abs(x - x1) + abs(y - y1);
                int totalCostToEndpoint = d + walkToStart + cost;
                
                if(dist.find({x2, y2}) == dist.end() || totalCostToEndpoint < dist[{x2, y2}]){
                    dist[{x2, y2}] = totalCostToEndpoint;
                    pq.push({totalCostToEndpoint, x2, y2});
                }
            }
        }
        
        return ans;     
    }
};