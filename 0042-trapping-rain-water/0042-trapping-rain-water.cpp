class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size() ; 

        vector<int> prev(n,0) ; 
        prev[0] = -1 ; 
        for(int i=1 ; i<n ; i++){
            prev[i] = max(prev[i-1],height[i-1]) ; 
        }

        vector<int> nextLargest(n,0) ; 
        nextLargest[n-1] = -1 ; 
        for(int i=n-2 ; i>=0 ; i--){
            nextLargest[i] = max(nextLargest[i+1],height[i+1]) ; 
        }

        vector<int> mini(n) ; 
        for(int i=0 ; i<n ; i++) mini[i] = min(prev[i],nextLargest[i]) ; 

        int ans = 0 ; 
        for(int i=1 ; i<n-1 ; i++){
            ans += max(0,(mini[i]-height[i])) ; 
        }

        return ans ;
    }
};