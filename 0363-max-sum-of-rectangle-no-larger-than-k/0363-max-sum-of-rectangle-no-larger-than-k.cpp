class Solution {
public:
    int largestPossibleNoGreaterThanK(vector<long long>& v , int k){
        int n = v.size() ; 

        set<long long> s ; 
        s.insert(0) ; 
        long long curr = 0 ; 
        long long ans = INT_MIN ; 

        for(int i=0 ; i<n ; i++){
            curr += v[i] ; 
            auto lb = s.lower_bound(curr - k ) ; 
            if(lb != s.end()){
                ans = max(ans , curr - *lb ) ; 
            }
            s.insert(curr) ; 
        }

        return (int)ans ; 
    }
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int n = matrix.size() , m = matrix[0].size() ; 

        vector<vector<long long>> dp(n,vector<long long>(m,0)) ; 
        for(int i=0 ; i<n ; i++){
            dp[i][0] = matrix[i][0] ; 
            for(int j=1 ; j<m ; j++){
                dp[i][j] = dp[i][j-1] + matrix[i][j] ; 
            }
        }
        int ans = INT_MIN ; 
        for(int left = 0 ; left<m ; left++){
            for(int right = left ; right<m ; right++){
                vector<long long> v(n,0) ; 
                for(int i=0 ; i<n ; i++){
                    v[i] = dp[i][right] ; 
                    if(left!=0) v[i] -= dp[i][left-1] ; 
                }
                int candidate = largestPossibleNoGreaterThanK(v,k) ; 
                ans = max(ans,candidate) ; 
            }
        }

        return ans ; 
    }
};