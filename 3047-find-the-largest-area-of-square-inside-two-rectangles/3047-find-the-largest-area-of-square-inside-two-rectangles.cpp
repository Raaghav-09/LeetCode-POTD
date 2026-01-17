class Solution {
public:
    long long findIntersection(vector<int>& bl1 ,vector<int>& tr1 , vector<int>&bl2 , vector<int>& tr2 ){

        int l = min(tr2[1] , tr1[1]) - max(bl2[1] , bl1[1]) ; 

        int s1 = bl1[0] , s2 = bl2[0] , e1 = tr1[0] , e2 = tr2[0] ; 

        int b = min( e1 , e2 ) - max(s1 , s2) ; 
        
        if(l<0 || b<0) return 0 ; 
        int s = min(l,b) ; 
        return 1LL *s*s ; 
        
    }
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        int n = bottomLeft.size() ; 
        // vector<int> v(n,0) ; 
        // for(int i=0 ; i<n ; i++) v[i] = i ; 
        // no way i have to go for n2
        // sort(v.begin(),v.end(),[&](int ind1 , int ind2){

        // }) ; 

        long long ans = 0 ; 
        for(int i=0 ; i<n ; i++){
            for(int j=i+1 ; j<n ; j++){
                long long area = 0 ; 
                int s1 = bottomLeft[i][1] , s2 = bottomLeft[j][1] ; 
                if(s1 <= s2) area = findIntersection(bottomLeft[i] , topRight[i] , bottomLeft[j] , topRight[j]) ; 
                else area = findIntersection(bottomLeft[j] , topRight[j] , bottomLeft[i] , topRight[i]) ; 
                ans = max(area , ans) ; 
            }
        }

        return ans ; 
    }
};