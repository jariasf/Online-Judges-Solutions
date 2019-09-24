/*******************************************
 ***Problema: Minimum Falling Path Sum
 ***ID: 1711
 ***Juez: LintCode
 ***Tipo: Dynamic Programming
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    /**
     * @param A: the given array
     * @return: the minimum sum of a falling path
     */
    int minFallingPathSum(vector<vector<int>> &A) {
        int h = A.size(), w = A[0].size();
        vector<int> last(w + 2, 1<<30), final(w + 2, 1<<30);
        for( int i = 1 ; i <= w ; ++i )
            last[i] = final[i] = A[0][i - 1];
        
        for( int i = 1 ; i < h ; ++i ){
            for( int j = 1 ; j <= w ; ++j ){
                if( i & 1 )
                    final[j] = min( last[j-1], min( last[j], last[j+1])) + A[i][j - 1];
                else
                    last[j] = min( final[j-1], min( final[j], final[j+1])) + A[i][j - 1];                
            }
        }
        
        int result = 1<<30;
        if( h % 2 == 0){
            for( int i = 1 ; i <= w ; ++i ) result = min( result, final[i]);
        }else{
            for( int i = 1 ; i <= w ; ++i ) result = min( result, last[i]);            
        }
        return result;
    }
};
