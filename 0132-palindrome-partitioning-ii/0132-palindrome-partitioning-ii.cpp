class Solution {
public:
    bool isPalindrome(string& s){
        int i = 0 , j = s.size() -1 ; 
        while(i<=j){
            if(s[i] == s[j]){
                i++ , j-- ; 
            }
            else return false ;
        }
        return true ; 
    }
    int dp[2005] ; 
    int minCut(string s) {
        int n = s.size() ;  

        // dp[i][j] = minimum cuts to make i to j palindromic
        // dp[i][j] = 1 + min( dp[i][k] + dp[k+1][j] )

        auto f = [&](auto&& f , int idx ) -> int{
            if(idx == n) return 0 ; 
            if(dp[idx] != -1) return dp[idx] ; 
            string temp = "" ; 
            int res = n ; 
            for(int p = idx ; p<n ; p++){
                temp += s[p] ; 
                if(isPalindrome(temp)){
                    res = min(res , 1 + f(f,p+1)) ; 
                }
            }

            return dp[idx] = res ; 
        };
        memset(dp,-1,sizeof(dp)) ; 
        return f(f,0) - 1 ; 
    }
};