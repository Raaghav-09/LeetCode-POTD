class Solution {
public:
    string getString(map<string,string>& allowedBase , string& bottom , int ind){
        string s = bottom.substr(ind,2) ; 
        if(allowedBase.find(s)==allowedBase.end()) return "" ; 
        return allowedBase[s] ; 
    }
    void giveMeAllPossibleBases(string& bottom , vector<string>& allowed , map<string,string>& allowedBase , vector<string>& possibleBase , int ind , string str , bool& check){
        int m = bottom.size() ; 
        if(check==false) return ; 
        if(ind==m-1){
            possibleBase.push_back(str) ;
            return ; 
        }
        string avail = getString(allowedBase , bottom , ind) ; 
        if(avail.size()==0){
            check = false ; 
            return ; 
        }
        for(char ch : avail){
            giveMeAllPossibleBases(bottom,allowed , allowedBase , possibleBase,ind+1, str+ch , check) ; 
        }
    }
    unordered_map<string,bool> dp ; 
    bool f(string& bottom , vector<string>& allowed , map<string,string>& allowedBase){
        if(dp.count(bottom)) return dp[bottom];
        int m = bottom.size() ; 
        if(m==1) return true ; 
        vector<string> possibleBase ;

        bool check = true ; 
        giveMeAllPossibleBases(bottom , allowed , allowedBase ,possibleBase , 0 , "" , check) ; 
        bool ans = false ; 
        if(!check) return dp[bottom] = false;  
        for(auto& s : possibleBase){
            if(f(s, allowed, allowedBase)) return dp[bottom] = true;
        }
        return dp[bottom] = false;
    }
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        int n = allowed.size() ; 
        map<string,string> allowedBase ; 
        for(string& s : allowed){
            if(allowedBase.find(s.substr(0,2)) == allowedBase.end()) allowedBase[s.substr(0,2)] = "" ;
            allowedBase[s.substr(0,2)] += s[2] ; 
        }
        return f(bottom,allowed,allowedBase) ; 
    }
};