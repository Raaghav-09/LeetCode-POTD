class Solution {
public:
    vector<int> nextSmallestIndex(vector<int>& nums){
        stack<int> st ;
        int n = nums.size();
        st.push(n-1);
        vector<int> nsi(n);
        nsi[n-1] = n ; 
        for(int i = n-2 ; i>=0 ; i--){
            while(st.size() && nums[st.top()]>=nums[i]) st.pop();
            if(!st.size()) nsi[i] = n ;
            else nsi[i]=st.top();
            st.push(i);
        }
        return nsi ;
    }

    vector<int> prevSmallestIndex(vector<int>& nums){
        stack<int> st ;
        int n = nums.size();
        st.push(0);
        vector<int> psi(n);
        psi[0] = -1 ; 
        for(int i = 1 ; i<n ; i++){
            while(st.size() && nums[st.top()]>=nums[i]) st.pop();
            if(!st.size()) psi[i] = -1 ;
            else psi[i]=st.top();
            st.push(i);
        }
        return psi ;    
    }

    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> width(n);
        vector<int> nsi = nextSmallestIndex(heights) ;
        vector<int> psi = prevSmallestIndex(heights) ;
        for(int i=0 ; i<n ; i++){
            width[i] =  nsi[i]-psi[i] - 1 ;
        }
        for(int i=0 ; i<n ; i++){
            width[i] = heights[i]*width[i];
        }
        int maxArea = INT_MIN ;
        for(int i=0 ; i<n ; i++){
            maxArea = max( maxArea , width[i] );
        }
        return maxArea ;
    }
};