class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int n = bank.size() ; 
        int ans = 0 ;
        vector<int> v ; 
        for(int i=0 ; i<n ; i++){
            int one = 0 ;
            for(char ch : bank[i]){
                if(ch=='1'){
                    one++ ; 
                }
            }
            if(one) v.push_back(one) ; 
        }
        int m = v.size() ; 
        for(int i=0 ; i<m-1 ; i++){
            ans += v[i]*v[i+1] ; 
        }
        return ans ; 
    }
};