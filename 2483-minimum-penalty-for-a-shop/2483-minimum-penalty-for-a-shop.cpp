class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size() ; 

        vector<int> nYet(n,0) ; 
        nYet[0] = customers[0]=='N' ; 
        for(int i=1 ; i<n ; i++){
            if(customers[i]=='N'){
                nYet[i] = nYet[i-1]+1 ; 
            }
            else{
                nYet[i] = nYet[i-1] ; 
            }
        }

        vector<int> yAhead(n,0) ; 
        yAhead[n-1] = customers[n-1]=='Y' ; 
        for(int i=n-2 ; i>=0 ; i--){
            if(customers[i] == 'Y'){
                yAhead[i] = yAhead[i+1] + 1 ; 
            }
            else{
                yAhead[i] = yAhead[i+1] ; 
            }
        }

        int mnPenality = yAhead[0] ;
        int time = 0 ;  
        for(int i=1 ; i<n ; i++){
            int penality = yAhead[i] + nYet[i-1] ; 
            if(mnPenality>penality){
                mnPenality = penality ; 
                time = i ; 
            }
        }

        if(mnPenality>nYet[n-1]){
            mnPenality = nYet[n-1] ; 
            time = n ; 
        }
        return time ; 
    }
};