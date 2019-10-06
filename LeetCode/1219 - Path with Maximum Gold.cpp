/*******************************************
 ***Problema: Path with Maximum Gold
 ***ID: 1219
 ***Juez: LeetCode
 ***Tipo: Backtracking
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    #define pii pair<int,int>
    #define mp make_pair
    int dx[4] = {0,  0, 1, -1};
    int dy[4] = {1, -1, 0,  0};
    vector<vector<bool> > visited;
    int dfs(vector<vector<int>>& grid, int x, int y){
        int h = grid.size(), w = grid[0].size();
        visited[x][y] = 1;
        int total = grid[x][y];
        for( int i = 0 ; i < 4 ; ++i ){
            int nx = dx[i] + x, ny = dy[i] + y;
            if( nx >= 0 && ny >= 0 && nx < h && ny < w && grid[nx][ny] > 0 && !visited[nx][ny] ){
                total = max(total, grid[x][y] + dfs(grid,nx, ny));
            }
        }
        visited[x][y] = 0;
        return total;
    }
    
    int getMaximumGold(vector<vector<int>>& grid) {
        int h = grid.size(), w = grid[0].size();
        visited = vector<vector<bool> >(h, vector<bool>(w, 0));
        int maximum = 0;
        for( int i = 0 ; i < h ; ++i ){
            for( int j = 0 ; j < w ; ++j ){
                if( grid[i][j] > 0 ){
                    maximum = max(maximum, dfs(grid, i, j));
                }
            }
        }
        return maximum;
    }
};
