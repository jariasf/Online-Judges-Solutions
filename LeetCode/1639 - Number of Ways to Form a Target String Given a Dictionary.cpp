/*******************************************
 ***Problema: Number of Ways to Form a Target String Given a Dictionary
 ***ID: 1639
 ***Juez: LeetCode
 ***Tipo: Hashing + Dynamic Programming
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

#define MAX 1001
int dp[MAX][MAX];
class Solution {
public:
    int MOD = 1e9+7;
    typedef long long LL;
    vector<vector<int> > hash;
    int L, N;
    string t;
    LL solve(int i, int j){
        if(i == t.size()) return 1;
        if( j == L ) return 0;
        if( dp[i][j] != -1 ) return dp[i][j];
        LL res = solve(i, j + 1);
        if( i < t.size() && hash[j][t[i] - 'a'] > 0 ){
            res = res % MOD + hash[j][t[i] - 'a'] * solve(i + 1, j + 1) % MOD;  
        }
        return dp[i][j] = res % MOD;
    }

    int numWays(vector<string>& words, string target) {
        N = words.size();
        L = words[0].size();
        t = target;
        hash = vector<vector<int> >(L, vector<int>(26));
        for( int i = 0 ; i < L; ++i ){
            for( int j = 0 ; j < N ; ++j ){
                hash[i][ words[j][i] - 'a']++;
            }
        }
        memset(dp, -1, sizeof(dp));
        return solve(0,0);
    }
};
