/*******************************************
 ***Problema: Rotting Oranges
 ***ID: Week2.2
 ***Juez: LeetCode
 ***Tipo: BFS
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    #define pii pair<int, int>
    #define mp make_pair
    vector<vector<int> > dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int orangesRotting(vector<vector<int>>& grid) {
        int h = grid.size(), w = grid[0].size();
        int valid = 0;
        queue<pii> Q;
        for( int i = 0 ; i < h ; ++i ){
            for( int j = 0 ; j < w ; ++j ){
                if( grid[i][j] == 2 )
                    Q.push(mp(i, j));
                if( grid[i][j] != 0)
                    valid++;
            }
        }
        
        int res = 0;
        while( !Q.empty() ){
            int sz = Q.size();
            valid -= sz;
            bool changed = false;
            while( sz-- > 0 ){
                pii p = Q.front(); Q.pop();
                for( int i = 0 ; i < 4 ; ++i ){
                    int nx = dir[i][0] + p.first, ny = dir[i][1] + p.second;
                    if( nx >= 0 && ny >= 0 && nx < h && ny < w && grid[nx][ny] == 1 ){
                        grid[nx][ny] = 2;
                        changed = true;
                        Q.push(mp(nx, ny));
                    }
                }
            }
            if( changed )
                res++;
            else
                break;
        }
        if( valid > 0 ) return -1;
        return res;
    }
};
