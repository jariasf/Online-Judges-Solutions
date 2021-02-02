/*******************************************
 ***Problema: Number of 1 Bits
 ***ID: Week1.1
 ***Juez: LeetCode
 ***Tipo: Bitwise Operations
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int cnt = 0;
        while(n){
            cnt++;
            n = n & (n - 1);
        }
        return cnt;
    }
};
