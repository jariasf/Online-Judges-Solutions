/*******************************************
 ***Problema: Pow(x, n)
 ***ID: Week3.2
 ***Juez: LeetCode
 ***Tipo: Exponentiation by squaring
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    double bigPow(double x, int n){
        if( n == 0 ) return 1;
        if( n & 1 ){
            return x * bigPow(x, n - 1);
        }else{
            if( n < 0 ) n /= -2;
            else n /= 2;
            double value = bigPow(x, n);
            return value * value;
        }
    }
    
    double myPow(double x, int n) {
        if( n < 0 ){
            if( n & 1 ) 
                return 1/bigPow(x, -n);
            else
                return 1/bigPow(x, n);
        }
        else
            return bigPow(x, n);
    }
};
