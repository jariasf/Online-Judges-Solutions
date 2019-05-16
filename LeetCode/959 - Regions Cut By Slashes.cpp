/*******************************************
 ***Problema: Regions Cut By Slashes
 ***ID: 959
 ***Juez: LeetCode
 ***Tipo: Flood Fill
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    int dx[4] = {0 , 0 ,1, -1};
    int dy[4] = {1, -1, 0, 0};
    void flood(vector<vector<bool> >& ady, int x , int y , int h, int w){
        ady[x][y] = 1;
        for( int i = 0 ; i < 4 ; ++i ){
            int nx = x + dx[i], ny = y + dy[i];
            if( nx >= 0 && ny >= 0 && nx < h && ny < w && ady[nx][ny] == 0 ){
                flood(ady, nx, ny, h, w);
            }
        }
        
    }
    
    int regionsBySlashes(vector<string>& grid) {
        int h = grid.size(), w = grid[0].size();
        int H = h * 3, W = w * 3;
        vector<vector<bool> > ady( H, vector<bool>(W, 0));

        for( int i = 0, ii= 0; i < h ; ++i, ii += 3 ){
            for( int j = 0, jj =0  ; j < w ; ++j, jj += 3 ){
                char c = grid[i][j];
                if( c == '/'){
                    for( int k = 2; k >= 0 ; --k ){
                        ady[ii + 2 - k][jj + k] = 1;
                    }
                }else if( c == '\\' ){
                    for( int k = 0; k < 3 ; ++k ){
                        ady[ii + k][jj + k] = 1;
                    }
                }
            }
        }

        int res = 0;
        for( int i = 0 ; i < H ; ++i ){
            for( int j = 0 ; j < W ; ++j ){
                if( ady[i][j] == 0 ){
                    res++;
                    flood(ady, i, j, H, W);
                }
            }
        }
        
        return res;
    }
};
