class Solution {
public:
    #define ll long long
    const ll mod = 1e9 + 7 ; 
    int specialTriplets(vector<int>& nums) {
        int n = nums.size() ; 
        // map<int,vector<int>> m ; 
        // for(int i=0 ; i<n ; i++){
        //     m[nums[i]].push_back(i) ; 
        // }
        // long long ans = 0 ; 
        // // if(m.find(0)!=m.end()){
            
        // // }
        // // vector<int> visited(n,0) ; 
        // for(int i=0 ; i<n ; i++){
        //     if(m[nums[i]].size()==1 || nums[i]%2==1){
        //         continue ; 
        //     }
        //     vector<int> v = m[nums[i]] ; 
        //     int sz = v.size() ; 
        //     int target = nums[i]/2 ; 
        //     if(m.find(target)==m.end()) continue ; 

        //     int l = i ;
        //     for(int j=1 ; j<sz ; j++){
        //         int r = v[j] ; 
        //         int f1 = lower_bound(v.begin(),v.end(),l) - v.begin() ; 
        //         int f2 = upper_bound(v.begin(),v.end(),r) - v.begin() ; 

        //         ans += f2 - f1 ; 
        //         ans %= mod ; 
        //     }
        // }

        // return (int)ans ; 
        map<ll,ll> left , right ; 
        for(int x : nums){
            right[x]++ ; 
        }
        ll ans = 0 ; 
        for(int x : nums){
            right[x]-- ; 
            ll target = 2*x ; 
            ll leftcnt = left[target] ; 
            ll rightcnt = right[target] ; 
            ans += leftcnt * rightcnt ; 
            ans %= mod ; 
            left[x]++ ; 
        }
        ans = (int)ans ; 
        return ans ; 
    }
};