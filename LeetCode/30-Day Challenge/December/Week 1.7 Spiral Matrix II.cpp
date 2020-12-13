/*******************************************
 ***Problema: Spiral Matrix II
 ***ID: Week1.7
 ***Juez: LeetCode
 ***Tipo: Ad hoc
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int> > res;
        if( n == 0 ) return res;
        int xini =0, yini = 0, w , h, id = 1;
        w = h = n;
        res = vector<vector<int> >(n, vector<int>(n, 0));
        while( id <= n * n ){
            for( int i = yini ; i < w ; ++i )
                res[xini][i] = id++;
            
            xini++;
            for( int i = xini; i < h ; ++i )
                res[i][w - 1] = id++;
            
            w--;
            for( int i = w - 1 ; i >= yini ; --i )
                res[h - 1][i] = id++;
            
            h--;
            
            for( int i = h - 1 ; i >= xini ; --i )
                res[i][yini] = id++;
            
            yini++;
        }
        return res;
    }
};
