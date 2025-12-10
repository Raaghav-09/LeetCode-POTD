class Solution {
public:
    int mod = 1e9 + 7 ; 
    int countPermutations(vector<int>& com) {
        int n = com.size() ; 
        map<int,queue<int>> mp ; 
        int mn = com[0] ; 
        for(int i=0 ; i<n ; i++){
            mp[com[i]].push(i) ; 
            mn = min(mn,com[i]) ; 
        }
        //
        if((mn==com[0] && mp[com[0]].size()>1) || mn!=com[0]) return false ; 
        vector<int> fact(n+1,1) ; 
        for(int i=2 ; i<=n ; i++){
            fact[i] = (fact[i-1]*1LL*i)%mod   ; 
        }
        int ans = (int)(fact[n-1]%(mod)) ; 
        return ans ; 
    }
};