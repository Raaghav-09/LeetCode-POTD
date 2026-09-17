class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size() ; 

        vector<int> pre(n,0) ; 
        pre[0] = arr[0] ; 
        for(int i=1 ; i<n ; i++){
            pre[i] = pre[i-1] + arr[i] ; 
        }
        
        map<int,int> last ; 
        vector<int> prev(n,n+1) , nxt(n,n+1) ; 
        last[0] = -1 ; 
        for(int i=0 ; i<n ; i++){
            int num = pre[i] - target ; 
            if(last.count(num)){
                prev[i] = i - last[num] ; 
            }
            if(i>0) prev[i] = min(prev[i],prev[i-1]) ; 
            last[pre[i]] = i ; 
        }

        map<int,int> first ; 
        for(int i=n-1 ; i>=0 ; i--){
            first[pre[i]] = i ; 
            int prev = (i > 0) ? pre[i-1] : 0; 
            int num = prev + target ; 
            if(first.count(num)){
                nxt[i] = first[num] - i + 1; 
            }
            if(i<n-1) nxt[i] = min(nxt[i+1],nxt[i]) ; 
        }

        int ans = n+1 ; 

        for(int i=0 ; i<n-1 ; i++){
            ans = min(prev[i]+nxt[i+1],ans) ; 
        }

        if(ans>n) ans = -1 ; 
        return ans ; 
    }
};