class Solution {
public:
    int maxArea(vector<int>& v){
        int n = v.size();
        vector<int> prevSmallerIdx(n), nextSmallerIdx(n);
        stack<int> st;

        // Previous smaller element
        for(int i = 0; i < n; i++){
            while(!st.empty() && v[st.top()] >= v[i])
                st.pop();
            prevSmallerIdx[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        while(!st.empty()) st.pop();

        // Next smaller element
        for(int i = n - 1; i >= 0; i--){
            while(!st.empty() && v[st.top()] >= v[i])
                st.pop();
            nextSmallerIdx[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        int area = 0;
        for(int i = 0; i < n; i++){
            int width = nextSmallerIdx[i] - prevSmallerIdx[i] - 1;
            area = max(area, v[i] * width);
        }
        return area;
    }

    vector<int> f(int row, vector<vector<char>>& grid){
        int m = grid[0].size();
        vector<int> v(m, 0);

        for(int j = 0; j < m; j++){
            int cnt = 0;
            for(int i = row; i >= 0; i--){
                if(grid[i][j] == '1') cnt++;
                else break;
            }
            v[j] = cnt;
        }
        return v;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int ans = 0;

        for(int i = 0; i < n; i++){
            vector<int> v = f(i, matrix);
            ans = max(ans, maxArea(v));
        }
        return ans;
    }
};
