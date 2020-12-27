/*******************************************
 ***Problema: Cherry Pickup II
 ***ID: Week3.5
 ***Juez: LeetCode
 ***Tipo: Dynamic Programming
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

#define MAX 71
int dp[MAX][MAX][MAX];
class Solution {
public:
    vector<vector<int>> v;
    int h, w;
    int solve(int row, int c1, int c2){
        if( row == h ) return 0;
        if( dp[row][c1][c2] != -1 ) return dp[row][c1][c2];
        int res = 0;
        for( int i = -1 ; i <= 1 ; ++i ){
            for( int j = -1; j <= 1 ; ++j ){
                int nx = c1 + i, ny = c2 + j;
                if( nx >= 0 && nx < w && ny >= 0 && ny < w ){
                    res = max(res, solve(row + 1, nx, ny));
                }
            }
        }
        if( c1 == c2 )
            res += v[row][c1];
        else
            res += v[row][c1] + v[row][c2];
        return dp[row][c1][c2] = res;
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        v = grid;
        h = v.size(); w = v[0].size();
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, w-1);
    }
};
