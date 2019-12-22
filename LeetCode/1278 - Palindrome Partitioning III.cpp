/*******************************************
 ***Problema: Palindrome Partitioning III
 ***ID: 1278
 ***Juez: LeetCode
 ***Tipo: Dynamic Programming
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:

    vector<vector<int> > dp;
    vector<vector<int> > pal;
    int solve(int n, int pos, int k){
        if( k < 0 ) return 1<<30;
        if( pos == n ){
            if( k != 0 ) return 1<<30;
            return 0;
        }
        
        if( dp[pos][k] != -1 ) return dp[pos][k];
        
        int res = 1<<30;
        for( int i = pos + 1 ; i <= n ; ++i ){
            res= min( res, pal[pos][i - 1] + solve(n, i, k - 1));
        }
        return dp[pos][k] = res;
    }
    
    int palindromePartition(string s, int k) {
        int n = s.size();
        if( n == k ) return 0;
        pal = vector<vector<int> >(n + 5, vector<int>(n + 5, 1<<30));      
        for( int i = 0 ; i < n ; ++i ){
            pal[i][i] = 0;
        }
        
        for( int l = 1 ; l < n ; ++l ){
            for( int i = 0, j = i + l ; i < n, j < n ; ++i, ++j ){
                if( s[i] == s[j] ){
                    if( i + 1 <= j - 1){
                        pal[i][j] = min(pal[i][j], pal[i + 1][j - 1]);
                    }else
                        pal[i][j] = 0;
                }else{
                    if( i + 1 <= j - 1 ){
                        pal[i][j] = min(pal[i][j], 1 + pal[i + 1][j - 1]);
                    }else{
                        pal[i][j] = 1;
                    }
                }
            }
        }
        
        dp = vector<vector<int> >(n + 5, vector<int>(k + 5, -1));
        return solve(n, 0, k);
    }
};
