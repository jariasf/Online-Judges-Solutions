/*******************************************
 ***Problema: Day of the Week
 ***ID: 1185
 ***Juez: LeetCode
 ***Tipo: Julian Number | JAVA Calendar | Simulation
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    
    string dayOfWeek[8] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
    int dateToInt (int m, int d, int y){
        return
          1461 * (y + 4800 + (m - 14) / 12) / 4 +
          367 * (m - 2 - (m - 14) / 12 * 12) / 12 -
          3 * ((y + 4900 + (m - 14) / 12) / 100) / 4 +
          d - 32075;
    }

    string intToDay (int jd){
        return dayOfWeek[jd % 7];
    }    
    
    string dayOfTheWeek(int day, int month, int year) {
        int jd = dateToInt (month, day, year);
        return intToDay (jd);
    }
};
