class Solution {
public:
    const int mod = 1e9 + 7 ; 
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = queries.size() ; 
        int m = s.size() ; 

        vector<int> ind1(m,-1) ;// index , newIndex => for l 
        vector<int> ind2(m,-1) ;// index , newIndex => for r
        string ns = "" ; 
        int idx = 0 ; 
        for(int i=0 ; i<m ; i++){
            if(s[i] != '0'){
                ind1[i] = idx ; 
                ind2[i] = idx ; 
                idx++ ; 
                ns += s[i] ; 
            }
        }
        // for l 
        int prev = m ; 
        for(int i=m-1 ; i>=0 ; i--){
            if(ind1[i] == -1) ind1[i] = prev ; 
            else prev = ind1[i] ; 
        }
        // for r
        prev = -1 ; 
        for(int i=0 ; i<m ; i++){
            if(ind2[i] == -1) ind2[i] = prev ; 
            else prev = ind2[i] ; 
        }
        int nm = ns.size() ; 
        vector<int> pre(nm,0) ; 
        vector<long long> pre2(nm,0) ; 
        vector<long long> powerOf10(nm+1,0) ; 
        powerOf10[0] = 1 ; 
        for(int i=1 ; i<nm ; i++){
            powerOf10[i] = powerOf10[i-1]*10 ; 
            powerOf10[i] %= mod ; 
        }
        if(nm > 0){
            pre[0] = ns[0] - '0' ; 
            for(int i=1 ; i<nm ; i++){
                pre[i] = pre[i-1] + ns[i] - '0' ; 
            }
            pre2[0] = ns[0] - '0' ; 
            long long num = pre2[0] ; 
            for(int i=1 ; i<nm ; i++){
                num = num * 10 + ns[i] - '0' ; 
                num %= mod ; 
                pre2[i] = num ; 
            }
        }

        vector<int> ans ; 
        for(auto& query : queries){
            int l = query[0] , r = query[1] ; 
            int nl = ind1[l] , nr = ind2[r] ; 

            if(nl == m || nr == -1 || nl > nr){
                ans.push_back(0) ; 
                continue ; 
            }
            int len = nr - nl + 1 ; 
            prev = (nl == 0) ? 0 : pre[nl-1] ; 
            long long prev2 = (nl == 0) ? 0 : pre2[nl-1] ; 
            long long res = pre2[nr] - (prev2 * powerOf10[len]) % mod ; 
            res %= mod ; 
            if(res < 0) res += mod ; 
            res = res * (pre[nr] - prev) ; 
            res %= mod ; 
            if(res < 0) res += mod ; 
            ans.push_back(res) ; 
        }
        return ans ;
    }
};