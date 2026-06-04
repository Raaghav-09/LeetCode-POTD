class Solution {
public:
    int totalWaviness(int num1, int num2) {
        int ans = 0 ; 
        for(int i=num1 ; i<=num2 ; i++){
            string s = to_string(i) ; 
            int m = s.size() ; 
            if(m<3) continue ; 
            for(int j=1 ; j<m-1 ; j++){
                if(s[j] > s[j-1] && s[j] > s[j+1]) ans++ ; 
                else if(s[j] < s[j-1] && s[j] < s[j+1]) ans++ ; 
            }
        }

        return ans ;
    }
};