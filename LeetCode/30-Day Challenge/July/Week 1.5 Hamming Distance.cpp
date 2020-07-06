/*******************************************
 ***Problema: Hamming Distance
 ***ID: Week1.5
 ***Juez: LeetCode
 ***Tipo: Bitwise Operations
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    int hammingDistance(int x, int y) {
        int ones = 0;
        x ^= y;
        while(x){
            x = x & (x - 1);
            ones++;
        }
        return ones;
    }
};
