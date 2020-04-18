/*******************************************
 ***Problema: Number of Islands
 ***ID: Week3.3
 ***Juez: LeetCode
 ***Tipo: Flood Fill
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    
    void mark(vector<vector<char>>& grid, int x, int y){
        int h = grid.size(), w = grid[0].size();
        if( x >= h || y >= w || x < 0 || y < 0 || grid[x][y] == '0') return;
        grid[x][y] = '0';
        mark(grid, x + 1, y);
        mark(grid, x, y + 1);
        mark(grid, x - 1, y);
        mark(grid, x, y - 1);
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int h = grid.size();
        if( h == 0 ) return 0;
        int w = grid[0].size();
        int cnt = 0;
        for( int i = 0 ; i < h ; ++i ){
            for( int j = 0 ; j < w ; ++j ){
                if( grid[i][j] == '1'){
                    cnt++;
                    mark(grid, i, j);
                }
            }
        }
        return cnt;
    }
};
