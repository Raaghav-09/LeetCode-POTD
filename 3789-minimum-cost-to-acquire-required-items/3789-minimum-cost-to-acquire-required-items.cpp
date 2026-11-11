class Solution {
public:
    using ll = long long ; 
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        // type 1 : - cost1
        // type 2 : - cost2
        // type 3 : - costBoth
        ll cost = 0 ; 
        // if(cost1>=costBoth/2 && cost2>=costBoth/2){
        //     cost = max(need1,need2)*costBoth ; 
        // }
        // else if(cost1>=costBoth/2 && cost2 < costBoth/2){
            
        // }
        ll c1 = ((ll)cost1)*((ll)need1) + ((ll)cost2)*((ll)need2) ; 
        ll c2 = ((ll)max(need1,need2))*((ll)costBoth) ; 
        ll c3 ;
        if(need1>need2){
            c3 = ((ll)need2*(ll)costBoth) + ((ll)(need1-need2))*((ll)cost1 ); 
        }
        else{
            c3 = ((ll)need1)*((ll)costBoth) + ((ll)(need2-need1))*((ll)cost2) ; 
        }
        cost = min(min(c1,c2),c3) ; 
        return cost ; 
    }
};