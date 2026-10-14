class Solution {
public:
    // int ans = 0 ; 
    // void f(int &num , int &sum , int currSum , string s){

    //     if(num == s.size() && currSum==sum){
    //         ans = max(ans,stoi(s)) ; 
    //     }
    //     else if(s.size() > num) return ; 
        
    //     if(currSum > sum) return ; 
    //     for(int i=0 ; i<=9 ; i++){
    //         char ch = i-'0' ; 
    //         f(num,sum,currSum+i,s+ch) ; 
    //     }
        
    // }
    string maxSumOfSquares(int num, int sum) {
        // // at max 7 places to nos
        // if(ans==0) return "" ; 
        // for(int i=0 ; i<=9 ; i++){
        //     string s = "" ; 
        //     s+= i+'0' ; 
        //     f(num,sum,0,s) ; 
        // }
        // string res = to_string(ans) ; 
        // return res ; 
        // map<int,int> freq ; 

        string ans = "" ;
        int times = sum/9 ; 
        while(times--) ans += '9' ; 
        int rem = sum%9 ; 
        if(rem!=0) ans += rem + '0' ; 
        if(ans.size()>num) return "" ; 
        while(ans.size()!=num) ans += '0' ; 
        return ans ; 
        
    }
};