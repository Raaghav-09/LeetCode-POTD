class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size() ; 
        unordered_map<int,int> freq ; 
        unordered_set<int> s ; 
        vector<int> ans(n) ; 
        for(int i=0 ; i<n ; i++){
            freq[A[i]]++ ; 
            freq[B[i]]++ ; 
            if(freq[A[i]]==2) s.insert(A[i]) ; 
            if(freq[B[i]]==2) s.insert(B[i]) ; 
            ans[i] = s.size() ; 
        }
        return ans ; 
    }
};