class Solution {
public:
    int maxOperations(string s) {
        int n = s.size() ; 
        int i=n-1 ; 
        while(i>=0 && s[i]=='1') i-- ; 
        vector<int> bulk ; 
        while(i>=0){
            int cnt = 0 ; 
            while(i>=0 && s[i]=='1'){
                cnt++ ; 
                i-- ; 
            }
            while(i>=0 && s[i]=='0') i-- ; 
            if(cnt!=0) bulk.push_back(cnt) ; 
        }

        int ans = 0 ; 
        int m = bulk.size() ;
        reverse(bulk.begin(),bulk.end()) ; 
        for(int j=1 ; j<m ; j++){
            // cout << bulk[j] << " " ;
            bulk[j] += bulk[j-1] ; 
        }
        for(int j=0 ; j<m ; j++){
            ans += bulk[j] ; 
        }
        return ans ; 
    }
};