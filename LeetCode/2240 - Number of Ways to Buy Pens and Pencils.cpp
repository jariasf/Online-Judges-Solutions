/*******************************************
 ***Problema: Number of Ways to Buy Pens and Pencils
 ***ID: 2240
 ***Juez: LeetCode
 ***Tipo: Math
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    typedef long long LL;
    long long waysToBuyPensPencils(int total, int cost1, int cost2) {
        LL res = 0;
        for( int i = 0, j = 0 ; i <= total ; i += cost1, ++j ){
            LL val = total - i;
            res += val/cost2;
            res++;
        }
        return res;
    }
};
