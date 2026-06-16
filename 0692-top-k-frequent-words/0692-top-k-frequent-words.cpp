class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        int n = words.size() ; 

        map<string,int> mp ;
        for(int i=0 ; i<n ; i++) mp[words[i]]++ ; 

        auto cmp = [](const pair<int,string>& p1 , const pair<int,string>& p2){
            if(p1.first != p2.first) return p1.first > p2.first ; // minheap
            return p1.second < p2.second ; 
        };

        priority_queue<pair<int,string> , vector<pair<int,string>> , decltype(cmp)> pq(cmp) ; 

        for(auto p : mp){
            auto np = make_pair(p.second,p.first) ; 
            pq.push(np) ; 
            if(pq.size() > k){
                pq.pop() ; 
            }
        }

        vector<string> ans ; 
        while(!pq.empty()){
            ans.push_back(pq.top().second) ; 
            pq.pop() ; 
        }
        reverse(ans.begin(),ans.end()) ; 

        return ans ; 
    }
};