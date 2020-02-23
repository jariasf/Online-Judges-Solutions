/*******************************************
 ***Problem: Number of Days Between Two Dates
 ***ID: 1360
 ***Judge: LeetCode
 ***Type: Ad hoc - Gregorian Date
 ***Author: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    int dateToInt (int m, int d, int y){
        return
          1461 * (y + 4800 + (m - 14) / 12) / 4 +
          367 * (m - 2 - (m - 14) / 12 * 12) / 12 -
          3 * ((y + 4900 + (m - 14) / 12) / 100) / 4 +
          d - 32075;
    }
    
    int daysBetweenDates(string date1, string date2) {
        int m1, d1, y1, m2, d2, y2;
        y1 = stoi(date1.substr(0,4));
        m1 = stoi(date1.substr(5,2));        
        d1 = stoi(date1.substr(8,2));
        
        y2 = stoi(date2.substr(0,4));
        m2 = stoi(date2.substr(5,2));        
        d2 = stoi(date2.substr(8,2));        
        
        return abs(dateToInt(m2, d2, y2) - dateToInt(m1, d1, y1));
    }
};
