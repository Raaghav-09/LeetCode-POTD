class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int m = capacity.size() , n = apple.size() ; 
        int sum = accumulate(apple.begin(),apple.end(),0) ; 
        sort(capacity.begin(),capacity.end()) ; 
        int ans = 0 ; 
        for(int i=m-1 ; i>=0 ; i--){
            sum -= capacity[i] ; 
            ans++ ; 
            if(sum<=0){
                break ; 
            }
        }
        return ans ; 
    }
};