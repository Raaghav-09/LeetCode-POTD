class Solution {
public:
    using ll = long long ; 
    long long numOfSubsequences(string s) {
        int n = s.size() ; 

        // l must be placed at the begining
        // t must be placed at the end
        // m will be place at a point where no of l (left) * no of t (right) are maximum

        vector<ll> pre(n,0) ,suff(n,0); 
        pre[0] = (s[0] == 'L') , suff[n-1] = (s[n-1] == 'T') ; 
        for(int i=1 ; i<n ; i++){
            pre[i] = pre[i-1] + (s[i] == 'L') ; 
        }
        for(int i=n-2 ; i>=0 ; i--){
            suff[i] = suff[i+1] + (s[i] == 'T') ; 
        }

        ll cand1 = 0 ; 
        for(int i=0 ; i<n ; i++){
            if(s[i] == 'C'){
                ll res = (pre[i]+1)*suff[i] ; 
                cand1 += res ; 
            }
        }
        ll cand2 = 0 ; 
        for(int i=0 ; i<n ; i++){
            if(s[i] == 'C'){
                ll res = (pre[i])*(suff[i]+1) ; 
                cand2 += res ; 
            }
        }
        ll cand3 = 0 ; 
        for(int i=0 ; i<n ; i++){
            if(s[i] == 'C'){
                ll res = (pre[i])*(suff[i]) ; 
                cand3 += res ; 
            }
        }

        ll mx = 0 ; 
        for(int i=1 ; i<n ; i++){
            ll res = pre[i-1] * suff[i] ; 
            mx = max(mx,res) ; 
        }
        cand3 += mx ; 
        ll ans = max({cand1,cand2,cand3}) ; 
        return ans ; 
    }
};