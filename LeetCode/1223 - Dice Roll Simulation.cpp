/*******************************************
 ***Problema: Dice Roll Simulation
 ***ID: 1223
 ***Juez: LeetCode
 ***Tipo: Dynamic Programming
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    const int MOD = 1e9 + 7;
    int N;
    vector<int> roll;
    vector<vector<vector<int> > > dp;
    int solve(int pos, int last, int cnt_last ){
        if( pos == N )
            return 1;
        if( dp[pos][last][cnt_last] != -1 )
            return dp[pos][last][cnt_last];
        int total = 0;
        for( int i = 1 ; i <= 6 ; ++i ){
            if( last == i ){
                if( cnt_last + 1 <= roll[i - 1]){
                    total += solve(pos + 1, i, cnt_last + 1);
                    if( total >= MOD ) total -= MOD;
                }
            }else{
                total += solve(pos + 1, i, 1);
                if( total >= MOD ) total -= MOD;
            }
        }
        return dp[pos][last][cnt_last] = total;
    }
    
    int dieSimulator(int n, vector<int>& rollMax) {
        dp = vector<vector<vector<int> > >(n + 1, vector<vector<int> >(7, vector<int>(16, -1)) );
        N = n;
        roll = rollMax;
        return solve(0, 0, 0);
    }
};
