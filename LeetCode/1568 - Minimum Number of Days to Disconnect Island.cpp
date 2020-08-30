/*******************************************
 ***Problema: Minimum Number of Days to Disconnect Island
 ***ID: 1568
 ***Juez: LeetCode
 ***Tipo: DFS
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:

    void dfs(int x, int y, vector<vector<int>> &grid){
        int h = grid.size(), w = grid[0].size();
        if( x < 0 || y < 0 || x >= h || y >= w || grid[x][y] == 0 )
            return;
        grid[x][y] = 0;
        dfs(x + 1, y , grid);
        dfs(x, y + 1, grid);
        dfs(x - 1, y, grid);
        dfs(x, y - 1 , grid);
    }
    
    int num_comp(vector<vector<int> > grid){
        int h = grid.size(), w = grid[0].size();
        int cnt = 0;
        for( int i = 0 ; i < h ; ++i ){
            for( int j = 0 ; j < w ; ++j ){
                if( grid[i][j] == 1 ){
                    cnt++;
                    if( cnt > 1 ) goto end;
                    dfs(i, j, grid);
                }
            }
        }
        end:
        return cnt;
    }
    
    int minDays(vector<vector<int>>& grid) {
        int h = grid.size(), w = grid[0].size();
        if( num_comp(grid) != 1 ) return 0;
        for( int i = 0 ; i < h ; ++i ){
            for( int j = 0 ; j < w ; ++j ){
                if( grid[i][j] == 1 ){
                    grid[i][j] = 0;
                    if( num_comp(grid) != 1 ) 
                        return 1;
                    grid[i][j] = 1;
                }
            }
        }
        return 2;
    }
};
