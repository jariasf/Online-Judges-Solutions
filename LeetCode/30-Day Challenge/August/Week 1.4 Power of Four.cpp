/*******************************************
 ***Problema: Power of Four
 ***ID: Week1.4
 ***Juez: LeetCode
 ***Tipo: Math
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    bool isPowerOfFour(int num) {
        if( num <= 0 ) return false;
        double p = log(num)/log(4);
        return (int)p == p;
    }
};
