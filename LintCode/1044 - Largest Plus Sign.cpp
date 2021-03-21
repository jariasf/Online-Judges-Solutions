/*******************************************
 ***Problema: Largest Plus Sign
 ***ID: 1044
 ***Juez: LintCode
 ***Tipo: Prefix and Suffix Sums
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    /**
     * @param N: size of 2D grid
     * @param mines: in the given list
     * @return: the order of the plus sign
     */
    int orderOfLargestPlusSign(int N, vector<vector<int>> &mines) {
        vector<vector<int> > grid(N, vector<int>(N, N));
        for( vector<int> mine: mines)
            grid[mine[0]][mine[1]] = 0;

        for( int i = 0, ii = N - 1 ; i < N ; ++i, --ii ){
            int left, right, down, up;
            left = right = down = up = 0;
            for( int j = 0, jj = N - 1 ; j < N ; ++j, --jj ){
                if( grid[i][j])
                    left++;
                else left = 0;

                if( grid[j][i])
                    down++;
                else down = 0;

                if( grid[ii][jj])
                    right++;
                else
                    right = 0;

                if( grid[jj][ii])
                    up++;
                else
                    up = 0;
                grid[i][j] = min(grid[i][j], left);
                grid[ii][jj] = min(grid[ii][jj], right);
                grid[j][i] = min(grid[j][i], down); 
                grid[jj][ii] = min(grid[jj][ii], up);                                               
            }
        }

        int result = 0;
        for( int i = 0 ; i < N ; ++i ){
            for( int j = 0 ; j < N ; ++j ){
                result = max(result, grid[i][j]);
            }
        }
        return result;
    }
};
