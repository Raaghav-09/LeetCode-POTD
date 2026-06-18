class Solution {
public:
    double angleClock(int hour, int minutes){
        double hourAngle = (hour%12)*30 + 30 * (minutes)/((double)(60)) ;

        double minuteAngle = (minutes) * 6 ; 

        double angle = abs(minuteAngle - hourAngle) ; 
        angle = min(angle , (double)(360 - angle)) ; 

        return angle ; 
    }
};