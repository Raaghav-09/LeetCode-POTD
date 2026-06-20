class Solution {
public:
    bool consider(string& a , string& b){
        if(a.size() != b.size()) return false ;
        int n = a.size() ;
        int cnt = 0 ; 
        for(int i=0 ; i<n ; i++){
            if(a[i] != b[i]) cnt++ ; 
            if(cnt > 1) return false ; 
        }

        return cnt == 1 ; 
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n = wordList.size() ; 
        int target = -1 ; 
        vector<vector<int>> adj(n+1) ; 
        int src = 0 ; 
        for(int i=0 ; i<n ; i++){
            if(endWord == wordList[i]) target = i+1 ; 
            if(beginWord == wordList[i]) src = i+1 ; 
            for(int j=i+1 ; j<n ; j++){
                if(consider(wordList[i],wordList[j])){
                    adj[i+1].push_back(j+1) ; 
                    adj[j+1].push_back(i+1) ; 
                }
            }
        }

        if(src == 0){
            for(int i=0 ; i<n ; i++){
                if(consider(wordList[i],beginWord)){
                    adj[0].push_back(i+1) ; 
                }
            }
        }

        vector<int> visited(n+1) ; 

        queue<int> q ; 
        q.push(src) ; 
        visited[src] = 1 ;
        int time = 0 ; 
        while(!q.empty()){
            time++ ; 
            int sz = q.size() ;
            while(sz--){
                int node = q.front() ; q.pop() ;
                if(target == node) return time ; 
                for(auto adjNode : adj[node]){
                    if(!visited[adjNode]){
                        visited[adjNode] = 1 ; 
                        q.push(adjNode) ; 
                    }
                }
            }
            
        }

        return 0 ; 
    }
};