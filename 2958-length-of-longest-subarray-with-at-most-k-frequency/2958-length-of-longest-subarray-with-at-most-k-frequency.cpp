class Solution {
public:
    int maxSubarrayLength(vector<int>& a, int k) {
        int n = a.size();

        map<int, int> mp;
        int currmx = 0;
        int i = 0, j = 0, ans = 1;
        while(j < n){
            mp[a[j]]++;
            while(i<j && mp[a[j]] > k){
                mp[a[i]]--;
                i++;
            }
            currmx= max(currmx,j-i+1);
            j++;
        }
        return currmx;
    }
};