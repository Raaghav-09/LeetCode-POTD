using ll = long long ; 
class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        int n = happiness.size() ; 
        sort(happiness.begin(),happiness.end()) ; 
        ll ans = 0 ; 
        int minus = 0 ; 
        for(int i=n-1 ; i>=0  && k-- ; i--){
            if(happiness[i]-minus>=0) happiness[i] -= minus ; 
            else happiness[i] = 0 ; 
            ans += happiness[i] ; 
            if(k) minus++ ; 
        }



        return ans ; 
    }
};