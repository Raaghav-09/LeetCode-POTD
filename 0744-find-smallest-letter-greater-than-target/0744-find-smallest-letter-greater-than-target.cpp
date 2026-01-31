class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int n = letters.size() ; 
        int trgt = (int)target ; 
        if(target>=letters[n-1]) return letters[0];
        // int low = 0 ; 
        // int high = n-1 ;
        char ans ;
        // while(low<=high){
        //     int mid = low + (high-low)/2 ; 
        //     if(diff>minDiff){
        //         minDiff = diff ;
        //     }

        // }
        // int minDiff = INT_MAX ;
        // int diff ;
        for(int i = 0 ; i < n ; i++){
            int x=(int)letters[i];
            if(x>trgt){
                ans=letters[i];
                break;
            }
                
            
        }
        return ans ;
    }
};