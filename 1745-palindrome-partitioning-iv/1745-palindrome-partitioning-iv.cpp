class Solution {
public:
    bool isPalindrome(string& s , int i , int j){
        while(i<=j){
            if(s[i] == s[j]){
                i++ , j-- ; 
            }
            else return false ; 
        }
        return true ; 
    }
    int dp[2005][4] ; 
    bool checkPartitioning(string s) {
        int n = s.size() ; 

        auto f = [&](auto&& f , int idx , int parts) -> bool{
            if(parts == 0 && idx == n) return true ; 
            if(parts == 0 || idx == n) return false ; 
            if(dp[idx][parts] != -1) return dp[idx][parts] ; 
            bool ans = false; 

            for(int i=idx ; i<n ; i++){
                if(isPalindrome(s,idx,i)){
                    ans = ans | f(f,i+1,parts-1) ; 
                }
            }

            return dp[idx][parts] = ans ; 
        };
        memset(dp,-1,sizeof(dp)) ; 
        return f(f,0,3) ; 
    }
};