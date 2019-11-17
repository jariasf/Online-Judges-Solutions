/*******************************************
 ***Problema: Shift 2D Grid
 ***ID: 1260
 ***Juez: LeetCode
 ***Tipo: Simulation
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int h = grid.size(), w = grid[0].size();
        vector<vector<int> > res(h, vector<int>(w));
        int n = h * w;
        for( int i = 0 ; i < h ; ++i ){
            for( int j = 0 ; j < w ; ++j ){
                int id = (i * w + j + k) % n;
                res[id/w][id%w] = grid[i][j];
            }
        }
        return res;
    }
};

// Simulation - Brute Force
class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int h = grid.size(), w = grid[0].size();
        while(k-- > 0 ){
            vector<vector<int> > aux = grid;
            for( int i = 0 ; i < h ; ++i ){
                for( int j = 1 ; j < w ; ++j ){
                    aux[i][j] = grid[i][j - 1];
                }
            }
            
            aux[0][0] = grid[h - 1][ w - 1];
            for( int i = 1 ; i < h ; ++i ){
                aux[i][0] = grid[i - 1][w - 1];
            }
            grid = aux;
        }
        return grid;
    }
};
