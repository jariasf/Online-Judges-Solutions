/*******************************************
 ***Problema: Making A Large Island
 ***ID: 827
 ***Juez: LeetCode
 ***Tipo: BFS | DFS | Connected Components
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:

    #define ID_START 2

    vector<vector<int> > adj = { {0,1}, {0,-1}, {1, 0}, {-1, 0}};
    int floodfill(vector<vector<int> > &grid, int x, int y, int id){
        int h = grid.size();
        int w = grid[0].size();
        grid[x][y] = id;
        int res = 1;
        for( int i = 0 ; i < 4 ; ++i ){
            int nx = x + adj[i][0], ny = y + adj[i][1];
            if( nx >= 0 && ny >= 0 && nx < h && ny < w && grid[nx][ny] == 1 ){
                res += floodfill(grid, nx, ny, id);
            }
        }
        return res;
    } 
     
    int largestIsland(vector<vector<int>> &grid) {
        int h = grid.size();
        int w = grid[0].size();
        vector<int> cc;
        int id = ID_START;
        int maximum = 0;
        for( int i = 0 ; i < h ; ++i ){
            for( int j = 0 ; j < w ; ++j ){
                if( grid[i][j] == 1 ){
                    int sz = floodfill(grid, i, j, id);
                    cc.push_back(sz);
                    id++;
                    maximum = max(maximum, sz);
                }
            }
        }
                
        for( int i = 0 ; i < h ; ++i ){
            for( int j = 0 ; j < w ; ++j ){
                if( grid[i][j] == 0 ){
                    unordered_set<int> adj_ids;
                    for( int k = 0 ; k < 4 ; ++k ){
                        int nx = i + adj[k][0], ny = j + adj[k][1];
                        if( nx >= 0 && ny >= 0 && nx < h && ny < w && grid[nx][ny] != 0 ){
                            adj_ids.insert(grid[nx][ny]);
                        }
                    }
                    int total = 1;
                    for( auto it:adj_ids ){
                        total += cc[it - ID_START];
                    }
                    maximum = max( maximum, total );
                }
            }
        }
        return maximum;
    }
};
