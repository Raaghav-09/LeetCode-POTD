class Solution {
public:
    long long count(long long n){
        return ((n)*(n+1))/2 ; 
    }
    int numSub(string s) {
        long long ans = 0 ; 
        int n = s.length() ; 
        int i = 0 ; 
        int mod = 1e9 + 7 ; 
        while(i<n){
            if(s[i]=='0'){
                i++ ; 
            }
            else{
                int cnt = 0 ; 
                while(s[i]=='1'){
                    cnt++ , i++ ; 
                }
                ans += count((long long)cnt) ; 
                ans = ans % (mod) ;
            }
        }
        return ans ; 
    }
};