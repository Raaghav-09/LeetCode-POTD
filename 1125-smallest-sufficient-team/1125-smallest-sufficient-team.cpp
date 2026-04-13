class Solution {
public:
    vector<int> smallestSufficientTeam(vector<string>& rs, vector<vector<string>>& people) {
        int n = rs.size() , m = people.size() ; 
        map<string,int> mp ; 
        for(int i=0 ; i<n ; i++){
            mp[rs[i]] = i ; 
        }
        // vector<vector<int>> dp(m+1,vector<int>(1 << n , -1)) ; 
        // auto f = [&](int ind , int mask , auto&& f) -> int{
        //     if(mask == (1 << n) - 1) return 0 ; 
        //     if(ind == m) return 1e9 ; 
        //     if(dp[ind][mask] != -1) return dp[ind][mask] ; 
        //     int newmask = mask ; 
        //     for(auto ele : people[ind]){
        //         if(mp.find(ele) == mp.end()) continue ; 
        //         int idx = mp[ele] ; 
        //         newmask = newmask | (1<<idx) ; 
        //     }
        //     int take = 1e9 ; 
        //     if(mask != newmask) take = 1 + f(ind+1,newmask , f) ; 
        //     int notTake = f(ind+1,mask , f) ; 

        //     return dp[ind][mask] = min(take,notTake) ; 
        // };
        // int sz = f(0,0,f) ; 
        // I have to pick sz people such that their mask = (1<<n) - 1
        // people size = 60 , 2^16 vectors in wrost case , lets say each of size 60 
        // 64k * 60 = 4 * 10^6 => Can be allocated in one second 

        vector<vector<int>> dp(m+1,vector<int>(1 << n , 1e9)) ;  
        vector<int> ans ; 
        
        // Passing by value copies the array every recursion and causes a Time Limit Exceeded (TLE).
        // We also change the return type to void, since we are just updating the global 'ans'.
        auto ff = [&](int ind , int mask , vector<int>& v , auto&& ff) -> void{
            if(mask == (1 << n) - 1){
                if(ans.size() == 0 || (ans.size() > v.size())){
                    ans = v ; 
                }
                return ; 
            }
            if(ind == m) return ; 
            
            if(ans.size()!=0 && v.size()>= ans.size()) return;
            if(dp[ind][mask] <= v.size()) return ; 
            dp[ind][mask] = v.size() ; 

            int newmask = mask ; 
            for(auto ele : people[ind]){
                if(mp.find(ele) == mp.end()) continue ; 
                int idx = mp[ele] ; 
                newmask = newmask | (1<<idx) ; 
            }

            if(mask != newmask){
                v.push_back(ind) ; 
                ff(ind+1,newmask,v,ff) ; 
                v.pop_back() ; 
            }

            ff(ind+1,mask,v,ff) ; 
        };
        
        vector<int> v ; 
        ff(0,0,v,ff) ; 
        return ans ; 
    }
};