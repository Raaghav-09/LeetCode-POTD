class Solution {
private:
    int mxAreaOfHistogram(vector<int>& h){
        int n = h.size() ; 

        /*
        3 1 3 2 2
        => largest area of rectangle in a histogram

        how much i can extend from any index to left and to right 
        if i get that than i can find the largest area for that h[i]

        */

        stack<int> st ; 
        vector<int> prevSmaller(n,0) ;
        prevSmaller[0] = -1 ; 
        st.push(-1) ;
        for(int i=0 ; i<n ; i++){
            while(st.top()!=-1 && h[st.top()] >= h[i]){
                st.pop() ; 
            }
            prevSmaller[i] = st.top() ; 
            st.push(i) ; 
        }

        while(st.size()) st.pop() ; 
        vector<int> nextSmaller(n,0) ;
        st.push(n) ; 
        for(int i=n-1 ; i>=0 ; i--){
            while(st.top()!=n && h[st.top()] >= h[i]){
                st.pop() ; 
            }
            nextSmaller[i] = st.top() ; 
            st.push(i) ; 
        }

        int ans = 0 ; 

        for(int i=0 ; i<n ; i++){
            int val = h[i]*(nextSmaller[i] - prevSmaller[i] - 1) ; 
            ans = max(ans,val) ; 
        }
        return ans ; 
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size() , m = matrix[0].size() ; 

        vector<vector<int>> pre(n,vector<int>(m,0)) ; 
        for(int i=0 ; i<m ; i++) pre[0][i] = matrix[0][i] - '0' ; 

        for(int i=1 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                if(matrix[i][j] == '0') pre[i][j] = 0 ; 
                else pre[i][j] = pre[i-1][j] + 1 ; 
            }
        }

        /*
        1 0 1 0 0 
        2 0 2 1 1
        3 1 3 2 2
        4 0 0 3 0
        */
        int ans = 0 ; 
        for(int i=0 ; i<n ; i++){
            ans = max(ans,mxAreaOfHistogram(pre[i])) ; 
        }

        return ans ; 
    }
};