class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int n = landStartTime.size() ; 
        int m = waterStartTime.size() ; 
        int t = INT_MAX ; 
        int ans = INT_MAX ; 
        for(int i=0 ; i<n ; i++){
            bool flag = false ; 
            int l = landStartTime[i] ; 
            int dl = landDuration[i] ; 
            int iflast = l+dl ; 
            for(int j=0 ; j<m ; j++){
                int w = waterStartTime[j] ; 
                int wl = waterDuration[j] ; 
                int iflastw = w + wl ; 
                int finish1 = max(w,iflast) + wl ; 
                int finish2 = max(l,iflastw) + dl ; 
                ans = min({ans,finish1,finish2}) ; 
            }
        }
        return ans ; 
        
    }
};