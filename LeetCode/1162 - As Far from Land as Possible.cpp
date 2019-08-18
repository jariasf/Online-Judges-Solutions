/*******************************************
 ***Problema: As Far from Land as Possible
 ***ID: 1162
 ***Juez: LeetCode
 ***Tipo: BFS
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:

    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    #define pii pair<int,int>
    #define mp make_pair
    #define INF 1<<30
    int maxDistance(vector<vector<int>>& grid) {
        int h = grid.size(), w = grid[0].size();
        queue<pii> Q;
        vector<vector<int> > dist(h + 1, vector<int>(w + 1, INF));
        for( int i = 0 ; i < h ; ++i ){
            for( int j = 0 ; j < w ; ++j ){
                if( grid[i][j] == 1 ){
                    Q.push(mp(i,j));
                    dist[i][j] = 0;
                }
            }
        }

        bool possible = false;
        while( !Q.empty() ){
            pii p = Q.front(); Q.pop();
            int x = p.first, y = p.second;
            for( int i = 0 ; i < 4 ; ++i ){
                int nx = dx[i] + x, ny = dy[i] + y;
                if( nx >= 0 && ny >= 0 && nx < h && ny < w && grid[nx][ny] == 0 && dist[nx][ny] > dist[x][y] + 1 ){
                    dist[nx][ny] = dist[x][y] + 1;
                    Q.push( mp(nx,ny));
                    possible = true;
                }
            }
        }

        if( !possible ) return -1;
        int maxi = -1;
        for( int i = 0 ; i < h ; ++i ){
            for( int j = 0 ; j < w ; ++j ){
                if( dist[i][j] != INF ){
                    maxi = max(maxi, dist[i][j]);
                }
            }
        }
        return maxi;
    }
};
