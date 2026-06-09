class Solution {
public:
    // bool count(string& s , int i , int j , int k){
    //     if((j-i+1) < k) return false ; 
    //     while(i<=j){
    //         if(s[i] == s[j]){
    //             i++ , j-- ;
    //         }
    //         else return false ; 
    //     }
    //     return true ; 
    // }

    bool check(string& s , int i , int j){
        while(i<=j){
            if(s[i] == s[j]){
                i++ , j-- ;
            }
            else return false ; 
        }
        return true ; 
    }
    int dp[2005];
    bool isPalindrome[2002][2002] ;
    int maxPalindromes(string s, int k) {
        int n = s.size() ; 

        // auto f = [&](auto&& f , int idx) -> int{
        //     if(idx == n) return 0 ;
        //     if(dp[idx] != -1) return dp[idx]; 
        //     int res = 0 ; 
        //     for(int i=idx ; i<n ; i++){
        //         int val = count(s,idx,i,k) + f(f,i+1) ; 
        //         res = max(res,val) ; 
        //     }
        //     return dp[idx] = res ; 
        // };

        // memset(dp,-1,sizeof(dp)) ; 
        // return f(f,0) ; 
        memset(isPalindrome,false,sizeof(isPalindrome)) ;

        for (int i = n - 1; i >= 0; i--) {
            isPalindrome[i][i] = true;
            for (int j = i + 1; j < n; j++) {
                if (s[i] == s[j]) {
                    if (j - i == 1) isPalindrome[i][j] = true;
                    else isPalindrome[i][j] = isPalindrome[i + 1][j - 1];
                }
            }
        }

        memset(dp,0,sizeof(dp)) ; 
        for(int i=n-1 ; i>=0 ; i--){
            for(int j=i ; j<n ; j++){
                if((j-i+1) < k) dp[i] = max(dp[i] , dp[i+1]) ; 
                else dp[i] = max(dp[i] , isPalindrome[i][j] + dp[j+1] ) ; 
            }
        }

        return dp[0] ;
    }
};