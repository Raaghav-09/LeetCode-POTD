class Solution {
public:
// MUST DOO
    int scoreOfParentheses(string s) {
        int n = s.length() ; 
        /*
        
        ( () () ) ()
        ( ((())) () )

        
        ( 

        fut *= 2 
        fut/=2 ; 
        */
        // stack<char> st ; 
        // stack<int> results ; 
        // int i=0 ; 
        // int score = 0 ; 
        // int res = 1 ; 
        // int fut = 1 ; 
        // int mx = 0 ; 
        // while(i<n){
        //     if(s[i] == '('){
        //         st.push(s[i]) ; 
        //         mx = max(mx,(int)st.size()) ; 
        //     }
        //     else{
        //         int diff = mx - st.size() ; 
        //         score += pow(2,diff) ; 
        //         st.pop() ; 
        //     }
        //     if(st.size() == 0){
        //         mx = 0 ; 
        //     }
        //     i++ ; 
        // }

        // return score; 

        stack<int> st ; 
        st.push(0) ; 

        for(int i=0 ; i<n ; i++){
            if(s[i] == '('){
                st.push(0) ; 
            }
            else{
                int t = st.top();  
                st.pop() ; 
                int score = 0 ; 
                if(t == 0) score = 1 ; 
                else score = 2*t  ; 

                st.top() += score ; 
            }
        }

        return st.top() ; 
    }
};