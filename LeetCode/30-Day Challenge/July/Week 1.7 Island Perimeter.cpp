/*******************************************
 ***Problema: Island Perimeter
 ***ID: Week1.7
 ***Juez: LeetCode
 ***Tipo: Ad hoc
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int h = grid.size();
        if( h == 0 ) return 0;
        int w = grid[0].size(), perimeter = 0;
        for( int i = 0 ; i < h ; ++i ){
            for( int j = 0 ; j < w ; ++j ){
                if( grid[i][j] ){
                    perimeter += (i == 0 || i > 0 && grid[i - 1][j] == 0);
                    perimeter += (j == 0 || j > 0 && grid[i][j - 1] == 0);
                    perimeter += (i == h - 1 || i + 1 < h && grid[i + 1][j]  == 0);
                    perimeter += (j == w - 1 || j + 1 < w && grid[i][j + 1] == 0);
                }
            }
        }
        return perimeter;
    }
};
