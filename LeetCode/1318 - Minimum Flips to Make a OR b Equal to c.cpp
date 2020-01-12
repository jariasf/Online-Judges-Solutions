/*******************************************
 ***Problema: Minimum Flips to Make a OR b Equal to c
 ***ID: 1318
 ***Juez: LeetCode
 ***Tipo: Bitwise Manipulation
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    typedef long long LL;
    int minFlips(int a, int b, int c) {
        int res = 0;
        for( int i = 0; i < 32 ; ++i ){
            int one_a = a & (1<<i);
            int one_b = b & (1<<i);
            int one_c = c & (1<<i);
            if( (one_a | one_b) == one_c ) continue;

            if( one_c ){
                res++;
            }else{
                if( one_a ) res++;
                if( one_b ) res++;
            }
        }
        return res;
    }
};
