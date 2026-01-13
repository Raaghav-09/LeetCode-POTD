class Solution {
public:
    double areaAbove(vector<vector<int>>& squares , double y){

        int n = squares.size() ; 
        double area = 0.0 ; 
        for(int i=0 ; i<n ; i++){
            int yco = squares[i][1] ;
            int l = squares[i][2] ; 
            if(yco>=y){
                area += 1.0 * l*l ; 
            }
            else if((yco+l)>y){
                area += (double)((yco+l-y)*l) ; 
            }
        }
        
        return area ; 
    }   
    double separateSquares(vector<vector<int>>& squares) {

        int n = squares.size() ; 
        sort(squares.begin(),squares.end(),[&](vector<int>& v1 , vector<int>& v2){
            return v1[1] < v2[1] ; 
        }) ; 

        double totalArea = 0 ; 
        for(int i=0 ; i<n ; i++){
            totalArea += 1.0 * squares[i][2]* 1.0 * squares[i][2] ; 
        }
        
        double precision = 1e7 ; 
        double low = 0.00 , high = (double)1e14 ; 

        for(int iterations = 0 ; iterations <= 150 ; iterations++){

            double mid = (low+high)/2.0 ; 
            double above = areaAbove(squares , mid) ; 
            
            if(2*above <= totalArea){
                high = mid ; 
            }
            else low = mid ; 
        }

        return low ; 
    }
};