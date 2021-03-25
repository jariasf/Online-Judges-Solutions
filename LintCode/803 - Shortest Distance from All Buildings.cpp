/*******************************************
 ***Problema: Shortest Distance from All Buildings
 ***ID: 803
 ***Juez: LintCode
 ***Tipo: BFS
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    /**
     * @param grid: the 2D grid
     * @return: the shortest distance
     */
    vector<vector<int> > dir = {{0,1},{0,-1},{1,0},{-1,0}};
    int shortestDistance(vector<vector<int>> &grid) {
        int h = grid.size(), w = grid[0].size(), minimum = INT_MAX, id = 0;
        vector<vector<int> > cnt(h, vector<int>(w));
        for( int i = 0 ; i < h ; ++i ){
            for( int j = 0 ; j < w ; ++j ){
                if( grid[i][j] != 1 ) continue;
                queue<pair<int,int> > Q;
                Q.push(make_pair(i * w + j, 0));
                while( !Q.empty() ){
                    pair<int, int> p = Q.front(); Q.pop();
                    int val = p.first, dist = p.second;
                    int x = val/w, y = val % w;
                    for( int i = 0 ; i < 4 ; ++i ){
                        int nx = dir[i][0] + x, ny = dir[i][1] + y;
                        if( nx >= 0 && ny >= 0 && nx < h && ny < w && grid[nx][ny] == id){
                            Q.push(make_pair(nx * w + ny, dist + 1));
                            cnt[nx][ny] += dist + 1;
                            grid[nx][ny]--;
                        }
                    }
                }
                id--;
            }
        }

        for(int i = 0 ; i < h ; ++i )
            for( int j = 0 ; j < w ; ++j )
                if( grid[i][j] == id )
                    minimum = min(minimum, cnt[i][j]);
        if( minimum == INT_MAX ) return -1;
        return minimum;
    }
};
