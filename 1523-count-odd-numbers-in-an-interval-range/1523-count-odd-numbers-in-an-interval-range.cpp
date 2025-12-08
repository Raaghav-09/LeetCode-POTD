class Solution {
public:
    int countOdds(int low, int high) {
        if(low==high) return low%2 ; 
        return (high-low)/2 + (high%2 || low%2) ;
    }
};