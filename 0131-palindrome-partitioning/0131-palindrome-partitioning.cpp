class Solution {
public:
    bool isPalindrome(string& s){
        int i = 0 , j = s.size() -1 ; 
        while(i<=j){
            if(s[i] == s[j]){
                i++ , j-- ; 
            }
            else return false ;
        }
        return true ; 
    }
    vector<vector<string>> partition(string s) {
        int n = s.size() ; 
        vector<vector<string>> ans ; 

        auto f = [&](auto&& f , int idx , vector<string> v)-> void{
            if(idx == n){
                ans.push_back(v) ; 
                return ; 
            }
            string temp = "" ; 
            for(int i=idx ; i<n ; i++){
                temp += s[i] ; 
                if(isPalindrome(temp)){
                    v.push_back(temp) ; 
                    f(f,i+1,v) ; 
                    v.pop_back() ; 
                }
            }
        };
        vector<string> v ; 
        f(f,0,v) ; 

        return ans ; 
    }
};