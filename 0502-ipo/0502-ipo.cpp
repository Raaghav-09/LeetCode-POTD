class Solution {
public:
    int findMaximizedCapital(int k, int w , vector<int>& profits, vector<int>& capital) {
        int n = profits.size() ; 
        /*
    =>  1 2 3 
    =>  0 1 1 


        */

        vector<int> indices(n) ; 
        iota(indices.begin(),indices.end(),0) ; 

        sort(indices.begin(),indices.end(),[&](int idx1 , int idx2){
            if(capital[idx1] != capital[idx2]) return capital[idx1] < capital[idx2] ; 
            return profits[idx1] > profits[idx2] ; 
        }) ; 

        priority_queue<int> pq ; 
        int idx = 0 ; 
        int curr = w ; 
        int ans = 0 ; 
        while(k){
            while(idx<n && capital[indices[idx]] <= curr){
                pq.push(profits[indices[idx]]) ; 
                idx++ ; 
            }
            if(pq.size()){
                curr += pq.top() ;  
                pq.pop() ; 
                k-- ; 
            }
            else break ; 
        }

        return curr ; 
    }
};