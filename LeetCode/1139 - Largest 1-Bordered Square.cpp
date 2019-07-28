/*******************************************
 ***Problema: Largest 1-Bordered Square
 ***ID: 1139
 ***Juez: LeetCode
 ***Tipo: Dynamic Programming
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    int largest1BorderedSquare(vector<vector<int>>& grid) {
        int h = grid.size(), w = grid[0].size();
        
        vector<vector<int> > col = vector<vector<int> >(h + 1, vector<int>(w + 1));
        vector<vector<int> > row = vector<vector<int> >(h + 1, vector<int>(w + 1));        
        
        for( int i = 1 ; i <= h ; ++i ){
            for( int j = 1 ; j <= w ; ++j ){
                row[i][j] = row[i][j - 1] + grid[i - 1][j - 1];
                col[i][j] = col[i - 1][j] + grid[i - 1][j - 1];
            }
        }
        
        int result = 0;
        for( int i = 1; i <= h ; ++i ){
            for( int j = 1 ; j <= w ; ++j ){
                for( int k = 0 ; i + k <= h && j + k <= w ; ++k ){
                    if( col[i + k][j] - col[i - 1][j] == (k + 1) &&
                        col[i + k][j + k] - col[i - 1][ j + k] == (k + 1) &&
                        row[i][j + k] - row[i][j - 1] == (k + 1) &&
                        row[i + k][j + k] - row[i + k][j - 1] == (k + 1) ){
                        result = max( result, (k + 1) * ( k + 1 ) );
                    }
                    
                }
            }
        }
        
        return result;
    }
};
