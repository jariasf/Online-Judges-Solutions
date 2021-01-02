/*******************************************
 ***Problema: Diagonal Traverse
 ***ID: Week4.4
 ***Juez: LeetCode
 ***Tipo: Ad hoc
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        int h = matrix.size();
        if( h == 0 ) return {};
        int w = matrix[0].size();
        int n = h * w;
        vector<int> res(n);        
        int incr = -1;        
        int x = 0, y = 0, pos = 0, top = 1;
        while( pos < n ){
            for( int i = 0 ; i < top && pos < n ; ++i ){
                if( x >= 0 && y >= 0 && x < h && y < w ){
                    res[pos++] = matrix[x][y];
                }
                x += incr;
                y -= incr;
            }
            if( top & 1 ) x = 0, y = top, incr=1;
            else x = top, y = 0, incr=-1;
            top++;
        }
        return res;
    }
};
