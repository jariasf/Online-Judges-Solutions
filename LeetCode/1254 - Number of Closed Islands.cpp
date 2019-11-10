/*******************************************
 ***Problema: Number of Closed Islands
 ***ID: 1254
 ***Juez: LeetCode
 ***Tipo: BFS|DFS
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    int h , w;
    bool valid;
    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {1, -1, 0, 0};
    void flood( vector<vector<int> > &grid, int x, int y ){
        if( x == 0 || y == 0 || x == h - 1 || y == w - 1 ){
            valid = false;
        }
        grid[x][y] = -1;
        for( int i = 0 ; i < 4 ; ++i ){
            int nx = x + dx[i], ny = y + dy[i];
            if( nx >= 0 && ny >= 0 && nx < h && ny < w && grid[nx][ny] == 0 ){
                flood(grid, nx, ny);
            }
        }
    }
    
    int closedIsland(vector<vector<int>>& grid) {
        h = grid.size(); w = grid[0].size();
        int res = 0;
        for( int i = 0 ; i < h ; ++i ){
            for( int j = 0 ; j < w ; ++j ){
                if( grid[i][j] == 0 ){
                    valid = true;
                    flood(grid, i, j);
                    res += valid;
                }
            }
        }
        return res;
    }
};
