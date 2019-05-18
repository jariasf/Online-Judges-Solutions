/*******************************************
 ***Problema: Tallest Billboard
 ***ID: 956
 ***Juez: LeetCode
 ***Tipo: Dynamic Programming
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    
    #define MAXN 25
    #define MAXSUM 5005

    bool visited[MAXN + 1][2 * MAXSUM + 1];
    int dp[MAXN + 1][2 * MAXSUM + 1];
    int N;
    int solve(int pos, int sum, vector<int> &rods){
        if( visited[pos][sum + MAXSUM] ){
            return dp[pos][sum + MAXSUM];
        }

        visited[pos][sum + MAXSUM] = true;
        int &res = dp[pos][sum + MAXSUM];
        res = -MAXSUM;
        if( pos == N ){
            if( sum == 0 )
                res = 0;
        }else{
            res = max(res, rods[pos] + solve(pos + 1, sum + rods[pos], rods));
            res = max(res, solve(pos + 1, sum - rods[pos], rods));
            res = max(res, solve(pos + 1, sum, rods));
        }
        return res;
    }
    
    int tallestBillboard(vector<int>& rods) {
        N = rods.size();
        memset(visited,0 , sizeof(visited));
        return solve(0, 0, rods);
    }
};
