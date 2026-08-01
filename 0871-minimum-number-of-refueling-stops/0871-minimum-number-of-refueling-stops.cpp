class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int n = stations.size() ; 
        n++ ; 
        /*
        _ _ _ _ _ _ _ _ _ _ _ 


        */
        stations.push_back({target,0}) ; 
        priority_queue<int> pq ; 
        int idx = 0 ; 
        int pos = 0 ; 
        int cnt = 0 ; 
        int fuel = startFuel ; 
        while(idx<n){
            int p = stations[idx][0] ; 
            int f = stations[idx][1] ; 
            if(fuel >= p - pos){
                fuel -= p - pos ; 
                pos = p ; 
            }
            else{
                while(pq.size() && fuel < p - pos){
                    fuel += pq.top() ; pq.pop() ; 
                    cnt++ ; 
                }
                if(fuel < p - pos) return -1 ; 
                fuel -= p - pos ; 
                pos = p ; 
            }
            pq.push(f) ; 
            idx++ ; 
        }
        return cnt ;
    }
};