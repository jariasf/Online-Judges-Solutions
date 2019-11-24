/*******************************************
 ***Problema: Count Servers that Communicate
 ***ID: 1267
 ***Juez: LeetCode
 ***Tipo: Ad hoc
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int  h = grid.size(), w = grid[0].size();
        vector<int> row(h, 0);
        vector<int> col(w, 0);
        for( int i = 0 ; i < h ; ++i ){
            for( int j = 0 ; j < w ; ++j ){
                if( grid[i][j] ){
                    row[i]++;
                    col[j]++;
                }
            }
        }
        int result = 0;
        for( int i = 0 ; i < h ; ++i ){
            for( int j = 0 ; j < w ; ++j ){
                if( grid[i][j]){
                    if( row[i] + col[j] > 2 ) result++;
                }
            }
        }
        return result;
    }
};
