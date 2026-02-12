class Solution {
public:
    bool isValid(string& h){
        int num = stoi(h) ; 
        if(h.size()>1 && h[0] == '0') return false ; 
        if(num > 255) return false ;
        return true  ;
    }
    void f(int ind , string& s , string yet , string h , int partition , vector<string>& ans){
        if(h.size()>0 && !isValid(h)){
            return  ; 
        }
        if(partition>4) return ; 
        int n = s.size() ; 
        if(ind == n){
            if(h.size() == 0 && partition == 4) return ans.push_back(yet) ; 
            else if(isValid(h) && partition == 3 )return ans.push_back(yet+h) ; 
            else return ;
        }

        f(ind+1 , s , yet , h + s[ind] , partition,ans) ; 
        if(h.size()){
            yet += h + '.' ;
            f(ind+1 , s , yet ,string(1, s[ind]) , partition+1,ans ) ;
            yet.pop_back() ; 
        }

    }
    vector<string> restoreIpAddresses(string s) {
        int n = s.size() ; 
        if(n>12) return {} ; 

        vector<string> ans ; 
        f(0 , s , "" , "" , 0 , ans) ; 
        return ans ; 
    }
};