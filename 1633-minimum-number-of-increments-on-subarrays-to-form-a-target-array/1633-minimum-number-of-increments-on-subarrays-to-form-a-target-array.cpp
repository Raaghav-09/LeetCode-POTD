// class Solution {
// public:
//     int minNumberOperations(vector<int>& target) {
//         int n = target.size() ; 
//         int ans = 0 ; 
//         // 3 2 1 => min + ini - fin = 1 + 2 = 3
//         // 1 4 1 1 3 3 2 3 => ??
//         // 1 + 
//         // step 1 : find minimum and make initial to that 
//         int gmn = *min_element(target.begin(),target.end()) ; 
//         vector<int> initial(n,gmn) ; 
//         ans += gmn ; 


//         // step 2 : find ups downs pairs 
//         vector<pair<int,int>> v ; 
//         int i=0 ; 
//         int prev = -1 ; 
//         bool ups = true ; 
//         int st = 0 ; 
//         while(i<n){
//             if(ups){
//                 if(target[i]>=prev) prev = target[i] ; 
//                 else{
//                     prev = target[i] ; 
//                     ups = false ; 
//                 }
//             }
//             else{
//                 if(target[i]<=prev) prev = target[i] ;
//                 else{ // target[i] > prev 
//                     prev = target[i] ; 
//                     v.push_back({st,i-1}) ; 
//                     st = i ;
//                 }
//             }
//             i++ ; 
//         }
//         i = 0 ; 
//         int m = v.size() ;
//         while(i<m){
//             int mn = INT_MAX , mx = -1 ; 
//             for(int j=v[i].first ; j<=v[i].second ; j++){
//                 mn = min(mn,target[j]) ; 
//                 mx = max(mx,target[j]) ; 
//             }
//             ans += mx - mn + (mn-gmn) ; 
//             i++ ; 
//         }
//         return ans ; 
//     }
// };

class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int n = target.size();
        if (n == 0) return 0;
        int ans = target[0];
        for (int i = 1; i < n; ++i) {
            if (target[i] > target[i-1]) ans += target[i] - target[i-1];
        }
        return ans;
    }
};