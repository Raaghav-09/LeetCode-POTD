class Solution {
public:
    bool checkStrings(string s1, string s2) {
        int n = s1.size() ; 
        
        multiset<char> m1 , m2 , m3 , m4; 
        for(int i=0 ; i<n ; i++){
            if(i%2 == 0){
                m1.insert(s1[i]) ; 
                m3.insert(s2[i]) ;
            }
            else{
                m2.insert(s1[i]) ; 
                m4.insert(s2[i]) ; 
            }
        }

        return m1 == m3 && m2 == m4 ; 
    }
};