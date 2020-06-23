/*******************************************
 ***Problema: Dungeon Game
 ***ID: Week3.7
 ***Juez: LeetCode
 ***Tipo: Binary Search + Dynamic Programming
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:

    bool possible(vector<vector<int>> &A, int h , int w , int value ){
        vector<vector<int> > dp( h + 5 , vector<int>(w + 5, 0) );
        dp[0][0] = value + A[0][0];
        for( int i = 0 ; i < h ; ++i ){
            for( int j = 0 ; j < w ; ++j ){
                if( i - 1 >= 0 ){
                    if( dp[i - 1 ][j] <= 0 )
                        dp[i][j] = 0;
                    else
                        dp[i][j] = A[i][j] + dp[i - 1][j];
                }
                
                if( j - 1 >= 0 ){
                    if( dp[i][j - 1] <= 0 )
                        dp[i][j] = max( dp[i][j], 0);
                    else
                        dp[i][j] = max(dp[i][j], dp[i][j - 1] + A[i][j] );
                }
                if(dp[i][j] <= 0 )
                    dp[i][j] = 0;
            }
        }
        
        return dp[h - 1][w - 1] > 0;
    }

    int calculateMinimumHP(vector<vector<int>>& A) {
        if(A.size() == 0 ) return 0;
        int h = A.size(), w = A[0].size();
        int left = 1, right = 10000;
        while( left < right ){
            int mid = ( left + right ) >> 1;
            if( possible(A, h , w, mid) ){
                right = mid;
            }else
                left = mid + 1;
        }
        
        return right;
    }
};
