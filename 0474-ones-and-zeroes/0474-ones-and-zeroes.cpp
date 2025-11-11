class Solution {
public:
    int f(vector<pair<int,int>>& v , int i , int m , int n , vector<vector<vector<int>>>& dp , int cnt0 , int cnt1){
        int sz = v.size() ; 

        if(m<cnt0 || n<cnt1){
            return INT_MIN ; 
        }
        if(i==sz){
            if(m>=cnt0 && n>=cnt1) return 0 ; 
            else return INT_MIN ; 
        }

        if(dp[i][cnt0][cnt1]!=-1) return dp[i][cnt0][cnt1] ; 

        int take = 1+f(v,i+1,m,n,dp,cnt0+v[i].first,cnt1+v[i].second) ; 
        int notTake = f(v,i+1,m,n,dp,cnt0,cnt1) ; 

        return dp[i][cnt0][cnt1] = max(take,notTake) ; 
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        int sz = strs.size() ; 
        vector<pair<int,int>> v ; // {0,1}
        for(int i=0 ; i<sz ; i++){
            int o = 0 , z = 0 ; 
            for(char ch : strs[i]){
                if(ch=='1') o++ ; 
                else z++ ; 
            }
            v.push_back({z,o}) ; 
        }
        vector<vector<vector<int>>> dp(sz+1,vector<vector<int>>(m+1,vector<int>(n+1,-1))) ; 
        return f(v,0,m,n,dp,0,0) ; 
    }
};