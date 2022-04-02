/*******************************************
 ***Problema: Minimum Bit Flips to Convert Number
 ***ID: 2220
 ***Juez: LeetCode
 ***Tipo: Ad hoc
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    int minBitFlips(int start, int goal) {
        start ^= goal;
        int res = 0;
        while(start>0){
            start = start & (start - 1);
            res++;
        }
        return res;
    }
};
