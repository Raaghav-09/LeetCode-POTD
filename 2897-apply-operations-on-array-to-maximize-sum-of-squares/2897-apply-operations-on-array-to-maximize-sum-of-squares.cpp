class Solution {
public:
    const int mod = 1e9 + 7 ; 
    int maxSum(vector<int>& nums, int k) {
        int n = nums.size() ; 

        sort(nums.begin(),nums.end()) ; 
        /*
        Logic Building :

        1.  nums[i] = nums[i] AND nums[j]
            nums[j] = nums[i] OR nums[j]

        2.  Off course OR will increase the element .
        3.       AND OR
            0 1 : 0  1
            1 1 : 1  1
            0 0 : 0  0
            Just bit transfer ho rha hai , nothing else 
        4.  Taking example : 10 , 110 , 101 , 1000
        =>      1 -> 1 
                10 -> 2
                100 -> 2
                1000 -> 1 
        5.  1111 , 
            10 -> 1 , 100 -> 1 
            110 
        6. Got the solution , let's code it 
        */

        vector<vector<int>> v(n,vector<int>(32,0)) ; 

        for(int i=0 ; i<n ; i++){
            int no = nums[i] ; 
            int j = 0 ; 
            while(no){
                int rem = no % 2 ; 
                if(rem == 1){
                    v[i][j] = 1 ; 
                }
                no >>= 1 ; 
                j++ ; 
            }
        }

        vector<int> cal(32,0) ; 

        for(int i=0 ; i<32 ; i++){
            int sum = 0 ; 
            for(int j=0 ; j<n ; j++){
                sum += v[j][i] ; 
            }
            cal[i] = sum ; 
        }

        vector<long long> res(k) ; 

        for(int i=0 ; i<k ; i++){
            long long no = 0 ; 
            for(int j=0 ; j<32 ; j++){
                if(cal[j]){
                    no |= (1<<j) ; 
                    cal[j]-- ; 
                }
            }
            res[i] = no%mod ; 
        }

        long long ans = 0 ; 
        for(long long ele : res){
            ans = (ans + ele*ele % mod) % mod ; 
        }

        return ans ; 
    }
};