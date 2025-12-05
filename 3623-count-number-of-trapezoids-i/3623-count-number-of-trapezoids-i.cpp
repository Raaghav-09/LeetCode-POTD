const int mod = 1e9 + 7 ;

class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        int n = points.size() ; 
        map<int,int> mp ;
        for(int i=0 ; i<n ; i++){
            mp[points[i][1]]++ ;
        }
        vector<int> v ; 
        for(auto [p,q] : mp){
            if(q==1) continue ; 
            long long freq = (long long)((long long)(q)*(long long)(q-1))/2 ; 
            freq %= mod ; 
            v.push_back(freq) ; 
        }
        
        int sum = accumulate(v.begin(),v.end(),0) ; 
        long long ans = 0 ; 
        for(int ele : v){
            sum -= ele ; 
            sum %= mod ; 
            ele %= mod ; 
            ans += (long long)((long long)ele)*((long long)(sum)) ; 
            ans %= mod ; 
        }
        return ans ; 
    }
};