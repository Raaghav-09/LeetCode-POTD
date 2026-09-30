class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size() ; 
        sort(nums.begin(),nums.end()) ; 
        // unordered_map<int,queue<int>> mp ; 
        // for(int i=n-1 ; i>=0 ; i--) mp[nums[i]].push(i) ; 

        // vector<vector<int>> ans ; 
        // for(int i=0 ; i<n ; i++){
        //     mp[nums[i]].pop() ; 
        //     if(mp[nums[i]].size() == 0) mp.erase(nums[i]) ; 
        //     for(int j=0 ; j<i ; j++){
        //         int total = - nums[i] - nums[j] ; 
        //         if(mp.count(total)){
        //             ans.push_back({nums[i],nums[j],total}) ; 
        //         }
        //     }
        // }

        // return ans ; 

        /*
        i j 
        */
        int i=0 ; 
        vector<vector<int>> ans ; 
        while(i<n-2){
            int j = i+1 , k = n-1 ;
            int target = -nums[i] ;  
            while(j<k){
                if(nums[j] + nums[k] == target){
                    ans.push_back({nums[i],nums[j],nums[k]}) ; 
                    int valj = nums[j] , valk = nums[k] ; 
                    while(j<k && nums[j] == valj) j++ ; 
                    while(k>j && nums[k] == valk) k-- ; 
                }
                else if(nums[j] + nums[k] > target){
                    k-- ; 
                }
                else{
                    j++ ; 
                }
            }

            int val = nums[i] ; 
            while(i<n-2 && nums[i] == val) i++ ; 
        }

        return ans ; 
    }
};