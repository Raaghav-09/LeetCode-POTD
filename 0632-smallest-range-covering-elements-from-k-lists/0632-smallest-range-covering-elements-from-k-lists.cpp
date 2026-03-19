class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int n = nums.size() ; 
        
        map<int,vector<int>> mp ; 
        for(int i=0 ; i<n ; i++){
            int m = nums[i].size() ; 
            for(int j=0 ; j<m ; j++){
                mp[nums[i][j]].push_back(i) ; 
            }
        }

        vector< pair<int,set<int>> > v ; 
        for(auto [x,s] : mp){
            set<int> ss(s.begin(),s.end()) ; 
            v.push_back(make_pair(x,ss)) ; 
        }
        int sz = v.size() ;

        int l = 0 , r = 0 ; 
        pair<int,int> ans = {-1e5 , 1e5} ; 
        map<int,int> ind ; 
        // multiset< pair<int,int> > mul ; 
        for(int ele : v[l].second){
            ind[ele]++ ; 
        }
        // for(auto [x,y] : ind){
        //     mul.insert(make_pair(y,x)) ; 
        // }
        while(l<sz && r<sz){
            while(ind.size() == n){
                if(ans.second - ans.first > v[r].first - v[l].first){
                    ans.first = v[l].first , ans.second = v[r].first ; 
                }

                for(int ele : v[l].second){
                    ind[ele]--;
                    if(ind[ele] == 0) {
                        ind.erase(ele); 
                    }
                }
                l++;
                
            }
            r++ ; 
            if(r<sz){
                for(auto ele : v[r].second){
                    ind[ele]++ ; 
                }
            }
        }


        return {ans.first , ans.second} ; 
    }
};