class UnionFind{
private:
    vector<int> parent , rank ;
public :
    int noc ; 
    UnionFind(int n){
        parent.assign(n,0) , rank.assign(n,1) ; 
        iota(parent.begin(),parent.end(),0) ; 
        noc = n ; 
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
            noc-- ; 
            u = findSet(u) , v = findSet(v) ; 
            if(rank[u] < rank[v]) swap(u,v) ; 
            if(rank[u] == rank[v]) rank[u]++ ; 
            parent[v] = u ; 
        }
    }

};
class Solution {
public:
    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size() ; 

        auto checkIfSimilar = [&](int i , int j) -> bool{
            int sz1 = strs[i].size() , sz2 = strs[j].size() ; 
            if(sz1 != sz2) return false ; 
            int ind1 = -1 , ind2 = -1 ; 
            for(int it = 0 ; it<sz1 ; it++){
                if(strs[i][it] != strs[j][it]){
                    if(ind1 == -1){
                        ind1 = it ; 
                    }
                    else if(ind2 == -1){
                        ind2 = it ; 
                    }
                    else return false;  
                }
            }
            if(ind1 == -1 && ind2 == -1) return true ; 
            if(strs[i][ind1] == strs[j][ind2] && strs[i][ind2] == strs[j][ind1]){
                return true ; 
            }
            else return false;  
        };

        UnionFind dsu(n) ; 

        for(int i=0 ; i<n ; i++){
            for(int j=i+1 ; j<n ; j++){
                if(checkIfSimilar(i,j)){
                    dsu.unite(i,j) ; 
                }
            }
        }

        return dsu.noc ; 
    }
};