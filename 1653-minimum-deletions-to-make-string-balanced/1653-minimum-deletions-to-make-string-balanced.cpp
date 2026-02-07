class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size() ; 
        vector<int> a(n,0) , b(n,0) ; 
        if(s[0] == 'b') b[0]++ ; 
        for(int i=1 ; i<n ; i++){
            if(s[i] == 'b') b[i] = b[i-1] + 1 ; 
            else b[i] = b[i-1] ; 
        }

        if(s[n-1] == 'a') a[n-1] = 1 ; 
        for(int i=n-2 ; i>=0 ; i--){
            if(s[i] == 'a') a[i] = a[i+1] + 1 ; 
            else a[i] = a[i+1] ; 
        }

        int ans = min(a[0] , b[n-1]) ; 
        
        for(int i=0 ; i<n-1 ; i++){
            ans = min(ans,b[i] + a[i+1]) ; 
        }

        return ans ; 
    }
};