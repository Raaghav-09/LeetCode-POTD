class Solution {
    public:
        int minOperations(vector<vector<int>>& grid, int x) {
                int m = grid.size();
                        int n = grid[0].size();

                                vector<int> Gone;
                                        Gone.push_back(grid[0][0]);

                                                int flag = grid[0][0] % x;
                                                        int mid = n*m / 2;

                                                                for(int i = 0; i < m; i++){
                                                                            for(int j = 0; j < n; j++){
                                                                                            if(i == 0 && j == 0) continue;
                                                                                                            if(flag != grid[i][j] % x) return -1;

                                                                                                                            Gone.push_back(grid[i][j]);
                                                                                                                                        }
                                                                                                                                                }

                                                                                                                                                        sort(Gone.begin(), Gone.end());
                                                                                                                                                                int target = Gone[mid];
                                                                                                                                                                        int count = 0;

                                                                                                                                                                                for(int i = 0; i < (n*m); i++){
                                                                                                                                                                                            while(Gone[i] != target){
                                                                                                                                                                                                            if(Gone[i] < target){
                                                                                                                                                                                                                                Gone[i] += x;
                                                                                                                                                                                                                                                }else{
                                                                                                                                                                                                                                                                    Gone[i] -= x;
                                                                                                                                                                                                                                                                                    }
                                                                                                                                                                                                                                                                                                    count++;
                                                                                                                                                                                                                                                                                                                }
                                                                                                                                                                                                                                                                                                                        }


                                                                                                                                                                                                                                                                                                                                return count;
                                                                                                                                                                                                                                                                                                                                    }
                                                                                                                                                                                                                                                                                                                                    };
