class Solution {
public:
    // bool isPrime(int n){
    //     if(n==1) return false ; 
    //     if(n==2) return true ; 
    //     if(n%2==0) return false ; 
    //     for(int i=3 ; i*i<=n ; i++){
    //         if(n%i==0) return false ; 
    //     }
    //     return true ; 
    // }
    // set<int> factor(int n){
    //     vector<int> ans ; 
    //     while(n%2==0){
    //         ans.insert(2) ; 
    //         n/=2 ; 
    //     }
    //     for(int i=3 ; i*i<=n ; i++){
    //         while(n%i==0){
    //             ans.insert(i) ; 
    //             n/=i ; 
    //         }
    //     }
    //     return ans ; 
    // }
    int minJumps(vector<int>& nums) {
        int n = nums.size() ; 
        int mx = *max_element(nums.begin(),nums.end()) ; 
        vector<int> spf(mx+1,0) ;  
        for(int i=2 ; i<=mx ; i++){
            if(spf[i]==0){
                for(int j=i ; j<=mx ; j+=i){
                    if(spf[j]==0) spf[j] = i ; 
                }
            }
        }

        map<int,vector<int>> prime_to_ind ; 
        for(int i=0 ; i<n ; i++){
            int x = nums[i] ;

            int lastp = 0 ; 
            while(x>1){
                int p = spf[x] ;
                if(p!=lastp){
                    prime_to_ind[p].push_back(i) ;
                    lastp = p ; 
                }
                x/=p ; 
            }
        }

        vector<int> dis(n,-1) ; 
        dis[0] = 0 ; 
        deque<int> dq ; 
        dq.push_back(0) ; 
        unordered_set<int> used ; 
        while(dq.size()){
            int i = dq.front() ; dq.pop_front() ; 
            int d = dis[i] ; 
            if(i == n-1) return d ; 

            if(i+1<n && dis[i+1]==-1){
                dis[i+1] = d+1 ; 
                dq.push_back(i+1) ; 
            }
            if(i-1>=0 && dis[i-1] == -1){
                dis[i-1] = d+1 ; 
                dq.push_back(i-1) ; 
            }
            int val = nums[i] ; 
            if(val>1 && spf[val]==val){
                int p = val ; 
                if(!used.count(p)){
                    for(int j : prime_to_ind[p]){
                        if(dis[j]==-1){
                            dis[j] = d+1 ; 
                            dq.push_back(j) ; 
                        }
                    }
                    used.insert(p) ; 
                }
            }
        }
        return -1 ; 
    }
};