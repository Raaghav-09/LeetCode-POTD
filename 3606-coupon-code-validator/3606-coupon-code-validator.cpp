class Solution {
public:
    bool isValidCode(const string& s){
        if(s=="") return false ; 
        for(char ch : s){
            if((ch>='a' && ch<='z') || (ch>='A' && ch<='Z') || (ch=='_') ||(ch>='0' && ch<='9')){
                continue ; 
            }
            else return false; 
        }
        return true ;
    }
    bool isValidBusiness(const string& s){
        return s=="electronics" || s=="grocery" || s=="pharmacy" || s=="restaurant" ; 
    }
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        int n = code.size() ;
        vector<pair<string,string>> v ; 
        for(int i=0 ; i<n ; i++){
            if(isActive[i] && isValidCode(code[i]) && isValidBusiness(businessLine[i])){
                v.push_back({businessLine[i],code[i]}) ;             
            }
        }
        sort(v.begin(),v.end()) ; 
        vector<string> ans ; 
        for(auto& p : v){
            ans.push_back(p.second) ; 
        }
        return ans ; 
    }
};