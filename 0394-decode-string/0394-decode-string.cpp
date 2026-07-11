class Solution {
public:
    string decodeString(string str){
        int n = str.size(); 

        auto f = [&](auto&& f, int i, int j) -> string {
            int idx = i; 
            string ans = ""; 
            
            while(idx <= j){
                if(isdigit(str[idx])){
                    int times = 0;
                    while (idx <= j && isdigit(str[idx])) {
                        times = times * 10 + (str[idx] - '0');
                        idx++;
                    }
                
                    idx++; 
                    
                    int open_brackets = 1;
                    int endIdx = idx; 
                    while(endIdx <= j && open_brackets > 0){
                        if(str[endIdx] == '[') open_brackets++;
                        else if(str[endIdx] == ']') open_brackets--;
                        endIdx++; 
                    }
                    string req = f(f, idx, endIdx - 2);
                    while(times--) ans += req;
                    idx = endIdx; 
                }
                else {
                    ans += str[idx]; 
                    idx++; 
                }
            }
            return ans; 
        };

        return f(f,0,n-1) ; 
    }
};