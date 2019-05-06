/***************************************************
 ***Problema: Minimum Score Triangulation of Polygon
 ***ID: 1039
 ***Juez: LeetCode
 ***Tipo: Dynamic Programming
 ***Autor: Jhosimar George Arias Figueroa
 **************************************************/

class Solution {
public:
    #define MAX 55
    int dp[MAX][MAX];
    
    int solve(vector<int>& A, int i, int j){
        if( i + 1 >= j ) return 0;
        if( dp[i][j] != -1 ) return dp[i][j];
        int res = 1<<30;
        for( int k = i + 1 ; k < j ; ++k ){
            res = min( res, A[i] * A[k] * A[j] + solve(A, i, k) + solve(A, k, j) );
        }
        return dp[i][j] = res;
    }
    
    int minScoreTriangulation(vector<int>& A) { 
        memset(dp, -1, sizeof(dp));
        return solve(A, 0, A.size() - 1);
    }
    
};
