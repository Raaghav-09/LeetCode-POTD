class Solution {
public:
    int minInsertions(string s) {
        int n = s.size() ; 

        /*
        ( -> 2 
        ) -> 1 
        curr , ( + 2 , ) -1 


        ))())(

        curr = -2 , mn = -2 ; 


        */

        int i=0 ; 
        int curr = 0 ; 
        int ans = 0 ;
        while(i<n){
            if(s[i] == '('){
                curr+=2 ; 
            }
            else{
                if(i+1<n){
                    if(s[i+1] == ')'){
                        i++ ; 
                        curr -= 2 ; 
                    }
                    else{
                        ans++ ; 
                        curr -= 2 ; 
                    }
                }
                else{
                    ans++ ; 
                    curr -= 2 ; 
                }
            }
            if(curr < 0){
                ans += abs(curr)/2 ; 
                curr = 0 ; 
            }
            i++ ;
        }
        // cout << ans << " " << mn << " " << curr << endl ;
        // mn = abs(mn) ; 
        // ans += mn/2 ; 
        // if(curr > 0){
        //     ans += curr ; 
        // }

        if(curr > 0){
            ans += (curr); 
        }
        

        return ans ; 
    }
};