/*******************************************
 ***Problema: Number of Paths with Max Score
 ***ID: 1301
 ***Juez: LeetCode
 ***Tipo: Dynamic Programming
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:

    const int MOD = 1e9 + 7;
    vector<vector<int> > getMax(vector<string> &board){
        int n = board.size();
        board[0][0] = board[n-1][n-1] = '0';
        vector<vector<int> > dp = vector<vector<int> >(n, vector<int>(n,-1));
        dp[n - 1][n - 1] = dp[0][0] = 0;
        for( int i = n - 1; i >= 0 ; --i ){
            for(int j = n - 1; j >= 0 ; --j ){
                if( board[i][j] == 'X') continue;
                int val = board[i][j] - '0';
                if( j + 1 < n && board[i][j + 1] != 'X' && dp[i][j + 1] != -1 && dp[i][j] < val + dp[i][j + 1]){
                    dp[i][j] = val + dp[i][j + 1];
                }
                if( i + 1 < n && board[i + 1][j] != 'X' && dp[i + 1][j] != -1 && dp[i][j] < val + dp[i + 1][j]){
                    dp[i][j] = val + dp[i + 1][j];
                }
                if( i + 1 < n && j + 1 < n && board[i + 1][j + 1] != 'X' && dp[i+1][j+1] != -1 && dp[i][j] < val + dp[i + 1][j + 1]){
                    dp[i][j] = val + dp[i + 1][j + 1];
                }                
            }
        }
        return dp;
    }
    
    typedef long long LL;
    vector<vector<LL> > getCount(vector<string> &board, vector<vector<int> > dp_max){
        int n = board.size();
        vector<vector<LL> > dp = vector<vector<LL> >(n, vector<LL>(n,0));
        dp[n-1][n-1] = 1;
        for( int i = n - 1; i >= 0 ; --i ){
            for(int j = n - 1; j >= 0 ; --j ){
                if( board[i][j] == 'X') continue;
                int val = board[i][j] - '0';
                
                if( j + 1 < n && board[i][j + 1] != 'X' && dp_max[i][j + 1] != -1 && dp_max[i][j] == val + dp_max[i][j + 1]){
                    dp[i][j] += dp[i][j + 1];
                    dp[i][j] %= MOD;
                }

                if( i + 1 < n && board[i + 1][j] != 'X' && dp_max[i + 1][j] != -1 && dp_max[i][j] == val + dp_max[i + 1][j]){
                    dp[i][j] += dp[i + 1][j];
                    dp[i][j] %= MOD;
                }

                if( i + 1 < n && j + 1 < n && board[i + 1][j + 1] != 'X'&& dp_max[i + 1][j + 1] != -1 && dp_max[i][j] == val + dp_max[i + 1][j + 1]){
                    dp[i][j] += dp[i + 1][j + 1];
                    dp[i][j] %= MOD;
                }
            }
        }
        return dp;
    }     

    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size();
        vector<vector<int> > dp_max = getMax(board);
        int maxi = dp_max[0][0];
        vector<vector<LL> > dp_cnt = getCount(board, dp_max);
        int cnt = dp_cnt[0][0];
        vector<int> res = {maxi, cnt};
        return res;
    }
};
