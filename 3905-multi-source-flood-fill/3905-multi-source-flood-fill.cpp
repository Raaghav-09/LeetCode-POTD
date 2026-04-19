class Solution {
public:
    vector<vector<int>> colorGrid(int n, int m, vector<vector<int>>& sources) {
        vector<pair<int,int>> dirs = {{-1,0},{0,-1},{1,0},{0,1}} ; 
        vector<vector<int>> ans(n,vector<int>(m,0)) ; 
        queue<pair<pair<int,int>,int>> q ; // row , col , color
        for(vector<int> v : sources){
            int r = v[0] , c = v[1] , color = v[2] ; 
            ans[r][c] = color ; 
            q.push({{r,c},color}) ; 
        }

        while(q.size()){
            int sz = q.size() ; 
            map<pair<int,int>,int> mp ; 
            while(sz--){
                int r = q.front().first.first , c = q.front().first.second , color = q.front().second ; 
                q.pop() ; 
                for(auto [dx,dy] : dirs){
                    int x = r + dx , y = c + dy ; 

                    if(x>=0 && x<n && y>=0 && y<m){
                        if(mp.find(make_pair(x,y)) != mp.end()){
                            mp[make_pair(x,y)] = max(mp[make_pair(x,y)] , color) ; 
                        }
                        else if(ans[x][y] == 0){
                            mp[make_pair(x,y)] = color ; 
                        }
                    }
                }
            }

            for(auto ele : mp){
                int r = ele.first.first , c = ele.first.second , color = ele.second ; 

                ans[r][c] = color ; 
                q.push({{r,c},color}) ; 
            }
        }

        return ans ; 
    }
};