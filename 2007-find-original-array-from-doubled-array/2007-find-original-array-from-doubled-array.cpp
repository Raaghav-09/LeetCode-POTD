class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        int n = changed.size() ; 
        if(n%2 == 1) return {} ; 
        sort(changed.begin(),changed.end()) ; 

        vector<int> original ; 
        map<int,int> skip ;
        for(int i=0 ; i<n ; i++){
            int val = 2*changed[i] ; 
            if(skip.count(changed[i])){
                skip[changed[i]]-- ; 
                if(skip[changed[i]] == 0) skip.erase(changed[i]) ; 
            }
            else{
                original.push_back(changed[i]) ; 
                skip[val]++ ; 
            }
        }

        if(skip.size() != 0) return {};
        return original ; 
    }
};