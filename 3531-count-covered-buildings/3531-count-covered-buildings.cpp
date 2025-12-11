class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        map<int,set<pair<int,int>>> hori , ver ; 
        int m = buildings.size() ; 
        for(int i=0 ; i<m ; i++){
            vector<int> v = buildings[i] ; 
            int x = v[0] , y = v[1] ; 
            hori[x].insert({y,i}) ; 
            ver[y].insert({x,i}) ; 
        }
        for(auto& [x,s] : hori){
            s.erase(*s.begin()) ; 
            if(s.size()) s.erase(*s.rbegin()) ; 
        }

        for(auto& [y,s] : ver){
            s.erase(*s.begin()) ; 
            if(s.size()) s.erase(*s.rbegin()) ;
        }

        set<int> hori_uni , ver_uni ; 
        for(auto& [xx,s] : hori){
            for(auto [x,y] : s){
                hori_uni.insert(y) ; 
            }
        }
        for(auto& [yy,s] : ver){
            for(auto [x,y] : s){
                ver_uni.insert(y) ; 
            }
        }

        int ans = 0 ; 
        for(auto& ele : hori_uni){
            if(ver_uni.find(ele)!=ver_uni.end()){
                ans++ ; 
            }
        }

        return ans ; 
    }
};