/*******************************************
 ***Problema: Minimum One Bit Operations to Make Integers Zero
 ***ID: 1611
 ***Juez: LeetCode
 ***Tipo: Bitwise Operations
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    int minimumOneBitOperations(int n) {
        int ans = 0;
        while(n) {
            ans ^= n;
            n /= 2;
        }
        return ans;
    }
};
