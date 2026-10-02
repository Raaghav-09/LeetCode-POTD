class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans ; 

        auto f = [&](auto&& f , int op , int cl , string curr) -> void{
            if(op == n && cl == n){
                ans.push_back(curr) ; 
                return ;
            }

            // always op >= cl
            if(op == cl){
                f(f,op+1,cl,curr + '(') ; 
            }
            else if(op > cl){
                if(op != n) f(f,op+1,cl,curr + '(') ; 
                f(f,op,cl+1,curr+')');
            }

            return ;
        };

        f(f,0,0,"") ; 
        return ans ; 
    }
};