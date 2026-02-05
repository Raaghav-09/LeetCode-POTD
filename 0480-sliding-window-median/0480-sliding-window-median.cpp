class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& v , int k){
        int n = v.size() ; 
        vector<double> ans ; 
        
        multiset<int> left , right ; 

        for(int i=0 ; i<k ; i++){
            if(left.size() < (k+1)/2){
                left.insert(v[i]) ; 
            }
            else if(*left.rbegin() > v[i]){
                right.insert(*left.rbegin()) ; 
                left.erase(prev(left.end())) ; 
                left.insert(v[i]) ; 
            }
            else{
                right.insert(v[i]) ; 
            }
        }

        ans.push_back((k%2) ? *left.rbegin() : (1LL* (*left.rbegin()) + 1LL*(*right.begin()))/2.0) ; 

        for(int i=k ; i<n ; i++){
            int toInsert = v[i] , toDelete = v[i-k] ; 

            if(right.find(toDelete) != right.end()){
                right.erase(right.find(toDelete)) ; 
            }
            else{
                left.erase(left.find(toDelete)) ; 
            }

            if(left.size() && *left.rbegin() > toInsert) left.insert(toInsert) ; 
            else right.insert(toInsert) ; 

            // now balance them 
            // Case 1 : If left size is more
            while(left.size() > (k+1)/2){
                right.insert(*left.rbegin()) ; 
                left.erase(prev(left.end())) ; 
            }
            // Case 2 : If right right size is more
            while(left.size() < (k+1)/2){
                left.insert(*right.begin()) ; 
                right.erase(right.begin()) ; 
            }
            // Case 3 : Both have correct size but the distribution among them is wrong 
            while(left.size() && right.size() && *left.rbegin() > *right.begin()){
                int lmx = *left.rbegin() ;
                int rmn = *right.begin() ; 
                left.erase(prev(left.end())) ; 
                right.erase(right.begin()) ; 
                left.insert(rmn) ; 
                right.insert(lmx) ; 
            }

            ans.push_back((k%2) ? *left.rbegin() : (1LL* (*left.rbegin()) + 1LL*(*right.begin()))/2.0) ; 
        }

        return ans ;
        // One more method is there pbds (policy based data structure but that is too easy , need not to mention and also interviewer will not be expecting that )
    }
};