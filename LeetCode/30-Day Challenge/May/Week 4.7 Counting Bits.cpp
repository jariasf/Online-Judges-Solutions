/*******************************************
 ***Problema: Counting Bits
 ***ID: Week4.7
 ***Juez: LeetCode
 ***Tipo: Bitcount | DP
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    int bitcount(int x){
        int ones = 0;
        while(x > 0){ 
            ones++;
            x = x & (x - 1);
        }
        return ones;
    }
    vector<int> countBits(int num) {
        vector<int> ones(num + 1);
        for( int i = 1 ; i <= num ; ++i )
            ones[i] = bitcount(i);
        return ones;
    }
};
