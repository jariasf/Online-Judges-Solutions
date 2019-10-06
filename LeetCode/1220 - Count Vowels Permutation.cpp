/*******************************************
 ***Problema: Count Vowels Permutation
 ***ID: 1220
 ***Juez: LeetCode
 ***Tipo: Dynamic Programming
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    const int MOD = 1e9 + 7;
    typedef long long LL;
    vector<vector<int> > adj= {{1},{0, 2}, {0, 1, 3, 4}, {2, 4},{0}};
    vector<vector<LL> > dp;

    LL solve(int n, int u){
        if(n == 0){
            return 1;
        }
        if(dp[n][u] != -1) return dp[n][u];
        LL tot = 0;
        for(int i = 0 ; i < adj[u].size(); ++i ){
            int v = adj[u][i];
            tot = tot + solve(n - 1, v);
            tot %= MOD;
        }
        return dp[n][u] = tot;
    }
    
    int countVowelPermutation(int n) {
        dp = vector<vector<LL> >(n , vector<LL>(5, -1)); 
        LL tot = 0;
        for( int i = 0 ; i < 5 ; ++i ){
            tot = tot + solve(n - 1, i);
            tot %= MOD;
        }
        return tot;
    }
};
