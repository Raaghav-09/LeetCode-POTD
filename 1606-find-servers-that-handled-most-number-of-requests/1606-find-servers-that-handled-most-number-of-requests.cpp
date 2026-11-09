class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        /*
        serverId -> time at which it which become free , and if it is free , mark it -1
        serverId -> 0 to k-1 

    =>  multiset<pair<int,int>> mul => If the server is available then only the serverId will be in this multiset {serverId,time}
    =>  prority_queue<pair<int,int>> pq (min heap requried) => server which are busy right now , and the time they will be free again {time,serverId}

    => Have a hashmap , storing the time at which a particular server will be free , 
    => Another hashmap for storing the count, which server gets used how many number of times .

    Let's dry run the algorithm 

    0 = 6 
    1 = 4
    2 = 6

    0 = 0 
    1 = 0 
    2 = 0 


    0th request => 6 , currTime = 1
    1th request => 4 , currTime = 2
    2th request => 6 , currTime = 3
    3rd request => check priority queue , insert the required ids into multiset and then pop them from priorityqueue and at the same time update the current time , currTime = 4
    
    => I think this algorithm will suffice 

    */
    
        int n = load.size() ; 
        multiset<int> mul ; // only available servers
        for(int i=0 ; i<k ; i++) mul.insert(i) ; 

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq ; // only busy servers 
        vector<int> timeOfFree(k,-1) ; 
        vector<int> used(k,0) ; 

        int currTime = arrival[0] ; 
        int mx = 0 ; 
        for(int i=0 ; i<n ; i++){
            int arrivalTime = arrival[i] ; 
            while(pq.size() && pq.top().first <= arrivalTime){
                int sId = pq.top().second ; pq.pop() ; 
                mul.insert(sId) ; // available
            }

            if(mul.size() == 0){
                continue ; 
            }

            auto it = mul.lower_bound(i%k) ; 
            if(it == mul.end()){
                it = mul.begin() ; 
            } 
            int serverId = *it ; 
            int timeTaken = load[i] ; 

            pq.push(make_pair(arrivalTime+timeTaken,serverId)) ; 
            mul.erase(serverId) ; 
            used[serverId]++ ; 
            mx = max(mx,used[serverId]) ; 
        }

        vector<int> res ; 
        for(int i=0 ; i<k ; i++){
            if(used[i] == mx) res.push_back(i) ; 
        }
        
        return res ; 
    }
};