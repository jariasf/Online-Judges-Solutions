/*******************************************
 ***Problema: The kth Factor of n
 ***ID: 1492
 ***Juez: LeetCode
 ***Tipo: Ad hoc | Number Theory
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:  
    int kthFactor(int n, int k) {
        for( int i = 1 ; i <= n ; ++i ){
            if( n % i == 0 ){
                k--;
                if( k == 0 ) return i;
            }
        }
        return -1;
    }
};
