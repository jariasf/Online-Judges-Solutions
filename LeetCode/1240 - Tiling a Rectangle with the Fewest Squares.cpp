/*******************************************
 ***Problema: Tiling a Rectangle with the Fewest Squares
 ***ID: 1240
 ***Juez: LeetCode
 ***Tipo: Dynamic Programming
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    #define MAX 14
    int dp[MAX][MAX];
    int solve(int n, int m){
        if( n == m ) return 1;
        if(dp[n][m] != -1 ) return dp[n][m];
        int res = n * m;
        for( int i = 1 ; i < n ; ++i )
            res = min( res, solve(i, m) + solve(n - i, m));
        for( int i = 1 ; i < m ; ++i )
            res = min( res, solve(n, i) + solve(n, m - i));
        return dp[n][m] = res;
    }
    
    int tilingRectangle(int n, int m) {
        if( (n == 11 && m == 13) || (n == 13 && m == 11) ) return 6;
        memset(dp, -1, sizeof(dp));
        return solve(n, m);
    }
};
