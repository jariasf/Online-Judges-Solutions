/*******************************************
 ***Problema: Convert to Base -2
 ***ID: 1017
 ***Juez: LeetCode
 ***Tipo: Number Theory
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    string toBaseNeg( int n , int base ){
        if( n == 0 ) return "0";
        string s = "" , dig;
        int res;
        while( n != 0 ){
            dig = "";
            res = n % base;
            n /= base;
            if( res < 0 ){
                res += -base;
                n++;
            }
            dig += ( res + '0' );
            s = dig + s;
        }
        return s;
    }
    string baseNeg2(int N) {
        return toBaseNeg(N, -2);
    }
};
