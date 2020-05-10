/*******************************************
 ***Problem: Number of Ways of Cutting a Pizza
 ***ID: 1444
 ***Judge: LeetCode
 ***Type: Dynamic Programming
 ***Author: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    typedef int LL;
    int MOD = 1e9+7;
    vector<vector<int> > sum;
    
    void pre_cal(vector<string> & pizza){
        int h = pizza.size(), w = pizza[0].size();;
        sum = vector<vector<int> >(h + 1, vector<int>(w + 1, 0));
        for( int i = 1 ; i <= h ; ++i ){
            for( int j = 1 ; j <= w ; ++j ){
                sum[i][j] = sum[i][j - 1] + sum[i - 1][j] - sum[i - 1][j - 1] + (pizza[i - 1][j - 1] == 'A');
            }
        }
    }
    
    int query(int a, int b, int c, int d){
        return sum[c][d] - sum[c][b - 1]- sum[a - 1][d] + sum[a - 1][b - 1];
    }
    
    vector<vector<vector<LL> > > dp;
    
    LL solve(int x, int y, int k){
        int h = sum.size(), w = sum[0].size();
        if( k == 0 ){
            return query(x, y, h - 1, w - 1) > 0;
        }
        if( x > h || y > w ) return 0LL;
        if( dp[x][y][k] != -1 ) return dp[x][y][k];
               
        LL res = 0;
        for( int i = y ; i < w; ++i ){
            if( query(x, y, h - 1, i) > 0 ){
                res += solve(x, i + 1, k - 1 );
                res %= MOD;
            }
        }
        
        for( int i = x ; i < h ; ++i ){
            if( query(x, y, i, w - 1) > 0 ){
                res += solve(i + 1, y, k - 1);
                res %= MOD;
            }
        }
        return dp[x][y][k] = res % MOD;
        
    }
    
    
    int ways(vector<string>& pizza, int k) {
        pre_cal(pizza);
        int res = 0;
        int h = sum.size(), w = sum[0].size();
        dp = vector<vector<vector<LL> > >(h + 1, vector<vector<LL> >(w + 1, vector<LL>(k + 1, -1)));
        return solve(1 , 1, k - 1);
    }
};
