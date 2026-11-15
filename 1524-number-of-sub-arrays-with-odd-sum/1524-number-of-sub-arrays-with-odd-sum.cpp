class Solution {
public:
    int MOD = 1e9 + 7 ; 
    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size() ; 
        vector<int> pre(n,0) ; 
        int cnt = 0 ;  
        for(int i=0 ; i<n ; i++){
            if(arr[i]%2==1) cnt++ ; 
            pre[i] = cnt ; 
        }
        //Code
        int odd = 0 ;
        for(int i=0 ; i<n ; i++){
            if(pre[i]%2==1) odd++ ; 
        }
        return ((long long)((long long)odd*(long long)(n-odd))+(long long)odd)%MOD ; 
    }
};