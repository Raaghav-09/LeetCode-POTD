class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n = s.length();
        if (n < k) return false;                   

        long long num = 0;
        int i = 0, j = 0;
        unordered_set<int> ss;
        while (j < k && j < n) {
            num = (num << 1) | (s[j] - '0');     
            j++;
        }
        ss.insert((int)num);

        int mask = (1 << k) - 1;
        while (j < n) {
            num = ((num << 1) & mask) | (s[j] - '0'); 
            i++; j++;
            ss.insert((int)num);
            if ((int)ss.size() == (1 << k)) return true; 
        }

        return (int)ss.size() == (1 << k);
    }
};