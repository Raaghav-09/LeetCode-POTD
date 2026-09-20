class Solution {
public:
    using ll = long long;
    long long countIntersectingIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<ll> st, ed;
        for(auto &x : intervals){
            st.push_back(x[0]);
            ed.push_back(x[1]);
        }
        sort(st.begin(),st.end());
        sort(ed.begin(), ed.end());
        ll res = 0;
        int j = 0;
        for(int i=0;i<n;i++){
            while(j<i && ed[j] < st[i]) j++;
            res += (ll)(i-j);
        }
        return res;
    }
};