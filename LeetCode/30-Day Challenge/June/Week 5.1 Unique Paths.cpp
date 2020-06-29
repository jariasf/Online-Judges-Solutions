/*******************************************
 ***Problema: Unique Paths
 ***ID: Week5.1
 ***Juez: LeetCode
 ***Tipo: Combinatorics | DP
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    int uniquePaths(int m, int n) {
        m--; n--;
        int tot = m + n;
        if( m < n ) swap(m, n);
        long long res = 1;
        for( int j = 0 ; j < n ; ++j ){
            res *= tot--;
            res /= (j + 1);
        }
        return res;
    }
};
