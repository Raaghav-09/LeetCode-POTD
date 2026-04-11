class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size() ; 
        map<int,vector<int>> mp ; 
        for(int i=0 ; i<n ; i++) mp[nums[i]].push_back(i) ; 
        int ans = -1 ; 
        for(auto [ele,v] : mp){
            if(v.size()>=3){
                vector<int> diff ; 
                for(int j=0 ; j<v.size()-1 ; j++){
                    diff.push_back(v[j+1]-v[j]) ; 
                }
                for(int j=0 ; j<diff.size()-1 ; j++){
                    if(ans==-1) ans = (diff[j]+diff[j+1])*2 ; 
                    ans = min(ans,(diff[j]+diff[j+1])*2) ; 
                }
            }
        }
        return ans ; 
    }
};