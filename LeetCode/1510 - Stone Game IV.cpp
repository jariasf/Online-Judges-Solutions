/*******************************************
 ***Problema: Stone Game IV
 ***ID: 1510
 ***Juez: LeetCode
 ***Tipo: Dynamic Programming - Grundy Numbers
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    bool winnerSquareGame(int n) {
        vector<bool> G(n + 1);
        for( int i = 1 ; i <= n ; ++i ){
            bool b = true;
            for( int j = 1 ; j * j <= i ; ++j ){
                if( i >= j * j )
                    b &= G[i - j * j];
            }
            G[i] = !b;
        }
        return G[n];
    }
};
