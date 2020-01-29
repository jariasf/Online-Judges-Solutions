/*******************************************
 ***Problema: Game of Life
 ***ID: 289
 ***Juez: LeetCode
 ***Tipo: Simulation
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:

    #define CHANGED_TO_ONE 2
    #define CHANGED_TO_ZERO 3
    #define REMAIN_ONE 1
    #define REMAIN_ZERO 0

    void gameOfLife(vector<vector<int> >& board) {
        int h = board.size();
        if( h == 0 ) return;
        int w = board[0].size();
        
        for( int i = 0 ; i < h ; ++i ){
            for( int j = 0 ; j < w ; ++j ){
                int ones = 0;
                for( int ii = -1 ; ii <= 1 ; ++ii ){
                    for( int jj = -1; jj <= 1 ; ++jj ){
                        if( ii == 0 && jj == ii ) continue;
                        int x = i + ii, y = j+jj;
                        if( x >= 0 && y >= 0 && x < h && y < w && 
                            (board[x][y] == CHANGED_TO_ZERO || board[x][y] == REMAIN_ONE) ){
                            ones++;
                        }
                    }
                }
                if( board[i][j] == 1 ){
                    if( ones < 2 || ones > 3 ) board[i][j] = CHANGED_TO_ZERO;
                }else if( ones == 3 ) board[i][j] = CHANGED_TO_ONE;
            }
        }
        
        for( int i = 0 ; i < h ; ++i )
            for( int j = 0 ; j < w ; ++j )
                if( board[i][j] == CHANGED_TO_ZERO ) board[i][j] = 0;
                else if( board[i][j] == CHANGED_TO_ONE ) board[i][j] = 1;
        
    }
};
