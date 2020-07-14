/*******************************************
 ***Problema: Reverse Bits
 ***ID: Week2.5
 ***Juez: LeetCode
 ***Tipo: Bitwise Operations
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;
        for( int i = 0 ; i < 32 ; ++i ){
            if( n & (1<<i))
                res |= 1<<(32 - i - 1);
        }
        return res;
    }
};
