class UnionFind{
private:
    vector<int> parent , rank ;
public :
    UnionFind(int n){
        parent.assign(n,0) , rank.assign(n,1) ; 
        iota(parent.begin(),parent.end(),0) ; 
    }
    int findSet(int node){
        if(node == parent[node]) return node ; 
        return parent[node] = findSet(parent[node]) ; 
    }
    bool isSameSet(int u , int v){
        return findSet(u) == findSet(v) ;
    }
    void unite(int u , int v){
        if(!isSameSet(u,v)){
            u = findSet(u) , v = findSet(v) ; 
            if(rank[u] < rank[v]) swap(u,v) ; 
            if(rank[u] == rank[v]) rank[u]++ ; 
            parent[v] = u ; 
        }
    }
};

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size() ; 

        vector<vector<pair<int,int>>> adj(n) ; 
        vector<vector<int>> edges ; 
        for(int i=0 ; i<n ; i++){
            for(int j=i+1 ; j<n ; j++){
                int dist = abs(points[i][0]-points[j][0]) + abs(points[i][1] - points[j][1]) ; 
                adj[i].push_back({j,dist}) ; 
                adj[j].push_back({i,dist}) ; 
                edges.push_back({dist,i,j}) ; 
            }
        }

        sort(edges.begin(),edges.end()) ; 
        UnionFind dsu(n) ; 
        int ans = 0 ; 
        for(auto edge : edges){
            int w = edge[0] , u = edge[1] , v = edge[2] ; 
            if(!dsu.isSameSet(u,v)){
                dsu.unite(u,v) ; 
                ans += w ; 
            }
        }

        return ans ; 
    }
};