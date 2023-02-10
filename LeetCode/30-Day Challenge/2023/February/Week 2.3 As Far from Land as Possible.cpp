/*******************************************
 ***Problema: As Far from Land as Possible
 ***ID: Week 2.3
 ***Juez: LeetCode
 ***Tipo: BFS | DP
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        queue<vector<int>> Q;
        vector<vector<int> > dir = {{0,1}, {1,0}, {-1,0}, {0,-1}};
        int h = grid.size(), w = grid[0].size(), nx, ny;
        for(int i = 0 ; i < h ; ++i){
            for(int j = 0 ; j < w ; ++j){
                if( grid[i][j] == 1){
                    Q.push({i,j,0});
                }
            }
        }
        int res = -1, x, y, d;
        while(!Q.empty()){
            vector<int> p = Q.front(); Q.pop();
            x = p[0]; y = p[1]; d = p[2];
            for(int i = 0 ; i < 4 ; ++i){
                nx = x + dir[i][0], ny = y + dir[i][1];
                if( nx >= 0 && ny >= 0 && nx < h && ny < w && grid[nx][ny] == 0){
                    grid[nx][ny] = 1;
                    res = max(res, d+1);
                    Q.push({nx, ny, d+1});
                }
            }
        }
        return res;
    }
};
