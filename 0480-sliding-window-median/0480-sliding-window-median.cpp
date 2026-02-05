class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size() ; 
        multiset<int> left , right ; 
        vector<double> ans ; 

        for(int i=0 ; i<k ; i++){
            if(left.size() < (k+1)/2 ){
                left.insert(nums[i]) ; 
            }
            else if(nums[i] < *left.rbegin()){
                left.insert(nums[i]) ; 
                right.insert(*left.rbegin()) ; 
                left.erase(prev(left.end())) ;  // new things , add in notes rbegin() is not working here 
            }
            else{
                right.insert(nums[i] ) ; 
            }
        }
        
        ans.push_back((k%2) ? *left.rbegin() : (*left.rbegin()*1LL + *right.begin()*1LL)/2.0 ) ; 

        for(int i=k ; i<n ; i++){
            int toDelete = nums[i-k] , toInsert = nums[i] ; 
            if(right.find(toDelete) != right.end()){
                right.erase(right.find(toDelete)) ; 
            }
            else{
                left.erase(left.find(toDelete)) ; 
            }

            if (left.empty() || toInsert <= *left.rbegin()) left.insert(toInsert);
            else right.insert(toInsert); 

            // Now balance them 
            while(left.size() > (k+1)/2){
                right.insert(*left.rbegin()) ; 
                left.erase(prev(left.end())) ; 
            }
            while(left.size() < (k+1)/2 ){
                left.insert(*right.begin()) ; 
                right.erase(right.begin()) ; 
            }
            while(left.size() && right.size() && *left.rbegin() > *right.begin()){
                int lmx = *left.rbegin() ; 
                int rmn = *right.begin() ; 
                right.erase(right.begin()) ;
                left.erase(prev(left.end())) ;  
                left.insert(rmn) ;
                right.insert(lmx) ; 
            }

            ans.push_back((k%2) ? *left.rbegin() : (*left.rbegin()*1LL+ *right.begin()*1LL)/2.0 ) ; 
        }

        return ans ; 
    }
};