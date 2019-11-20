/*******************************************
 ***Problema: Coin Path
 ***ID: 866
 ***Juez: LintCode
 ***Tipo: Dynamic Programming
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    /**
     * @param A: a list of integer
     * @param B: an integer
     * @return: return a list of integer
     */
    vector<int> cheapestJump(vector<int> &A, int B) {
        int n = A.size();
        vector<int> dp(n + 2, INT_MAX);
        vector<int> path(n + 2, -1);
        dp[n - 1] = A[n - 1];
        for( int i = n - 2 ; i >= 0 ; --i ){
            if( A[i] == -1 ) continue;
            for( int j = 1; j <= B && i + j < n ; ++j ){
                if(dp[i+j] != INT_MAX && dp[i] > dp[i + j] + A[i]){
                    dp[i] = A[i] + dp[i + j];
                    path[i] = i + j;
                }
            }
        }
        if( dp[0] == INT_MAX )
            return vector<int>();
        
        vector<int> result;
        int pos = 0;
        do{
            result.push_back(pos + 1);
            pos = path[pos];
        }while(pos != -1 );
        return result;
    }
};
/*
[1,2,3,4,5]
2
[1,2,4,-1,2]
1
[0,0,0,0,0,0]
3
*/
