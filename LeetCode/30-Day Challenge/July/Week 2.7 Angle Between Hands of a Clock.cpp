/*******************************************
 ***Problema: Angle Between Hands of a Clock
 ***ID: Week2.7
 ***Juez: LeetCode
 ***Tipo: Math
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    double angleClock(int hour, int minutes) {
        double hour_to_min = (5.0 * minutes)/60.0;
        double hour_angle = 30.0 * hour + 6.0 * hour_to_min;
        double minutes_angle = (6.0 * minutes);
        double diff = fabs(minutes_angle - hour_angle);
        return min(360.0 - diff, diff);
    }
};
