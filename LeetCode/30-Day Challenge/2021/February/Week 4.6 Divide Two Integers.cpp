/*******************************************
 ***Problema: Divide Two Integers
 ***ID: Week4.6
 ***Juez: LeetCode
 ***Tipo: Math
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    int divide(int dividend, int divisor) {
        bool negative = false;
        long long divisorll = divisor, dividendll= dividend;
        if( dividendll < 0 ){
            dividendll = -dividendll;
            if( divisorll >= 0 ){
                negative = true;
            }else
                divisorll = -divisorll;
        }else if( divisorll < 0 ){
            negative = true;
            divisorll = -divisorll;
        }

        long long result = 0;
        for( long long i = 31 ; i >= 0 ; --i ){
            if( dividendll >= divisorll<<i ){
                result |= (1LL<<i);
                dividendll -= divisorll<<i;
            }
        }

        if( negative ) return -result;
        if( result > INT_MAX ) result = INT_MAX;
        return result;
    }
};
