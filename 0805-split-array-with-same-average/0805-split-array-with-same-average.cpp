class Solution {
public:
    bool splitArraySameAverage(vector<int>& nums) {
        int n = nums.size() ; 
        if(n <= 1) return false;
        int sum = accumulate(nums.begin(),nums.end(),0) ; 
        int n1 = n/2 ; 
        int n2 = n-n1 ; 

        map<int,unordered_set<int>> mp1 , mp2 ; 
        for(int mask = 0 ; mask<(1<<n1) ; mask++){
            int s = 0 ; 
            int bit = 0 ; 
            for(int i=0 ; i<n1 ; i++){
                if((mask & 1<<i) != 0){
                    s += nums[i] ; 
                    bit++ ; 
                }
            }
            mp1[bit].insert(s) ; 
            int s2 = sum - s ; 
            int len2 = n - bit ; 
            if(bit > 0 && len2 * s == s2 * bit){
                return true ; 
            }
        }

        for(int mask = 0 ; mask<(1<<n2) ; mask++){
            int s = 0 ; 
            int bit = 0 ; 
            for(int i=0 ; i<n2 ; i++){
                if((mask & (1<<i)) != 0){
                    s += nums[i+n1] ; 
                    bit++ ; 
                }
            }
            mp2[bit].insert(s*n) ; 
            int s2 = sum - s ; 
            int len2 = n - bit ; 
            if(bit > 0 && len2 * s == s2 * bit){
                return true ; 
            }
        }
        /*
        int array1 => m1 => sum1
        int array2 => m2 => sum2

        sum1 * m2 = (sum - sum1) * m1
        sum1 * (m2) = sum * m1 - sum1 * m1
        sum1 * (n) = sum * m1 

        (s1 + s2)* n = sum * m1
        s2 * n = sum * m1 - s1 * n 

        */

        for(auto& [bit,v] : mp1){
            for(int sz = 0 ; sz <= n2 ; sz++){
                int bits = bit + sz ; 

                if(bits == 0 || bits == n) continue ;

                for(auto ele : v){
                    int target = sum * bits - ele*n ; 
                    if(mp2[sz].find(target) != mp2[sz].end()){
                        return true ; 
                    }
                }
            }
        }

        return false ; 
    }
};