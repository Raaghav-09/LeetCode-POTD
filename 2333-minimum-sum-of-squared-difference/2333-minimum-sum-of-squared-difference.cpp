class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        /*
        x2 - (x-1)^2 = 2x - 1 
        x2 - (x-2)^2 = 4x - 4 
        x2 - (x-3)^2 = 6x - 9 

        5 8 9 11 , k = 7 

        5 8 9 9 ,  k = 5 


        */
        int n = nums1.size() ; 
        map<int,int> mp ;
        priority_queue<pair<int,int>> pq ; 
        pq.push({0,0}) ; 
        for(int i=0 ; i<n ; i++){
            mp[abs(nums1[i]-nums2[i])]++ ;  
        }

        for(auto [ele,freq] : mp){
            pq.push(make_pair(ele,freq)) ; 
        }

        long long cnt = k1 + k2 ; 
        while(cnt > 0 && pq.size() > 1){
            auto [ele,freq] = pq.top(); pq.pop();
            auto [ele2,freq2] = pq.top() ; pq.pop() ; 
            int diff = ele - ele2 ; 

            if(1LL*diff*freq <= cnt){
                pq.push({ele2,freq+freq2}) ; 
                cnt -= diff*freq ; 
            }
            else{
                pq.push({ele2,freq2}) ; 
                int cf = cnt/freq ; 
                int rem = cnt % freq ; 

                
                if(ele > cf){
                    ele = ele - cf ; 
                    cnt -= freq*cf ; 
                    cnt -= rem ; 
                    pq.push({ele,freq-rem}) ; 
                    if(ele > 1 ) pq.push({ele-1,rem}) ; 
                }
                else{
                    cf = ele ;
                    cnt -= cf * freq ; 
                    pq.push({0,freq}) ; 
                }
                // freq - rem no of elements is at ele
                // rem is at ele - 1 
            }
        }

        long long ans = 0 ; 
        while(pq.size()){
            auto [ele,freq] = pq.top() ; pq.pop() ; 

            ans += 1LL*ele*ele * freq ; 
        }

        return ans ; 
    }
};