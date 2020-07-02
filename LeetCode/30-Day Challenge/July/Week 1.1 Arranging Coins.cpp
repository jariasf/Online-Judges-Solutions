/*******************************************
 ***Problema: Arranging Coins
 ***ID: Week1.1
 ***Juez: LeetCode
 ***Tipo: Ad hoc - Math
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/


//O(1)
class Solution {
public:
    int arrangeCoins(int n) {
        return (sqrt(8LL * n + 1) - 1)/2;
    }
};


class Solution {
public:
    int arrangeCoins(int n) {
        long long x = 1;
        while( x * (x + 1)/2 <= n ){
            x++;
        }
        return x - 1;
    }
};
