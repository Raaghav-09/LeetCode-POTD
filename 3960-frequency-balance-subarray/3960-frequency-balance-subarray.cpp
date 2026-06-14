class Solution {
public:
    int getLength(vector<int>& nums) {
        int n = nums.size() ; 

        /*
        if i to j is balanced 
        then i to j+1 is balanced as well ???

        -> not sure => no 

        if i to j is notbalanced 
        then i to j+1 may become balanced 

        No two pointer

        => what if i iterate over length 1e3 
        and then for every possible subarray => n
        + maintain a frequecny set => multiset
        */

        auto shouldConsider = [&](unordered_map<int,int>& freq) -> bool{
            if(freq.size() == 1) return freq.begin()->second == 1; 
            
            if(freq.size() == 2){
                auto it = freq.begin();
                int f1 = it->first;
                it++;
                int f2 = it->first;
                
                if(f1 > f2) swap(f1, f2);
                if(2 * f1 == f2) return true;
            }
            return false ; 
        };
        
        int ans = 1 ; 
        unordered_map<int,int> mp ;
        unordered_map<int,int> freq ;
        for(int len = n ; len >= 2 ; len--){
            mp.clear() ; 
            freq.clear(); 

            int i=0 , j=0 ; 
            for(j=0 ; j<len ; j++){
                mp[nums[j]]++ ;
            }

             
            for(auto& ele : mp) freq[ele.second]++ ;    
            if(shouldConsider(freq)){
                ans = len ; 
                break ; 
            }

            bool found = false; 
            while(j<n){
                int prevEle = nums[i] ; 
                int prevFreq = mp[prevEle] ; 
                int newEle = nums[j] ; 
            
                freq[prevFreq]-- ; 
                if(freq[prevFreq] == 0) freq.erase(prevFreq) ; 

                mp[prevEle]-- ;
                if(mp[prevEle] == 0){
                    mp.erase(prevEle) ; 
                } 
                else {
                    freq[mp[prevEle]]++ ; 
                }

                if(mp.find(newEle) != mp.end()){
                    int prevFreqOfnewEle = mp[newEle] ; 
                    freq[prevFreqOfnewEle]-- ;
                    if(freq[prevFreqOfnewEle] == 0){
                        freq.erase(prevFreqOfnewEle) ; 
                    }
                }
                mp[newEle]++ ; 
                freq[mp[newEle]]++ ; 

                if(shouldConsider(freq)){
                    ans = len ; 
                    found = true;
                    break ; 
                }
                j++ , i++ ; 
            }
            if(found) break; 
        }

        return ans ; 
    }
};