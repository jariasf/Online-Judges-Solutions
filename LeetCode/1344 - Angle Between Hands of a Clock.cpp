/*******************************************
 ***Problema: Angle Between Hands of a Clock
 ***ID: 1344
 ***Juez: LeetCode
 ***Tipo: Sliding Window
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    double angleClock(int hour, int minutes) {
        if( hour == 12 ) hour = 0;
        double hour_angle = 0.5 * (hour * 60 + minutes);
        double minute_angle = minutes * 6;
        double angle = fabs(hour_angle - minute_angle);
        return min(360 - angle, angle);  
    }
};
