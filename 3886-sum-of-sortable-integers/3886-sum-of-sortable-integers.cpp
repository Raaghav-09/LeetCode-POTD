class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size() ; 

        // around cbrt(n) no of factors of n 
        vector<int> div ; 
        for(int i=1 ; i*i<=n ; i++){
            int d1 = i , d2 = n/i ; 
            if(n%i == 0){
                div.push_back(i) ; 
                if(d1 != d2) div.push_back(d2) ; 
            }
        }

        vector<int> sorted = nums ; 
        sort(sorted.begin() , sorted.end()) ; 
        // 10^(5*4/3) -> Good to go 
        int j = 0 ; 
        int m = div.size() ; 
        int ans = 0 ; 
        for(int i=0 ; i<m ; i++){
            int k = div[i] ; 
            bool isPossible = true ; 
            while(j<n){
                int ind = -1 ; 
                int limit = j+k ; 
                for(int i2 = j+1 ; i2<limit ; i2++){
                    if(nums[i2] < nums[i2-1]){
                        ind = i2 ; 
                    }
                }

                if(ind == -1) ind = j ; 
                int cnt = k ;
                int temp_j = j ; 
                bool flag = true ; 
                while(cnt--){
                    if(sorted[temp_j] == nums[ind]){
                        temp_j++ ;
                        ind++ ; 
                        if(ind >= limit) ind -= k ; 
                    }
                    else{
                        flag = false ; 
                        break ; 
                    }
                }
    
                if(!flag){
                    isPossible = false; 
                    break ; 
                }
                j+=k ; 
            }

            if(isPossible) ans += k ; 
            j = 0 ; 
        }

        return ans ; 
    }
};