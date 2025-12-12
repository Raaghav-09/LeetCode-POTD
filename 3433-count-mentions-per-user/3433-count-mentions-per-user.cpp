class Solution {
public:
    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
        int n = events.size() ; 
        sort(events.begin(), events.end(), [&](vector<string>& v1, vector<string>& v2){
            int n1 = stoi(v1[1]), n2 = stoi(v2[1]);
            if(n1 == n2){
                bool isOffline1 = (v1[0] == "OFFLINE");
                bool isOffline2 = (v2[0] == "OFFLINE");
                return isOffline1 > isOffline2; 
            }
            return n1 < n2; 
        });

        queue<pair<int,int>> againOnline ; 

        set<int> online ; 
        for(int i=0 ; i<numberOfUsers ; i++) online.insert(i) ; 

        vector<int> ans(numberOfUsers,0) ; 

        int cnt = 0 ; 
        for(int i=0 ; i<n ; i++){
            int ts = stoi(events[i][1]) ; 
            while(againOnline.size() && againOnline.front().second<=ts){
                online.insert(againOnline.front().first) ; 
                againOnline.pop() ; 
            }
            if(events[i][0]=="MESSAGE"){
                if(events[i][2]=="HERE"){
                    for(auto &ele : online){
                        ans[ele]++ ;
                    }
                }
                else if(events[i][2]=="ALL"){
                    cnt++ ; 
                }
                else{
                    int j=0 , m = events[i][2].size() ; 
                    string str = "" ; 
                    while(j<m){
                        if(events[i][2][j]==' '){
                            if(str.size()!=0){
                                int id = stoi(str.substr(2)) ; 
                                ans[id]++ ; 
                                str = "" ;  
                            }
                        }
                        else str+= events[i][2][j] ; 
                        j++ ; 
                    }
                    if(str.size()!=0){
                        int id = stoi(str.substr(2)) ; 
                        ans[id]++ ; 
                    }

                }
            }
            else{
                int id = stoi(events[i][2]) , ts = stoi(events[i][1]) ; 
                againOnline.push({id,ts+60}) ; 
                online.erase(id) ; 
            }
        }

        for(int i=0 ; i<numberOfUsers ; i++) ans[i]+=cnt ; 

        return ans ; 
    }
};