/*******************************************
 ***Problema: N-th Tribonacci Number
 ***ID: Week 5.1
 ***Juez: LeetCode
 ***Tipo: Ad hoc
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    int tribonacci(int n) {
        if( n == 0 ) return 0;
        if( n < 3 ) return 1;
        int a = 0, b = 1, c = 1, d = 2;
        for(int i = 3 ; i <= n ; ++i){
            d = a + b + c;
            a = b;
            b = c;
            c = d;
        }
        return d;
    }
};
