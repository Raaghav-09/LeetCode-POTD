class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size() , m = strs[0].size() ; 
        // int ans = 0 ; 
        set<int> deletion ; 
        for(int j=0 ; j<m ; j++){
            char prev = 'a' ;
            for(int i=0 ; i<n ; i++){
                if(strs[i][j]>=prev){
                    prev = strs[i][j] ; 
                }
                else{ // Collision
                    bool check = true ; 
                    for(int k = j-1 ; k>=0 ; k--){
                        if(deletion.find(k)!=deletion.end()) continue ; 
                        if(strs[i][k] > strs[i-1][k]){
                            check = false ; 
                            break ; 
                        }
                    }
                    if(check){
                        deletion.insert(j) ; 
                        break ; 
                    }
                    prev = strs[i][j] ; 
                }
            }
        }
        return deletion.size() ; 
    }
};

/*





*/