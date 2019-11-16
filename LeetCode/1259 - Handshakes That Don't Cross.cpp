/*******************************************
 ***Problema: Handshakes That Don't Cross
 ***ID: 1259
 ***Juez: LeetCode
 ***Tipo: Dynamic Programming - Catalan Numbers
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    typedef long long LL;
    LL MOD = 1e9 + 7;
    int numberOfWays(int N) {
        N /= 2;
        LL dp[ N + 5 ];
        dp[ 0 ] = 1;
        int j;
        for( int i = 1 ; i <= N ; ++i ){
            dp[ i ] = 0;
            for( j = 0 ; j < i; ++j ){
                dp[ i ] = (dp[i] + dp[ j ] * dp[ i - j - 1 ] % MOD) % MOD;
            }
        }
        return dp[N];
    }
};
