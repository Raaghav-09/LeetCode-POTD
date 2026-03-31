// class Solution {
// public:
//     string generateString(string str1, string str2) {
//         int n = str1.size() , m = str2.size() ; 

//         /*
//         We can only keep at index i where str1[i] = 'T' . 

//         And at the remaining places we will need to check what should come over there . 
//         */

//         string word = "" ; 
//         int k = n + m - 1 ; 
//         while(k--) word += 'A' ; 

//         for(int i=0 ; i<n ; i++){
//             if(str1[i] == 'T'){
//                 for(int j=0 ; j<m ; j++){
//                     if(word[i+j] == 'A' || word[i+j] == str2[j]){
//                         word[i+j] = str2[j] ; 
//                     }
//                     else return "" ; 
//                 }
//             }
//         }

//         for(int i=0 ; i<n+m-1 ; i++){
//             if(word[i] == 'A'){ // that means str1[i] = F
//                 if()
//             }
//         }


//     }
// };

class Solution {
public:
    string generateString(string s, string t) {
        int n = s.size(), m = t.size();
        string ans(n + m - 1, '?'); // ? indicates an undecided position

        // Process T
        for (int i = 0; i < n; i++) {
            if (s[i] != 'T') {
                continue;
            }
            // The substring must equal t
            for (int j = 0; j < m; j++) {
                char v = ans[i + j];
                if (v != '?' && v != t[j]) {
                    return "";
                }
                ans[i + j] = t[j];
            }
        }

        string old_ans = ans;
        for (char& c : ans) {
            if (c == '?') {
                c = 'a'; // Initial value for undecided positions is a
            }
        }

        // Process F
        for (int i = 0; i < n; i++) {
            if (s[i] != 'F') {
                continue;
            }
            // The substring must not equal t
            if (string(ans.begin() + i, ans.begin() + i + m) != t) {
                continue;
            }
            // Find the last undecided position
            bool ok = false;
            for (int j = i + m - 1; j >= i; j--) {
                if (old_ans[j] == '?') { // Previously filled with a, now change it to b
                    ans[j] = 'b';
                    ok = true;
                    break;
                }
            }
            if (!ok) {
                return "";
            }
        }

        return ans;
    }
};