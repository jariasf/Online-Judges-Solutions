/*******************************************
 ***Problema: Walls and Gates
 ***ID: 663
 ***Juez: LintCode
 ***Tipo: BFS
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    /**
     * @param rooms: m x n 2D grid
     * @return: nothing
     */

    //#define pair<int, int> pii
    //#define make_pair mp
    vector<vector<int> > dir = {{0,1}, {0, -1}, {1,0}, {-1,0}};
    void wallsAndGates(vector<vector<int>> &rooms) {
        int h = rooms.size(), w = rooms[0].size();
        queue<pair<int, int> > Q;
        for( int i = 0 ; i < h ; ++i ){
            for( int j = 0 ; j < w ; ++j ){
                if( rooms[i][j] == 0 ){
                    Q.push(make_pair(i, j));
                }
            }
        }

        while( !Q.empty() ){
            pair<int ,int> p = Q.front(); Q.pop();
            int x = p.first, y = p.second;
            for( int i = 0 ; i < 4 ; ++i ){
                int nx = x + dir[i][0], ny = y + dir[i][1];
                if( nx >= 0 && ny >= 0 && nx < h && ny < w && rooms[nx][ny] == INT_MAX ){
                    Q.push(make_pair(nx,ny));
                    rooms[nx][ny] = rooms[x][y] + 1;
                }
            }
        }
    }
};
