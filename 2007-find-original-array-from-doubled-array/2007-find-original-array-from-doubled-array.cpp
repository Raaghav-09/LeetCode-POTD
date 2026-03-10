class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        // for half of the element should have their half to be present inside the array
        int n = changed.size() ; 
        if(n%2 == 1) return {} ; 
        map<int,int> mp ; 
        for(int i=0 ; i<n ; i++){
            mp[changed[i]]++ ; 
        }

        sort(changed.begin() , changed.end()) ; 

        vector<int> ans ; 
        if(mp.find(0) != mp.end()){
            if(mp[0] % 2 == 1) return ans ; 
            else{
                int freq = mp[0]/2 ; 
                while(freq--) ans.push_back(0) ; 
                mp.erase(0) ;
            }
        }

        for(int i=0 ; i<n ; i++){
            if(changed[i] == 0) continue ;
            if(mp.find(changed[i]) == mp.end()) continue ;  
            ans.push_back(changed[i]) ; 
            mp[changed[i]]-- ; 
            int toRemove = 2*changed[i] ; 
            if(mp.find(toRemove) == mp.end()) return {} ; 
            mp[toRemove]-- ; 
            if(mp[changed[i]] == 0) mp.erase(changed[i]) ; 
            if(mp[toRemove] == 0) mp.erase(toRemove) ;  
            if(ans.size() == n/2) break ; 
        }
        if(ans.size() != n/2) return {} ; 
        return ans; 
    }
};