/*******************************************
 ***Problema: Divisor Game
 ***ID: 1025
 ***Juez: LeetCode
 ***Tipo: Dynamic Programming
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    #define MAX 1005
    int dp[MAX][2];
    bool solve(int N, bool alice){
        if( N == 1 ){
            if( alice ) return false;
            return true;
        }
        if(dp[N][alice]  != -1 ) return dp[N][alice];
        bool result = false;
        for( int i = 1 ; i < N ; ++i ){
            if( N % i == 0 ){
                result = solve(N - i, !alice);
                if( alice && result == true ) return true;
                if( !alice && result == false ) return false;
            }
        }
        return dp[N][alice] = result;
    }
    
    bool divisorGame(int N) {
        memset(dp, -1, sizeof(dp));
        return solve(N, true);
    }
};
