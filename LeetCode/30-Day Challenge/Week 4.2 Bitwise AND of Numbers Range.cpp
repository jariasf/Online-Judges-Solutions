/*******************************************
 ***Problema: Bitwise AND of Numbers Range
 ***ID: Week4.2
 ***Juez: LeetCode
 ***Tipo: Bitwise Operators
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int result = 0;
        for( int i = 0 ; i < 32 ; ++i ){
            if( n == m && n & 1 )
                result |= 1<<i;
            m >>= 1;
            n >>= 1; 
        }
        return result;
    }
};
