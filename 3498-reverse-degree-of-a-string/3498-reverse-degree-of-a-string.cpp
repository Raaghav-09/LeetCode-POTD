class Solution {
public:
    int reverseDegree(string s) {
        int n = s.length();
        int ans = 0;
        for(int i=0;i<s.length();i++){
            int pos2 = 26 - (s[i]-'a');
            ans += ((i+1)*pos2);
        }
        return ans;
    }
};