const int inf = 1e9 ; 
class UnionFind{
private:
    vector<int> parent ;
    vector<int> size ; 
public:
    UnionFind(int n){
        size.assign(n,1) ; 
        parent.assign(n,0) ; 
        iota(parent.begin(),parent.end(),0) ; 
    }
    int unionParent(int node){
        if(parent[node] == node) return node ; 
        return parent[node] = unionParent(parent[node]) ; 
    }
    void unite(int u , int v){
        u = unionParent(u) , v = unionParent(v) ;
        if(u != v){
            if(size[u] > size[v]) swap(u,v) ; 
            // size[u] <= size[v]
            parent[u] = v ;
            size[v] += size[u] ;   
        }
    }
};

class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        // UnionFind dsu(n) ; 
        // for(auto& road : roads){
        //     int u = road[0] , v = road[1] ; 
        //     u-- , v-- ; 
        //     dsu.unite(u,v) ; 
        // }   
        // int ans = 1e9 ; 
        // int par = dsu.unionParent(0) ; 
        // for(auto& road : roads){
        //     int u = road[0] , v = road[1] , w = road[2] ; 
        //     u-- , v-- ; 
        //     if(par == dsu.unionParent(u)){
        //         ans = min(ans,w) ; 
        //     }
        // }

        // return ans ; 

        vector<vector<pair<int,int>>> adj(n) ; 
        for(auto road : roads){
            int u = road[0] , v = road[1] , w = road[2] ; 
            u-- , v-- ; 
            adj[u].push_back(make_pair(v,w)) ; 
            adj[v].push_back(make_pair(u,w)) ; 
        }

        int mn = 1e9 ; 
        vector<int> visited(n,0) ; 
        auto dfs = [&](auto&& dfs , int node) -> void{
            visited[node] = 1 ; 
            for(auto& [adjNode,weight] : adj[node]){
                mn = min(weight,mn) ; 
                if(!visited[adjNode]){
                    dfs(dfs,adjNode) ; 
                }
            }
        };

        dfs(dfs,0) ;
        return mn ; 
    }
};