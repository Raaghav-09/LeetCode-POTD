class Solution {
public:
    const int mod = 1e9 + 7 ;
    int concatenatedBinary(int n) {
        long long ans = 0 ; 
        long long mul = 1 ; 
        for(int i=n ; i>=1 ; i--){
            ans += i*mul ; 
            ans %= mod ; 
            int temp = i ; 
            while(temp){
                mul*=2 ; 
                mul %= mod ; 
                temp/=2 ;
            }
        }
        return ans ; 
    }
};