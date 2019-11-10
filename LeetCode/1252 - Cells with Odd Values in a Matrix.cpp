/*******************************************
 ***Problema: Cells with Odd Values in a Matrix
 ***ID: 1252
 ***Juez: LeetCode
 ***Tipo: Simulation
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    int oddCells(int n, int m, vector<vector<int>>& indices) {
        int sz = indices.size();
        vector<vector<int> > v(n, vector<int>(m));
        for( int i = 0 ; i < sz ; ++i ){
            int x = indices[i][0], y = indices[i][1];
            for( int j = 0 ; j < m ; ++j )
                v[x][j]++;
            for( int j = 0 ; j < n ; ++j )
                v[j][y]++;
        }
        
        int odd = 0;
        for( int i = 0 ; i < n ; ++i ){
            for( int j = 0 ; j < m ; ++j ){
                if( v[i][j] & 1 ) odd++;
            }
        }
        return odd;
    }
};
