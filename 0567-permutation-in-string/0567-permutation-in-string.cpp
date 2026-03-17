class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size() , m = s2.size() ; 

        multiset<int> mul1 ; 
        for(char ch : s1) mul1.insert(ch) ; 

        multiset<int> mul2 ;  
        for(int i=0 ; i<min(n,m) ; i++){
            mul2.insert(s2[i]) ; 
        }
        if(mul1 == mul2) return true ; 
        for(int i=n ; i<m ; i++){
            int toDelete = i-n ; 
            mul2.erase(mul2.find(s2[toDelete])) ; 
            mul2.insert(s2[i]) ; 
            if(mul1 == mul2) return true ; 
        }
        return mul1 == mul2 ; 
    }
};