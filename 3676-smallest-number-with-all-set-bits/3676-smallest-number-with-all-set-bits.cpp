class Solution {
public:
    int smallestNumber(int n) {
        int p = 0 ; 
        while((1<<p) < (n+1)){
            p++ ; 
        }
        return (1<<p)- 1 ; 
    }
};