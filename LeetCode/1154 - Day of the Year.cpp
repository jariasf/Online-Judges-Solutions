/*******************************************
 ***Problema: Day of the Year
 ***ID: 1154
 ***Juez: LeetCode
 ***Tipo: Ad hoc, gregorian
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    int gregorian(int y, int m, int d){
        return 1461 * (y + 4800 + (m - 14) / 12) / 4 + 
            367 * (m - 2 - (m - 14) / 12 * 12) / 12 -
            3 * ((y + 4900 + (m - 14) / 12) / 100) / 4 +
            d - 32075;
    }
    int dayOfYear(string date) {
        int y = stoi(date.substr(0,4));
        int m = stoi(date.substr(5,2));
        int d = stoi(date.substr(8,2));
        return gregorian(y,m,d) - gregorian(y,1,1) + 1;
    }
};
