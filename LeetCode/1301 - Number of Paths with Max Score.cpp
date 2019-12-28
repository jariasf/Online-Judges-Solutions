/*******************************************
 ***Problema: Number of Paths with Max Score
 ***ID: 1301
 ***Juez: LeetCode
 ***Tipo: Dynamic Programming
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    typedef long long LL;
    const int MOD = 1e9 + 7;
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size();
        vector<vector<int> > dp_max = vector<vector<int> >(n, vector<int>(n,-(1<<30) ));
        vector<vector<LL> > dp = vector<vector<LL> >(n, vector<LL>(n,0));
        board[0][0] = board[n-1][n-1] = '0';
        
        dp_max[n - 1][n - 1] = dp_max[0][0] = 0;
        dp[n-1][n-1] = 1;
        vector< vector<int> > dir = { {1, 1}, {0, 1}, {1, 0} };
        for( int i = n - 1; i >= 0 ; --i ){
            for(int j = n - 1; j >= 0 ; --j ){
                if( board[i][j] == 'X') continue;
                int val = board[i][j] - '0';
                for( int k = 0 ; k < 3 ; ++k ){
                    int x = i + dir[k][0], y = j + dir[k][1];
                    if( x < n && y < n ){
                        if( dp_max[i][j] < val + dp_max[x][y]){
                            dp_max[i][j] = val + dp_max[x][y];
                            dp[i][j] = dp[x][y];
                        }else if( dp_max[i][j] == val + dp_max[x][y] ){
                            dp[i][j] += dp[x][y];
                            dp[i][j] %= MOD;
                        }
                    }
                }
            }
        }        
        
        int maxi = dp_max[0][0];        
        int cnt = dp[0][0];
        vector<int> res = {maxi, cnt};
        return res;
    }
};
