class Solution {
public:
    using ll = long long ; 
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        int n = asteroids.size() ; 

        sort(asteroids.begin(),asteroids.end()) ; 
        ll curr = mass ; 

        for(int i=0 ; i<n ; i++){
            if(curr < asteroids[i]){
                return false ; 
            }
            curr += asteroids[i] ; 
        }

        return true ; 
    }
};