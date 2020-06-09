/*******************************************
 ***Problema: Power of Two
 ***ID: Week2.1
 ***Juez: LeetCode
 ***Tipo: Bitwise operations
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n > 0 && ( (n & (n - 1)) == 0);
    }
};
