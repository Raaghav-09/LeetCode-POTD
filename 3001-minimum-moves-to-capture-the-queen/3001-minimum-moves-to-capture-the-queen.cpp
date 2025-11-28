class Solution {
public:
    int minMovesToCaptureTheQueen(int a, int b, int c, int d, int e, int f) {
        set<pair<int,int>> s ; 
        pair<int,int> bishop = {c,d} ; 
        pair<int,int> rook = {a,b} ; 
        // left
        for(int i=a+1 ; i<=8 ; i++){
            pair<int,int> p = {i,b} ; 
            if(p==bishop) break ; 
            s.insert(p) ; 
        }
        // right
        for(int i=a ; i>=1 ; i--){
            pair<int,int> p = {i,b} ; 
            if(p==bishop) break ; 
            s.insert(p) ; 
        }
        //down
        for(int j=b ; j<=8 ; j++){
            pair<int,int> p = {a,j} ; 
            if(p==bishop) break ; 
            s.insert(p) ; 
        }
        // up 
        for(int j=b ; j>=1 ; j--){
            pair<int,int> p = {a,j} ; 
            if(p==bishop) break ; 
            s.insert(p) ; 
        }
        // north west
        for(int i=c , j=d ; i>=1 && j>=1 ; i-- , j--){
            pair<int,int> p = {i,j} ; 
            if(p==rook) break ; 
            s.insert(p) ; 
        }
        // north east 
        for(int i=c , j=d ; i<=8 && j>=1 ; i++ , j--){
            pair<int,int> p = {i,j} ; 
            if(p==rook) break ; 
            s.insert(p) ; 
        }
        // south west
        for(int i=c , j=d ; i>=1 && j<=8 ; i-- , j++){
            pair<int,int> p = {i,j} ; 
            if(p==rook) break ; 
            s.insert(p) ; 
        }
        // south east
        for(int i=c , j=d ; i<=8 && j<=8 ; i++ , j++){
            pair<int,int> p = {i,j} ; 
            if(p==rook) break ; 
            s.insert(p) ; 
        }
        pair<int,int> queen = {e,f} ; 
        if(s.find(queen)!=s.end()) return 1 ; 
        else return 2 ; 
    }
};