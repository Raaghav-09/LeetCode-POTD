const int mod = 1e9 + 7 ; 
class Solution {
public:
    long long check(int a , int b , long long num){
        // a union b = a + b - a intersection b
        long long div_a = num/(long long)a ; 
        long long div_b = num/(long long)b ; 
        long long lcm = a*b/__gcd(a,b) ; 
        long long div_lcm = num/lcm ; 
        return div_a + div_b - div_lcm ; 
    }
    int nthMagicalNumber(int n, int a, int b) {
        long long low = 1 , high = 1e17 ; 
        while(low<high){
            long long mid = (low+high)/2 ; 
            long long store = check(a,b,mid) ; 
            if(store>=n) high = mid ; 
            else {
                low = mid + 1 ;
            }
        }
        return low%mod ; 
    }
};