class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        int n = people.size() ; 
        map<int,int> mp ; 

        for(auto& flower : flowers){
            int s = flower[0] ,e = flower[1] + 1 ; 
            mp[s]++ , mp[e]-- ; 
        }

        int curr = 0 ; 
        for(auto& [p,val] : mp){
            curr += val ; 
            mp[p] = curr ; 
        }
        vector<int> ans(n,0) ; 
        for(int i=0 ; i<n ; i++){

            auto val = mp.upper_bound(people[i]); 
            if(val == mp.begin()){
                ans[i] = 0 ; 
                continue ; 
            }
            val-- ; 

            ans[i] = val->second ;

        }

        return ans;
    }
};