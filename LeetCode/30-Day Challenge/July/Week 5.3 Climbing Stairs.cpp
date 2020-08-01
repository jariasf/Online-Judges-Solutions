/*******************************************
 ***Problema: Climbing Stairs
 ***ID: Week5.3
 ***Juez: LeetCode
 ***Tipo: Dynamic Programming | Fibonacci Numbers
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    int climbStairs(int n) {
        int a = 1, b = 1, c = 1;
        for( int i = 2 ; i <= n ; ++i ){
            c = a + b;
            a = b;
            b = c;
        }
        return c;
    }
};
