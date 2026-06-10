class Solution {
public:
    bool consider(string& a , string& b){
        int cnt = 0 ; 
        int n = a.size() ;
        for(int i=0 ; i<n ; i++){
            if(a[i] != b[i]){
                cnt++ ; 
            }
            if(cnt>1) return false ; 
        }
        if(cnt == 0) return false ; 
        return true ; 
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n = wordList.size() ; 

        queue<pair<string,int>> q ; 
        q.push({beginWord,1}) ; 

        set<string> s(wordList.begin(),wordList.end()) ; 

        while(q.size()){
            string curr = q.front().first ;
            int step = q.front().second ; 
            q.pop() ; 
            
            if(step > n+1) continue ; 

            if(curr == endWord){
                return step ; 
            }
            set<string> remove ; 
            for(auto str : s){
                if(consider(str,curr)){
                    q.push({str,step+1}) ; 
                    remove.insert(str) ; 
                }
            }

            for(auto& str : remove) s.erase(str) ; 
        }


        return 0 ; 
    }
};