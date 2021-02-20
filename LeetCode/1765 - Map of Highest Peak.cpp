/*******************************************
 ***Problema: Map of Highest Peak
 ***ID: 1765
 ***Juez: LeetCode
 ***Tipo: BFS
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    vector<vector<int> > dir = {{0,1},{1,0},{0,-1},{-1,0}};
    vector<vector<int>> highestPeak(vector<vector<int>>& grid) {
        int h = grid.size(), w = grid[0].size();       
        queue<pii> Q;
        vector<vector<int> > seen(h, vector<int>(w, -1));
        for( int i = 0 ; i < h ; ++i ){
            for( int j = 0 ; j < w ; ++j ){
                if( grid[i][j] == 1 ){
                    Q.push(mp(i, j));
                    seen[i][j] = 0;
                }
            }
        }
        while( !Q.empty() ){
            pii p = Q.front(); Q.pop();
            int x = p.first, y = p.second;
            for( int i = 0 ; i < 4 ; ++i ){
                int nx = x + dir[i][0], ny = y + dir[i][1];
                if( nx >= 0 && ny >= 0 && nx < h && ny < w && seen[nx][ny] == -1 ){ 
                    seen[nx][ny] = seen[x][y] + 1;
                    Q.push(mp(nx,ny));
                }
            }
        }
        return seen;
    }
};
