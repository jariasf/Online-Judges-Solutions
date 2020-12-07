/*******************************************
 ***Problema: The kth Factor of n
 ***ID: Week1.4
 ***Juez: LeetCode
 ***Tipo: Ad hoc
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    int kthFactor(int n, int k) {
        for( int i = 1 ; i <= n ; ++i ){
            if( n % i == 0 ) k--;
            if( k == 0 ) return i;
        }
        return -1;
    }
};
