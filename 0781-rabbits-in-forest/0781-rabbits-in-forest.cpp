class Solution {
public:
    int numRabbits(vector<int>& answers) {
        int n = answers.size() ; 

        // a[i] + 1 
        // 2 2 2 2 2
        map<int,int> mp ; 
        for(int i=0 ; i<n ; i++) mp[answers[i]]++ ; 

        int cnt = 0 ; 
        for(auto [ans,freq] : mp){
            if(freq <= ans+1){
                cnt+= (ans+1) ; 
            }
            else{
                int res = (freq)/(ans+1) ;
                int add = res * (ans+1) ;  
                freq -= res*(ans+1) ; 
                if(freq != 0){
                    add += (ans+1) ; 
                }
                cnt += add ; 
            }
        }

        return cnt ; 
    }
};