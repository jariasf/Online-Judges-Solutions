/*******************************************
 ***Problema: Broken Calculator
 ***ID: 991
 ***Juez: LeetCode
 ***Tipo: Add hoc, Math
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    int brokenCalc(int x, int y) {
        int res = 0;
        while(y > x){
            if( y % 2 == 0 ){
                y /= 2;
            }else
                y++;
            res++;
        }
        res += x - y;
        return res;
    }
};
