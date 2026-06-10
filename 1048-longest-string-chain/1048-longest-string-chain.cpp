class Solution {
public:
    bool compare(string& a , string& b){
        if(a.size() != 1+b.size()) return false ;
        int n = a.size() ; 
        int i = 0 , j = 0 ; 
        while(i<n && j<n-1){
            if(a[i] == b[j]){
                i++ , j++ ; 
            }
            else{
                i++ ;
            }
        } 
        if(j==n-1) return true ; 
        else return false ; 
    }

    int longestStrChain(vector<string>& words) {
        int n = words.size() ; 
        sort(words.begin(),words.end(),[](string& a, string& b){
            return a.size() < b.size() ; 
        }) ; 

        vector<int> dp(n,1) ; 
        int maxi = 1 ; 
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<i ; j++){
                if(compare(words[i],words[j]) && dp[i] < 1+dp[j]){
                    dp[i] = 1 + dp[j] ; 
                }
            }
            maxi = max(maxi,dp[i]) ; 
        }
        return maxi ; 
    }
};