class Solution {
public:
    long long shadowPairs(vector<int>& nums) {
        int n = nums.size() ; 

        /*
        0 1 2 3 4 
        3 1 4 1 5
        5 1 4  
        */
        vector<int> nse(n) ; 
        stack<int> st ; 
        map<int,vector<int>> mp ; 
        for(int i=n-1 ; i>=0 ; i--){
            while(st.size() && nums[st.top()] >= nums[i]) st.pop() ; 
            if(st.size()) nse[i] = st.top() ; 
            else nse[i] = n ; 
            st.push(i) ; 

            mp[nums[n-1-i]].push_back(n-i-1) ; 
        }

        long long ans = 0 ; 

        for(int i=0 ; i<n ; i++){
            int ele = nums[i] ; 
            int nsi = nse[i] ; 

            int en = upper_bound(mp[ele].begin(),mp[ele].end(),nsi) - mp[ele].begin() ; 
            int s = lower_bound(mp[ele].begin(),mp[ele].end(),i) - mp[ele].begin() ; 

            ans += (nsi-i-(en-s)) ; 
        }

        return ans ; 
    }
};