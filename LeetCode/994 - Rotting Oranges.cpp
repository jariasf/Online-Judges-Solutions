/*******************************************
 ***Problema: Rotting Oranges
 ***ID: 994
 ***Juez: LeetCode
 ***Tipo: BFS
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    struct Data{
        int x, y, d;
        Data(int xx , int yy, int dd ): x(xx), y(yy), d(dd){}
        Data(){}
    };
    int dx[4] = {0 , 0 , 1, -1};
    int dy[4] = {1, -1, 0, 0};
    int orangesRotting(vector<vector<int>>& grid) {
        queue<Data> Q;
        int h = grid.size(); int w = grid[0].size();
        vector<vector<bool> > seen(h, vector<bool>(w, false));
        for( int i = 0 ; i < h; ++i ){
            for( int j = 0 ; j < w ; ++j ){
                if( grid[i][j] == 2 ){
                    Q.push(Data(i, j, 0));
                    seen[i][j] = true;
                }
            }
        }
        
        int tot = 0;
        while( !Q.empty() ){
            Data cur = Q.front(); Q.pop();
            tot = max(tot, cur.d);
            for( int i = 0 ; i < 4 ; ++i ){
                int nx = dx[i] + cur.x;
                int ny = dy[i] + cur.y;
                if( nx >= 0 && ny >= 0 && nx < h && ny < w && grid[nx][ny] != 0 && !seen[nx][ny] ){
                    seen[nx][ny] = true;
                    Q.push(Data(nx,ny,cur.d + 1));
                }
            }
        }
        
        for( int i = 0 ; i < h ; ++i ){
            for( int j = 0 ; j < w ; ++j ){
                if( grid[i][j] == 1 && !seen[i][j] ) return -1;
            }
        }
        return tot;
    }
};
