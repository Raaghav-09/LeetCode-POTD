class Solution {
public:
    int totalMoney(int n) {
        int m = n/7 ; 
        int rem = n%7 ; 
        int ans = 21*m + 7*(m)*(m+1)/2 ; 
        ans += (m+1)*rem + (rem)*(rem-1)/2 ; 
        return ans ; 
    }
};