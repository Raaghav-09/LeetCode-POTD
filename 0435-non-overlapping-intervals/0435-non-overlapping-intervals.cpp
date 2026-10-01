class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size() ; 

        sort(intervals.begin(),intervals.end(),[&](auto& p1 , auto& p2){
            return p1[1] < p2[1] ; 
        }) ; 
        int st = intervals[0][0] ; 
        int en = intervals[0][1] ; 
        int res = 0 ; 
        for(int i=0 ; i<n ; i++){
            if(intervals[i][0] < en){
                res++ ; 
            }
            else{
                st = intervals[i][0] ; 
                en = intervals[i][1] ; 
            }
        }

        return res-1 ; 
    }
};