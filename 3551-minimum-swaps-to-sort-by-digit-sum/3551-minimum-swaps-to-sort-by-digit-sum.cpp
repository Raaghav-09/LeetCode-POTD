class Solution {
public:
    static int sum(int n){
        int ans = 0 ; 
        while(n){
            ans += n%10 ; 
            n/=10 ; 
        }
        return ans ; 
    }
    static bool cmp(int a , int b){
        int a1 = sum(a) ; 
        int a2 = sum(b) ; 
        if(a1!=a2){
            return a1<a2 ; 
        }
        else{
            return a<b ; 
        }
    }
    int minSwaps(vector<int>& nums) {
        int n = nums.size() ; 
        vector<int> sorted = nums ; 
        sort(sorted.begin(),sorted.end(),cmp) ; 
        int noOfPositions = 0 ; 
        for(int i=0 ; i<n ; i++){
            if(nums[i]!=sorted[i]) noOfPositions++ ; 
        }
        int ans = minSwapsToMatch(sorted,nums) ; 
        return ans ; 
        
    }

    int minSwapsToMatch(vector<int>& A,vector<int>& B) {
        int n = A.size();
        unordered_map<int, queue<int>> pos;
        for (int i = 0; i < n; i++)
            pos[B[i]].push(i);
        vector<int> P(n);
        for (int i = 0; i < n; i++) {
            P[i] = pos[A[i]].front();
            pos[A[i]].pop();
        }
        vector<bool> vis(n);
        int swaps = 0;
        for (int i = 0; i < n; i++) {
            if (vis[i] || P[i] == i) continue;
            int len = 0, j = i;
            while (!vis[j]) {
                vis[j] = true;
                j = P[j];
                len++;
            }
            swaps += len - 1;
        }
        return swaps;
    }
};