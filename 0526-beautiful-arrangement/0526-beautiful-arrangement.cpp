class Solution {
public:
    int countArrangement(int n) {
        auto f = [&](int ind , int mask , auto&& f) -> int{
            if(ind == n){
                return 1 ; 
            }
            int ways = 0 ; 
            int pos = ind+1 ; 
            for(int j=1 ; j<=n ; j++){
                if((j%pos == 0 || pos%j == 0) && (mask & 1<<j) == 0 ){
                    ways += f(ind+1,mask | 1<<j , f) ; 
                }
            }

            return ways ; 
        };

        return f(0,0,f) ; 
    }
};