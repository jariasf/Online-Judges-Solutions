/********************************************
 ***Problema: Coloring A Border
 ***ID: 1034
 ***Juez: LeetCode
 ***Tipo: Flood Fill, DFS, BFS
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:

    #define COLORED 1
    #define SEEN 2
    vector<vector<int> > v;
    vector<vector<bool> > colored;
    vector<vector<bool> > visited;
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0 , 0};
    int new_color;
    int h, w;

    bool isBorder(int x, int y, int color ){
        int out = 0, other = 0;
        for( int i = 0 ; i < 4 ; ++i ){
            int nx = x + dx[i], ny = y + dy[i];
            if( nx < 0 || nx >= h || ny < 0 || ny >= w ) out++;
            if( nx >= 0 && nx < h && ny >= 0 && ny < w && v[nx][ny] != color ) other++;
        }
        if( out > 0 || other > 0 ) return true;
        return false;
    }

    void floodfill(int x , int y, int color){
        visited[x][y] = true;
        if( isBorder(x, y, color) ){
            colored[x][y] = true;
        }

        for( int i = 0 ; i < 4 ; ++i ){
            int nx = x + dx[i], ny = y + dy[i];
            if( nx >= 0 && nx < h && ny >= 0 && ny < w && v[nx][ny] == color && !visited[nx][ny] ){
                floodfill(nx, ny, color);
            }
        }
    }

    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int r0, int c0, int color) {
        h = grid.size(); w = grid[0].size();
        v = grid;
        visited = vector<vector<bool> >(h, vector<bool>(w, 0));
        colored = vector<vector<bool> >(h, vector<bool>(w, 0));
        new_color = color;
        floodfill(r0,c0, grid[r0][c0]);
        for( int i = 0 ; i < h ; ++i ){
            for( int j = 0 ; j < w ; ++j ){
                if( colored[i][j] == 1 ) grid[i][j] = color;
            }
        }
        return grid;
    }
};
