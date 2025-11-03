class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = neededTime.size() ; 
        int ans = 0 ; 
        int i=0 ;
        while(i<n){
            char ch = colors[i] ; 
            int sum = 0 , mx = 0 ; 
            while(ch==colors[i]){
                sum += neededTime[i] ; 
                mx = max(mx,neededTime[i]) ; 
                i++ ; 
            } 
            sum -= mx ;
            ans += sum ; 
        }
        return ans ;
    }
};