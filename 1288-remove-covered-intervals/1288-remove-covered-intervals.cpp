class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size() ; 

        sort(intervals.begin(),intervals.end(),[&](auto& p1 , auto& p2){
            if(p1[1] == p2[1]){
                return p1[0] > p2[0] ; 
            }
            return p1[1] < p2[1] ; 
        }) ; 

        reverse(intervals.begin(),intervals.end()) ; 

        /*
        ------------ => Remove
        ----------------- 
            ------------------------ 
                --------------  => Remove
                    ---------------  => Remove
                   ------------------------ 
        

                                    ------------------------ 
                                ------------------------ 
                                        ---------------  => Remove
                                    --------------  => Remove
                ---------------
        ----------------- 
        ------------ => Remove

        TestCase : [3,10] , [4,10] , [5,11]
            [5,11] , [4,10] , [3,10]
                ----------------
               ---------------
              ----------------
        */

        int remove = 0 ; 
        int starting = intervals[0][0] ; 
        for(int i=1 ; i<n ; i++){
            if(intervals[i][0] >= starting) remove++ ; 
            starting = min(starting,intervals[i][0]) ; 
        }
        return n - remove ; 
    }
};