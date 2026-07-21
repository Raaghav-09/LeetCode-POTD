class Solution {
public:
    int numTrees(int n) {
        auto f = [&](auto&& f, int low, int high)->int{
            if(low >= high) return 1 ; 

            int ways = 0 ; 
            for(int i=low ; i<=high ; i++){
                ways += f(f,low,i-1)*f(f,i+1,high) ; 
            }

            return ways ; 
        };
        return f(f,1,n) ; 
        // vector<int>dp(n+2,0);
        // dp[0] = dp[1] = 1;
        // for(int i=1;i<=n,i++){
        //     for(int j=0;j<i;j++){

        //     }
        // }
    }
};