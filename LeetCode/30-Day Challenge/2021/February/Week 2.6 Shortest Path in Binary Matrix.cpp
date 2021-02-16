/*******************************************
 ***Problema: Shortest Path in Binary Matrix
 ***ID: Week2.6
 ***Juez: LeetCode
 ***Tipo: BFS
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    #define pii pair<int, int>
    #define mp make_pair
    vector<vector<int> > dir = {{-1,-1}, {-1,0}, {-1,1},{0,-1}, {0,1},{1,-1}, {1,0}, {1,1} };
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if( grid[0][0] == 1 ) return -1;
        queue<pii> Q;
        Q.push(mp(0, 0));
        int h = grid.size(), w = grid[0].size();
        vector<vector<int> > dist(h, vector<int>(w, INT_MAX));
        dist[0][0] = 1;
        while(!Q.empty() ){
            pii cur = Q.front(); Q.pop();
            int x = cur.first, y = cur.second;
            if( x == h - 1 && y == w - 1 ) break;
            for( int i = 0 ; i < dir.size(); ++i ){
                int nx = x + dir[i][0], ny = y + dir[i][1];  
                if( nx >= 0 && ny >= 0 && nx < h && ny < w && !grid[nx][ny] && dist[x][y] + 1 < dist[nx][ny] ){
                    dist[nx][ny] = dist[x][y] + 1;
                    Q.push(mp(nx, ny));
                }
            }
        }
        
        if( dist[h - 1][w - 1] == INT_MAX) return -1;
        return dist[h - 1][w - 1];
    }
};
