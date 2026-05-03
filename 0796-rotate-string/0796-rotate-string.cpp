class Solution {
public:
    bool rotateString(string s, string goal) {
        for(int i=0;i<s.size();i++){
            int frontChar=s.front();
            s.erase(0,1); // start from index 0 
            s+=frontChar;
            if(s== goal) return true;
        }
        return false;
    }
};