class Solution {
public:
    bool sumGame(string num) {
        int n = num.size() ; 

        // 0 5 
        // 2 3 

        /*
        2 5 
        ? ?

        18 9
        9 0 9 0 9

        5 ? ?
        ? ? ? ?

        9 1
        9 0 1

        9 + x = y + z + w
        9 + x - w - w1 = y + z + w2

        8 + x = y + z + w 
        8 + x - z = y + w  

        */

        int s1 = 0 , s2 = 0 ; 
        int q1 = 0 , q2 = 0 ; 
        for(int i=0 ; i<n/2 ; i++){
            if(num[i] == '?') q1++ ; 
            else s1 += num[i] - '0' ; 
        }
        for(int i=n/2 ; i<n ; i++){
            if(num[i] == '?') q2++ ; 
            else s2 += num[i] - '0' ; 
        }
        if((q1 + q2) % 2 == 1) return true ; 
        int t1 = q1/2 * 9 ;
        int t2 = q2/2 * 9 ; 
        q1 %= 2 ; 
        q2 %= 2 ; 

        // if(q1 == q2){
            if(t1 + s1 == t2 + s2){
                return false ; 
            }
            else return true ; 
        // }
        


    }
};