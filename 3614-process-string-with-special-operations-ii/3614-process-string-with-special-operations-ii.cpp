// class Solution {
// public:
//     using ll = long long ; 
//     char processStr(string s, long long k) {
//         int n = s.size() ; 

//         /*
//         * => remove
//         # => duplicate 
//         % => reverse

//         so i am sure the character will be one of the lower case alphabet present in the string s 
//         how can i do that thing then 
//         => Is there any method , 
//         hmmmmmm????
//         ............................
//         => i can know that at the end what is the length of the resultant string .
//         => is less than k return '.'

//         else backtrack , if this operation doesn't have taken place what could have happen 
//         */
//     }
// };

// copy paste
class Solution {
    typedef long long ll;
public:
    char processStr(string s, ll k) {
        int n = s.size();
        ll len = 0;

        for (auto& ch : s) {
            if (ch == '*')
                len = max(len - 1, 0LL);
            else if (ch == '#')
                len *= 2;
            else if (ch != '%')
                len++;
        }

        if (k >= len) return '.';

        for (int i = n - 1;; i--) {
            switch (s[i]) {
            case '*':
                len++;
                break;
            case '#':
                if (k >= len / 2)
                    k -= len / 2;
                len /= 2;
                break;
            case '%':
                k = len - 1 - k;
                break;
            default:
                if (len == k + 1)
                    return s[i];
                len--;
            }
        }
    }
};