class Solution {
public:
    int minCut(string s) {
        int n = s.size() ; 
        vector<vector<int>> isPal(n,vector<int>(n,-1)) ; 
        auto isPalindrome = [&](int ind1 , int ind2 , auto&& self) -> int{
            if(isPal[ind1][ind2] != -1) return isPal[ind1][ind2] ; 
            if(ind1 > ind2) return isPal[ind1][ind2] = true  ; 
            if(ind1 == ind2) return isPal[ind1][ind2] = true ; 
            if(ind1 == ind2-1 && s[ind1] == s[ind2]) return isPal[ind1][ind2] = true ; 
            if(s[ind1] == s[ind2]){
                return isPal[ind1][ind2] = self(ind1+1,ind2-1,self) ; 
            }
            else return isPal[ind1][ind2] = false ; 
        };

        for(int i=0 ; i<n ; i++){
            for(int j=i ; j<n ; j++){
                isPalindrome(i,j,isPalindrome) ; 
            }
        }
        vector<int> dp(n,-1) ; 
        auto f = [&](int ind,auto&& self) -> int{
            if(ind == n) return 0 ; 
            if(dp[ind] != -1) return dp[ind] ; 
            int answer = INT_MAX ; 
            for(int i = ind ; i<n ; i++){
                if(isPal[ind][i]){
                    int res = self(i+1,self) ;
                    answer = min(answer , 1 + res) ; 
                }
            }
            return dp[ind] = answer ; 
        };

        return f(0,f)-1 ; 
    }
};