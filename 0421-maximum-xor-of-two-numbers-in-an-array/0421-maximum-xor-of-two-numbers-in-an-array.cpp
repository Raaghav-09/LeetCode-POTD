class Solution {
public:
    string f(int num){
        string s = ""; 
        while(num){
            s += num%2 + '0' ; 
            num/=2 ; 
        }
        reverse(s.begin(),s.end()) ; 
        return s ; 
    }
    int findMaximumXOR(vector<int>& nums) {
        // int n = nums.size() ; 
        // vector<vector<int>> v(n,vector<int>(32,0)) ; 

        // sort(nums.begin() , nums.end()) ; 

        // for(int i=0 ; i<n ; i++){
        //     string s = f(nums[i]) ; 
        //     int j = s.size() - 1 ; 
        //     int jj = 31 ; 
        //     while(j>=0){
        //         v[i][jj] = s[j] - '0' ; 
        //         j-- ; 
        //         jj-- ; 
        //     }
        // }
        int n = nums.size() ; 
        int max_yet = 0 ; 
        int mask = 0 ; 
        for(int i=31 ; i>=0 ; i--){

            mask |= 1 << i ; 
            set<int> s ; 
            for(int j=0 ; j<n ; j++){
                s.insert(mask & nums[j]) ; 
            }

            int tryy = max_yet | 1 << i ; 

            for(int num : s){
                if(s.find(num ^ tryy) != s.end()){
                    max_yet = tryy ; 
                    break ; 
                }
            }

        }

        return max_yet ; 
    }
};